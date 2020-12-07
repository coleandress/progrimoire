#include <stdio.h>

int main()
{
   int valueOne = 3;
   int valueTwo = 2;

   /* -- If we perform integer division and then cast to float,
         we're too late - we need to use floating point division
         from the start -- */

   float notGoodEnough = (float)(valueOne / valueTwo);
   float floatDivision = (float)valueOne / valueTwo;

   /* -- Integer division -- */

   printf("dividing: %d by %d yields: %d\n", valueOne, valueTwo, valueOne / valueTwo);

   /* -- Still integer division -- */

   printf("dividing: %d by %d yields: %f\n", valueOne, valueTwo, notGoodEnough);

   /* -- Now, float division -- */

   printf("dividing: %d by %d yields: %f\n", valueOne, valueTwo, floatDivision);

   /* -- This also works -- */

   printf("dividing: %d by %d yields: %f\n", valueOne, valueTwo, valueOne / (float)valueTwo);

   /* -- So does this -- */

   float valueThree = 2.0;

   printf("dividing: %d by %f yields: %f\n", valueOne, valueThree, valueOne / valueThree);

   return(0);
}
