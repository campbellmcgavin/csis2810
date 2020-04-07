#include "Arduino.h"
#include "Point.h"

Point::Point(int pointX, int pointY)
{
  this -> pointX = pointX;
  this -> pointY = pointY;
}

int Point::getX()
{
  return pointX;
}

int Point::getY()
{
  return pointY;
}
