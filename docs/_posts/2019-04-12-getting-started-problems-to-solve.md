---
permalink: getting-started-problems-to-solve/
title: Problems already I know I need to solve
date: 2019-04-12
author: Andrew
layout: page
sort_id: 20
sort_tag: v1_getting_started
---

I assume there will be all sorts of problems I need to solve in order to make this. At this stage, these are the ones I can think of.

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

WIP: This needs more research


### Tracking the subject
I was thinking this would need a second motor mounted on the camera gantry itself, but it looks like the commercial models use an adjustable rod mounted to the rails which is mechanically fixed to the granary and rotates it automatically across the traverse.

See for example, [this commercial model](https://www.amazon.co.uk/Motorized-centimeter-Time-lapse-Camecord-Photography/dp/B07D55FZFW?ref_=fsclp_pl_dp_8) (which seems like one of many Chinese clones):

![]({{site.baseurl}}/assets/71-b6ihMN1L._SL1500_.jpg)

![]({{site.baseurl}}/assets/71AX-0GRitL._SL1500_.jpg)


The central rod is attached in a swivel mount to the camera gantry. The rod ends can be moved to any position on each end of the rail. By pulling one side of the gantry forward or back, it rotates the whole gantry.

In the picture below (1) shows how the rod is adjusted, (7) shows how the rod interfaces with the gantry.

![]({{site.baseurl}}/assets/71I+bMzPbNL._SL1500_.jpg)


I imagine you could set the amount of rotation quite easily by hand, by moving the camera to each end of the rail, and adjusting it so that it remains locked on the subject. (Or otherwise, if you want what they call ‘panorama shooting’).

This passive mechanical method would certainly save on complexity if I could make something similar work.

WIP: I think for version 1 I might just put this whole problem aside and have a non-rotating gantry

### Synchronising time-lapse shutter release with motion

From this review on a commercial slider:  <https://www.amazon.co.uk/gp/customer-reviews/RDGLTSU4YIVCB/ref=cm_cr_dp_d_rvw_ttl?ie=UTF8&ASIN=B07BMLD4N4>

> On the timelapse setting, if you set a pause of, say, 2, seconds, it stops for 2 seconds, and then takes the picture at the point it starts moving again. This is a little insane. It needs to stop, take the picture at the *start* of the 2s gap, and then move. It must be still for the whole duration of the picture, obviously.

It sounds like this slider also lets you control the shutter release on the camera. Which could be a nice feature, but is more than I'm trying to do here. Nevertheless, it might be important to try and synchronise shutter release with points when the gantry is stationary – if indeed there are any with the kind of motion control I end up using.

<span class="wip">WIP</span> I'm going to leave this until I have something built.



### Adjusting the gantry so it slides well on the rails

The [Ratrig V-Slider DIY Camera Slider kit](https://ooznest.co.uk/product/v-slider-diy-camera-slider/?attribute_pa_v-slider-length=35cm&attribute_pa_v-slider-leg-kit=no-leg-kit&attribute_pa_v-motion-lite=no-v-motion-lite&gclid=EAIaIQobChMI3Zi-9r6i4QIVCJztCh30qAxvEAQYASABEgLAe_D_BwE) solves this problem by mounting the gantry with eccentric spacers – shims with off-centre holes that can be rotated to position the hole (and therefore the wheel) differently. Too loose a fit and the gantry will be unstable, too tight and there may be too much friction. Either problem could result in jerky movement.

A common solution in furniture design is to mount fixings into slots. This might be a simpler method, needing fewer specialised parts, but is also less finely adjustable.


### Providing user controls and feedback

<span class="wip">WIP</span>. I'll need some sort of controls, but I'm not quite sure what yet.


### Stopping the motor when the slider reaches the end of the rail.


<span class="wip">WIP</span>. I'll need some way of letting the system know when the gantry has got to the end of the rails, so it can be stopped safely.
