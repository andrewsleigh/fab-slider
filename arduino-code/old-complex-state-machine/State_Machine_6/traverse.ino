void traverse() {


  // check nieither end-stop is pressed
  // this traverse function assumes ends have been calibrated so on the happy path, neither endstop will be triggered, therefore any triggering is a fault
  if (digitalRead(leftEndStopPin) == HIGH || digitalRead(rightEndStopPin) == HIGH) { // either end-stops pressed
    errorMessage = "ERROR: hit an end-stop during traverse";
    currentState = ABORT;
  } else { // OK to proceed


    // check which direction we're going in
    if (startFromLeft) {
      stepper.moveTo(rightEndStopPosition); // this sets the target. It doesn't move anything yet!
      stepper.setSpeed(traverseSpeed); //  Docs: If you are trying to use constant speed movements, you should call setSpeed() after calling moveTo().
    } else {
      stepper.moveTo(leftEndStopPosition); // this sets the target. It doesn't move anything yet!
      stepper.setSpeed(traverseSpeed); //  Docs: If you are trying to use constant speed movements, you should call setSpeed() after calling moveTo().
    }


    while (stepper.currentPosition() != stepper.targetPosition()) { // only move it while we're not at the target
      stepper.runSpeedToPosition(); // I don't think this is blocking
    }
  }


  //TODO
  // what after finishing?


}
