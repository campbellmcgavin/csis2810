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
/**
 * Pretty much DrawLines except takes integers and updates their corresponding Points using our 25 point letter system.
 */
void LetterLines(int start, int finish, bool draw)
{
  Serial.print("\nDrawing: ");
  Serial.print(draw);
  pointA = UpdateCoordinates(start);
  pointB = UpdateCoordinates(finish);
  calculateLine(pointA, pointB);

  x_stepper.moveTo(pointB.getX());
  y_stepper.moveTo(pointB.getY());
//Serial.print("before while loop: ");
  int counter = 0;
  while(!areWeThereYet())
  {
    //Serial.print("X, Y: ");
    MoveMotors();
    counter = counter+1;
  }
}
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
/**
 * Used to update only the points we need rather than having to redo the Point array.
 * @param point - the desired point to update.
 * @return the updated Point.
 */
Point UpdateCoordinates(int point)
{ Point updatedPoint = Point(0,0);
  switch(point)
  {
      case 0:
          updatedPoint = Point(origin.getX() - 1.25 * sgr, origin.getY());
        break;
      case 1:
          updatedPoint = Point(origin.getX() , origin.getY());
        break; 
      case 2:
          updatedPoint = Point(origin.getX() - 0.25 * sgr,origin.getY());
        break; 
      case 3:
          updatedPoint = Point(origin.getX() - 0.5 * sgr,origin.getY());
        break; 
      case 4:
          updatedPoint = Point(origin.getX() - 0.75 * sgr,origin.getY());
        break; 
      case 5:
          updatedPoint = Point(origin.getX() - sgr, origin.getY());
        break; 
      case 6:
          updatedPoint = Point(origin.getX() , origin.getY() + 0.25 * s);
        break; 
      case 7:
          updatedPoint = Point(origin.getX() - 0.25 * sgr,origin.getY() + 0.25 * s);
        break; 
      case 8:        
          updatedPoint = Point(origin.getX() - 0.5 * sgr,origin.getY() + 0.25 * s);
        break; 
      case 9:       
          updatedPoint = Point(origin.getX() - 0.75 * sgr,origin.getY() + 0.25 * s);   
        break; 
      case 10:
          updatedPoint = Point(origin.getX() - sgr, origin.getY() + 0.25 * s);     
        break; 
      case 11:
          updatedPoint = Point(origin.getX() , origin.getY() + 0.5 * s);  
        break; 
      case 12:
          updatedPoint = Point(origin.getX() - 0.25 * sgr,origin.getY() + 0.5 * s);
        break; 
      case 13:
           updatedPoint = Point(origin.getX() - 0.5 * sgr,origin.getY() + 0.5 * s);
        break; 
      case 14:
           updatedPoint = Point(origin.getX() - sgr, origin.getY() + 0.5 * s);
        break;
      case 15:
           updatedPoint = Point(origin.getX() - 0.75 * sgr,origin.getY() + 0.5 * s);
        break;
      case 16:
           updatedPoint = Point(origin.getX() , origin.getY() + 0.75 * s);
        break;
      case 17:
           updatedPoint = Point(origin.getX() - 0.25 * sgr,origin.getY() + 0.75 * s);  
        break;
      case 18:
          updatedPoint = Point(origin.getX() - 0.5 * sgr,origin.getY() + 0.75 * s);
        break;
      case 19:
          updatedPoint = Point(origin.getX() - 0.75 * sgr,origin.getY() + 0.75 * s);
        break;
      case 20:
           updatedPoint = Point(origin.getX() - sgr  ,origin.getY() + 0.75 * s);
        break;
      case 21:
           updatedPoint = Point(origin.getX() , origin.getY() + s);
        break;
      case 22:
           updatedPoint = Point(origin.getX() - 0.25 * sgr,origin.getY() + s);
        break;
      case 23:
           updatedPoint = Point(origin.getX() - 0.5 * sgr,origin.getY() + s);
        break;
      case 24:
           updatedPoint = Point(origin.getX() - 0.75 * sgr,origin.getY() + s);
        break;
      case 25:
           updatedPoint = Point(origin.getX() - sgr, origin.getY() + s);
        break;
      default:
          Serial.print("\nError!: ");
          Serial.print(point);
          Serial.print(" is not a valid coordinate.");
        break;
  }
  return updatedPoint;
}





//Point GoToPosition(Point origin, int finish, int scale)
//{
//    Point start = ;
//    Point finish;
//    int sgr = s/1.618;
//     
//    switch finishSpot
//    case 1//(x,y)
//       finish = Point(origin.getX(), origin.getY())
//       start = (getCurrentX, getCurrentY());
//       DrawLine(start,finish)
//       
//    case 2//(x + 0.25sgr),y))
//    
//    case 3//(x + 0.5sgr),y))
//    
//    case 4//(x + 0.75sgr),y))
//    
//    case 5//(x + 1sgr),y))
//    
//    return finish
//}


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
