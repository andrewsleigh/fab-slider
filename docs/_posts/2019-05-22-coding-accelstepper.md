---
permalink: coding-accelstepper/
title: Coding version 1 – Understanding the AccelStepper library
date: 2019-05-22
author: Andrew
layout: page
sort_id: 53
---

I decided to use the AccelStepper library to handle motion control for this project. As my state machine became simpler, I suspect the need for this became less urgent, and I could have made do with the standard Arduino stepper library, or even just written some functions myself to control the motor directly by pulsing the step pin.  

However, I spent some time getting to grips with this library, so I wanted to record a few things I learned here, not least because the library comes with sparse examples, and minimal documentation generated with the docs builder, [Doxygen](http://www.doxygen.nl/index.html), which I find to be pretty unhelpful. Critically, I can't find anywhere a description of the conceptual model AccelStepper uses. What does it mean by 'move' or 'run' or 'stop' and how do these concepts inter-relate? These are things that it's easy for an experienced user to understand, but opaque for a new user.

## Creating a stepper object with the constructor function.

Docs here: <https://www.airspayce.com/mikem/arduino/AccelStepper/classAccelStepper.html#a3bc75bd6571b98a6177838ca81ac39ab>

Initially I was confused by the `FULL4WIRE` and `FULL2WIRE` options. My motor has four wires, so that seemed appropriate, but then it is controlled with 2 pins, so that could also be correct. Eventually, I realised that because I'm using an A4988 driver, I should use the `DRIVER` option. And because my shield has DIRECTION on D3 and STEP on D2, I should specify those arguments like so in the constructor:

```
AccelStepper stepper(AccelStepper::DRIVER, 2, 3);
```


## Blocking and non-blocking functions


## Using acceleration

I think this is the raison d'etre of this library. I think it could be useful for me for two reasons:

1. Giving more naturalistic slides in video mode by easing in at the beginning and easing out at the end of the traverse
2. Moving heavy loads (like a DSLR camera) with more stability and les risk of motor slippage by avoiding sudden starts and stops

Some of the library functions implement acceleration (e.g. `runToPosition()`), and some don't (e.g. `runSpeedToPosition()`). 

I believe that the program needs to know the total number of steps in a given traverse so that it can calculate how fast to accelerate/decelerate and when to start decelerating
