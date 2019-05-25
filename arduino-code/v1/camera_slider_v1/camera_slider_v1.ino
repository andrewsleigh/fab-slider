// 2019-05-12
// Andrew Sleigh
// https://andrewsleigh.com/fab-slider/
// Previous version: "State_Machine-No_Calibration_9"


// =============================================================================
// Libraries
#include <AccelStepper.h>
#include <neotimer.h>
#include <Bounce2.h>
// -----------------------------------------------------------------------------




// =============================================================================
// USER CONFIGURATION
int videoMinSpeed = 500;
int videoMaxSpeed = 5000;
int timelapseMinSpeed = 50;
int timelapseMaxSpeed = 250;
int endStopPadding = 100; // a safe distance to disengage the gantry from the end stops, 

// -----------------------------------------------------------------------------




// =============================================================================
// Debugging 
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
// -----------------------------------------------------------------------------




// =============================================================================
// Create objects and variables

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


// Implement state machine
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





// *****************************************************************************
// Other functions


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


void switchOffMotor() {
  digitalWrite(motorOffPin, HIGH); // assumes ENABLE pin is connected to D13
}


void switchOnMotor() {
  digitalWrite(motorOffPin, LOW); 
}


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



// END
