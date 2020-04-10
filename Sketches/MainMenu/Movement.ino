//~~~~~~~~~~~~~~ HELPER FUNCTIONS ~~~~~~~~~~~~~~~//

bool areWeThereYet()
{
 // Serial.print("are we there yet?");
  if (xThereYet() && yThereYet()) return true;
  return false;
}

bool xThereYet()
{
 // Serial.print("\nxThere: " + x_stepper.distanceToGo() == 0);
  //if((x_stepper.distanceToGo() != 0)) return false;
  //if (x_move_finished == 0) x_move_finished=1;  // Reset move variable
  return x_stepper.distanceToGo() == 0;
}

bool yThereYet()
{
 //Serial.print("\nyThere: " + y_stepper.distanceToGo() == 0);
  //if((y_stepper.distanceToGo() != 0)) return false;
  //if (y_move_finished == 0) y_move_finished=1;  // Reset move variable
  return y_stepper.distanceToGo() == 0;
}

void printHowFarLeft()
{
   Serial.print("X, Y: ");
   Serial.print(x_stepper.distanceToGo());
   Serial.print(", ");
   Serial.println(y_stepper.distanceToGo());
   if(counter % 100 == 0)
    {
      Serial.print("counter: ");
      Serial.println(counter);
      printHowFarLeft();
      
    }
}


//~~~~~~~~~~~~~~~~~~ DRAW FUNCTIONS ~~~~~~~~~~~~~~~~//

void DrawLine(Point start, Point finish, bool draw)
{
  calculateLine(start, finish);

  x_stepper.moveTo(finish.getX());
  y_stepper.moveTo(finish.getY());
//Serial.print("before while loop: ");
  int counter = 0;
  while(!areWeThereYet())
  {
    
    
    //Serial.print("X, Y: ");
    MoveMotors();
    counter = counter+1;
  }
}

DrawLetter(char letter, int scale)
{
switch letter

  case"A"
  drawA(scale)
  case"B"
  drawB(scale)

}


DrawA(int scale)
{
  Point start = Point(x.getLocation,y.getLocation)
  start = GoToPosition(start, scale)
  start = GoToPosition(3,scale,start)
}



Point GoToPosition(Point origin, int finish,int scale)
{
    Point start;
    Point finish;
    int sgr = s/1.618;
     
    switch finishSpot
    case 1//(x,y)
       finish = Point(origin.getX(), origin.getY())
       start = (getCurrentX, getCurrentY());
       DrawLine(start,finish)
       
    case 2//(x + 1/4sgr),y))
    
    case 3//(x + 1/2sgr),y))
    
    case 4//(x + 3/4sgr),y))
    
    case 5//(x + 1sgr),y))
    
    return finish
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
     //printHowFarLeft();
     
     // Check if the Stepper has reached desired position
     if (!xThereYet()) {
      x_stepper.run();  // Move Stepper into position
     }
     if (!yThereYet()) {
      y_stepper.run();  // Move Stepper into position
     }
}

void MoveToPoint(Point p)
{
    
  
}
