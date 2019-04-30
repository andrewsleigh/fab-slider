---
permalink: design-v1-motor/
title: Designing version 1 – Stepper motor
date: 2019-04-12
author: Andrew
layout: page
sort_id: 32
---

This project requires a stepper motor. For background on motors, see:
* [Motors – code, circuits, & construction](http://www.tigoe.com/pcomp/code/circuits/motors/)

On steppers specifically:
* [Stepper Motor Quickstart Guide - SparkFun Electronics](https://www.sparkfun.com/tutorials/400)
* [What is a Stepper Motor? -  Adafruit Learning System](https://learn.adafruit.com/all-about-stepper-motors)

Figuring out which size of motor is complicated, so instead, I went for the soft option, and asked some people who have worked with them, and looked at what other projects use. The consensus was to go for the NEMA 17. You might think NEMA is a brand name for a motor, but no, NEMA stands for [National Electrical Manufacturers Association](http://en.wikipedia.org/wiki/National_Electrical_Manufacturers_Association). The 17 refers to the size of the faceplate - 1.7" x 1.7".

According to <https://reprap.org/wiki/NEMA_Motor>
> Some (all?) NEMA 17 motors (is this specified in the standard?) have blind mounting holes 4.5 mm deep, tapped to accept M3x.50 metric bolts. The 4 mounting holes are in a square 31.0 mm (1.220 inch, about 7/32) center-to-center. The holes in the part that needs to be bolted to the NEMA 17 motor typically need to be reamed out with a 1/8" drill bit to allow the M3 bolt to pass through. The drive shaft is typically 5 mm dia.

According to <https://learn.adafruit.com/all-about-stepper-motors/types-of-steppers>:
>The NEMA numbers define standard faceplate dimensions for mounting the motor. They do not define the other characteristics of a motor. Two different NEMA 17 motors may have entirely different electrical or mechanical specifications and are not necessarily interchangeable.

Specs typically vary on a number of common parameters:
*  Number of steps per full rotation: 200 (1.8&deg; steps) or 400 (0.9&deg; steps). For time-lapse, I would assume a finer step gradation would be better. (However, most motors can also be used in a 'micro-step' mode, which breaks down these steps into 1/4, 1/8 or 1/16 micro-steps)
* Current draw (i.e. power). These vary from about 0.3A to 2A. Some motor current draws are listed as 'per phase' so I don't know how comparable these are.
* Unipolar or bipolar – from [the Adafruit guide](https://learn.adafruit.com/all-about-stepper-motors/types-of-steppers):
  * Unipolar drivers, always energize the phases in the same way. One lead, the "common" lead, will always be negative. The other lead will always be positive. Unipolar drivers can be implemented with simple transistor circuitry. The disadvantage is that there is less available torque because only half of the coils can be energized at a time.")
  * Bipolar drivers use H-bridge circuitry to actually reverse the current flow through the phases. By energizing the phases with alternating the polarity, all the coils can be put to work turning the motor.
* 2-phase or 4-phase – from [the Adafruit guide](https://learn.adafruit.com/all-about-stepper-motors/types-of-steppers):
  * A two phase bipolar motor has 2 groups of coils. A 4 phase unipolar motor has 4. A 2-phase bipolar motor will have 4 wires - 2 for each phase. Some motors come with flexible wiring that allows you to run the motor as either bipolar or unipolar.

<!-- One question for me is: what is the speed range of each motor? I'm looking for wide range of traverse speeds, from say 50 cm in 50 minutes, to 50 cm in 5 seconds. Let's see what kinds of RP ranges that would cover

Don't think this is an issue, as for slow speeds, I can just move one step at a time, with delays between -->




Lets look at some actual motors for sale:

[**Ooznest**](https://ooznest.co.uk/product/nema17-stepper-motors/)
* Bipolar
* 2-phase
* 1.33 A – 2 A per phase (but note this motor is rated at 2.8 V, so the current draw at 12 V would be different)
* 200 or 400 steps per rotation

Their cheapest motor is a 200 step 1.4 A model for £9.90 (NEMA17 Stepper Motors - 1.8° - 1701HS140A - 21oz - 1.40A)

[**Cool Components**](https://coolcomponents.co.uk/products/stepper-motor-with-cable)

This is a Sparkfun model, for about £15:

* Step Angle (degrees) :1.8
* 2 Phase
* Rated Voltage : 12 V
* Rated Current : 0.33 A
* Holding Torque : 2.3 kg*cm

[**Adafruit**](https://www.adafruit.com/product/324) seem to have something quite similar. ($14, 350 mA, 4-wire bipolar, 1.8° steps (200/revolution))

[Digikey also has some pretty similar models](https://www.digikey.co.uk/products/en/motors-solenoids-driver-boards-modules/stepper-motors/179?k=&pkeyword=&sv=0&pv14=126&sf=0&FV=ffe000b3&quantity=&ColumnSort=0&page=1&pageSize=25)

As I was buying other parts from Ooznest, I went with their 77 oz model (1.68 A/phase) for £12.65
