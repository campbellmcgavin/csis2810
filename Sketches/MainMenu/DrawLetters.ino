/**
 * Contains methods for drawing basic A-Z, 0-9, newLine, and ' '(space) characters 
 * on a two dimensional plane of 25 point coordinates.
 * 
 * All coordinates are in reference to an "origin" point 0, the first point is the 0 point of the previous character plane.
 * Once point 0 is updated it moves to the next character plane becoming the point '1' for the next character.
 */

void DrawA()
{
  LetterLines(1, 21, false);
  LetterLines(21, 3, true);  
  LetterLines(3, 25, true);
  LetterLines(25, 14, true);     
  LetterLines(14, 12, true);
  LetterLines(12, 2, true);
  LetterLines(2, 0, false);   
     
  origin =  UpdateCoordinates(0);   
}
void DrawB()
{
  LetterLines(1, 21, true);
  LetterLines(21, 24, true);  
  LetterLines(24, 20, true);
  LetterLines(20, 14, true);     
  LetterLines(14, 11, true);
  LetterLines(11, 14, false);
  LetterLines(14, 10, true);
  LetterLines(10, 4, true);
  LetterLines(4, 1, true);
  LetterLines(1, 0, false);   
      
  origin =  UpdateCoordinates(0);
}
void DrawC()
{
  LetterLines(1, 20, false);
  LetterLines(20, 24, true);  
  LetterLines(24, 22, true);
  LetterLines(22, 16, true);     
  LetterLines(16, 6, true);
  LetterLines(6, 2, true);
  LetterLines(2, 4, true);
  LetterLines(4, 10, true);
  LetterLines(10, 0, false);   
      
  origin =  UpdateCoordinates(0);
}
void DrawD()
{
  LetterLines(1, 21, true);
  LetterLines(21, 24, true);  
  LetterLines(24, 20, true);
  LetterLines(20, 10, true);     
  LetterLines(10, 4, true);
  LetterLines(4, 1, true);
  LetterLines(1, 0, false);   
      
  origin =  UpdateCoordinates(0);
}
void DrawE()
{
  LetterLines(1, 21, false);
  LetterLines(21, 25, false);
  LetterLines(25, 21, true);  
  LetterLines(21, 11, true);
  LetterLines(11, 13, true);     
  LetterLines(13, 11, false);
  LetterLines(11, 1, true);
  LetterLines(1, 5, true);   
  LetterLines(5, 0, false);
    
  origin =  UpdateCoordinates(0);
}
void DrawF()
{
//  Serial.println("Draw F");
  LetterLines(1, 21, true);
//  Serial.println("1 21");
//  while(Serial.available() ==0){}
//  Serial.read();
  LetterLines(21, 11, true);  
//  Serial.println("21 11");
//  while(Serial.available() ==0){}
//  Serial.read();
  LetterLines(11, 13, true);
//  Serial.println("11 13");
//  while(Serial.available() ==0){}
//  Serial.read();
  LetterLines(13, 11, false);
//  Serial.println("13 11");  
//  while(Serial.available() ==0){}   
//  Serial.read();
  LetterLines(11, 1, true);
//  Serial.println("11 1");
//  Serial.read();
//  while(Serial.available() ==0){}
  LetterLines(1, 5, true); 
//  Serial.println("1 5");  
//  Serial.read();
//  while(Serial.available() ==0){}
  LetterLines(5, 0, false);
       
  origin =  UpdateCoordinates(0);
}
void DrawG()
{
  LetterLines(1, 4, true);
  LetterLines(4, 10, true);
  LetterLines(10, 4, true);
  LetterLines(4, 2, true);
  LetterLines(2, 6, true);
  LetterLines(6, 16, true);
  LetterLines(16, 22, true);
  LetterLines(22, 24, true);
  LetterLines(24, 20, true);
  LetterLines(20, 15, true);
  LetterLines(15, 13, true);
  LetterLines(13, 15, true);  
  LetterLines(15, 0, true); 
         
  origin =  UpdateCoordinates(0);
}
void DrawH()
{
  LetterLines(1, 21, true);
  LetterLines(21, 11, false);  
  LetterLines(11, 15, true);
  LetterLines(15, 25, false);     
  LetterLines(25, 5, true);
  LetterLines(5, 0, false);   
      
  origin =  UpdateCoordinates(0);
}
void DrawI()
{
  LetterLines(1, 21, false);
  LetterLines(21, 25, true);  
  LetterLines(25, 23, false);
  LetterLines(23, 3, true);     
  LetterLines(3, 1, false);
  LetterLines(1, 5, true);
  LetterLines(5, 0, false);   
      
  origin =  UpdateCoordinates(0);
}

