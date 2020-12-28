#include <stdio.h>

#define SIZE(x) ( sizeof(x) / sizeof(x[0]) )

int main()
{
   int someArray[] = { 2, 3, 5, 7, 11, 13 };

   int size = SIZE(someArray);

   /* -- Show every other element -- */

   for(int i = 0; i < size; i += 2)
      printf("someArray[%d] = %d\n", i,  someArray[i]);

   printf("\n");

   /* -- Show the first half of the array -- */

   for(int i = 0; i < size / 2; i ++ )
      printf("someArray[%d] = %d\n", i,  someArray[i]);

   printf("\n");

   /* -- Now the last half of the array -- */

   for(int i = size / 2; i < size; i ++ )
      printf("someArray[%d] = %d\n", i,  someArray[i]);

   return(0);
}
