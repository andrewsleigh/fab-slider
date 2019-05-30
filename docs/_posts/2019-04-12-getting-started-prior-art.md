---
permalink: getting-started-prior-art/
title: Prior art
date: 2019-04-12
author: Andrew
layout: page
sort_id: 11
sort_tag: v1_getting_started
---


#### Commercial motorised sliders
There are many similar looking Chinese sliders on Amazon, at about £320-£360, for example:
[GVM Camera Slider Track](https://www.amazon.co.uk/GVM-Sliders-Motorized-Panoramic-Shooting/dp/B07BMLD4N4?ref_=fsclp_pl_dp_1):

![]({{site.baseurl}}/assets/71kQOGjJWyL._SL1500_.jpg)

These mount the motor on the gantry and use carbon fibre poles as the slide rails.
They have a nice mechanism to allow rotation of the gantry across the traverse without using a second motor.
They mount the motor to the gantry and move it along a timing belt stretched along the rails.

Ooznest sell the [Ratrig V-Slider DIY Camera Slider kit](https://ooznest.co.uk/product/v-slider-diy-camera-slider/?attribute_pa_v-slider-length=35cm&attribute_pa_v-slider-leg-kit=no-leg-kit&attribute_pa_v-motion-lite=no-v-motion-lite&gclid=EAIaIQobChMI3Zi-9r6i4QIVCJztCh30qAxvEAQYASABEgLAe_D_BwE) for about £260 with a motor:

![]({{site.baseurl}}/assets/V-Slider-Full-Kit.jpg)


V-Slot sell a simple [linear actuator](http://vslot-europe.com/home/123-v-slot-linear-actuator-bundle-belt-driven-1meter-150cm.html) based on one 2040 aluminium extrusion rail, and a Nema 17 motor for €120:
![]({{site.baseurl}}/assets/v-slot-linear-actuator-bundle-belt-driven-1meter-150cm.jpg)



This mounts the motor at one end of the rail and uses a loop of timing belt to move the gantry.

#### DIY sliders
There are several Fab Academy slider projects, e.g.:
* Barcelona 2018: [Week 15: Machine design - Group4 Machine Design @FabAcademy](http://barcelonamachines.fabcloud.io/group4/2018/05/14/week15-machine-design.html)  / [Week 15 - Machine Design - Part II](http://fab.academany.org/2018/labs/barcelona/students/oscar-gonzalezfernandez//2018/05/16/Week-15-Machine-Design-Part-II.html) (Using a DRV8825 stepper motor driver
* Aachen 2018: [Fab Lab Aachen @ Fab Academy](http://fab.academany.org/2018/labs/fablabaachen/groupProjects/machine.html)

And some on Instructables, such as: [Make an Arduino Controlled Motorized Camera Slider!: 13 Steps (with Pictures)](https://www.instructables.com/id/Make-a-Motorized-Camera-Slider/). This one adapts a non-motorised rail, using a Nema 17 stepper and ‘A4988 Compatible’ driver board.

There’s also [this one](https://howtomechatronics.com/tutorials/arduino/diy-motorized-camera-slider-pan-tilt-head-project/) that uses three Nema 17 steppers (and three A4988 driver boards) for sliding, panning and tilting. It’s based on a frame of copper plumbing pipes and MDF brackets.

![]({{site.baseurl}}/assets/DIY-Motorized-Camera-Slider-with-Pan-and-Tilt-Mechanism-Arduino-Based.jpg)

Adafruit have a [lovely slider](https://learn.adafruit.com/motorized-camera-slider-mk3) with nice 3D printed parts, and great assembly documentation. It mounts the motor at one end and attaches a loop of GT2 timing belt to the gantry. They use the [Adafruit Motor/Stepper/Servo Shield for Arduino v2 Kit](https://www.adafruit.com/product/1438) driver board

![]({{site.baseurl}}/assets/3d_printing_hero-2.jpg)

But it uses this definitely-not-standardised [sliding ball-bearing rail and platform](https://www.adafruit.com/product/1866) which will set you back $55 . That’s in addition to the two lengths of 2020 extrusion that are still needed for the main frame. Possibly money well-spent, but I’d rather stick to standard components.

![]({{site.baseurl}}/assets/1866-02.jpg)

This is a pretty good tutorial on the electronics side (and includes functionality to trigger the shutter release from the Arduino as well as handling the slider itself): [Motion Control With Arduino: Motorising a Camera Slider](https://computers.tutsplus.com/tutorials/motion-control-with-arduino-motorising-a-camera-slider--cms-21539)


Next: [Problems to be Solved &rarr;](../getting-started-2-problems-to-solve/)
