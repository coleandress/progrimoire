#include <stdlib.h>
#include <stdio.h>

#define SIZE(x) ( sizeof(x) / sizeof(x[0]) )

#define ITEMS (20)
#define N      (6)
#define COUNT (10)

int main()
{
   int someArray[ITEMS] = { 2, 3, 5, 7, 11, 13 };

   /* -- If the array has room (capacity is 20 but only 6
         elements have been stored in the array) we can
         store elements in the unused locations -- */

   for(int i = N, j = -1; i < ITEMS; i ++, j --)
      someArray[i] = j;

   for(int i = 0, n = SIZE(someArray); i < n; i ++)
      printf("someArray[%d] = %d\n", i, someArray[i]);

   printf("\n");

   /* -- However, there's no way to store elements in our
         array beyond the initial capacity (ITEMS).
         It is possible to dynamically allocate an
         array and then call 'realloc' to enlarge
         that array's size as we see here -- */

   int *ptr = malloc(COUNT * sizeof(int));

   if(!ptr)
   {
      printf("Malloc failed\n");
      return(1);
   }

   for(int i = 0; i < COUNT; i ++)
      ptr[i] = i;

   for(int i = 0; i < COUNT; i ++)
      printf("ptr[%d] = %d\n", i, ptr[i]);

   printf("\n");

   int *newPtr = realloc(ptr, 2 * COUNT * sizeof(int));

   if(!newPtr)
   {
      printf("Realloc failed\n");
      free(ptr);
      return(1);
   }

   for(int i = COUNT; i < 2 * COUNT; i ++)
      newPtr[i] = -i;

   for(int i = 0; i < 2 * COUNT; i ++)
      printf("newPtr[%d] = %d\n", i, newPtr[i]);

   free(newPtr);

   return(0);
}
