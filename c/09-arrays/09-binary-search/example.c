#include <stdlib.h>
#include <stdio.h>

#define SIZE(x) ( sizeof(x) / sizeof(x[0]) )

static int compare(const void *a, const void *b)
{
   int ia = *((int *)a);
   int ib = *((int *)b);

   return(ia - ib);
}

int main()
{
   int someArray[] = { 31, 3, 7, 23, 11, 13, 2, 17, 19, 5, 29 };

   /* -- Sort 'someArray' using qsort -- */

   qsort(someArray, SIZE(someArray), sizeof(int), compare);

   for(int i = 0; i < SIZE(someArray); i ++)
      printf("%d\n", someArray[i]);

   printf("\n");

   /* -- Now use 'bsearch' to see if we can find the
         elements in question -- */

   for(int i = 0; i < 40; i ++)
   {
      void *ptr = bsearch(
         (void *)&i,
         someArray,
         SIZE(someArray),
         sizeof(int),
         compare
      );

      printf("%d was %s\n", i, ptr ? "found" : "not found");
   }
   
   return(0);
}
