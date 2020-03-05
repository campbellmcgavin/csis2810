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

AccelStepper x_stepper(1, x_pinStep, x_pinDir); // Defaults to Accelx_stepper::FULL4WIRE (4 pins) on 2, 3, 4, 5
AccelStepper y_stepper(1, y_pinStep, y_pinDir); // constructor for y_stepper.


void setup()
{  
   x_stepper.setMaxSpeed(3000);
   y_stepper.setMaxSpeed(3000);
   x_stepper.setSpeed(-3000);
   y_stepper.setSpeed(-3000); 
   
}

void loop()
{  
   x_stepper.setSpeed(-3000);
   y_stepper.setSpeed(-3000); 
   counter = 0;
   while(counter < 40000)
   {
       x_stepper.runSpeed();
       y_stepper.runSpeed();
       counter=counter + 1;
   }
    
    counter = 0;
    x_stepper.setSpeed(3000);
    y_stepper.setSpeed(3000); 
   
      while(counter < 40000)
   {
       x_stepper.runSpeed();
       y_stepper.runSpeed();
       counter= counter+1;
   }

   
   //x_stepper.setSpeed(3000);
   //y_stepper.setSpeed(3000); 
   //x_stepper.runSpeed();
   //y_stepper.runSpeed();
   //delay(3000);
   
}
