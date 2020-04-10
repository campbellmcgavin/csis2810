#include <MultiStepper.h>
#include <AccelStepper.h>

// ConstantSpeed.pde
// -*- mode: C++ -*-
//
// Shows how to run Accelx_stepper in the simplest,
// fixed speed mode with no accelerations
/// \author  Mike McCauley (mikem@airspayce.com)
// Copyright (C) 2009 Mike McCauley
// $Id: ConstantSpeed.pde,v 1.1 2011/01/05 01:51:01 mikem Exp mikem $

int stepperMode = 1;

int x_pinStep = 5;
int x_pinDir = 2;

int y_pinStep = 6;
int y_pinDir = 4;
int counter = 0;

int cnt = 0;

boolean clockwise =true;
AccelStepper x_stepper(1, x_pinStep, x_pinDir); // Defaults to Accelx_stepper::FULL4WIRE (4 pins) on 2, 3, 4, 5
AccelStepper y_stepper(1, y_pinStep, y_pinDir); // constructor for y_stepper.


void setup()
{  
   x_stepper.setMaxSpeed(3000);
   y_stepper.setMaxSpeed(3000);


   
   

   x_stepper.setSpeed(30000);
   y_stepper.setSpeed(30000); 
}

void loop()
{  
   int steps = random(-1000, 0);
  int steps2 = random(-1000, 0);
  if (movement == 0) {
    moveBackward();
  }
  if (movement == 1)
  /*
  y_stepper.runSpeedToPosition();
  while(clockwise)
  {
    x_stepper.move(10);
    x_stepper.runSpeedToPosition();
    
    y_stepper.move(10);
    y_stepper.runSpeedToPosition();
    
    counter++;
    if(cnt == 20) 
    {
      clockwise = false;
      }
  }
  if(!clockwise)
  {
      x_stepper.move(-10);
      y_stepper.move(-10);
      counter--;
      if(cnt == 0) 
    {
      clockwise = true;
      }
    x_stepper.run();
    y_stepper.run();
  }
    

   //x_stepper.runToNewPosition(10000);
   //y_stepper.runToNewPosition(10000); 
   //x_stepper.
   */
}

void moveRight(int steps)
{
  //stepperLeft.stop();
  x_stepper.moveTo(steps);
  x_stepper.setSpeed(50);
  while (x_stepper.currentPosition() != steps)
  {
    x_stepper.run();
  }
  x_stepper.setCurrentPosition(0);
  y_stepper.setCurrentPosition(0);
}

void moveForward()
{
  stepperLeft.moveTo(MOTION);
  stepperLeft.setSpeed(50);
  x_stepper.moveTo(MOTION);
  x_stepper.setSpeed(50);

  while (stepperLeft.currentPosition() != MOTION && stepperRight.currentPosition() != MOTION)
  {
    stepperLeft.run();
    x_stepper.run();
  }

  //stepperRight.stop();
  //stepperLeft.stop();
  //stepperLeft.setCurrentPosition(stepperRight.currentPosition());
  //stepperRight.setCurrentPosition(stepperLeft.currentPosition());
  x_stepper.setCurrentPosition(0);
  stepperLeft.setCurrentPosition(0);
  movement += 1;
}

void moveBackward()
{
  stepperLeft.moveTo(-MOTION);
  stepperLeft.setSpeed(50);
  x_stepper.moveTo(-MOTION);
  x_stepper.setSpeed(50);
  while (stepperLeft.currentPosition() != -MOTION && stepperRight.currentPosition() != -MOTION)
  {
    stepperLeft.run();
    stepperRight.run();
  }

  //stepperRight.stop();
  //stepperLeft.stop();
  //stepperRight.setCurrentPosition(stepperRight.currentPosition());
  // stepperLeft.setCurrentPosition(stepperLeft.currentPosition());
  stepperRight.setCurrentPosition(0);
  stepperLeft.setCurrentPosition(0);
  movement += 1;

}

///
AF_Stepper motor1(200, 1);
AF_Stepper motor2(200, 2);
int movement = 0;
const int MOTION = 1000;

// you can change these to DOUBLE or INTERLEAVE or MICROSTEP!
// wrappers for the first motor!
void forwardstep1() {
  motor1.onestep(FORWARD, SINGLE);
}
void backwardstep1() {
  motor1.onestep(BACKWARD, SINGLE);
}
// wrappers for the second motor!
void forwardstep2() {
  motor2.onestep(FORWARD, SINGLE);
}
void backwardstep2() {
  motor2.onestep(BACKWARD, SINGLE);
}

// Motor shield has two motor ports, now we'll wrap them in an AccelStepper object
AccelStepper stepperLeft(forwardstep1, backwardstep1);
AccelStepper stepperRight(forwardstep2, backwardstep2);

void setup() {
  stepperLeft.setMaxSpeed(200);
  stepperLeft.setAcceleration(200);
  stepperLeft.moveTo(0);
  stepperRight.setMaxSpeed(200);
  stepperRight.setAcceleration(200);
  stepperRight.moveTo(0);
}

void moveLeft(int steps) // STEPS MUST BE NEG TO MAKE IT REVERSE
{
  //stepperRight.stop();
  stepperLeft.moveTo(steps);
  stepperLeft.setSpeed(50);
  while (stepperLeft.currentPosition() != steps)
  {
    stepperLeft.run();
  }
  stepperRight.setCurrentPosition(0);
  stepperLeft.setCurrentPosition(0);

}

void moveRight(int steps)
{
  //stepperLeft.stop();
  stepperRight.moveTo(steps);
  stepperRight.setSpeed(50);
  while (stepperRight.currentPosition() != steps)
  {
    stepperRight.run();
  }
  stepperRight.setCurrentPosition(0);
  stepperLeft.setCurrentPosition(0);
}

void moveForward()
{
  stepperLeft.moveTo(MOTION);
  stepperLeft.setSpeed(50);
  stepperRight.moveTo(MOTION);
  stepperRight.setSpeed(50);

  while (stepperLeft.currentPosition() != MOTION && stepperRight.currentPosition() != MOTION)
  {
    stepperLeft.run();
    stepperRight.run();
  }

  //stepperRight.stop();
  //stepperLeft.stop();
  //stepperLeft.setCurrentPosition(stepperRight.currentPosition());
  //stepperRight.setCurrentPosition(stepperLeft.currentPosition());
  stepperRight.setCurrentPosition(0);
  stepperLeft.setCurrentPosition(0);
  movement += 1;
}

void moveBackward()
{
  stepperLeft.moveTo(-MOTION);
  stepperLeft.setSpeed(50);
  stepperRight.moveTo(-MOTION);
  stepperRight.setSpeed(50);
  while (stepperLeft.currentPosition() != -MOTION && stepperRight.currentPosition() != -MOTION)
  {
    stepperLeft.run();
    stepperRight.run();
  }

  //stepperRight.stop();
  //stepperLeft.stop();
  //stepperRight.setCurrentPosition(stepperRight.currentPosition());
  // stepperLeft.setCurrentPosition(stepperLeft.currentPosition());
  stepperRight.setCurrentPosition(0);
  stepperLeft.setCurrentPosition(0);
  movement += 1;

}
