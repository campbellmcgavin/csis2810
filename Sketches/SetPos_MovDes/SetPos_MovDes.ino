/*  Motor Homing code using AccelStepper and the Serial Monitor

  Created by Yvan / https://Brainy-Bits.com
  This code is in the public domain...
  You can: copy it, use it, modify it, share it or just plain ignore it!
  Thx!

*/
#include <MultiStepper.h>
#include <AccelStepper.h>
#include <Point.h>
#include <Scribe.h>
// Library created by Mike McCauley at http://www.airspayce.com/mikem/arduino/AccelStepper/

// AccelStepper Setup


int stepperMode = 1;
int x_pinStep = 5;
int x_pinDir = 2;
int y_pinStep = 6;
int y_pinDir = 4;
int counter = 0;
AccelStepper x_stepper(1, x_pinStep, x_pinDir); // Defaults to Accelx_stepper::FULL4WIRE (4 pins) on 2, 3, 4, 5
AccelStepper y_stepper(1, y_pinStep, y_pinDir); // constructor for y_stepper.

// Define the Pins used
#define x_switch 12 // Pin 9 connected to Home Switch (MicroSwitch) // THIS IS NOT BEING USED YET.
#define y_switch 13

// Stepper Travel Variables
long x_travel;  // Used to store the X value entered in the Serial Monitor
int x_move_finished = 1; // Used to check if move is completed
long x_initial_homing = -1; // Used to Home Stepper at startup
long y_initial_homing = -1;
// Printer bed information
long bedSize = 1500;

void setup() {
  Serial.begin(9600);  // Start the Serial monitor with speed of 9600 Bauds

  pinMode(x_switch, INPUT_PULLUP);

  delay(5);  // Wait for EasyDriver wake up

  //  Set Max Speed and Acceleration of each Steppers at startup for homing
  x_stepper.setMaxSpeed(1000.0);      // Set Max Speed of Stepper (Slower to get better accuracy)
  x_stepper.setAcceleration(1000.0);  // Set Acceleration of Stepper
  y_stepper.setMaxSpeed(1000.0);      // Set Max Speed of Stepper (Slower to get better accuracy)
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
  x_stepper.setMaxSpeed(1000.0);      // Set Max Speed of Stepper (Slower to get better accuracy)
  x_stepper.setAcceleration(1000.0);  // Set Acceleration of Stepper
  x_initial_homing = 1;

  y_stepper.setCurrentPosition(0);  // Set the current position as zero for now
  y_stepper.setMaxSpeed(1000.0);      // Set Max Speed of Stepper (Slower to get better accuracy)
  y_stepper.setAcceleration(1000.0);  // Set Acceleration of Stepper
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
  x_stepper.setMaxSpeed(1000.0);      // Set Max Speed of Stepper (Faster for regular movements)
  x_stepper.setAcceleration(1000.0);  // Set Acceleration of Stepper

  // Print out Instructions on the Serial Monitor at Start
  Serial.println("Enter Travel distance (Positive for CW / Negative for CCW and Zero for back to Home): ");
}

void loop() {

 // x_travel = GetInput();

  Point point = new Point(1,2);
  Serial.println("New point x: " + point.getX() + "New point y: " + point.getY());
  while (Serial.available() > 0)  { // Check if values are available in the Serial Buffer
    Serial.println((String)Serial.parseInt());

    x_move_finished = 0; // Set variable for checking move of the Stepper
    x_travel = Serial.parseInt(); // Put numeric value from buffer in x_travel variable

    if (x_travel < 0 || x_travel > 1350) {  // Make sure the position entered is not beyond the HOME or MAX position
      Serial.println("");
      Serial.println("Please enter a value greater than zero and smaller or equal to 1350.....");
      Serial.println("");
    } else {
      //Serial.print("x_travel before" + (String)count++ + ": ");
      //Serial.println(x_travel);

      x_stepper.moveTo(x_travel);  // Set new moveto position of Stepper
      //Serial.print("distanceToGo before1: ");
      //Serial.println(x_stepper.distanceToGo());

      delay(1000);  // Wait 1 seconds before moving the Stepper
    }
    //Serial.print("distanceToGo before2: ");
    //Serial.println(x_stepper.distanceToGo());
  }




}
