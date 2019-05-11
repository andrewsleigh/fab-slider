void getControlInputs() {

  // TIMELAPSE OR VIDEO MODE =======================================
  if (digitalRead(isTimelapseSpeedPin) == LOW) { // timelapse mode selected
    isTimelapseSpeed = true;
  } else {
    isTimelapseSpeed = false;
  }
  // END TIMELAPSE OR VIDEO MODE -----------------------------------


  // SET DIRECTION =================================================
  if (digitalRead(startFromLeftPin) == LOW) { // timlapse mode selected
    startFromLeft = true;
  } else {
    startFromLeft = false;
  }
  // END SET DIRECTION ---------------------------------------------

  
  // SPEED CONTROL =================================================
  // Fine speed control knob
  durationInput = analogRead(speedPotPin);

  // map the duration set on the knob to useful values
  // test to see if we're running in timelapse or video mode
  if (isTimelapseSpeed) {
    durationOutput = map(durationInput, 0, 1023, timelapseMinDuration, timelapseMaxDuration);
  } else {
    durationOutput = map(durationInput, 0, 1023, videoMinDuration, videoMaxDuration);
  }

  totalSteps = rightEndStopPosition - leftEndStopPosition; // assuming left is always a lower number, possibly negative 
 
  // calculate speed from specified duration. speed = distance/time, units:steps/second 
  // check we have got a value for totalSteps first
  if (totalSteps > 0) {
    traverseSpeed = totalSteps/durationOutput;  
  }
  
  // test to see if we're running L-R or R-L
  if (!startFromLeft) { // if NOT startFromLeft
    traverseSpeed = -traverseSpeed; // Left is negative, so if we start from the left, speed must be positive!
  }

  // check we're not setting speed too high
  if (abs(traverseSpeed) > maxSafetraverseSpeed) { // make sure traverseSPeed is + before checking
    // Serial.println("ERROR: Speed is above safe limit");
     errorMessage = "ERROR: Speed is above safe limit";
     currentState = ABORT;
  }
  // END OF SPEED CONTROL -----------------------------------------

  
}
