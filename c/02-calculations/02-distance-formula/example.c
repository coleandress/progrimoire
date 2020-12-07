#include <stdio.h>
#include <math.h>

static double getDistance(double x1, double y1, double x2, double y2)
{
   return(sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

int main()
{
   double x1 = 0.0;
   double y1 = 0.0;

   double x2 = 4.0;
   double y2 = 3.0;

   double distance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

   printf("Distance from: (%f, %f) to: (%f, %f) is: %f\n", x1, y1, x2, y2, distance);

   double xDelta = (x2 - x1);
   double yDelta = (y2 - y1);

   distance = sqrt(xDelta * xDelta + yDelta * yDelta);

   printf("Distance from: (%f, %f) to: (%f, %f) is: %f\n", x1, y1, x2, y2, distance);

   printf("Distance from: (%f, %f) to: (%f, %f) is: %f\n", x1, y1, x2, y2, getDistance(x1, y1, x2, y2));

   return(0);
}
