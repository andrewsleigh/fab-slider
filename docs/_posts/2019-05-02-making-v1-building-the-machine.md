---
permalink: making-v1-building-the-machine/
title: Making version 1 – Building the machine
date: 2019-05-02
author: Andrew
layout: page
sort_id: 42
---

I had a few days access to the fablab, so I tried to make as much of the physical hardware as I could so I could work on the motion control software later. One of [my original aims for the project](../getting-started-why/) was to try and learn more about 3D printing, and I was very successful in this aspect. I [modelled the whole assembly in Fusion 360](https://github.com/andrewsleigh/fab-slider/tree/master/3d-parts/v1/assembly) and 3D-printed several iterations of key parts on our Creality CR-10 printer. I had a lot of fun with it.

![]({{site.baseurl}}/assets/fab-slider-v1-whole-assembly.png)





## Tapping holes in the V-slot

The V-slot extrusion has holes in each end, which can be tapped to an M5 thread. Some suppliers (like Ooznest) will do this for you, or you can do it yourself. I thought I would ask them to tap some of the holes and do the rest myself, since I'd like this to be as DIY as possible. 

However, despite having had some experience of tapping before, and watching some [good videos](https://www.youtube.com/watch?v=r6Ijd9o-C10) I had limited success. I shattered one tap, leaving it stuck n the hole, and after a little more practice, on my three remaining holes, only did a good job on 2 of them.  

![]({{site.baseurl}}/assets/IMG_1703.jpg)

So I ended up using the pre-tapped holes on the business end of the slider, where the motor is mounted, and on the other end, using a combination of some of my tapped holes, and right-angle v-slot brackets to mount the end-cap.

For a future version, I would like to design a mounting system that doesn't rely on tapped holes at all, as there is too much room for error.

## Gantry



# End-stop posts on the gantry

I only need one!




### Wheels

I bought [some relatively cheep wheels](https://www.amazon.co.uk/BIQU-Printer-Plastic-Bearings-Passive/dp/B06X9Q9Y8V/ref=sr_1_5?keywords=v+slot+wheels&qid=1556802322&s=gateway&sr=8-5), which are OK, though don't turn as easily as I expected. However, this is my first experience woking with bearings, so I don't know what I should expect. 

### Adjustment

I mounted one pair of wheels through circular holes in the gantry, and the other set through elongated slots, perpendicular to the rails, to allow the wheel spacing to be adjusted slightly. 

This worked OK in the 3D printed gantry (less so in the laser-cut acrylic version, where there is less friction between the nut and the gantry). It also made it possible to mount and demount the gantry even when the end-caps are fitted, and it can't be slid off an end.

### Washers

Initially, I used washers on the wheel assembly – it's just a convention that I've got used to, to add washers to enable free rotation of parts against a tightened nut. But of course, in this assembly, the bearing itself is designed to be held firm in the assembly at the centre, but to rotate freely on the outside. And I found the washers were interfering with this, so I removed them.



## Motor backet

<script src="https://embed.github.com/view/3d/andrewsleigh/fab-slider/blob/master/3d-parts/v1/motor-bracket/motor-bracket.stl"></script>


This was a simple part to design. It just needs to hold the motor at 90&deg; against the end of the slider rails.

![]({{site.baseurl}}/assets/motor-bracket-assembly-diagram.png)

However, my current design is attached to the rails by bolting through the end-cap into the threaded holes in the extrusion. That's a solid design, but perhaps les easy for others to replicate. So for a future design, it would be good to think about an alternative approach that doesn't relay on these threaded holes.



## End-stops



# End-stop wiring



### Cable clips

I'm running wires from the far end of the slider down towards the  microcontroller board, so I wanted some way of keeping the cables tidy and out of the way. 

Fortunately, Thingiverse has plenty of solutions for this problem, so I printed a few V-slot cable clips that do the job nicely. I used these <a href="www.thingiverse.com/thing:2676595">V-Slot Cable Clips</a>.


