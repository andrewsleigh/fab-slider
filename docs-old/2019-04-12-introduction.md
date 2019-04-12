---

permalink: 
title: Introduction
date: 2019-04-12
author: Andrew
layout: page

---


# Camera Slider page 1
## Format
Introduction: Prior art, objectives, success measures, bigger picture

Research questions
What are the key problems to overcome
What are my options for key components:
Motors
Drivers
Structural elements
Assembly elements

Plan:
Spiral development
Feature set for version 1, what will be delayed to v2

Method: what I did
Results

Discussion: 
what could be improved
What new problems have I discovered
How could it be cheaper, easier to make, more reliable, more flexible

- - - -

## Introduction
A camera slider is a simple machine that smoothly moves a still or video camera along a track, sometimes rotating the camera so it remains targeted at the same spot. It allows you to create more interesting and revealing time lapses, but also more interesting footage of still objects that can be used as part of a larger video project. For these reasons they are useful tools for makers who want to document processes, or show off final projects in videos.

I would like to make one myself. Right now, there’s almost nothing I know about how to do it, so these notes serve as a document of what I’m learning. 

### Why am I doing this?
* A slider is a good candidate for assembly with 3D-printed parts. I’ve done very little 3D printing, so this is a good excuse for me to learn more about it.
* Many makers photograph their projects poorly. There is a great deal of skill involved, but having the right kit helps too. Along with some good documentation on how to use it, a slider could be helpful here.
* More broadly, I can foresee a set of fab-able photography tools that together could be adopted more broadly by labs and other maker spaces that would solve more photography and video problems: lighting, backdrops, stands, sound recording, etc.
* One of the things that appeals to me about the fablab ethos is the culture of sharing and developing a common set of tools. [WIP: Examples]. A good camera slider could be a useful addition to the suite.
* There are many commercial sliders available, but they tend to be expensive (and of course, not made by you or me). There are many DIY versions, but they are often of indeterminate quality, or poorly documented. 
* Finally, just because I got it into my head.

### My aims for this slider

* Smooth, controllable motion
* Flexible in the kinds of cameras that can be supported (e.g. phone to full-frame SLR)
* Made using standardised, widely-available components and materials 
* Manufacturable in a standard fablab or typical makerspace
* Significantly cheaper to make that a decent quality commercial alternative
* Able to shoot both realtime video (eg. traversing 1m in 10 seconds) and timelapse photos (eg. traversing 1m in 1 or 10 hours)
* Quiet, so if used for video, there is no discernible machine noise recorded


### Feature list

There are many features I would like, but not all are achievable in version 1, so I’ve ordered these by importance, with a proposed cut-off line for features that could be pushed back to version 2.

#### Version 1 prototype / proof-of-concept
* Controlled by commercial Arduino board and motor driver boards 
* 50 cm traverse for compactness and affordability 
* On-machine controls
* Speed can be adjusted for realtime video or long-duration time-lapse


