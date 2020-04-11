void goHome()
{
  delay(5);  // Wait for EasyDriver wake up

//  Set Max Speed and Acceleration of each Steppers at startup for homing
  x_stepper.setMaxSpeed(maxSpeed);      // Set Max Speed of Stepper (Slower to get better accuracy)
  x_stepper.setAcceleration(1000.0);  // Set Acceleration of Stepper
  y_stepper.setMaxSpeed(maxSpeed);      // Set Max Speed of Stepper (Slower to get better accuracy)
  y_stepper.setAcceleration(1000.0);  // Set Acceleration of Stepper
  
  // Start Homing procedure of Stepper Motor at startup


  Serial.print("Stepper is Homing . . . . . . . . . . . ");

  
  while (digitalRead(x_switch) || digitalRead(y_switch))  
  {  // Make the Stepper move CCW until the switch is activated
   if(digitalRead(x_switch))
    {
      x_stepper.moveTo(x_initial_homing);  // Set the position to move to
      x_initial_homing--;  // Decrease by 1 for next move if needed
      x_stepper.run();  // Start moving the stepper
      delay(5);
    }
    
    
    if(digitalRead(y_switch))
    {
      y_stepper.moveTo(y_initial_homing);  // Set the position to move to
      y_initial_homing--;  // Decrease by 1 for next move if needed
      y_stepper.run();  // Start moving the stepper
      delay(5);
    }
  }
   
  x_stepper.setCurrentPosition(0);  // Set the current position as zero for now
  x_stepper.setMaxSpeed(maxSpeed);      // Set Max Speed of Stepper (Slower to get better accuracy)
  x_stepper.setAcceleration(maxAccel);  // Set Acceleration of Stepper
  x_initial_homing = 1;

  y_stepper.setCurrentPosition(0);  // Set the current position as zero for now
  y_stepper.setMaxSpeed(maxSpeed);      // Set Max Speed of Stepper (Slower to get better accuracy)
  y_stepper.setAcceleration(maxAccel);  // Set Acceleration of Stepper
  y_initial_homing = 1;



  while (!digitalRead(x_switch) || !digitalRead(y_switch)) { // Make the Stepper move CW until the switch is deactivated
    
    if(!digitalRead(x_switch))
    {
      x_stepper.moveTo(x_initial_homing);
      x_stepper.run();
      x_initial_homing++;
      delay(5);
    }
    if(!digitalRead(y_switch))
    {
      y_stepper.moveTo(y_initial_homing);
      y_stepper.run();
      y_initial_homing++;
      delay(5);
    }
  }


  x_stepper.setCurrentPosition(0);
  Serial.println("Homing Completed");
  Serial.println("");
  x_stepper.setMaxSpeed(maxSpeed);      // Set Max Speed of Stepper (Faster for regular movements)
  x_stepper.setAcceleration(maxAccel);  // Set Acceleration of Stepper

  // Print out Instructions on the Serial Monitor at Start
 // Serial.println("Enter Travel distance (Positive for CW / Negative for CCW and Zero for back to Home): ");

}