void DrawJ()
{
  LetterLines(1, 5, true);
  LetterLines(5, 3, false);
  LetterLines(3, 23, true);
  LetterLines(23, 22, true);
  LetterLines(22, 16, true);
  LetterLines(16, 22, true);
  LetterLines(22, 23, true);
  LetterLines(23, 3, true);
  LetterLines(3, 0, true);  
      
  origin =  UpdateCoordinates(0);
}
void DrawK()
{
  LetterLines(1, 21, true);
  LetterLines(21, 11, false);
  LetterLines(11, 13, true);
  LetterLines(13, 25, true);
  LetterLines(25, 13, true);
  LetterLines(13, 5, true);
  LetterLines(5, 0, true);  
     
origin =  UpdateCoordinates(0);
}
void DrawL()
{
  LetterLines(1, 21, true);
  LetterLines(21, 25, true);
  LetterLines(25, 0, true);  
        
  origin =  UpdateCoordinates(0);
}
void DrawM()
{
  LetterLines(1, 21, false);
  LetterLines(21, 6, true);
  LetterLines(6, 2, true);
  LetterLines(2, 8, true);
  LetterLines(8,13, true);
  LetterLines(13,8, true);
  LetterLines(8,4, true);
  LetterLines(4,10, true);
  LetterLines(10,25, true);
  LetterLines(25, 0, true);  
        
  origin =  UpdateCoordinates(0);
}
void DrawN()
{
  LetterLines(1, 21, false);
  LetterLines(21, 1, true);
  LetterLines(1, 25, true);
  LetterLines(25, 5, true);
  LetterLines(5, 0, true);  
        
  origin =  UpdateCoordinates(0);   
}
void DrawO()
{
  LetterLines(1, 2, false);
  LetterLines(2, 6, true);
  LetterLines(6, 16, true);
  LetterLines(16, 22, true);
  LetterLines(22, 24, true);
  LetterLines(24, 20, true);
  LetterLines(20, 10, true);
  LetterLines(10, 4, true);
  LetterLines(4, 2, true);
  LetterLines(2, 0, true);  
        
  origin =  UpdateCoordinates(0);   
}
void DrawP()
{
  LetterLines(1, 21, true);
  LetterLines(21, 11, true);
  LetterLines(11, 14, true);
  LetterLines(14, 10, true);
  LetterLines(10, 4, true);
  LetterLines(4, 1, true);
  LetterLines(1, 0, true);  
        
  origin =  UpdateCoordinates(0);   
}
void DrawQ()
{
  LetterLines(1, 2, false);
  LetterLines(2, 6, true);
  LetterLines(6, 16, true);
  LetterLines(16, 22, true);
  LetterLines(22, 24, true);
  LetterLines(24, 20, true);
  LetterLines(20, 19, true);
  LetterLines(19, 25, true);
  LetterLines(25, 19, true);
  LetterLines(19, 20, true);
  LetterLines(20, 10, true);
  LetterLines(10, 4, true);
  LetterLines(4, 2, true);
  LetterLines(2, 0, true);  
        
  origin =  UpdateCoordinates(0);   
}

void DrawR()
{
   LetterLines(1, 21, true);
   LetterLines(21, 11, false);
   LetterLines(11, 13, true);
   LetterLines(13, 25, true);
   LetterLines(25, 13, true);
   LetterLines(13, 14, true);
   LetterLines(14, 10, true);
   LetterLines(10, 4, true);
   LetterLines(4, 1, true);
   LetterLines(1, 0, true);  
          
   origin =  UpdateCoordinates(0);    
}