#### Version 2 improvements or additional features
* Rotating camera mount, so subject can be tracked throughout the traverse. (This may well be critical enough that it should go in version 1)
* Uses a DIY controller board, possibly with integrated microcontroller (so all control is handled by one integrated, fab-able board, along the lines of the Satshakit series: [GitHub - satstep/satstep6600: Open source & fabbable stepper driver based on TB6600.](https://github.com/satstep/satstep6600))
* 1 m traverse (or a design that allows for different lengths to be used or even swapped out)
* Controlled wirelessly using phone or computer
* Adjustable feet to compensate for uneven surfaces and dampen vibration
* Power from portable supply




### Prior art

#### Commercial motorised sliders
There are many similar looking Chinese sliders on Amazon, at about £320-£360, for example: 
[GVM Camera Slider Track Dolly SlidersRail System with Motorized Time Lapse and Video Shot Follow Focus Shot and 120 Degree Panoramic Shooting 31”80cm](https://www.amazon.co.uk/GVM-Sliders-Motorized-Panoramic-Shooting/dp/B07BMLD4N4?ref_=fsclp_pl_dp_1):

![](Camera%20Slider%20page%201/71kQOGjJWyL._SL1500_.jpg)

These mount the motor on the gantry and use carbon fibre poles as the slide rails.
They have a nice mechanism to allow rotation of the gantry across the traverse without using a second motor.
They mount the motor to the gantry and move it along a timing belt stretched along the rails.

Ooznest sell the [Ratrig V-Slider DIY Camera Slider kit](https://ooznest.co.uk/product/v-slider-diy-camera-slider/?attribute_pa_v-slider-length=35cm&attribute_pa_v-slider-leg-kit=no-leg-kit&attribute_pa_v-motion-lite=no-v-motion-lite&gclid=EAIaIQobChMI3Zi-9r6i4QIVCJztCh30qAxvEAQYASABEgLAe_D_BwE) for about £260 with a motor: 
![](Camera%20Slider%20page%201/V-Slider-Full-Kit.jpg)

V-Slot sell a simple [linear actuator](http://vslot-europe.com/home/123-v-slot-linear-actuator-bundle-belt-driven-1meter-150cm.html) based on one 2040 aluminium extrusion rail, and a Nema 17 motor for €120:
![](Camera%20Slider%20page%201/v-slot-linear-actuator-bundle-belt-driven-1meter-150cm.jpg)
 
This mounts the motor at one end of the rail and uses a loop of timing belt to move the gantry.

#### DIY sliders
There are several Fab Academy slider projects, e.g.:
Barcelona 2018: [Week 15: Machine design | Group4 Machine Design @FabAcademy](http://barcelonamachines.fabcloud.io/group4/2018/05/14/week15-machine-design.html)  / [Week 15 - Machine Design - Part II](http://fab.academany.org/2018/labs/barcelona/students/oscar-gonzalezfernandez//2018/05/16/Week-15-Machine-Design-Part-II.html) (Using a DRV8825 stepper motor driver
Aachen 2018: [Fab Lab Aachen @ Fab Academy](http://fab.academany.org/2018/labs/fablabaachen/groupProjects/machine.html)

And some on Instructables, such as: [Make an Arduino Controlled Motorized Camera Slider!: 13 Steps (with Pictures)](https://www.instructables.com/id/Make-a-Motorized-Camera-Slider/). This one adapts a non-motorised rail, using a Nema 17 stepper and ‘A4988 Compatible’ driver board.

There’s also [this one](https://howtomechatronics.com/tutorials/arduino/diy-motorized-camera-slider-pan-tilt-head-project/) that uses three Nema 17 steppers (and three A4988 driver boards) for sliding, panning and tilting. It’s based on a frame of copper plumbing pipes and MDF brackets.

![](Camera%20Slider%20page%201/DIY-Motorized-Camera-Slider-with-Pan-and-Tilt-Mechanism-Arduino-Based.jpg)

Adafruit have a [lovely slider](https://learn.adafruit.com/motorized-camera-slider-mk3) with nice 3D printed parts, and great assembly documentation. It mounts the motor at one end and attaches a loop of GT2 timing belt to the gantry. They use the [Adafruit Motor/Stepper/Servo Shield for Arduino v2 Kit](https://www.adafruit.com/product/1438) driver board 


![](Camera%20Slider%20page%201/3d_printing_hero-2.jpg)

But it uses this definitely-not-standardised [sliding ball-bearing rail and platform](https://www.adafruit.com/product/1866) which will set you back $55 . That’s in addition to the two lengths of 2020 extrusion that are still needed for the main frame. Possibly money well-spent, but I’d rather stick to standard components.

![](Camera%20Slider%20page%201/1866-02.jpg)




## Problems to be solved

### Handling different speeds
Will the same motor be able to handle both kinds of usage?

The [Ratrig V-Slider DIY Camera Slider kit](https://ooznest.co.uk/product/v-slider-diy-camera-slider/?attribute_pa_v-slider-length=35cm&attribute_pa_v-slider-leg-kit=no-leg-kit&attribute_pa_v-motion-lite=no-v-motion-lite&gclid=EAIaIQobChMI3Zi-9r6i4QIVCJztCh30qAxvEAQYASABEgLAe_D_BwE) comes with 3 options for motors:


> THE V-MOTION LITE IS AVAILABLE WITH THREE DIFFERENT MOTOR OPTIONS:  
> Timelapse motor – motion is almost unnoticeable in real time  
> Top speed: 1 meter in 18 minutes (1 RPM)  
> Lowest speed: 1 meter in 3 hours  
> Max. Power consumption: 0.09A  
>   
> Standard motor – adequate for timelapses in its slowest setting, adequate for real time action in its fastest   
> Top speed: 1 meter in 38 seconds (28 RPM)  
> Lowest speed: 1 meter in 9 minutes  
> Max. Power consumption: 0.15A  
>   
> Fast motor – great range of speeds for real time action.   
> Top speed: 1 meter in 18 seconds (57 RPM)  
> Lowest speed: 1 meter in 3 minutes  
> Max. Power consumption: 0.29A  


### Tracking the subject
I was thinking this would need a second motor mounted on the camera gantry itself, but it looks like the commercial models use an adjustable rod mounted to the rails which is mechanically fixed to the granary and rotates it automatically across the traverse. 

See for example, this commercial model (which seems like one of many Chinese clones): https://www.amazon.co.uk/Motorized-centimeter-Time-lapse-Camecord-Photography/dp/B07D55FZFW?ref_=fsclp_pl_dp_8
![](Camera%20Slider%20page%201/71-b6ihMN1L._SL1500_.jpg)
![](Camera%20Slider%20page%201/71AX-0GRitL._SL1500_.jpg)

The central rod is attached in a swivel mount to the camera gantry. The rod ends can be moved to any position on each end of the rail. By pulling one side of the gantry forward or back, it rotates the whole gantry. 

In the picture below (1) shows how the rod is adjusted, (7) shows how the rod interfaces with the gantry.

![](Camera%20Slider%20page%201/71I+bMzPbNL._SL1500_.jpg)

I imagine you could set the amount of rotation quite easily by hand, by moving the camera to each end of the rail, and adjusting it so that it remains locked on the subject. (Or otherwise, if you want what they call ‘panorama shooting’). 

This passive mechanical method would certainly save on complexity if I could make something similar work.

### Synchronising time-lapse shutter release with motion
 
https://www.amazon.co.uk/gp/customer-reviews/RDGLTSU4YIVCB/ref=cm_cr_dp_d_rvw_ttl?ie=UTF8&ASIN=B07BMLD4N4

> Lots of good points, nice build quality, smooth, works pretty well - so mostly happy. But it has a flaw that is a little critical and its very surprising the manufacturers neither spotted it nor corrected it via firmware etc. On the timelapse setting, if you set a pause of, say, 2, seconds, it stops for 2 seconds, and then takes the picture at the point it starts moving again. This is a little insane. It needs to stop, take the picture at the *start* of the 2s gap, and then move. It must be still for the whole duration of the picture, obviously. This is such core functionality of the product its astonishing it doesn’t operate correctly. If the manufacturers could correct this via firmware or new controllers I would happily give this 5 stars.  


### Adjusting the gantry so it slides well on the rails

The [Ratrig V-Slider DIY Camera Slider kit](https://ooznest.co.uk/product/v-slider-diy-camera-slider/?attribute_pa_v-slider-length=35cm&attribute_pa_v-slider-leg-kit=no-leg-kit&attribute_pa_v-motion-lite=no-v-motion-lite&gclid=EAIaIQobChMI3Zi-9r6i4QIVCJztCh30qAxvEAQYASABEgLAe_D_BwE) solves this problem by mounting the gantry with eccentric spacers – shims with off-centre holes that can be rotated to position the hole (and therefore the wheel) differently. Too loose a fit and the gantry will be unstable, too tight and there may be too much friction. Either problem could result in jerky movement.

A common solution in furniture design is to mount fixings into slots. This might be a simpler method, needing fewer specialised parts, but is also less finely adjustable.


Parts

Timing belt and pulley
https://learn.adafruit.com/bluetooth-motorized-camera-slider/overview
> A GT2 timing pulley mounted to the stepper motor and a radial ball bearing allows a GT2 timing belt to pull the platform across the support slide rail.   

https://www.adafruit.com/product/1184
Timing Belt GT2 Profile - 2mm pitch - 6mm wide 1164mm long (582 teeth on a 2mm tooth pitch) 

![](Camera%20Slider%20page%201/gt2tooth.jpg)

#Camera Slider#
