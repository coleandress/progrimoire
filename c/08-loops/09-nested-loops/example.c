#include <stdio.h>

int main()
{
   /* -- Output times from 1 o'clock to 12 o'clock, show
         every 15 minutes -- */

   for(int hour = 1; hour <= 12; hour ++)
      for(int minute = 0; minute < 60; minute += 15)
         printf("%d:%02d\n", hour, minute);

   printf("\n");

   /* -- A set of three nested while loops -- */

   int i = 0;

   while(i < 2)
   {
      int j = 0;

      while(j < 2)
      {
         int k = 0;

         while(k < 2)
         {
            printf("%d %d %d\n", i, j, k);
            k++;
         }

         j++;
      }
      
      i++;
   }

   return(0);
}
