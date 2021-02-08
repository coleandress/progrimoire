#include <stdio.h>

typedef struct
{
   int mX;
   int mY;

} Point;

Point makePoint(int x, int y)
{
   Point p = { 0 };

   p.mX = x;
   p.mY = y;

   return(p);
}

int main()
{
   const Point p = makePoint(0, 1);

   /*p.mX++;*/

   return(0);
}
