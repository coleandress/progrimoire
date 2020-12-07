#include <stdio.h>
#include <math.h>

int main()
{
   /*
   **   Given a quadratic equation:
   **
   **      ax^2 + bx + c
   **
   **   Use the quadratic formula to find the values of 'x'
   **
   **      x = -b +/- sqrt(b^2 - 4 * a * c)
   **          ----------------------------
   **                       2a
   ** 
   */

   double a = 2.0;
   double b = 3.0;
   double c = 1.0;

   double discriminant = b * b - 4 * a * c;

   if(discriminant < 0.0)
   {
      printf("Cannot proceed, discriminant is negative\n");
   }
   else
   {
      double sd   = sqrt(discriminant);
      double twoA = 2 * a;

      double x1 = (-b + sd) / twoA;
      double x2 = (-b - sd) / twoA;

      printf("Roots of %fx^2 + %fx + %f are: %f and %f\n", a, b, c, x1, x2);
   }

   return(0);
}
