---
permalink: design-v1-endstops/
title: Designing version 1 – Endstops
date: 2019-04-12
author: Andrew
layout: page
sort_id: 37
---

There needs to be some way to put power to the motor when the gantry reaches the end of its travel. It may also be useful to have a way of calibrating the slider so it knows where its endpoints are. This is what end-stops are for.

## Examples


Via <https://hackaday.com/2017/03/30/endstops-that-stay-out-of-the-way/>:

![]({{site.baseurl}}/assets/endstop-wide.png)

<https://www.thingiverse.com/thing:2204123>

> It is designed to be triggered by the third wheel of a three wheel carriage. When used in this way, the endstop does not waste any space on the linear motion, since the carriage plate edge can travel completely past it.  

Notice the alignment of the lever - it’s 90&deg; from the rail, pointing into the cavity. Aligned with the wheel. So the whole thing fits against the V-groove, and can be triggered by the wheel itself, which rides in the same groove.

For maximum travel, could I mount my stops in the end plates, in the same orientation?

Looks like a friction fit base on the two fingers of the clip being pressed together by the cable tie.


From <http://marlinfw.org/docs/hardware/endstops.html>:
I think this is a Makerbot design, which incorporates capacitor and resistor as a hardware filter against noise, but also mounts the switch on a board with decent mounting holes.

![]({{site.baseurl}}/assets/makerbot_endstop.png)

<https://www.thingiverse.com/thing:2230378>

A simple design, but this would need some very small (M2?) bolts to go through the switch casing.

![]({{site.baseurl}}/assets/620a53a6ff0c23ef09bb7889649231ca_preview_featured.jpg)

## Running cables back
I might need to print some little cable clips that find into underside of V-slot to trail wires back from far end end-stop back to electrical parts at the other end.

## Electrical issues

I also need to deal with interference, denouncing, and possibly the resistance of the motor - how quickly can it be stopped?

From <http://marlinfw.org/docs/hardware/endstops.html>

> Endstops and Electromagnetic Interference (EMI)  
> Electromagnetic Interference (EMI) or electric noise, is an effect which can ruin the clean signal needed to properly and precisely measure electronically, be it temperature, endstop hits or any other value.  
>   
> In today’s life an abundance of sources for Electric Noise exists: Mobile phones, microwaves, WIFI, power supplies etc. In a 3D printer itself, there are also some prominent and strong sources of such noise:  
> * Heated beds  
> * Hot ends  
> * Stepper motors  
> * PWM modulation  
> The Electromagnetic Interference created by these sources are picked up by other components, either because they are directly connected or via radiation. The useful signal needed by the other components will be disturbed or even altered so much that it is no longer useful.  

![]({{site.baseurl}}/assets/switch_noise.png)

> Endstop with capacitor  
> A more simple variant, that can easily be fitted to existing endstops is a 100nF capacitor, soldered over the two endstop connector pins (in parallel):  

![]({{site.baseurl}}/assets/switch_cap.png)



## What to do when you hit the switch?

### Stop the servo!

Maybe also stop drawing power – since even a stopped servo draws power.

### Pull back a bit…

From <https://www.instructables.com/id/End-Stop-Limit-Switch-Problems/>

> Another handy tip, if your using the  [omron lever style limit switches](http://3dtek.xyz/products/cnc-3d-printer-limit-switches) , set the pull off constants in grbl to about 5mm so that when your homing finishes it pulls back off the limits when done so that its not bending the levers so much, otherwise you constantly have to re bend them back out.  
