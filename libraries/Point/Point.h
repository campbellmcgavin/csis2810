#include "Arduino.h"

#ifndef point_h
#define point_h


class Point
{

  private:
  int pointX;
  int pointY;
  
  public:
  Point(int pointX, int pointY);
  int getX();
  int getY();


  
};



#endif
