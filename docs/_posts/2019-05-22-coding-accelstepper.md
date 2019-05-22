---
permalink: coding-accelstepper/
title: Coding version 1 – Understanding the AccelStepper library
date: 2019-05-22
author: Andrew
layout: page
sort_id: 53
---

I decided to use the AccelStepper library to handle motion control for this project. As my state machine became simpler, I suspect the need for this became less urgent, and I could have made do with the standard Arduino stepper library, or even just written some functions myself to control the motor directly by pulsing the step pin.  

However, I spent some time getting to grips with this library, so I wanted to record a few things I learned here, not least because the library comes with sparse examples, and minimal documentation generated with the docs builder [Doxygen](http://www.doxygen.nl/index.html), which I find to be pretty unhelpful. Critically, I can't find anywhere a description of the conceptual model AccelStepper uses. What does it mean by 'move' or 'run' or 'stop', and how do these concepts relate to each other? These are things that I guess it's easy for an experienced user to understand, but opaque for a new user.

As I'm in the middle of learning this stuff, I feel readers should exercise particular caution here: there could be many mistakes, misunderstandings or poor recommendations ahead. Proceed with caution!

## Creating a stepper object with the constructor function.

Docs here: <https://www.airspayce.com/mikem/arduino/AccelStepper/classAccelStepper.html#a3bc75bd6571b98a6177838ca81ac39ab>

Initially I was confused by the `FULL4WIRE` and `FULL2WIRE` options. My motor has four wires, so that seemed appropriate, but then it is controlled with 2 pins, so that could also be correct. Eventually, I realised that because I'm using an A4988 driver, I should use the `DRIVER` option. And because my shield has DIRECTION on D3 and STEP on D2, I should specify those arguments like so in the constructor:

```
AccelStepper stepper(AccelStepper::DRIVER, 2, 3);
```

Possibly a case of RTFM... 

## Moving from one known position to another known position

This is the most basic functionality I needed to enable (when I was using calibrated end positions). It gives some idea of how the different library concepts can work together:

```
stepper.moveTo(rightEndStopPosition); 
stepper.setSpeed(traverseSpeed); 

while (stepper.currentPosition() != stepper.targetPosition()) { 
  stepper.runSpeedToPosition();
}
```

In this simplified code (the full code is in [traverse.ino](https://github.com/andrewsleigh/fab-slider/blob/master/arduino-code/old-complex-state-machine/State_Machine_6/traverse.ino), the gantry moves from the left end to the right at a constant speed. You can see how the function `moveTo()` doesn't actually move anything. It took me a while to figure that out.

## Getting an end-stop position.

Useful if you want to calibrate the slider so you know where the two ends are:

```
if (digitalRead(leftEndStopPin) == HIGH) { // if it touches an end-stop 
  leftEndStopPosition = stepper.currentPosition(); 
  gotLeftLimit = true; // a boolean variable for tracking calibration status
  stepper.stop(); 
  stepper.runToPosition(); 
}
```

Note that `stop()` doesn't stop the motor! It just sets a new target at the current position. You then need to `runToPosition()` to actually stop the motor.

## Blocking and non-blocking functions

Because I want the user to be able to pause or cancel a slide, and also for the end-stops to be able to halt movement, I can't have the stepper control functions block other inputs. Generally, it seems (and I might be wrong) that library functions that implement acceleration are blocking, those that don't aren't... 


## Using acceleration

I think this is the raison d'etre of this library. I think it could be useful for me in two scenarios:

1. Giving more naturalistic slides in video mode by easing in at the beginning and easing out at the end of the traverse
2. Moving heavy loads (like a DSLR camera) with more stability and les risk of motor slippage by avoiding sudden starts and stops

Some of the library functions implement acceleration (e.g. `runToPosition()`), and some don't (e.g. `runSpeedToPosition()`). 

I believe that the program needs to know the total number of steps in a given traverse so that it can calculate how fast to accelerate/decelerate, and when to start decelerating. So in my original version of the code, in which the end positions were calibrated, I could use this everywhere. But in my new simpler version, the program can't know how how many total steps there are in a traverse, so I only use acceleration in the small backing-off movements when the gantry hits an end-stop and I want it to back off the switch lever:

```
stepper.runToNewPosition(leftEndStopPosition+endStopPadding);
```

This is a blocking function, but that's not a problem in this particular situation.

I need to do some more tests in the two scenarios noted above. I may need to do some more work in my code to implement acceleration and deceleration. <span class="wip">WIP</span>

## Disabling the motor

I don't want to keep the motor powered when I'm not moving the slider. It uses power and makes an annoying noise. The library has a [function](https://www.airspayce.com/mikem/arduino/AccelStepper/classAccelStepper.html#a3591e29a236e2935afd7f64ff6c22006) `disableOutputs()` which might do what I want, but I couldn't figure out how to get it to work. So instead, I just connected the ENABLE pin on my driver to one of the Arduino's digital outputs and pulled it high to disable the motor:

```
digitalWrite(motorOffPin, HIGH);
```

From the datasheet:

> Enable Input
> This input turns on or off all of the FET outputs. When set to a logic high, the outputs are disabled. When set to a logic low, the internal control enables the outputs as required. The translator inputs STEP, DIR, and MSx, as well as the internal sequencing logic, all remain active, independent of the ENABLE input state. 

