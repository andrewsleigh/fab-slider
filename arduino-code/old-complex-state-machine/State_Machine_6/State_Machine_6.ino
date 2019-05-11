// 2019-05-06
// Andrew Sleigh

// Note, I stopped work on this branch of the code before it was complete
// subsequent versions used a much simpler state machine model, with much less code
// I'm posting this as it has a few more interesting bits of stepper control, 
// and also shows a more complex state machine control flow

// version history

// Rebuilding as state machine, with more comprehensive states
// as per "Slider state machine v2.graffle"

// v2
// trying MStimer library to handle time outs

// v3
// trying neotimer to do the same

// v4
// now have motor connected up on the slider itself, so need to be much more careful about endstops!
// need to only move slider when end-stop is not pressed
// need to allow for possibility that slider will move in wrong directionwhen calibrating, so will hit wrong endstop
// need to allow for end-stops not being wired in at all

// So
// flipped switch pressed states from LOW to HIGH - so they will act as pressed even if disconnected.
// Add ABORT state to handle when things go badly wrong, and we need to stop everything
// removing use of variables to hold button states, just di a digitalRead in my conditionals

// current status
// my calculations of speed and duration in getControlInputs() are not working...


// v5
// added in speed control from Speed_Pot_Maths_Test_2.ino
// speed control knob on A0
// added in timelapse/video toggle - which pins?
// added in direction toggle - which pins?

// added L and R start positions

// added more sophisticated debugging, as seen here:
// https://forum.arduino.cc/index.php?topic=215334.msg1576067#msg1576067
// and https://forum.arduino.cc/index.php?topic=46900.0


// v6
// adding the traverse code
// removed all serial.prints, replaced with DEBUG_PRINT versions

// to do
// add error handling for moving to start position
// try a stepped version for timelapse...?
// add checks while traversing for endstops
// a version without calibration??

// maybe set some variables depending on whether MS is enabled??
// Is MS state readable??
// TODO - maybe need to set acceleration too?
// https://groups.google.com/forum/#!topic/accelstepper/AdYE-v5PwA8
// If you want acceleration, you have to set a target so it knows when to start decelerating, and NOT use runSpeed(). runSpeed() bypasses the acceleration calculations.


// current status: can't get end-stop error handling to work in moveToStartPosition()
// and presumably same problem in traverse()
// it does work in calibrateEnds() which uses different functions to move motor
// might help: https://groups.google.com/forum/#!topic/accelstepper/4EkIbXQC03I

// so it might be that I can avoid this by forgeting about calibrating ends, 
// and therefore never moving to specific positions, just moving until I hit a stop.
// so lets try that!





// Stepper library
#include <AccelStepper.h>

// timer library
// #include <MsTimer2.h>
#include <neotimer.h>



/*
 * USER CONFIGURATION
 * 
 */

// set some default speeds for movement

// TODO - may want to handle this differntly, now I have speed control incorporated
int calibrationSpeed = 5000; // CAREFUL!! Assumes I'm using microstepping mode

// set duration ranges in seconds
int videoMinDuration = 6;
int videoMaxDuration = 60;
int timelapseMinDuration = 5 * 60;
int timelapseMaxDuration = 60 * 60;

int endStopPadding = 100; // a safe distance to disengage the gantry from the end stops, will depend on use of microstepping modes
// TODO, maybe set these variables depending on whether MS is enabled??
// Is this readable??

// TODO - maybe need to set acceleration too?


// Timeout period
// TODO - maybe there should be an option to change this if you're on battery power...
Neotimer mytimer = Neotimer(100000); // 100 seconds 
 
/*  
 * END OF USER CONFIGURATION
 * 
 */
 
// Debugging setup
// See Debug_Testing_1.ino for details and simple version
#define DEBUG // comment this out to remove debugging


#ifdef DEBUG
// set up timer
int debugRefreshPeriod = 3000;
unsigned long debugTimeNow = 0;
String errorMessage = "";
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



// format: interface, step pin, direction pin
// for shield: note step D2 and dir D3 pins 
AccelStepper stepper(AccelStepper::DRIVER, 2, 3);


// define button pin numbers
const int startButtonPin = 10;
const int leftEndStopPin = 9;    
const int rightEndStopPin = 8; 
const int motorOffPin = 13;
const int startFromLeftPin = 11;
const int isTimelapseSpeedPin = 12;

// define analogue input for speed knob
const int speedPotPin = A0;
int durationInput = 0; // a variable to stare it in 
int durationOutput = 0; // a version mapped to useful range that the motor can use

// variable to hold total distance when calculated
int totalSteps = 0;

// variable to hold speed when calculated
int traverseSpeed = 0; 

// variables to hold left and right limit positions
int leftEndStopPosition = 0;
int rightEndStopPosition = 0;
bool gotLeftLimit = false;
bool gotRightLimit = false;

// variables to determine kind of traverse
bool startFromLeft = true;
bool isTimelapseSpeed = false;

int maxSafetraverseSpeed = 5000; // max step speed I think is safe

// debug strings for button states to assemble into serial monitor messages
String leftEndStopStatus = "";
String rightEndStopStatus = "";
String startButtonStatus = "";

// timer setup so we can print debug messages with a non-blocking delay
int period = 1000;
unsigned long time_now = 0;




