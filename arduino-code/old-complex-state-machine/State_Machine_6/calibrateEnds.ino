void calibrateEnds() {

  // TODO:  need to add a check that it isnt already touching one end or the other...


  if (!gotLeftLimit) { // hasn't calibrated either end yet

    // move slider left until it hits either end stop
    // (left is clockwise)
    // NO, LEFT IS CCW
  
    stepper.setSpeed(-calibrationSpeed);
    //stepper.setAcceleration(10);
    // stepper.run();
    stepper.runSpeed();

    // I don't think we can use decceleration here, as we don't yet know where the end point is
    // suppose we could use acceleration at the start
    // maybe best to use a low speed for calibration

    // first, check we're not going to the right
    // if so, we should abort the whole process
    //rightEndStopState = digitalRead(rightEndStopPin);
    if (digitalRead(rightEndStopPin) == HIGH) { // if it touches an end-stop
       // Serial.println("ERROR: Hit right end stop, when we should be going left.");
        errorMessage = "ERROR: Hit right end stop, when we should be going left.";
        currentState = ABORT;
    }

  
    //leftEndStopState = digitalRead(leftEndStopPin);
    if (digitalRead(leftEndStopPin) == HIGH) { // if it touches an end-stop 
      DEBUG_PRINT("Hit left end stop");
      leftEndStopPosition = stepper.currentPosition(); // record an end-limit position for that end-stop
      gotLeftLimit = true;
      stepper.stop(); // stop movement

      //Serial.println(leftEndStopPosition);
      //leftEndStopStatus = "Left: YES";
      
      delay(200);
      // move off the end stop so we're not trigering an error when we start going in the other direction
      stepper.runToNewPosition(leftEndStopPosition+endStopPadding); // Blocks until stepper is in position 

      delay(200);
      
    }
      
  } else if (gotLeftLimit && !gotRightLimit) { // has got left end but not right end

      stepper.setSpeed(calibrationSpeed);
      stepper.runSpeed();

      // again, check we're not going to the left (this time)
      // if so, we should abort the whole process
      if (digitalRead(leftEndStopPin) == HIGH) { // if it touches an end-stop
          errorMessage = "ERROR: Hit left end stop, when we should be going right.";
          currentState = ABORT;
      }
  

      if (digitalRead(rightEndStopPin) == HIGH) { // if it touches an end-stop
        DEBUG_PRINT("Hit right end stop");
        rightEndStopPosition = stepper.currentPosition(); // record an end-limit position for that end-stop
        gotRightLimit = true;
        stepper.stop(); // stop movement        
        delay(200);
        // move off the end stop so we're not triggering an error when we start going in the other direction
        stepper.runToNewPosition(rightEndStopPosition-endStopPadding); // Blocks until stepper is in position 
        delay(200);
      }
      
  } else if (gotLeftLimit && gotRightLimit) {  

     // start timout timer before moving to next state
     mytimer.start();
     DEBUG_PRINT("Timer started");
     currentState = CALIBRATED; // automatically move onto the next state after calibration is complete  

  } else {
   
     errorMessage = "ERROR: Unknown calibration error";
     currentState = ABORT;
  }

}
