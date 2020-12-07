#include <stdio.h>
#include <math.h>

int main()
{
   double x1 = 0.0;
   double y1 = 0.0;

   double x2 = 4.0;
   double y2 = 3.0;

   double x3 = 4.0;
   double y3 = 0.0;

   /* -- Find the length of each side using the distance formula -- */

   double a = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
   double b = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
   double c = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));

   /* -- Calculate the "semi-perimeter" of this triangle -- */

   double s = (a + b + c) / 2;

   /* -- Now, find its area -- */

   double area = sqrt(s * (s - a) * (s - b) * (s - c));

   printf("Triangle: (%f, %f) (%f, %f) (%f, %f) has area: %f\n", x1, y1, x2, y2, x3, y3, area);

   return(0);
}
