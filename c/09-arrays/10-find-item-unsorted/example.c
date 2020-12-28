#include <stdlib.h>
#include <stdio.h>

#define SIZE(x) ( sizeof(x) / sizeof(x[0]) )

int main()
{
   int someArray[] = { 31, 3, 7, 23, 11, 13, 2, 17, 19, 5, 29 };

   /* -- See which numbers are found in 'someArray' -- */

   for(int i = 0; i < 40; i ++)
   {
      /* -- Set 'index' to -1, (initially indicating we've not
            found the item yet) update that value if we
            encounter it -- */

      int index = -1;

      for(int j = 0; j < SIZE(someArray); j ++)
      {
         if(someArray[j] == i)
         {
            index = j;
            break;
         }
      }

      printf("%d was %s\n", i, index >= 0 ? "found" : "not found");
   }
   
   return(0);
}
