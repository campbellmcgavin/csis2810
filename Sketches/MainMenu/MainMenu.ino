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
double maxSpeed = 20000.0;
double maxAccel = 10000.0;
int s = 0;
int sgr = s/1.618;
Point origin = Point(0,0);
Point pointArray[] = {
   Point (origin.getX() + 1.25 * sgr, origin.getY()),
   Point (origin.getX() , origin.getY()),
   Point (origin.getX() + 1/4 * sgr,origin.getY()),
   Point (origin.getX() + 1/2 * sgr,origin.getY()),
   Point (origin.getX() + 3/4 * sgr,origin.getY()),
   Point (origin.getX() + sgr, origin.getY()),
   Point (origin.getX() , origin.getY() + 1/4 * s),
   Point (origin.getX() + 1/4 * sgr,origin.getY() + 1/4 * s),
   Point (origin.getX() + 1/2 * sgr,origin.getY() + 1/4 * s),
   Point (origin.getX() + 3/4 * sgr,origin.getY() + 1/4 * s),
   Point (origin.getX() + sgr, origin.getY() + 1/4 * s),
   Point (origin.getX() , origin.getY() + 1/2 * s),
   Point (origin.getX() + 1/4 * sgr,origin.getY() + 1/2 * s),
   Point (origin.getX() + 1/2 * sgr,origin.getY() + 1/2 * s),
   Point (origin.getX() + sgr, origin.getY() + 1/2 * s),
   Point (origin.getX() + 3/4 * sgr,origin.getY() + 1/2 * s),
   Point (origin.getX() , origin.getY() + 3/4 * s),
   Point (origin.getX() + 1/4 * sgr,origin.getY() + 3/4 * s),
   Point (origin.getX() + 1/2 * sgr,origin.getY() + 3/4 * s),
   Point (origin.getX() + 3/4 * sgr,origin.getY() + 3/4 * s),
   Point (origin.getX() + sgr  ,origin.getY() + 3/4 * s),
   Point (origin.getX() , origin.getY() + s),
   Point (origin.getX() + 1/4 * sgr,origin.getY() + s),
   Point (origin.getX() + 1/2 * sgr,origin.getY() + s),
   Point (origin.getX() + 3/4 * sgr,origin.getY() + s),
   Point (origin.getX() + sgr, origin.getY() + s)
  };
//Create instances of other classes


void setup() {
  Serial.begin(9600);  // Start the Serial monitor with speed of 9600 Bauds
  pinMode(x_switch, INPUT_PULLUP);
  pinMode(y_switch, INPUT_PULLUP);
  goHome();
  //Point origin



}

void loop() {

   MainMenu();
 
  
  
}
