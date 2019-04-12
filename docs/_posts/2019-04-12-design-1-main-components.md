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
There are different kinds of profile. [Notably T-slot and V-slot](https://www.makeuseof.com/tag/beginners-guide-building-things-v-slot-aluminum-extrusion/):

> T-Slot has a T-shaped groove on each side.
> V-Slot is similar, but it has a slight bevelled edge.
While this may seem like only a minor difference, it has a big impact in their use. V-Slot allows bearings and wheels to sit inside the profile, meaning it can also double as linear rail, greatly reducing the cost of parts for motion control.

> The two are somewhat interchangeable, but it’s usually best to stick with one type per project. Basic parts like brackets and T-Nuts work fine on either, however slightly more specialist parts — such as bearings or unusual joints — may only work on one or the other. Also, if you are mixing and matching parts, you may need to change or adapt your design, and have to purchase more lengths of one or the other extrusion.

> V-Slot was created by Mark Carew of OpenBuilds and is open source.

But also [Bosch type and Item type](https://www.thingiverse.com/groups/hypercube-3d-printer/forums/general/topic:17170):

> From what I found out, there are various extrusion types that differ in their cross section. There are (Bosch) B-Type extrusions which use 6mm slots for 2020 extrusions and are widely used internationally. There are also (Item) I-Type extrusions which use 5mm slots for 2020 extrusions and which are widely used in Germany or maybe Europe.


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



#### Choosing length




#### Prices

[2 x 50 cm 2020 V-Slot from Ooznest]: £9.60 (or both ends tapped with 5mm holes: £14.80)

[50 cm 8040 C-Beam from Ooznest](https://ooznest.co.uk/product/c-beam-linear-rail-cut-to-size/): £14.80 (both ends tapped with 5mm holes: £16.24. I should be able to tap these myself if needed)

I don't yet know the best kind of profile to use. Some options (for a 50cm) traverse are:

20/20

20/40

### Gantry


### Wheels/bearings


### Motor and electronics


### Belt


### Pulleys


### End caps / feet


### Fixings
