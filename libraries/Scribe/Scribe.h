#include "Arduino.h"
#include "Point.h"
#ifndef scribe_h
#define scribe_h


class Scribe
{
  String scribeString;
  Point scribePoint;

  public:
  Scribe();
  String requestString();
  Point requestPoint();
};

#endif
