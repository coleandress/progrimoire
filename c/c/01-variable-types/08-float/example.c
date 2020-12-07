#include <stdio.h>

int main()
{
   printf("The size of a float is: %d bytes\n\n", sizeof(float));

   /* -- C floating point literals default to
         type 'double', adding 'f' makes them
         type float -- */

   float theFloat = 123.456f;

   printf("theFloat: %f\n", theFloat);

   theFloat = 45.1234f;

   printf("theFloat: %f\n", theFloat);

   theFloat = 0.123456789f;

   printf("theFloat: %f\n", theFloat);

   printf("\n");

   printf("theFloat: %.9f\n", theFloat);
   printf("theFloat: %.8f\n", theFloat);
   printf("theFloat: %.7f\n", theFloat);
   printf("theFloat: %.6f\n", theFloat);
   printf("theFloat: %.5f\n", theFloat);
   printf("theFloat: %.4f\n", theFloat);
   printf("theFloat: %.3f\n", theFloat);
   printf("theFloat: %.2f\n", theFloat);
   printf("theFloat: %.1f\n", theFloat);

   return(0);
}
