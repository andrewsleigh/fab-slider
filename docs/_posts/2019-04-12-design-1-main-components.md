---
permalink: design-1-main-components/
title: Design 1 – Main Components
date: 2019-04-12
author: Andrew
layout: page
---

## Sketch

## Main Components

### Rails

I want to use standardised aluminium extrusion for the rails. These provide the main structure of the slider, and are also the guide surface along which the gantry slides. This is a good guide: [Beginner’s Guide to Building Things With V-Slot Aluminum Extrusion](https://www.makeuseof.com/tag/beginners-guide-building-things-v-slot-aluminum-extrusion/)

#### Choosing a profile
There are different kinds of profile. I can't find a comprehensive list anywhere, but there do seem to be some common types, and others may only differ from these in non-essential ways.

The two main profiles seems to be B-Type and I-Type (__Bosch Rexroth__ and __Item__ respectively). The B-type profile has a stepped slot, whereas the I-type has a smooth curve.

RS Components sell [RS-Pro branded extrusion](https://uk.rs-online.com/web/p/tubing-struts/8508476/). This has a 5 mm groove, and a 4.3 mm central hole. According to [this chart](https://www.boltdepot.com/fastener-information/metric-tap-drill-size.aspx) that can be tapped for a 5 mm thread.

They also have Bosch Rexroth branded extrusion with a 6 mm groove and a 5.5 mm central hole. Using that same table, that's a little off for tapping to a 6 mm thread, so I wonder if this is an imperial sizing?

There is also a newcomer to the field: V-type. From the [Beginner’s Guide to Building Things With V-Slot Aluminum Extrusion](https://www.makeuseof.com/tag/beginners-guide-building-things-v-slot-aluminum-extrusion/):

> T-Slot has a T-shaped groove on each side.
> V-Slot is similar, but it has a slight bevelled edge.
While this may seem like only a minor difference, it has a big impact in their use. V-Slot allows bearings and wheels to sit inside the profile, meaning it can also double as linear rail, greatly reducing the cost of parts for motion control.

> The two are somewhat interchangeable, but it’s usually best to stick with one type per project. Basic parts like brackets and T-Nuts work fine on either, however slightly more specialist parts — such as bearings or unusual joints — may only work on one or the other. Also, if you are mixing and matching parts, you may need to change or adapt your design, and have to purchase more lengths of one or the other extrusion.

> V-Slot was created by Mark Carew of OpenBuilds and is open source.


The V-type, as the name suggests, has a straight V-shaped bevel. I would say B-type or V-type would be best to take bearings depending on cost and availability (the latter is less of an issue if they can be easily swapped out for another type). V-slot accepts M5 bolts, so I think – at this stage – that V- and I-type profiles should be quite interchangeable.

#### Choosing size

I suspect two 2020 profile rails will be enough for this small span. 2040 mounted vertically would give me more rigidity. And the [8040 C Beam](https://ooznest.co.uk/product/c-beam-linear-rail-cut-to-size/) would be even more rigid:

![]({{site.baseurl}}/assets/C-Beam-Linear-Rail.jpg)

Ooznest has a [guide to help you estimate deflection](https://ooznest.co.uk/wp-content/uploads/2018/05/How-To-Estimate-Deflection.pdf).

In my case, the calculation looks like this:

![]({{site.baseurl}}/assets/deflection.png)

Let's plug in some numbers:

* Mass of the load: 1kg (roughly, for an SLR camera)
* F = Mass x Gravity = 1 * 9.81 = 9.81N
* L = 0.5m
* I (moment of inertia) = 6.988 * 10<sup>-9</sup> (for 2020 profile)
* E (modulus of elasticity) = 68.9 GPa (gigapascals) =  68.9 * 10<sup>9</sup> Pa

Therefore deflection  
= (9.81 * (0.5)<sup>3</sup>) / (48 * 68.9 * 10<sup>9</sup> * 6.988 * 10<sup>-9</sup>)  
= 1.22625 / 23110.7136  
= 0.000053 m  
= 0.053 mm  

So nothing to worry about at this length. However, if I made a 1 m long slider, deflection under ideal conditions for a 1 kg load would come out at: 9.81 / 23110.7136 = .00042 m = .42 mm. So for that span it might be worth using a more rigid profile.

**For now, I'll go with 2020**



#### Choosing length

While a bigger slider is always more useful, a smaller one is cheaper, and easier to store, so I think a better target for a first build. If I decide to remake it, I can always disassemble the first version and re-use some parts for a bigger one.

**So – all other things being equal – I'll go for a 50 cm length.**

#### Prices

[2 x 50 cm 2020 V-Slot from Ooznest]: £9.60 + postage

[2 x 50 cm 2020 IR Range Aluminium Profile (I-type) from KJN]: £7 + postage

[50 cm 8040 C-Beam from Ooznest](https://ooznest.co.uk/product/c-beam-linear-rail-cut-to-size/): £14.80 + postage (both ends tapped with 5mm holes: £16.24. I should be able to tap these myself if needed)

[1 m I-type from RS Components](https://uk.rs-online.com/web/p/tubing-struts/8508476/): £6.90 + postage


### Motor

This project requires a stepper motor. For background on motors, see:
* [Motors | code, circuits, & construction](http://www.tigoe.com/pcomp/code/circuits/motors/)

On steppers specifically:
* [Stepper Motor Quickstart Guide - SparkFun Electronics](https://www.sparkfun.com/tutorials/400)
* [What is a Stepper Motor? -  Adafruit Learning System](https://learn.adafruit.com/all-about-stepper-motors)

Figuring out which size of motor is complicated, so instead, I went for the soft option, and asked some people who have worked with them, and looked at what other projects use. The consensus was to go for the NEMA 17. You might think NEMA is a brand name for a motor, but no, NEMA stands for [National Electrical Manufacturers Association](http://en.wikipedia.org/wiki/National_Electrical_Manufacturers_Association). The 17 refers to the size of the faceplate - 1.7" x 1.7".

According to <https://reprap.org/wiki/NEMA_Motor>
> Some (all?) NEMA 17 motors (is this specified in the standard?) have blind mounting holes 4.5 mm deep, tapped to accept M3x.50 metric bolts. The 4 mounting holes are in a square 31.0 mm (1.220 inch, about 7/32) center-to-center. The holes in the part that needs to be bolted to the NEMA 17 motor typically need to be reamed out with a 1/8" drill bit to allow the M3 bolt to pass through. The drive shaft is typically 5 mm dia.

According to <https://learn.adafruit.com/all-about-stepper-motors/types-of-steppers>:
>The NEMA numbers define standard faceplate dimensions for mounting the motor. They do not define the other characteristics of a motor. Two different NEMA 17 motors may have entirely different electrical or mechanical specifications and are not necessarily interchangeable.

Specs typically seem to vary on a number of common parameters:
*  Number of steps per full rotation: 200 (1.8&deg; steps) or 400 (0.9&deg; steps). For timelapse, I would assume a finer step gradation would be better.
* Current draw (i.e. power). These vary from about 0.3A to 2A. Some motor current are listed as 'per phase' so I don't know how comparable these are.
* Unipolar or bipolar – from [the Adafruit guide](https://learn.adafruit.com/all-about-stepper-motors/types-of-steppers):
  * Unipolar drivers, always energize the phases in the same way. One lead, the "common" lead, will always be negative. The other lead will always be positive. Unipolar drivers can be implemented with simple transistor circuitry. The disadvantage is that there is less available torque because only half of the coils can be energized at a time.")
  * Bipolar drivers use H-bridge circuitry to actually reverse the current flow through the phases. By energizing the phases with alternating the polarity, all the coils can be put to work turning the motor.
* 2-phase or 4-phase – from [the Adafruit guide](https://learn.adafruit.com/all-about-stepper-motors/types-of-steppers):
  * A two phase bipolar motor has 2 groups of coils. A 4 phase unipolar motor has 4. A 2-phase bipolar motor will have 4 wires - 2 for each phase. Some motors come with flexible wiring that allows you to run the motor as either bipolar or unipolar.

Lets look at some actual motors for sale:

[**Ooznest**](https://ooznest.co.uk/product/nema17-stepper-motors/)
* Bipolar
* 2-phase
* 1.33A – 2A per phase
* 200 or 400 steps per rotation

Their cheapest motor is a 200 step 1.4A model for £9.90 (NEMA17 Stepper Motors - 1.8° - 1701HS140A - 21oz - 1.40A)

[**Cool Components**](https://coolcomponents.co.uk/products/stepper-motor-with-cable)

This is a Sparkfun model, for about £15:

* Step Angle (degrees) :1.8
* 2 Phase
* Rated Voltage : 12V
* Rated Current : 0.33A
* Holding Torque : 2.3kg*cm

[**Adafruit**](https://www.adafruit.com/product/324) seem to have something quite similar. ($14, 350 mA, 4-wire bipolar, 1.8° steps (200/revolution))


### Motor driver


### Microcontroller


### Gantry

Different sized bolts for camera mounts


### Wheels/bearings



### Belt


### Pulleys


### End caps / feet


### Fixings
