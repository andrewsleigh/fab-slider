---
permalink: getting-started-why/
title: Why am I doing this, and what am I trying to make?
date: 2019-04-12
author: Andrew
layout: page
sort_id: 10
sort_tag: v1_getting_started
---

## Introduction
A camera slider is a simple machine that smoothly moves a still or video camera along a track, sometimes rotating the camera so it remains targeted at the same spot. It allows you to create more interesting and revealing time lapses, but also more interesting footage of still objects that can be used as part of a larger video project. For these reasons they are useful tools for makers who want to document processes, or show off final projects in videos.

I would like to make one myself. Right now, there’s almost nothing I know about how to do it, so these notes serve as a document of what I’m learning.

### Why am I doing this?
* A slider is a good candidate for assembly with 3D-printed parts. I’ve done very little 3D printing, so this is a good excuse for me to learn more about it.
* Many makers photograph their projects poorly. There is a great deal of skill involved, but having the right kit helps too. Along with some good documentation on how to use it, a slider could be helpful here.
* More broadly, I can foresee a set of fab-able photography tools that together could be adopted more broadly by labs and other maker spaces that would solve more photography and video problems: lighting, backdrops, stands, sound recording, etc.
* One of the things that appeals to me about the fablab ethos is the culture of sharing and developing a common set of tools. A good camera slider could be a useful addition to the suite.
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
