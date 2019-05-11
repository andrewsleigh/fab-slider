void timeOut() {

  // after a time out
  
  // move gantry to center point if we know if
  if (gotLeftLimit && gotRightLimit) { 

    stepper.setSpeed(calibrationSpeed);
    int centerPosition = floor((leftEndStopPosition+rightEndStopPosition)/2);
    stepper.runToNewPosition(centerPosition); // Blocks until stepper is in position 
    DEBUG_PRINT("I'm at the center position: ");
    DEBUG_PRINT(centerPosition);
    
    stepper.stop(); // Stop as fast as possible: sets new target
    stepper.runToPosition(); 
    
    delay(1000);
    
  }
  


  // revert to initial state
  // note that this state will not clear any old error messages if we revert to it
  
  currentState = INIT;
  // motor is switched off in INIT state
  
}
