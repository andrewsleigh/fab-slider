---
permalink: design-v1-microcontroller/
title: Microcontroller
date: 2019-04-12
author: Andrew
layout: page
sort_id: 34
sort_tag: v1_design
---


### Microcontroller

Although I'm interested in making an integrated board that incorporates an AVR microcontroller and one or more stepper drivers, it's also a valid choice to design around a microcontroller that people already have.

For the Easy Driver-style boards, hookup varies depending on whether you want to control the microstep resolution with the Arduino (which requires 3 more pins).

The [simplest hookup](http://www.schmalzhaus.com/EasyDriver/Examples/EasyDriverExamples.html) just uses 2 pins to control step and direction, with power coming from a separate supply:

![]({{site.baseurl}}/assets/Example1_bb.png)

There is also an example given for multiple steppers, for which you need to use a library:

![]({{site.baseurl}}/assets/Example4_bb.png)

Again, this just uses 2 pins per motor. If I want to use two steppers, and also use all the control pins on the drivers, this may cause problems down the line...

The [Adafruit board](https://www.adafruit.com/product/1438) uses I2C, making it very easy to control multiple motors:
> Instead of using a latch and the Arduino's PWM pins, we have a fully-dedicated PWM driver chip onboard. This chip handles all the motor and speed controls over I2C. Only two data pins (SDA & SCL in addition to the power pins GND & 5V) are required to drive the multiple motors, and since it's I2C you can also connect any other I2C devices or shields to the same pins. This also makes it drop-in compatible with any Arduino, such as the Uno, Due, Leonardo and Mega R3.

Either way, for now, I should be able to get away with a standard Arduino Uno, and may be able to specify a smaller board like the Pro Mini, or maybe, for version 2, an ATtiny-based DIY board if I need only a few pins.
