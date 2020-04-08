#include <MultiStepper.h>
#include <AccelStepper.h>
#include <Point.h>

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
int y_move_finished = 1; // Used to check if move is completed
// Printer bed information
long bedSize = 1500;
double maxspeed = 1000.0;
double maxaccel = 1000.0;

//Create instances of other classes


void setup() {
  Serial.begin(9600);  // Start the Serial monitor with speed of 9600 Bauds
  pinMode(x_switch, INPUT_PULLUP);
  pinMode(y_switch, INPUT_PULLUP);
  goHome();
}

void loop() {
 
  MainMenu();
  
}
