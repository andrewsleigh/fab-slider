---
permalink: design-v1-motor/
title: Designing version 1 – Power supply
date: 2019-04-12
author: Andrew
layout: page
sort_id: 35
---

From [Stepper Motor Quickstart Guide - SparkFun Electronics](https://www.sparkfun.com/tutorials/400):
>  Stepper motors require more power than can be supplied by the Arduino. In this example we will be powering the Uno with a 12V external supply. Notice that the power input (M+) on the EasyDriver is attached to the Vin pin on the Arduino. This will allow you to power both the Arduino and the motor with the same power supply.

From https://learn.adafruit.com/motorized-camera-slider-mk3?view=all#12v-power-14-1
> 12V Power
> To properly power the stepper motor, you need at least 12V. A USB battery pack typically is only 5V and will not provide enough juice to push the weight of a camera (be it a lightweight GoPro or Mobile Phone). I highly suggest using either a 12V power wall adapter or 12V battery pack.
> Wall Adapter
> I mostly use the camera slider indoors. Having it plugged into the wall is nice because I don't have to worry about batteries getting low and dying. This  [12V DC 1000mA power adapter](https://www.adafruit.com/product/798)  works great with this project.

The Arduino Uno has a barrel jack power input, and can pass through 12V power to the driver board, so I think this is the best way to go. I have several old 12V wall-warts that can supply 1-2 A of current.

For portable power, an [8 x AA battery power pack](https://www.adafruit.com/product/875) is probably the best option.
