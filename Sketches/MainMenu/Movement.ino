//~~~~~~~~~~~~~~ HELPER FUNCTIONS ~~~~~~~~~~~~~~~//

bool areWeThereYet()
{
  if (xThereYet() && yThereYet()) return true;
  return false;
}

bool xThereYet()
{
  if((x_stepper.distanceToGo() != 0)) return false;
  if (x_move_finished == 0) x_move_finished=1;  // Reset move variable
  return true;
}

bool yThereYet()
{
  if((y_stepper.distanceToGo() != 0)) return false;
  if (y_move_finished == 0) y_move_finished=1;  // Reset move variable
  return true;
}

void printHowFarLeft()
{
   Serial.print("X, Y: ");
   Serial.print(x_stepper.distanceToGo() + ", " +  y_stepper.distanceToGo());
}


//~~~~~~~~~~~~~~~~~~ DRAW FUNCTIONS ~~~~~~~~~~~~~~~~//

void DrawLine(Point start, Point finish)
{
  calculateLine(start, finish);
  while(!ThereYet)
  {
    MoveMotors();
  }
}

/*void DrawCircle(Point start, Point finish, bool clockwise, )
{

  while(!ThereYet)
  {
    //MovePencil();
  }
}
*/


//~~~~~~~~~~~~~~~~ CALCULATE FUNCTIONS ~~~~~~~~~~~~~~//

void calculateLine(Point start, Point finish)
{
  // HELP set speed of motors according to dimensions of a triangle...
  int xDiff = finish.getX() - start.getX();
  int yDiff = finish.getY() - start.getY();

  if(xDiff > yDiff)
  {
    x_stepper.setSpeed(maxSpeed*.8);      // Set Max Speed of Stepper (Slower to get better accuracy)
    y_stepper.setSpeed(maxSpeed*.8*yDiff/xDiff);
  }
  else
  {
    y_stepper.setSpeed(maxSpeed*.8);      // Set Max Speed of Stepper (Slower to get better accuracy)
    x_stepper.setSpeed(maxSpeed*.8*xDiff/yDiff);
  }
}

void calculateCircle(Point radius, Point xxx)
{
  // HELP set speed of motors according to location in arc of circle...
}


//~~~~~~~~~~~~~~~~~ MOVE FUNCTIONS ~~~~~~~~~~~~~~~~~~//
void MoveMotors()
{
     printHowFarLeft();
     
     // Check if the Stepper has reached desired position
     if (!xThereYet()) {
      x_stepper.run();  // Move Stepper into position
     }
     if (!yThereYet()) {
      y_stepper.run();  // Move Stepper into position
     }

}
