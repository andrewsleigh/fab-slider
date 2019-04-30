---
permalink: design-v1-rails/
title: Designing version 1 – Aluminium extrusion rails
date: 2019-04-12
author: Andrew
layout: page
sort_id: 31
---

The rails provide the main structure of the slider, and are also the guide surface along which the gantry slides.

I want to use standardised aluminium extrusion for the rails. This provides the best balance of reproducibility and quality. Aluminium extrusion is widely available, cost effective, standardised and high-quality. This is a good guide to aluminium extrusion: [Beginner’s Guide to Building Things With V-Slot Aluminum Extrusion](https://www.makeuseof.com/tag/beginners-guide-building-things-v-slot-aluminum-extrusion/).



## Choosing a profile
There are different kinds of profile. The two main profiles seems to be B-Type and I-Type (__Bosch Rexroth__ and __Item__ respectively). The B-type profile has a stepped slot, whereas the I-type has a smooth curve.

They also differ in other areas. For example RS Components' [I-type 'RS-Pro' extrusion](https://uk.rs-online.com/web/p/tubing-struts/8508476/) has a 5 mm groove, and a 4.3 mm central hole, which can be tapped for a 5 mm thread. They also have Bosch Rexroth extrusion with a 6 mm groove and a 5.5 mm central hole.

There is also a newcomer to the field: V Slot. As the name suggests, this has a straight V-shaped bevel. This is an open source design, and ideal to take wheels, as it provides a flat even surface for them to roll against. It also has holes that can be tapped for M5 bolts.


## Choosing size

I suspect two 2020 profile rails will be enough for this small span. 2040 mounted vertically would give me more rigidity. And the [8040 C Beam](https://ooznest.co.uk/product/c-beam-linear-rail-cut-to-size/) would be even more rigid:

![]({{site.baseurl}}/assets/C-Beam-Linear-Rail.jpg)

Ooznest has a [guide to help you estimate deflection](https://ooznest.co.uk/wp-content/uploads/2018/05/How-To-Estimate-Deflection.pdf). In my case, the calculation looks like this:

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

However, there is one other advantage to a larger profile such as 2040. That has two holes at each end, allowing for more robust assembly. I'm concerned that the 2020, with only one hole at each end might twist in the assembly, causing the gantry to move poorly.



## Choosing length

While a bigger slider is always more useful, a smaller one is cheaper, and easier to store, so I think a better target for a first build. If I decide to remake it, I can always disassemble the first version and re-use some parts for a bigger one.

## Prices

[2 x 50 cm 2020 V-Slot from Ooznest](https://ooznest.co.uk/product-category/parts/mechanical-parts/v-slot-extrusions/): £9.60 + postage

[2 x 50 cm 2020 IR Range Aluminium Profile (I-type) from KJN](): £7 + postage

[50 cm 8040 C-Beam from Ooznest](https://ooznest.co.uk/product/c-beam-linear-rail-cut-to-size/): £14.80 + postage (both ends tapped with 5mm holes: £16.24. I should be able to tap these myself if needed). I like this, but it's not a standard profile,

[1 m I-type from RS Components](https://uk.rs-online.com/web/p/tubing-struts/8508476/): £6.90 + postage
