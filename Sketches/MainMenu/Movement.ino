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
  Serial.print("Drawing: ");
  Serial.print(start);
  Serial.print(",");
  Serial.println(finish);
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
void ZeroOutPosition()
{
  x_stepper.setCurrentPosition(0);
  y_stepper.setCurrentPosition(0); 
  origin = Point(0,0);
}

/**
 * Used to update only the points we need rather than having to redo the Point array.
 * @param point - the desired point to update.
 * @return the updated Point.
 */
Point UpdateCoordinates(int point)
{ 
  Point updatedPoint = Point(0,0);
  switch(point)
  {
      case 0:
          updatedPoint = Point(origin.getX() - 1.25 * sgr, origin.getY());
        break;
      case 1:
          updatedPoint = Point(origin.getX(), origin.getY());
        break; 
      case 2:
          updatedPoint = Point(origin.getX() - 0.25 * sgr, origin.getY());
        break; 
      case 3:
          updatedPoint = Point(origin.getX() - 0.5 * sgr,origin.getY());
        break; 
      case 4:
          updatedPoint = Point(origin.getX() - 0.75 * sgr, origin.getY());
        break; 
      case 5:
          updatedPoint = Point(origin.getX() - sgr, origin.getY());
        break; 
      case 6:
          updatedPoint = Point(origin.getX(), origin.getY() + 0.25 * s);
        break; 
      case 7:
          updatedPoint = Point(origin.getX() - 0.25 * sgr, origin.getY() + 0.25 * s);
        break; 
      case 8:        
          updatedPoint = Point(origin.getX() - 0.5 * sgr, origin.getY() + 0.25 * s);
        break; 
      case 9:       
          updatedPoint = Point(origin.getX() - 0.75 * sgr, origin.getY() + 0.25 * s);   
        break; 
      case 10:
          updatedPoint = Point(origin.getX() - sgr, origin.getY() + 0.25 * s);     
        break; 
      case 11:
          updatedPoint = Point(origin.getX(), origin.getY() + 0.5 * s);  
        break; 
      case 12:
          updatedPoint = Point(origin.getX() - 0.25 * sgr, origin.getY() + 0.5 * s);
        break; 
      case 13:
           updatedPoint = Point(origin.getX() - 0.5 * sgr, origin.getY() + 0.5 * s);
        break; 
      case 14:
           updatedPoint = Point(origin.getX() - sgr, origin.getY() + 0.5 * s);
        break;
      case 15:
           updatedPoint = Point(origin.getX() - 0.75 * sgr, origin.getY() + 0.5 * s);
        break;
      case 16:
           updatedPoint = Point(origin.getX(), origin.getY() + 0.75 * s);
        break;
      case 17:
           updatedPoint = Point(origin.getX() - 0.25 * sgr, origin.getY() + 0.75 * s);  
        break;
      case 18:
          updatedPoint = Point(origin.getX() - 0.5 * sgr, origin.getY() + 0.75 * s);
        break;
      case 19:
          updatedPoint = Point(origin.getX() - 0.75 * sgr, origin.getY() + 0.75 * s);
        break;
      case 20:
           updatedPoint = Point(origin.getX() - sgr, origin.getY() + 0.75 * s);
        break;
      case 21:
           updatedPoint = Point(origin.getX() , origin.getY() + s);
        break;
      case 22:
           updatedPoint = Point(origin.getX() - 0.25 * sgr, origin.getY() + s);
        break;
      case 23:
           updatedPoint = Point(origin.getX() - 0.5 * sgr, origin.getY() + s);
        break;
      case 24:
           updatedPoint = Point(origin.getX() - 0.75 * sgr, origin.getY() + s);
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

//TODO figure out which direction is which and adjust directions accordingly
void QuickBoundaries(bool home)
{
  
  if(home)
  {
    Serial.print("Stepper is Homing . . . . . . . . . . . ");

    //  Set Max Speed and Acceleration of each Steppers at startup for homing
    x_stepper.setMaxSpeed(maxSpeed*10);      // Set Max Speed of Stepper (Slower to get better accuracy)
    x_stepper.setAcceleration(1000.0);  // Set Acceleration of Stepper
    y_stepper.setMaxSpeed(maxSpeed*10);      // Set Max Speed of Stepper (Slower to get better accuracy)
    y_stepper.setAcceleration(1000.0);  // Set Acceleration of Stepper
    
    while (digitalRead(x_switchHome) || digitalRead(y_switchHome))  
    {  // Make the Stepper move CCW until the switch is activated
     if(digitalRead(x_switchHome))
      {
        x_stepper.moveTo(x_initial_homing);  // Set the position to move to
        x_initial_homing-=10;  // Decrease by 1 for next move if needed
        x_stepper.run();  // Start moving the stepper
        delay(5);
      }
      
      
      if(digitalRead(y_switchHome))
      {
        y_stepper.moveTo(y_initial_homing);  // Set the position to move to
        y_initial_homing-=10;  // Decrease by 1 for next move if needed
        y_stepper.run();  // Start moving the stepper
        delay(5);
      }
    }
     
    x_stepper.setCurrentPosition(0);    // Set the current position as zero for now
    x_stepper.setMaxSpeed(1);      // Set Max Speed of Stepper (Slower to get better accuracy)
    x_stepper.setAcceleration(maxAccel);  // Set Acceleration of Stepper
    x_initial_homing = 1;
  
    y_stepper.setCurrentPosition(0);  // Set the current position as zero for now
    y_stepper.setMaxSpeed(1);      // Set Max Speed of Stepper (Slower to get better accuracy)
    y_stepper.setAcceleration(maxAccel);  // Set Acceleration of Stepper
    y_initial_homing = 1;
  
  
  
  //lazily moves to a coordinate x_initialHoming duuuuuuhhhhh
    while (!digitalRead(x_switchHome) || !digitalRead(y_switchHome)) { // Make the Stepper move CW until the switch is deactivated
      
      if(!digitalRead(x_switchHome))
      {
        x_stepper.moveTo(x_initial_homing);
        x_stepper.run();
        x_initial_homing++;
        delay(5);
      }
      if(!digitalRead(y_switchHome))
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
  
    
  }
  else
  {
    long x_maxDist = 0;
    long y_maxDist = 0;
    Serial.print("Stepper is going beyond! . . . . . . . . . . . ");

    //  Set Max Speed and Acceleration of each Steppers at startup for homing
    x_stepper.setMaxSpeed(maxSpeed*10);      // Set Max Speed of Stepper (Slower to get better accuracy)
    x_stepper.setAcceleration(1000.0);  // Set Acceleration of Stepper
    y_stepper.setMaxSpeed(maxSpeed*10);      // Set Max Speed of Stepper (Slower to get better accuracy)
    y_stepper.setAcceleration(1000.0);  // Set Acceleration of Stepper
    
    while (digitalRead(x_switchMax) || digitalRead(y_switchMax))  
    {  // Make the Stepper move CCW until the switch is activated
     if(digitalRead(x_switchMax))
      {
        x_stepper.moveTo(x_initial_homing);  // Set the position to move to
        x_initial_homing-=10;  // Decrease by 1 for next move if needed
        x_stepper.run();  // Start moving the stepper
        x_maxDist++;
        delay(5);
      }
      
      
      if(digitalRead(y_switchMax))
      {
        y_stepper.moveTo(-y_initial_homing);  // Set the position to move to
        y_initial_homing-=10;  // Decrease by 1 for next move if needed
        y_stepper.run();  // Start moving the stepper
        y_maxDist++;
        delay(5);
      }
    }
     
    x_stepper.setCurrentPosition(x_maxDist);    // Set the current position as zero for now
    x_stepper.setMaxSpeed(1);      // Set Max Speed of Stepper (Slower to get better accuracy)
    x_stepper.setAcceleration(maxAccel);  // Set Acceleration of Stepper
    x_initial_homing = 1;
  
    y_stepper.setCurrentPosition(y_maxDist);  // Set the current position as zero for now
    y_stepper.setMaxSpeed(1);      // Set Max Speed of Stepper (Slower to get better accuracy)
    y_stepper.setAcceleration(maxAccel);  // Set Acceleration of Stepper
    y_initial_homing = 1;
  
  
  
  //lazily moves to a coordinate x_initialHoming duuuuuuhhhhh
    while (!digitalRead(x_switchHome) || !digitalRead(y_switchHome)) { // Make the Stepper move CW until the switch is deactivated
      
      if(!digitalRead(x_switchHome))
      {
        x_stepper.moveTo(x_initial_homing);
        x_stepper.run();
        x_initial_homing++;
        x_maxDist++;
        delay(5);
      }
      if(!digitalRead(y_switchHome))
      {
        y_stepper.moveTo(y_initial_homing);
        y_stepper.run();
        y_initial_homing++;
        y_maxDist++;
        delay(5);
      }
    }
  
  
    x_stepper.setCurrentPosition(x_maxDist);
    Serial.println("Homing Completed");
    Serial.println("");
    x_stepper.setMaxSpeed(maxSpeed);      // Set Max Speed of Stepper (Faster for regular movements)
    x_stepper.setAcceleration(maxAccel);  // Set Acceleration of Stepper
  
    y_stepper.setCurrentPosition(y_maxDist);
    Serial.println("Homing Completed");
    Serial.println("");
    y_stepper.setMaxSpeed(maxSpeed);      // Set Max Speed of Stepper (Faster for regular movements)
    y_stepper.setAcceleration(maxAccel);  // Set Acceleration of Stepper
  }

  // Print out Instructions on the Serial Monitor at Start
 // Serial.println("Enter Travel distance (Positive for CW / Negative for CCW and Zero for back to Home): ");

}
void DefineBoundaries()
{
  
  while (digitalRead(x_switchHome) || digitalRead(y_switchHome))  
  {  // Make the Stepper move CCW until the switch is activated
   if(digitalRead(x_switchMax))
    {
      
      x_stepper.moveTo(x_initial_homing);  // Set the position to move to
      x_initial_homing--;  // Decrease by 1 for next move if needed
      x_stepper.run();  // Start moving the stepper
      x_maxDist++;
      delay(5);
    }
    
    
    if(digitalRead(y_switchHome))
    {
      y_stepper.moveTo(y_initial_homing);  // Set the position to move to
      y_initial_homing--;  // Decrease by 1 for next move if needed
      y_stepper.run();  // Start moving the stepper
      y_maxDist++;
      delay(5);
    }
  }
  while (!digitalRead(x_switchMax) || !digitalRead(y_switchMax)) { // Make the Stepper move CW until the switch is deactivated
    
    if(!digitalRead(x_switchMax))
    {
      x_stepper.moveTo(x_initial_homing);
      x_stepper.run();
      x_initial_homing++;
      x_maxDist--;
      delay(5);
    }
    if(!digitalRead(y_switchMax))
    {
      y_stepper.moveTo(y_initial_homing);
      y_stepper.run();
      y_initial_homing++;
      y_maxDist--;
      delay(5);
    }
  }
}
