---
permalink: coding-better-debugging/
title: Coding version 1 – Better debugging with the serial monitor
date: 2019-05-12
author: Andrew
layout: page
sort_id: 52
---

Up until now, my approach to debugging has just been to litter my code with `Serial.println()` statements that print some input value to the serial monitor, scrolling on for eternity. They're quick to implement, and better than nothing, but I find them messy, easy to get wrong (and give misleading information), and for a project of any complexity, they quickly become confusing to interpret.

SO for this project I've tried to be more methodical, and I'm trying a few approaches out.

## Conditional debugging

Because I'm turning a motor, timing is important. I can't have an interruption every time some data has to be sent to the serial monitor. So I want debugging that i can easily switch off when I'm not using it. 

I found some useful resources on the Arduino forum that make use of  __preprocessors__ in C to do just this:

* <https://forum.arduino.cc/index.php?topic=215334.msg1576067#msg1576067>
* <https://forum.arduino.cc/index.php?topic=46900.0>

There's a nice explanation of these preprocessor keywords here: <https://community.arduboy.com/t/purpose-of-ifndef-and-define/3592/2>


> `#define` defines a word to mean something else.
> E.g. `#define FIVE 5` would result in all instances of FIVE being replaced with 5.
>
> `#if` tests if a condition is true.
> `#else` provides an alternative case for an `#if`, in case it is not true.
> `#endif` ends an `#if`

> `#ifdef` tests if a word is defined and `#ifndef` does the opposite - it tests if a word has not been defined.

So at the top of my file, I can include a line like: 

```
#define DEBUG
```

Then include commenting functionality in that only compiles if that line remains uncommented. e.g. 

```
#ifdef DEBUG
// set up string messages
#define DEBUG_PRINT(str)    \
   Serial.print(str); \
   Serial.print(" ------ ");      \ 
   Serial.print("In ");    \
   Serial.print(__PRETTY_FUNCTION__); \
   Serial.print(", line: ");      \
   Serial.println(__LINE__);     \   
#else
#define DEBUG_PRINT(str) // just leaves an empty definition without serial printing
#endif
```

And liberally sprinkle debug messages throughout my code which (a) can be turned off all at once, and (b) also include useful information about what line they're on, and which function they're inside:

```
// one-off debug message
DEBUG_PRINT("This is a one-off message just placed in to the code")
```

## Consolidating debug and status messages into one place

However, this still leaves debug messages all over my code, and I wanted to consolidate them into one place. 

So I wrote a simple function that neatly prints out all the information I want to know about the system at one time:

```
void printDebugMessages() {
#ifdef DEBUG  
  Serial.println("\n------");
  // machine state
  Serial.print("Current state:         ");
  Serial.println(stateLabels[currentState]);

  // latest error message
  if (errorMessage != "") {
    Serial.print("Message:               ");
    Serial.println(errorMessage);
  }

  // control settings
  Serial.print("Start from left?       ");
  Serial.println(startFromLeft);
  Serial.print("Use time-lapse mode?   ");
  Serial.println(isTimelapseSpeed);
  Serial.print("Speed:                 ");
  Serial.println(traverseSpeed);
#endif
}
```

And I can call that function either from a non-blocking timer that runs inside the main `loop()` and prints messages every couple of seconds:

```
#ifdef DEBUG_TIMER
  if (millis() > debugTimeNow + debugRefreshPeriod) {
    debugTimeNow = millis();
    printDebugMessages();
  }
#endif
```

Or at any other point, for example, every time there is a transition to a new state. 

```
#ifdef DEBUG_STATE_CHANGE
  printDebugMessages();
#endif
```

For these two variants to work (and to be able to switch them on and off independently, I created a couple more definitions:

```
// comment these out to remove debugging
#define DEBUG // needed for all debugging
//#define DEBUG_TIMER // for messages that print every few seconds
#define DEBUG_STATE_CHANGE // for messages that print only on a change in the machine state
```

Although the timer variant is non-blocking, it still takes some time for the Arduino to send all that string data to the serial monitor, which interrupts the movement of the motor, so I'm using the state change variant instead.

This solution works well for this project, but is not particularly portable. [Some people recommend creating a debug header file](https://forum.arduino.cc/index.php?topic=46900.msg338652#msg338652) that can be used in all projects. Obviously mine is quite specific to this project, but perhaps a future version could be made more portable.


