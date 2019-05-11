void moveToStartPosition() {


  

  // check which direction we're going in
  if (startFromLeft) {
    stepper.moveTo(leftEndStopPosition); // this sets the target. It doesn't move anything yet!
    stepper.setSpeed(calibrationSpeed); //  Docs: If you are trying to use constant speed movements, you should call setSpeed() after calling moveTo().
  } else {
    stepper.moveTo(rightEndStopPosition); // this sets the target. It doesn't move anything yet!
    stepper.setSpeed(-calibrationSpeed); //  Docs: If you are trying to use constant speed movements, you should call setSpeed() after calling moveTo().
  }



  /*

    TODO: this version doesnt stop the motor or change the machine state when an endstop is pressed, but it does set the error message!
  */


  
    while (stepper.currentPosition() != stepper.targetPosition()) { // only move it while we're not at the target

      // check neither end-stop is pressed
      // this traverse function assumes ends have been calibrated so on the happy path, neither endstop will be triggered, therefore any triggering is a fault
      if (digitalRead(leftEndStopPin) == HIGH || digitalRead(rightEndStopPin) == HIGH) { // either end-stop pressed
        errorMessage = "ERROR: hit an end-stop while moving to start";
        currentState = ABORT;
      } else { // OK to proceed
        stepper.runSpeedToPosition(); // I don't think this is blocking

      }
    }







  //    if (startFromLeft) {
  //
  //      stepper.setSpeed(-calibrationSpeed);
  //      stepper.runToNewPosition(leftEndStopPosition); // Blocks until stepper is in position
  //      DEBUG_PRINT("I'm at the left end stop");
  //
  //    } else {
  //      stepper.setSpeed(calibrationSpeed);
  //      stepper.runToNewPosition(rightEndStopPosition); // Blocks until stepper is in position
  //      DEBUG_PRINT("I'm at the right end stop");
  //
  //    }

  //    stepper.stop(); // Stop as fast as possible: sets new target
  //    stepper.runToPosition();

  delay(1000);

  // start timout timer before moving to next state
  mytimer.start();
  DEBUG_PRINT("Timer started: waiting to traverse");


  currentState = WAITING_TO_TRAVERSE; // automatically move onto the next state after moved to start position





}
