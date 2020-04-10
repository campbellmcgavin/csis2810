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
ReadString(String userInput)(
// #input string
 //# loop through letters function

  
  for(int i = 0, i < userInput.length, i++)
  {
    switch userInput.charAt[i]:
      case 'A':
        
      break;   
      case 'B':break;
      
      case 'C':break;
      case 'D':break;
      case 'E':break;
      case 'F':break;
      case 'G':break;
      case 'H':break;
      case 'I':break;
      case 'J':break;
      case 'K':break;
      case 'L':break;
      case 'M':break;
      case 'N':break;
      case 'O':break;
      case 'P':break;
      case 'Q':break;
      case 'R':break;
      case 'S':break;
      case 'T':break;
      case 'U':break;
      case 'V':break;
      case 'W':break;
      case 'X':break;
      case 'Y':break;
      case 'Z':
      
      break;
      default:
        //ERROR
      return finish
   }
{

 DrawLetter(UserInput(i)
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
    ReadString(userInput);
  }
  if(command == 'p') 
  {
    Point p_start(x_stepper.currentPosition(), y_stepper.currentPosition());
    Point p_end = requestPoint();
    DrawLine(p_start, p_end);
  }
  if(command == 'h') 
  {
    goHome();
  }
  
}