// Implement state machine
// WARNING: values, order of items and total number of items must match the array below
enum possibleStates {
  INIT,
  CALIBRATING_ENDS,
  CALIBRATED,
  MOVING_TO_START_POSITION,
  WAITING_TO_TRAVERSE,
  TRAVERSING,
  PAUSED,
  FINISHED_TRAVERSE,
  ABORT  
  };

// create an array of labels from the enum for debugging
// WARNING: this array must be updated if you change the enum
String stateLabels[9] = {
  "INIT",
  "CALIBRATING_ENDS",
  "CALIBRATED",    
  "MOVING_TO_START_POSITION",    
  "WAITING_TO_TRAVERSE",    
  "TRAVERSING",    
  "PAUSED",    
  "FINISHED_TRAVERSE", 
  "ABORT"  
  };

// create a variable of this type
enum possibleStates currentState;
enum possibleStates previousState; // not sure how this works in state machines
  

void setup() {  

  stepper.setMaxSpeed(4000); // what does this do??
  stepper.setAcceleration(2000.0);

  #ifdef DEBUG
    // serial comms for debugging
    Serial.begin(9600);
  #endif  
  
   // initialize the button pins as inputs:
   pinMode(leftEndStopPin, INPUT_PULLUP);
   pinMode(rightEndStopPin, INPUT_PULLUP);   
   pinMode(startButtonPin, INPUT_PULLUP); 
   pinMode(startFromLeftPin, INPUT_PULLUP); 
   pinMode(isTimelapseSpeedPin, INPUT_PULLUP); 


   // initialise power-off  pin  
   pinMode(motorOffPin, OUTPUT);

   // set startup state
   currentState = INIT;
}

void loop() { 

  switch (currentState) {

    case INIT:  
     
      // note that this state will not clear any old error messages if we revert to it
    
      // disable motor until we need it
      switchOffMotor();

      // check for the Start button being pressed
      if (digitalRead(startButtonPin) == LOW) { // pressing the switch brings the pin low by connecting it to GND
        
        // first, check both end stops are connected and not currently closed
        if (digitalRead(rightEndStopPin) == HIGH || digitalRead(leftEndStopPin) == HIGH) {
          switchOffMotor; // just in case
          // Serial.println("ERROR: One of the end stops is either closed, or not connected");
          errorMessage = "ERROR: One of the end stops is either closed, or not connectedt";
          currentState = ABORT;
        
        } else {
          
        // otherwise, it's safe to start calibrating
        currentState = CALIBRATING_ENDS;
        }
      }  
      break;

    case CALIBRATING_ENDS: 
      // just in case, switch on power to the motor
      switchOnMotor();
      
      // find each end stop
      calibrateEnds();

     
      
      // TODO: add event handler here for pause button

      
      break;


      
    case CALIBRATED:  
     
      // here we need to get values for all the motion control variables
      getControlInputs();


      // wait for timer (started in CALIBRATING_ENDS state, using neotimer library
      // if it runs out, go back to init state
  
  
      if(mytimer.done()){
        // Serial.println("Timer finished");
        errorMessage = "ALERT: Timeout after calibration";
        timeOut();
      }
  
      if(mytimer.waiting()){
       // Serial.println("waiting...");
      }
  
      if (digitalRead(startButtonPin) == LOW) { //
        currentState = MOVING_TO_START_POSITION;
      }
      break;


   
    case MOVING_TO_START_POSITION:
    
      // just in case, switch on power to the motor
      switchOnMotor();
    
      moveToStartPosition();     
      break;


      
    case WAITING_TO_TRAVERSE:

           
      // Again, get values for all the motion control variables
      getControlInputs();

      // TODO: use timer here
      if(mytimer.done()){
        // Serial.println("Timer finished");
        errorMessage = "ALERT: Timeout while waiting to start traverse";
        timeOut();
      }

      // startButtonState = digitalRead(startButtonPin);
      if (digitalRead(startButtonPin) == LOW) { //
        currentState = TRAVERSING;
      }


      break;



      
    case TRAVERSING:

      traverse();

      // TODO: handle pause button
      
      break;



      
    case PAUSED:
      break;



      
    case FINISHED_TRAVERSE: 
      break;



    case ABORT: 

      switchOffMotor();      
      
      break;



      

  }


// program-wide debug status messages
#ifdef DEBUG
if(millis() > debugTimeNow + debugRefreshPeriod){
    debugTimeNow = millis();
    Serial.println("\n------");
    // machine state
    Serial.print("Current state:         ");    
    Serial.println(stateLabels[currentState]);

    // latest error message
    if(errorMessage != "") {
    Serial.print("Message:               ");    
    Serial.println(errorMessage);
    }
    
    // control settings
    Serial.print("Start from left?       ");    
    Serial.println(startFromLeft);
    Serial.print("Use time-lapse mode?   ");    
    Serial.println(isTimelapseSpeed);
    Serial.print("Duration:              ");    
    Serial.println(durationOutput);   
    Serial.print("Speed:                 ");    
    Serial.println(traverseSpeed);        

    // end stop switches and values
    Serial.print("Got left end-stop?     ");    
    Serial.println(gotLeftLimit);
    if (gotLeftLimit) {
    Serial.print("Left limit:            ");    
    Serial.println(leftEndStopPosition);  
    } 
    Serial.print("Got right end-stop?    ");    
    Serial.println(gotRightLimit);
    if (gotRightLimit) {
    Serial.print("Right limit:           ");    
    Serial.println(rightEndStopPosition);        
    }

} 
#endif  
  
}
