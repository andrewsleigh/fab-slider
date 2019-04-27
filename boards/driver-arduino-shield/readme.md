# Readme

This is a simple shield to mount an A4988 stepper driver board onto an Arduino Uno giving easy access to the configuration pins, connections to the motor, and also separate breakouts to attach switches and analogue inputs for motion control

![Shield labels](a4988-driver-arduino-shield-v1-labels.png)

Features:
* Mounting headers for a standard 'Stepstick'-style A4988 stepper motor driver
* Routes DIRECTION to Arduino pin D3, and STEP to Arduino pin D2
* Through-board male-female headers to fit an Arduino Uno R3
* 4 pin header breaking out pins 1B, 1A, 2A, 2B (reading left-right) to wire up to motor
* 3 pin header breaking out VDD line, so MS1, MS2, and MS3 can be pulled high to use micro-stepping modes
* 6 pin header breaking out the main driver configuration pins: SLEEP, RESET, MS3, MS2, MS1, ENABLE (reading left-right)
* One header to accept up to 3 digital inputs from buttons or end-stops (to Arduino I/O pins D10, D9, D8, reading top-bottom)
* One header to accept up to three analogue inputs for example from potentiometers (to Arduino I/O pins A2, A1, A0, reading top-bottom)


## Using the digital inputs

These inputs connect one side of the switch to GND, the other to the input pin. So you should set the internal pull-up resistor to use them:

```
pinMode(10, INPUT_PULLUP);
pinMode(9, INPUT_PULLUP);
pinMode(8, INPUT_PULLUP);
```

## Unused header pins

The driver is mounted on the left-most 8 pins of the dual 10-pin headers in the centre of the board (DIRECTION pin top-left). Ignore the two pins at the right of each header.

Analogue and digital inputs are connected in 3 sets of 3 pins each. This might be a slightly odd arrangement for the digital inputs, which only need two signals, but I'm using these for my end-stop switches, which have three terminals, and I want maximum flexibility in how I connect them. This is likely to change in a future version.
