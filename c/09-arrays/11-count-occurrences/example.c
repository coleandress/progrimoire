#include <stdlib.h>
#include <stdio.h>

#define SIZE(x) ( sizeof(x) / sizeof(x[0]) )

int main()
{
   int someArray[] = { 1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5 };

   for(int i = 1; i < 6; i ++)
   {
      /* -- Run through 'someArray' and update count
            each time we counter the element we seek -- */

      int count = 0;

      for(int j = 0; j < SIZE(someArray); j ++)
         if(someArray[j] == i)
            count++;

      printf("%d was found %d time%s\n", i, count, count == 1 ? "" : "s");
   }
   
   return(0);
}
