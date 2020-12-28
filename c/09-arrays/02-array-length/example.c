#include <stdio.h>

#define SIZE(x) ( sizeof(x) / sizeof(x[0]) )

static void printArrayBad(int *array)
{
   for(int i = 0; i < SIZE(array); i ++)
      printf("array[%d] = %d\n", i, array[i]);
}

static void printArrayGood(int *array, int n)
{
   for(int i = 0; i < n; i ++)
      printf("array[%d] = %d\n", i, array[i]);
}

int main()
{
   /* -- If the array declaration is in scope, we can
         use the 'SIZE' macro to determine its size -- */

   int someArray[] = { 2, 3, 5, 7, 11 };

   for(int i = 0; i < SIZE(someArray); i ++)
      printf("someArray[%d] = %d\n", i, someArray[i]);

   printf("\n");

   /* -- Our macro fails, however, when the array declaration
         is not in scope -- */

   printArrayBad(someArray);

   printf("\n");

   /* -- To author a working version of 'printArray', we'll need to
         pass in the array size -- */

   printArrayGood(someArray, SIZE(someArray));

   return(0);
}
