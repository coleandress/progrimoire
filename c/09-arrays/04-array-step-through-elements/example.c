#include <stdio.h>

#define SIZE(x) ( sizeof(x) / sizeof(x[0]) )

int main()
{
   /* -- Create and print our initial array -- */

   int someArray[] = { 2, 3, 5, 7, 11 };

   for(int i = 0; i < SIZE(someArray); i ++)
      printf("someArray[%d] = %d\n", i, someArray[i]);

   printf("\n");

   /* -- Now print it backwards -- */

   for(int i = SIZE(someArray) - 1; i >= 0; i --)
      printf("someArray[%d] = %d\n", i, someArray[i]);

   printf("\n");

   /* -- Now, print every other element -- */

   for(int i = 0; i < SIZE(someArray); i += 2)
      printf("someArray[%d] = %d\n", i, someArray[i]);

   return(0);
}
