String requestString()
{
  String scribeString;
  while (Serial.available()>0)  
  { 
    Serial.read();
  }
  Serial.print("Enter text to be printed: ");
  while (Serial.available()==0); // do nothing until you receive input.
  while (Serial.available()>0)  
  { // Check if values are available in the Serial Buffer
  scribeString = Serial.readString();
  Serial.println(scribeString);
  }
  return scribeString;  // return variable
}

Point requestPoint()
{
  int x;
  int y;
    while (Serial.available()>0)  
  { 
    Serial.read();
  }
  Serial.print("Enter an x coordinate: ");
  while (Serial.available()==0); // do nothing until you receive input.
  while (Serial.available()>0)  { // Check if values are available in the Serial Buffer
  x = Serial.parseInt();
  Serial.println(x);
  }

  Serial.print("Enter a  y coordinate: ");
  while (Serial.available()==0); // do nothing until you receive input.
  while (Serial.available()>0)  { // Check if values are available in the Serial Buffer
  y = Serial.parseInt();
  Serial.println(y);
  }
  Point point(x,y);
  return point;  // return variable
}

void MainMenu()
{
  char command;
  Serial.print("Main Menu:\nGo To Point (p)\nWrite String (s)\nGo Home (h)... ");
  while (Serial.available()==0); // do nothing until you receive input.
  while (Serial.available()>0)  
  { // Check if values are available in the Serial Buffer
  command = Serial.read();
  }
  Serial.println(command);
  if(command == 's')
  {
    String userInput = requestString();
    
  }
  if(command == 'p') 
  {
    Point point = requestPoint();
  }
  if(command == 'h') 
  {
    goHome();
  }
  
}
