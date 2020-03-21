class Scribe
{
  String scribeString;
  Point scribePoint;
  //Style scribeStyle;

  public:
  Scribe();
  String requestString();
  Point requestPoint();
};


Scribe::Scribe()
{
  this -> scribeString = scribeString;
  this -> scribePoint = scribePoint;
  //this -> scribeStyle = scribeStyle;
}

String Scribe::requestString()
{
  Serial.print("Enter text to be printed: ");
  while (Serial.available()==0); // do nothing until you receive input.
  while (Serial.available()>0)  { // Check if values are available in the Serial Buffer
  scribeString = Serial.readString();
  Serial.println(scribeString);
  }
  return scribeString;  // return variable
}
  

Point Scribe::requestPoint()
{
  int x;
  int y;
  
  Serial.println("Enter an x coordinate: ")
  while (Serial.available()==0); // do nothing until you receive input.
  while (Serial.available()>0)  { // Check if values are available in the Serial Buffer
  x = Serial.parseInt();
  Serial.println(x);
  }

  Serial.println("Enter a  y coordinate: ")
  while (Serial.available()==0); // do nothing until you receive input.
  while (Serial.available()>0)  { // Check if values are available in the Serial Buffer
  y = Serial.parseInt();
  Serial.println(y);
  }
  
  return new Point(x,y);  // return variable
}
