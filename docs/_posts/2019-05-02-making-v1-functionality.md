---
permalink: making-v1-functionality/
title: Making version 1 – Basic functionality
date: 2019-05-02
author: Andrew
layout: page
sort_id: 41
---


I've started to think about the functions needed for the slider to work well, and how these should be implemented in hardware and software.


## On startup

### Find ends

* Move to one end til you hit switch, then pull back a little. Set `endPoint1`
* Do the same for the other end - `endPoint2`

Hardware controls:

* Maybe nothing - just does this when you connect power
* Or perhaps a reset button to send it to its config state (which just disconnects/reconnects power…)
* Or maybe there should be a ‘setup’ button. So any motion is triggered deliberately.

### Set start and end positions - optional (could just use the two ends)

* User moves gantry to desired starting point - sets `startPoint`
* User moves gantry to desired end point - sets `endPoint`

Hardware controls:

* A button for each
* Plus LED/on-screen feedback?

### Set video or time-lapse mode

* Switch between high- or low-speed ranges
* Timelapse mode could be quite jerky really - maybe better for photos…

Hardware controls:

* Switch

### Set speed

* Vary speed continuously across a range, 

Hardware controls: 

* Potentiometer could work. Want to read this value once, then ignore input for the rest of the program
* Ideally with some feedback (even just markings on a dial)
* Rotary encoder could also work, but would need visual feedback, e.g. 7-segment display or OLED module


### Pause and reset buttons

Could be handled with a mode, set in the code. One button press turns it into pause mode, stopping movement, another button press cancels everything….

### Power off or reset power

To Arduino etc.


## While running

* Cancel/reset?
* Pause?
* Should speed control have an effect if used when it's running, or should this be isolated to avoid unintentional changes


## Other control options

Some other projects use Bluetooth or phone apps. This might introduce some complexity, but reduce the need for physical controls. 
