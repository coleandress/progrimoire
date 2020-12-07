#include <stdio.h>

int main()
{
   printf("The size of a double is: %d bytes\n\n", sizeof(double));

   double theDouble = 123.456;

   printf("theDouble: %f\n", theDouble);

   theDouble = 45.1234;

   printf("theDouble: %f\n", theDouble);

   theDouble = 0.123456789;

   printf("theDouble: %f\n", theDouble);

   printf("\n");

   printf("theDouble: %.9f\n", theDouble);
   printf("theDouble: %.8f\n", theDouble);
   printf("theDouble: %.7f\n", theDouble);
   printf("theDouble: %.6f\n", theDouble);
   printf("theDouble: %.5f\n", theDouble);
   printf("theDouble: %.4f\n", theDouble);
   printf("theDouble: %.3f\n", theDouble);
   printf("theDouble: %.2f\n", theDouble);
   printf("theDouble: %.1f\n", theDouble);

   return(0);
}