void DrawS()
{
  LetterLines(1, 4, true);  
  LetterLines(4, 10, true);
  LetterLines(10, 4, true);  
  LetterLines(4, 2, true);
  LetterLines(2, 6, true);     
  LetterLines(6, 12, true);
  LetterLines(12, 14, true);   
  LetterLines(14, 20, true);
  LetterLines(20, 24, true);
  LetterLines(24, 21, true);
  LetterLines(21, 16, true);
  LetterLines(16, 21, true);
  LetterLines(21, 24, true);
  LetterLines(24, 20, true);
  LetterLines(20, 0, true);  
        
  origin =  UpdateCoordinates(0);   
}

void DrawT()
{
  LetterLines(1, 3, true);
  LetterLines(3, 23, false);  
  LetterLines(23, 3, true);
  LetterLines(3, 0, true);  
        
  origin =  UpdateCoordinates(0);   
}


void DrawU()
{
  LetterLines(1, 16, true);
  LetterLines(16, 22, true);  
  LetterLines(22, 24, true);
  LetterLines(24, 20, true);
  LetterLines(20, 5, true);
  LetterLines(5, 0, true);  
        
  origin =  UpdateCoordinates(0);   
}


void DrawV()
{
  LetterLines(1, 23, true);
  LetterLines(23, 5, true); 
  LetterLines(5, 0, true);  
         
  origin =  UpdateCoordinates(0);   
}

void DrawW()
{
  LetterLines(1, 22, true);
  LetterLines(22, 13, true);  
  LetterLines(13, 24, true);
  LetterLines(24, 5, true);
  LetterLines(5, 0, true);  
        
  origin =  UpdateCoordinates(0);   
}

void DrawX()
{
  LetterLines(1, 25, true);
  LetterLines(25, 13, false);  
  LetterLines(13, 21, true);
  LetterLines(21, 5, true);
  LetterLines(5, 0, true);  
        
  origin =  UpdateCoordinates(0);   
}

void DrawY()
{
  LetterLines(1, 13, true);
  LetterLines(13, 23, true);  
  LetterLines(23, 13, false);
  LetterLines(13, 5, true);
  LetterLines(5, 0, true);  
        
  origin =  UpdateCoordinates(0);   
}

