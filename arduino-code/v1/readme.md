# Readme

This is a lightly documented version of the code for the first version of my camera slider. This is much simplified from the old complex state machine. 

Here is a diagram of the simpler state machine I'm building in this code:

![](slider-state-machine-v4.png)


## Libraries

I'm using these Arduino libraries to handle motor control, non-blocking timers, and button debouncing respectively:
```
#include <AccelStepper.h>
#include <neotimer.h>
#include <Bounce2.h>
```


## User configuration

The variables that you might want to change are listed at the top of the file so speeds can be tweaked


```
int videoMinSpeed = 500;
int videoMaxSpeed = 5000;
int timelapseMinSpeed = 50;
int timelapseMaxSpeed = 250;
int endStopPadding = 100; 
```


## Debugging setup

As documented in [Better debugging with the serial monitor](https://andrewsleigh.com/fab-slider/coding-better-debugging/) (or [GitHub link](https://github.com/andrewsleigh/fab-slider/blob/master/docs/_posts/2019-05-12-coding-better-debugging.md)), this section sets up the definitions that allow you to switch serial debugging on and off. You'd want to turn it off in use because sending all that data to the serial monitor interrupts the motion of the stepper.
```
String errorMessage = ""; // this string needs to be initialised even if we're not running debugging

// comment these out to remove debugging
#define DEBUG // needed for all debugging
// #define DEBUG_TIMER // for messages that print every few seconds
// #define DEBUG_STATE_CHANGE // for messages that print only on a change in the machine state

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

## Creating objects and variables

After that we just setup all the objects and variables we'll use later:

```
// Accelstepper object
AccelStepper stepper(AccelStepper::DRIVER, 2, 3); // format: interface, step pin, direction pin (for shield: step:D2 and dir:D3)
// Instantiate a Bounce object for the start button
Bounce debouncer = Bounce(); 


// define input/button pin numbers
const int startButtonPin = 10;
const int leftEndStopPin = 9;
const int rightEndStopPin = 8;
const int startFromLeftPin = 11;
const int isTimelapseSpeedPin = 12;

// define output pin numbers
const int motorOffPin = 13;
const int ledPin = 5;

// set up LED and debug timers
Neotimer warningBlinkTimer = Neotimer(); 
Neotimer readyBlinkTimer = Neotimer(); 
Neotimer statusUpdateTimer = Neotimer(); 

// define analogue input for speed knob
const int speedPotPin = A0;
int speedInput = 0; // a variable to stare it in
int traverseSpeed = 0; // variable to hold speed when calculated

// variables to determine kind of traverse
bool startFromLeft = true;
bool isTimelapseSpeed = false;
```


## Setup state machine

As part of this, there is a section for the state machine itself:

```
// WARNING: values, order of items and total number of items must match the array below
enum possibleStates {
  INIT,
  TRAVERSING,
  ABORTED
};

// create an array of labels from the enum for debugging
// WARNING: this array must be updated if you change the enum
String stateLabels[3] = {
  "INIT",
  "TRAVERSING",
  "ABORTED"
};

// create a variable of this type
enum possibleStates currentState;

// keep track of whether the state has changed to limit status message updates
bool isNewState;
```


## Setup()

In `setup()` we:
* Set values for the motor
* Set values for the timers
* Open serial comms, if debugging is enabled
* Set up the switches with internal pullup resistors (so they're pulled low to activate)
* Set up output pins for the motor enable function and the status LED
* Use the debounce library to set up our one push-button
* Finally, set the starting state, ready for the loop

```
void setup() {

  stepper.setMaxSpeed(4000); // See https://forum.arduino.cc/index.php?topic=487134.0
  stepper.setAcceleration(2000.0);

  // set up blink and debug message timers
  warningBlinkTimer.set(100);
  readyBlinkTimer.set(1000);
  statusUpdateTimer.set(2000);

#ifdef DEBUG
  Serial.begin(9600); // serial comms for debugging
#endif

  // initialize the button pins as inputs:
  pinMode(leftEndStopPin, INPUT_PULLUP);
  pinMode(rightEndStopPin, INPUT_PULLUP);
  pinMode(startFromLeftPin, INPUT_PULLUP);
  pinMode(isTimelapseSpeedPin, INPUT_PULLUP);

  // initialise output pins
  pinMode(motorOffPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  // Debounced start button
  debouncer.attach(startButtonPin,INPUT_PULLUP); // Attach the debouncer to a pin with INPUT_PULLUP mode
  debouncer.interval(25); // Use a debounce interval of 25 milliseconds

  // set startup state
  currentState = INIT;
  isNewState = true;
}
```


## Loop()

Inside the main loop, we first check the state of the push-button, as this has some function in every state. 

Then we switch through all of the possible machine states, printing any debug messages if required, calling the functions for that state, and checking to see if the push button has been pressed in case we need to switch to a different state.  

After the stae machine switch, we just check to see if continuous debug messages need to be printed.

```
void loop() {

  // Debounced start button
  debouncer.update(); // Update the Bounce instance


  switch (currentState) {
    case INIT:

      #ifdef DEBUG_STATE_CHANGE
        if (isNewState) {
          printDebugMessages();
          isNewState = false;
        }
      #endif

      setLEDStatus(0);       // LED status light 
      switchOffMotor();      // disable motor until we need it
      getControlInputs();    // get values for all the motion control variables

      if ( debouncer.fell() ) {  
        // first, check both end stops are connected and not currently closed
        if (digitalRead(rightEndStopPin) == HIGH || digitalRead(leftEndStopPin) == HIGH) {
          switchOffMotor; // just in case
          errorMessage = "ERROR: One of the end stops is either closed, or not connected";
          currentState = ABORTED;
          isNewState = true;
        } else { // otherwise, it's safe to start traverse
          currentState = TRAVERSING;
          isNewState = true;
        }
      }
      break;


    case TRAVERSING:
    
      #ifdef DEBUG_STATE_CHANGE
        if (isNewState) {
          printDebugMessages();
          isNewState = false;
        }
      #endif

      if ( debouncer.fell() ) {  
        currentState = INIT;
        isNewState = true;
      }

      switchOnMotor();
      traverse();
      setLEDStatus(1);    // LED status light 

      break;
      

    case ABORTED:

      #ifdef DEBUG_STATE_CHANGE
        if (isNewState) {
          printDebugMessages();
          isNewState = false;
        }
      #endif
      
      switchOffMotor();
      setLEDStatus(2);    // LED status light 

      if ( debouncer.fell() ) {  
        currentState = INIT;
        isNewState = true;
      }
  
      break;
      
  }


  // program-wide debug status messages
  // runs continuously on a timer
  #ifdef DEBUG_TIMER
    if(statusUpdateTimer.repeat()){
      printDebugMessages();
    }
  #endif

}
```


## Other functions

These functions are called from different states within the main loop. 

`setLEDStatus` switches based on the possible values of the enum we set up earlier called `possibleStates`. An easy mistake here is to write this function as:

```
void setLEDStatus(enum possibleStates) {
}
```

But of course the parameter type is `possibleStates` not `enum` (even though `possibleStates` is a kind of `enum` we created earlier).

```
void setLEDStatus(possibleStates currentStateForLED) {
  switch (currentStateForLED) {
    case INIT:
      if(readyBlinkTimer.repeat()){
        digitalWrite(ledPin,!digitalRead(ledPin)); 
      }
      break;

    case TRAVERSING:
      digitalWrite(ledPin, HIGH);
      break;   

    case ABORTED:
      if(warningBlinkTimer.repeat()){
        digitalWrite(ledPin,!digitalRead(ledPin)); 
      }  
      break;
  } 
}
```

I only want to get the speed, direction and mode inputs when the slider is not moving; that way any unintentional changes don't affect motion while you're recording. 

```
void getControlInputs() {

  // TIMELAPSE OR VIDEO MODE 
  if (digitalRead(isTimelapseSpeedPin) == LOW) { // timelapse mode selected
    isTimelapseSpeed = true;
  } else {
    isTimelapseSpeed = false;
  }

  // SET DIRECTION
  if (digitalRead(startFromLeftPin) == LOW) { // start from left selected
    startFromLeft = true;
  } else {
    startFromLeft = false;
  }
 

  // SPEED CONTROL 
  speedInput = analogRead(speedPotPin);

  // map the speed set on the knob to useful values
  if (isTimelapseSpeed) { // test to see if we're running in timelapse or video mode
    traverseSpeed = map(speedInput, 0, 1023, timelapseMinSpeed, timelapseMaxSpeed);
  } else {
    traverseSpeed = map(speedInput, 0, 1023, videoMinSpeed, videoMaxSpeed);
  }


  // test to see if we're running L-R or R-L
  if (!startFromLeft) { // if NOT startFromLeft
    traverseSpeed = -traverseSpeed; // Left is negative, so if we start from the left, speed must be positive!
  }
}
```

For the motion itself, I'm using the AccelStepper library. I documented some of my trials with that [here](https://andrewsleigh.com/fab-slider/coding-accelstepper/): 

```
void traverse() {
  stepper.setSpeed(traverseSpeed);
  stepper.runSpeed();

  if (digitalRead(leftEndStopPin) == HIGH) { // if it touches left end-stop
    DEBUG_PRINT("Hit left end stop");
    // move off the end stop
    stepper.runToNewPosition(stepper.currentPosition() + endStopPadding); // Blocks until stepper is in position
    errorMessage = "Finished traverse";
    currentState = INIT;
    isNewState = true;
  }

  if (digitalRead(rightEndStopPin) == HIGH) { // if it touches right end-stop
    DEBUG_PRINT("Hit left end stop");
    // move off the end stop
    stepper.runToNewPosition(stepper.currentPosition() - endStopPadding); // Blocks until stepper is in position
    errorMessage = "Finished traverse";
    currentState = INIT;
    isNewState = true;
  }
}
```

It's pretty easy to switch off power to the motor by pulling the ENABLE pin high:

```
void switchOffMotor() {
  digitalWrite(motorOffPin, HIGH); // assumes ENABLE pin is connected to D13
}


void switchOnMotor() {
  digitalWrite(motorOffPin, LOW); 
}
```

And finally there's a function handle printing the current stus to the serial monitor:

```
void printDebugMessages() {
#ifdef DEBUG  
  Serial.println("\n--------------------   ----------");
  // machine state
  Serial.print("Current state:         ");
  Serial.println(stateLabels[currentState]);

  // latest error message
  if (errorMessage != "") {
    Serial.print("Last message:          ");
    Serial.println(errorMessage);
  }

  // control settings
  Serial.print("Start from:            ");
  if (startFromLeft == 1) {
    Serial.println("Left");  
  } else {
    Serial.println("Right"); 
  }
  Serial.print("Mode:                  ");
  if (isTimelapseSpeed == 1) {
    Serial.println("Time-lapse");  
  } else {
    Serial.println("Video"); 
  }
  Serial.print("Speed:                 ");
  Serial.println(traverseSpeed);
  Serial.println("--------------------   ----------\n");
#endif
}
```
