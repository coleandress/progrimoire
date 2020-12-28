#include <stdlib.h>
#include <stdio.h>

#define SIZE(x) ( sizeof(x) / sizeof(x[0]) )

int main()
{
   int someArray[] = { 31, 3, 7, 23, 11, 13, 2, 17, 19, 5, 29 };
   int min         = 0;
   int max         = 0;
   int sum         = 0;

   /* -- Set min/max to the first element and then
         update those values when we encounter a
         smaller/largest value -- */

   for(int i = 0; i < SIZE(someArray); i ++)
   {
      sum += someArray[i];

      if(i == 0)
      {
         min = max = someArray[i];
      }
      else
      {
         if(min < someArray[i])
            min = someArray[i];

         else if(max > someArray[i])
            max = someArray[i];
      }
   }

   /* -- Note we have to cast 'sum' to a floating
         point type in order to avoid integer division
         when calculating our average -- */

   printf(
      "min: %d, max: %d, sum: %d, average: %.2f\n",
      min, max, sum, (double)sum / SIZE(someArray)
   );

   return(0);
}
