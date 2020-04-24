
String requestString()
{
  String scribeStringScale;
  String scribeString;
//  while (Serial.available()>0)  
//  { 
//    Serial.read();
//  }
    Serial.print("Enter scale/size: ");
    while (Serial.available()==0); // do nothing until you receive input.
    while (Serial.available()>0)  
    { // Check if values are available in the Serial Buffer
      s = (Serial.read()-48) * 500;
      Serial.println(s);
     
      sgr = s/1.618;
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

/**
 * Store the length of input strings for use in newLine calculations.
 * 
 */
void setPrevStringLength(String input)
{
   if(stringAlternator)
   {
       inputStringLengthA = input.length();
   }
   else
   {
     inputStringLengthB = input.length();  
   }
   stringAlternator = !stringAlternator;      
}
/**
 * Reads the length of input strings for use in newLine calculations.
 * 
 */
int readPrevStringLength(bool previousString)
{
   if(previousString)
   {
      if(!stringAlternator)
        return inputStringLengthA;
      else
        return inputStringLengthB;
   }
   else
   {
     if(stringAlternator)
        return inputStringLengthA;
      else
        return inputStringLengthB;    
   }  
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
  while (Serial.available()>0)  
  { // Check if values are available in the Serial Buffer
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
void DrawString(String userInput)
{
  
// #input string
 //# loop through letters function
//TODO set scale
  userInput.toUpperCase();
  Serial.println("Scale: ");
  Serial.println(s);
  Serial.println("sgr: ");
  Serial.println(sgr);
  for(int i = 0; i < userInput.length(); i++)
  {
    Serial.print("i: ");
    Serial.println(i);
    
    Serial.print("char at i: ");
    Serial.println(userInput.charAt(i));
//    while(Serial.available() ==0){}
//    Serial.read();
   
    switch(userInput.charAt(i))
    {
      case '/':
        if(userInput.charAt(i+1) == 'N')
        {
          i++;
          DrawNewLine();
        }
        else DrawForwardSlash();
        break;
      case 'A':
          DrawA();
        break;   
      case 'B':
          DrawB();
        break;
      case 'C':
          DrawC();
        break;
      case 'D':
          DrawD();
        break;
      case 'E':
          DrawE();
        break;
      case 'F':
          DrawF();
        break;
      case 'G':
          DrawG();
        break;
      case 'H':
          DrawH();
        break;
      case 'I':
          DrawI();
        break;
      case 'J': 
          DrawJ();
        break;
      case 'K': 
          DrawK();
        break;
      case 'L': 
          DrawL();
        break;
      case 'M': 
          DrawM();
        break;
      case 'N': 
          DrawN();
        break;
      case 'O': 
          DrawO();
        break;
      case 'P': 
          DrawP();
        break;
      case 'Q': 
          DrawQ();
        break;
      case 'R': 
          DrawR();
        break;
      case 'S': 
          DrawS();
        break;
      case 'T': 
          DrawT();
        break;
      case 'U': 
          DrawU();
        break;
      case 'V': 
          DrawV();
        break;
      case 'W':
          DrawW();
        break;
      case 'X':
          DrawX();
        break;
      case 'Y':
          DrawY();
        break;
      case 'Z':
          DrawZ();
        break;
      case ' ':
          DrawSpace();
        break;
      case '1':
          Draw1();
        break;
      case '2':
          Draw2();
        break;
      case '3':
          Draw3();
        break;
      case '4':
          Draw4();
        break;
      case '5':
          Draw5();
        break;
      case '6':
          Draw6();
        break;
      case '7':
          Draw7();
        break;
      case '8':
          Draw8();
        break;
      case '9':
          Draw9();
        break;
      default:
        //ERROR
        break;
    }
    ZeroOutPosition();
  }
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
    x_stepper.setCurrentPosition(0);
    y_stepper.setCurrentPosition(0);
    String userInput = requestString(); 
    DrawString(userInput);
  }
  if(command == 'p') 
  {
    Point p_start(x_stepper.currentPosition(), y_stepper.currentPosition());
    Point p_end = requestPoint();
    DrawLine(p_start, p_end, false);
  }
  if(command == 'h') 
  {
    goHome();
  }
  if(command == 'x')
  {
    x_stepper.move(-4000);
    while(!xThereYet())
      x_stepper.run();
  }
  if(command == 'w')
  {
    x_stepper.move(4000);
    while(!xThereYet())
      x_stepper.run();
  }
  if(command == 'd')
  {
    y_stepper.move(-4000);
    while(!yThereYet())
      y_stepper.run();
       
  }if(command == 'a')
  {
    
    y_stepper.move(4000);
    while(!yThereYet())
      y_stepper.run();
  }
  
}
