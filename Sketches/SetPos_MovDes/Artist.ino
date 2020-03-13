class Artist
{
  private: 

  public:
  Artist();
  void MovePencil();
  void UseRuler();
  void UseCompass();
  void DrawCircle();
  void DrawLine();
  bool ThereYet();
  
  
};

bool Artist:: ThereYet
{
  if(x_move_finished && y_move_finished) return true;
  return false;
}

void Artist::DrawLine(Point start, Point finish)
{
  UseRuler(start, finish);
  while(!ThereYet)
  {
    MovePencil();
  }
}

void Artist::DrawCircle(Point start, Point finish, bool clockwise, )
{

  while(!ThereYet)
  {
    //UseCompass(start, finish);
    //MovePencil();
  }
}

void UseRuler(Point start, Point finish)
{
  // HELP set speed of motors according to dimensions of a triangle...
}

void UseCompass(Point radius, Point xxx)
{
  // HELP set speed of motors according to location in arc of circle...
}



void Artist::MovePencil()
{

    if (x_travel >= 0 && x_travel <= bedSize) {

     // DEBUGGING STATEMENTS
     Serial.print("X, Y: ");
     Serial.print(x_stepper.distanceToGo() + ", " y_stepper.distanceToGo());
     
     // Check if the Stepper has reached desired position
     if ((x_stepper.distanceToGo() != 0)) {
      x_stepper.run();  // Move Stepper into position
     }
     if ((y_stepper.distanceToGo() != 0)) {
      y_stepper.run();  // Move Stepper into position
     }
  
  // If move is completed display message on Serial Monitor
    if ((x_move_finished == 0) && (x_stepper.distanceToGo() == 0)) {
      x_move_finished=1;  // Reset move variable
    }
    if ((y_move_finished == 0) && (y_stepper.distanceToGo() == 0)) {
      y_move_finished=1;  // Reset move variable
    }
    }

}
