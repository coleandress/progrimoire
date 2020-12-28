#include <stdio.h>

int main()
{
   for(int i = 1; i <= 100; i ++)
   {
      printf("%d: ", i);

      switch(i % 15)
      {
         case 0:
         {
            printf("divisible by both 3 and 5\n");
         }
         break;

         /* -- You can "stack" the case labels so that
               the same block of code applies to multiple
               cases -- */

         case 3: case 6: case 9: case 12:
         {
            printf("divisible by 3\n");
         }
         break;

         case 5: case 10:
         {
            printf("divisible by 5\n");
         }
         break;

         /* -- If none of the listed cases match, we'll end up
               at the default case -- */

         default:
         {
            printf("divisible by neither 3 nor 5\n");
         }
         break;
      }
   }

   return(0);
}
