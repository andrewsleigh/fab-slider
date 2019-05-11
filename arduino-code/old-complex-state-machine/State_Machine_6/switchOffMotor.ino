// assumes ENABLE pin is connected to D13

void switchOffMotor() {

  digitalWrite(motorOffPin, HIGH);
  gotLeftLimit = false;
  gotRightLimit = false;
  
}
