#include <stdio.h>
#include <math.h>

int main()
{
   const double PI = 3.14159265358979323846;
   const int VALUE = -12345;

   printf("The square root of: %f is: %f\n", 64.0, sqrt(64.0));
   printf("The sin of: %f is: %f\n", PI, sin(PI));
   printf("The cos of: %f is: %f\n", PI, cos(PI));
   printf("The natural log of: %f is: %f\n", 2.0, log(2.0));
   printf("The log base 10 of: %f is: %f\n", 1000.0, log10(1000.0));
   printf("The value of: exp(%f) is: %f\n", 1.0, exp(1.0));
   printf("The value of: %f^%f is: %f\n", 2.0, 3.0, pow(2.0, 3.0));
   printf("The absolute value of: %d is: %d\n", VALUE, abs(VALUE));

   return(0);
}