void DrawZ()
{
  LetterLines(1, 5, true);
  LetterLines(5, 21, true);  
  LetterLines(21, 25, false);
  LetterLines(25, 21, true);
  LetterLines(21, 5, true);
  LetterLines(5, 0, true);      
       
  origin =  UpdateCoordinates(0);   
}
void DrawSpace()
{
  LetterLines(1, 0, true);
   
  origin = UpdateCoordinates(0);   
}
void Draw0()
{
  LetterLines(1, 2, false);
  LetterLines(2, 6, true);
  LetterLines(6, 16, true);
  LetterLines(16, 22, true);
  LetterLines(22, 24, true);
  LetterLines(24, 20, true);
  LetterLines(20, 10, true);
  LetterLines(10, 4, true);
  LetterLines(4, 22, true);
  LetterLines(22, 4, true);
  LetterLines(4, 2, true);
  LetterLines(2, 0, true); 
         
  origin =  UpdateCoordinates(0);  
}
void Draw1()
{
  LetterLines(1, 7, true);
  LetterLines(7, 3, true);
  LetterLines(3, 23, true);
  LetterLines(23, 21, true);
  LetterLines(21, 25, true);
  LetterLines(25, 0, true);  
        
  origin =  UpdateCoordinates(0);  
}
void Draw2()
{
  LetterLines(1, 6, true);
  LetterLines(6, 2, true);
  LetterLines(2, 4, true);
  LetterLines(4, 10, true);
  LetterLines(10, 21, true);
  LetterLines(21, 25, true);
  LetterLines(25, 0, true); 
         
  origin =  UpdateCoordinates(0);  
}
void Draw3()
{
  LetterLines(1, 6, true);
  LetterLines(6, 2, true);
  LetterLines(2, 4, true);
  LetterLines(4, 10, true);
  LetterLines(10, 14, true);
  LetterLines(14, 13, true);
  LetterLines(13, 14, true);
  LetterLines(14, 20, true);
  LetterLines(20, 24, true);
  LetterLines(24, 22, true);
  LetterLines(22, 16, true);
  LetterLines(16, 22, true);
  LetterLines(22, 24, true);
  LetterLines(24, 25, true);
  LetterLines(25, 0, true);  
        
  origin =  UpdateCoordinates(0);   
}
void Draw4()
{
  LetterLines(1, 11, true);
  LetterLines(11, 15, true);
  LetterLines(15, 14, true);
  LetterLines(14, 24, true);
  LetterLines(24, 4, true);
  LetterLines(4, 0, true);  
        
  origin =  UpdateCoordinates(0);   
}
void Draw5()
{
  LetterLines(1, 5, true);
  LetterLines(5, 1, true);
  LetterLines(1, 11, true);
  LetterLines(11, 14, true);
  LetterLines(14, 20, true);
  LetterLines(20, 24, true);
  LetterLines(24, 22, true);
  LetterLines(22, 16, true);
  LetterLines(16, 22, true);
  LetterLines(22, 24, true);
  LetterLines(24, 25, true);
  LetterLines(25, 0, true);  
        
  origin =  UpdateCoordinates(0);   
}
void Draw6()
{
  LetterLines(1, 11, true);
  LetterLines(11, 14, true);
  LetterLines(14, 20, true);
  LetterLines(20, 24, true);
  LetterLines(24, 22, true);
  LetterLines(22, 16, true);
  LetterLines(16, 6, true);
  LetterLines(6, 2, true);
  LetterLines(2, 4, true);
  LetterLines(4, 10, true);
  LetterLines(10, 0, true);  
       
  origin =  UpdateCoordinates(0);   
}
void Draw7()
{
  LetterLines(1, 5, true);
  LetterLines(5, 21, true);
  LetterLines(21, 13, true);
  LetterLines(13, 12, true);
  LetterLines(12, 14, true);
  LetterLines(14, 13, true);
  LetterLines(13, 5, true);
  LetterLines(5, 0, true);  
        
  origin =  UpdateCoordinates(0);   
}
void Draw8()
{
  LetterLines(1, 2, true);
  LetterLines(2, 6, true);
  LetterLines(6, 12, true);
  LetterLines(12, 14, true);
  LetterLines(14, 20, true);
  LetterLines(20, 24, true);
  LetterLines(24, 22, true);
  LetterLines(22, 16, true);
  LetterLines(16, 12, true);
  LetterLines(12, 14, true);
  LetterLines(14, 10, true);
  LetterLines(10, 2, true);
  LetterLines(2, 0, true);  
        
  origin =  UpdateCoordinates(0);   
}
void Draw9()
{
  LetterLines(1, 2, true);
  LetterLines(2, 6, true);
  LetterLines(6, 12, true);
  LetterLines(12, 14, true);
  LetterLines(14, 10, true);
  LetterLines(10, 20, true);
  LetterLines(20, 24, true);
  LetterLines(24, 22, true);
  LetterLines(22, 16, true);
  LetterLines(16, 22, true);
  LetterLines(22, 24, true);
  LetterLines(24, 20, true);
  LetterLines(20, 10, true);
  LetterLines(10, 4, true);
  LetterLines(4, 2, true);
  LetterLines(2, 0, true);  
        
  origin =  UpdateCoordinates(0);   
}
void DrawForwardSlash()
{
  LetterLines(1, 5, false);
  LetterLines(5, 21, true);
  LetterLines(21, 5, false);
  LetterLines(5, 0, true);  
        
  origin =  UpdateCoordinates(0);   
}
void DrawNewLine()
{
  double xOffset = readPrevStringLength(true);
  xOffset += 0.25;
  xOffset *= sgr;
  Point newPointA(origin.getX(), origin.getY() + 1.5 * s);
  DrawLine(origin, newPointA, false);
  Point newPointB(newPointA.getX() + xOffset, newPointA.getY());
  DrawLine(newPointA, newPointB, false);
  Point newPointC(newPointB.getX(), newPointB.getY() + 0.5 * s);
  DrawLine(newPointB, newPointA, false);
  origin = newPointA;
    
  //keep track of how many characters

  //move down 1+ 1/2 plane
  //move to beginning
  //move down 1/2 plane 
  //done
}
