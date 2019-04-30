---
permalink: making-v1-testing-motor/
title: Making version 1 – Testing the motor and driver
date: 2019-04-30
author: Andrew
layout: page
sort_id: 40
---

Having never used a stepper motor before, I started by trying to get my head around how these can be controlled via Arduino.

## Driver board pinout

These boards have headers for connection to a breadboard (or carrier board). Unfortunately the pins are labelled on the underside, so it’s difficult to see what’s going on once you have it installed on a breadboard. In the end, I just connected wires directly from my Arduino and power supply to the male headers on the underside of the board.


![]({{site.baseurl}}/assets/IMG_1694.jpg)

## Mapping my pins to those on the [Big Easy Driver stepper motor driver](http://www.schmalzhaus.com/BigEasyDriver/index.html).

SparkFun’s Big Easy Driver (based on the same chip) has some nice documentation, so I wanted to use that to start experimenting with my motor. However the header pin arrangement and labelling on their board is slightly different, so I had to map one to the other. It was mostly pretty easy, except for the voltage pins (VDD and VMOT). So I had to do some digging on those:

The BigEasyDriver has a pin labelled M+:
> M+ : This is the power input to the Easy Driver. Connect this to the positive power supply lead. This should be a 6V to 30V, 3A (or more) power supply that is clean (low ripple).

The datasheet has a V pin called VBB (2 in fact, which are shorted with a large 100uF capacitor). This is the “Load Supply Voltage“, rated up to 35 V. So I think VBB maps to M+. And on my board, the largest capacitor is near the VMOT pin, so I think this is the equivalent

The BigEasyDriver also has a pin labelled VCC:
> VCC : This is an OUTPUT pin that will provide either 5V (default) or 3.3V from the voltage regulator, at a small amount of current (say 50mA - depends on input voltage) to power a circuit that you may need powered.

On the datasheet, I think this maps to the pin VDD, “Logic Supply Voltage“ (rated at –0.3 to 5.5 V). And I think this should maps to VDD on my board.

The result:

### (Left side of the chip – when viewed from the bottom – reading top to bottom)

| DIRECTION | This needs to be a 0V to 5V (or 0V to 3.3V if you’ve set your Big Easy Driver up that way) digital signal. The level if this signal (high/low) is sampled on each rising edge of STEP to determine which direction to take the step (or microstep). |
|   STEP    |                               This needs to be a 0V to 5V (or 0V to 3.3V if you’ve set your Big Easy Driver that way) digital signal. Each rising edge of this signal will cause one step (or microstep) to be taken.                               |
|   SLEEP   |                                                       This normally high input signal will minimize power consumption by disabling internal circuitry and the output drivers when pulled low.                                                       |
|   RESET   |                                                                 This normally high input signal will reset the internal translator and disable all output drivers when pulled low.                                                                  |
|    MS3    |                                                                                                These digital inputs control the microstepping mode.                                                                                                 |
|    MS2    |                                                                                                These digital inputs control the microstepping mode.                                                                                                 |
|    MS1    |                                                                                                These digital inputs control the microstepping mode.                                                                                                 |
|  ENABLE   |                                                                                      This normally low input signal will disable all outputs when pulled high.                                                                                      |




### (Right side of the chip – when viewed from the bottom – reading top to bottom)

|   GND    | There are three GND (Ground) pins on the Big Easy Driver. They are all connected together inside the board. Connect the negative side of your power supply; as well as from any other boards you are using to drive the Easy Driver to one or more of the GND pins. |                                                                                                |
| **VDD**  |                          This is an OUTPUT pin that will provide either 5V (default) or 3.3V from the voltage regulator; at a small amount of current (say 50mA - depends on input voltage) to power a circuit that you may need powered.                           |                                                                                                |
|    1B    |                                                                        These are the motor connections. See below diagrams for how to hook these up. A and B are the two coils of the motor                                                                         | and can swap the two wires for a given coil (it will just reverse the direction of the motor). |
|    1A    |                                                                                                                             (as above)                                                                                                                              |                                                                                                |
|    2A    |                                                                                                                             (as above)                                                                                                                              |                                                                                                |
|    2B    |                                                                                                                             (as above)                                                                                                                              |                                                                                                |
|   GND    |                                                                                                                           (as GND above)                                                                                                                            |                                                                                                |
| **VMOT** |                                                                     M+ : This is the power input to the Easy Driver. Connect this to the positive power supply lead. This should be a 6V to 30V                                                                     |                     3A (or more) power supply that is clean (low ripple).                      |


Connections


Safety

Adjusting current draw



Simple programs


Arduino libraries
