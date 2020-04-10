DrawA()
{
  DrawLine(pointArray[1] , pointArray[21], false);
  DrawLine(pointArray[21], pointArray[2] , true);  
  DrawLine(pointArray[2] , pointArray[25], true);
  DrawLine(pointArray[25], pointArray[14], true);
  DrawLine(pointArray[14], pointArray[12], true);
  DrawLine(pointArray[12], pointArray[0]  , false);   

  origin = pointArray[0];
}
