---

title: Getting Started: Problems to Solve
date: 2019-04-12
author: Andrew
layout: page
---

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

See for example, [this commercial model](https://www.amazon.co.uk/Motorized-centimeter-Time-lapse-Camecord-Photography/dp/B07D55FZFW?ref_=fsclp_pl_dp_8) (which seems like one of many Chinese clones): 

![]({{site.baseurl}}/assets/71-b6ihMN1L._SL1500_.jpg)

![]({{site.baseurl}}/assets/71AX-0GRitL._SL1500_.jpg)


The central rod is attached in a swivel mount to the camera gantry. The rod ends can be moved to any position on each end of the rail. By pulling one side of the gantry forward or back, it rotates the whole gantry. 

In the picture below (1) shows how the rod is adjusted, (7) shows how the rod interfaces with the gantry.

![]({{site.baseurl}}/assets/71I+bMzPbNL._SL1500_.jpg)


I imagine you could set the amount of rotation quite easily by hand, by moving the camera to each end of the rail, and adjusting it so that it remains locked on the subject. (Or otherwise, if you want what they call ‘panorama shooting’). 

This passive mechanical method would certainly save on complexity if I could make something similar work.

### Synchronising time-lapse shutter release with motion
 
From <https://www.amazon.co.uk/gp/customer-reviews/RDGLTSU4YIVCB/ref=cm_cr_dp_d_rvw_ttl?ie=UTF8&ASIN=B07BMLD4N4>

> Lots of good points, nice build quality, smooth, works pretty well - so mostly happy. But it has a flaw that is a little critical and its very surprising the manufacturers neither spotted it nor corrected it via firmware etc. On the timelapse setting, if you set a pause of, say, 2, seconds, it stops for 2 seconds, and then takes the picture at the point it starts moving again. This is a little insane. It needs to stop, take the picture at the *start* of the 2s gap, and then move. It must be still for the whole duration of the picture, obviously. This is such core functionality of the product its astonishing it doesn’t operate correctly. If the manufacturers could correct this via firmware or new controllers I would happily give this 5 stars.  


### Adjusting the gantry so it slides well on the rails

The [Ratrig V-Slider DIY Camera Slider kit](https://ooznest.co.uk/product/v-slider-diy-camera-slider/?attribute_pa_v-slider-length=35cm&attribute_pa_v-slider-leg-kit=no-leg-kit&attribute_pa_v-motion-lite=no-v-motion-lite&gclid=EAIaIQobChMI3Zi-9r6i4QIVCJztCh30qAxvEAQYASABEgLAe_D_BwE) solves this problem by mounting the gantry with eccentric spacers – shims with off-centre holes that can be rotated to position the hole (and therefore the wheel) differently. Too loose a fit and the gantry will be unstable, too tight and there may be too much friction. Either problem could result in jerky movement.

A common solution in furniture design is to mount fixings into slots. This might be a simpler method, needing fewer specialised parts, but is also less finely adjustable.

<!-- 

Parts

Timing belt and pulley
https://learn.adafruit.com/bluetooth-motorized-camera-slider/overview
> A GT2 timing pulley mounted to the stepper motor and a radial ball bearing allows a GT2 timing belt to pull the platform across the support slide rail.   

https://www.adafruit.com/product/1184
Timing Belt GT2 Profile - 2mm pitch - 6mm wide 1164mm long (582 teeth on a 2mm tooth pitch) 

![](Camera%20Slider%20page%201/gt2tooth.jpg)

#Camera Slider#
 -->
