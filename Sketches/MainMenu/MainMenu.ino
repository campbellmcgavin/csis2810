#include <MultiStepper.h>
#include <AccelStepper.h>
#include <Point.h>

// AccelStepper Setup
bool stringAlternator = true;
int inputStringLengthA = 0;
int inputStringLengthB = 0;
int stepperMode = 1;
int x_pinStep = 5;
int x_pinDir = 2;
int y_pinStep = 6;
int y_pinDir = 4;
int counter = 0;
int x_maxDist = 0;
int y_maxDist = 0;
AccelStepper x_stepper(1, x_pinStep, x_pinDir); // Defaults to Accelx_stepper::FULL4WIRE (4 pins) on 2, 3, 4, 5
AccelStepper y_stepper(1, y_pinStep, y_pinDir); // constructor for y_stepper.

// Define the Pins used
#define x_switchHome 12 // Pin 9 connected to Home Switch (MicroSwitch) // THIS IS NOT BEING USED YET.
#define x_switchMax 13
#define y_switchHome 14
#define y_switchMax 15

// Stepper Travel Variables
long x_travel;  // Used to store the X value entered in the Serial Monitor
int x_move_finished = 1; // Used to check if move is completed
long x_initial_homing = -1; // Used to Home Stepper at startup
long y_initial_homing = -1;
int y_move_finished = 1; // Used to check if move is completed
// Printer bed information
long bedSize = 1500;
double maxSpeed = 2000000.0;
double maxAccel = 10000.0;
int s = 0;
int sgr = s/1.618;
Point origin = Point(0,0);
Point pointA = Point(0,0);
Point pointB = Point(0,0);

void setup() 
{
  Serial.begin(9600);  // Start the Serial monitor with speed of 9600 Bauds
  //pinMode(x_switchHome, INPUT_PULLUP);
  //pinMode(y_switchHome, INPUT_PULLUP);
  //goHome();
  x_stepper.setCurrentPosition(0);
  y_stepper.setCurrentPosition(0);
  x_stepper.setMaxSpeed(maxSpeed);      // Set Max Speed of Stepper (Faster for regular movements)
  x_stepper.setAcceleration(maxAccel);
  y_stepper.setMaxSpeed(maxSpeed);      // Set Max Speed of Stepper (Faster for regular movements)
  y_stepper.setAcceleration(maxAccel);
}

void loop() 
{
  MainMenu();
 
}
