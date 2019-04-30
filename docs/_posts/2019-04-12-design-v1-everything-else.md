---
permalink: design-v1-everything-else/
title: Designing version 1 – Everything else
date: 2019-04-12
author: Andrew
layout: page
sort_id: 37
---

I will also need to design and make/buy a load of other things, which I haven't thought through fully yet.

## End caps / feet

A way to hold the rails together and also provide a stable base on (possibly uneven) surfaces


## Controls and screen

<span class="wip">WIP</span> I don't know what controls I'll need, or if I'll need to get any feedback.

## End stops

I have some end-stop switches left over from a previous project. These will need to be mounted onto the rails and connected to the microcontroller.

## Tripod mount

This is a 'nice-to-have' feature, but shouldn't be difficult to implement. I just need a plate on the bottom of the rails with a threaded hole (or captured nut) to accept a 1/4" (or possibly 3/8") UNC threaded bolt. These are the [standard sizes for tripod mounts](http://www.photokonnexion.com/photography-thread-size/):

| Diameter (inch) | Diameter (mm) | Thread size |
| :-------------: | :-----------: | :---------: |
|       1/4       |    6.3500     |     20      |
|       3/8       |    7.9375     |     16      |

## Assembly brackets and casings

### Motor

There are many [3D designs on Thingiverse](https://www.thingiverse.com/search?q=nema+17+bracket&dwh=1005cb30d3341f54).

The sketch at the top of the page shows the bare minimum I'd need to do to mount the motor to the rails in the right orientation. This needs more work, perhaps in Fusion 360.

### Belt bearing

Unless I use an idler pulley (which has fences on either side of the rail), this might need some sort of guides to stop the belt sliding off the bearing.

Ideally, (as on the Adafruit slider bearing bracket) the bolts in this bracket should fit into slots, so the bracket itself can be moved back and forth to adjust belt tension (just like the rear wheel on a single speed bike).

### Microcontroller and driver boards

I think for version 1, this could be an entirely separate assembly, since only an electrical connection is needed between the boards and the motor.


## Fixings

It would be nice if the design could standardise on one bolt size, say M5, with one head type. For example, if all bolts had Allen key heads of the same size, you could attach the correct key somewhere on the frame of the machine, for easy adjustment

I may also need T-nuts and brackets to connect other parts of the sytem to the rails.
