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
