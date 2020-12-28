#include <stdio.h>

#define SIZE(x) ( sizeof(x) / sizeof(x[0]) )

int main()
{
   /* -- Create and print our initial array -- */

   int someArray[] = { 2, 3, 5, 7, 11 };

   for(int i = 0; i < SIZE(someArray); i ++)
      printf("someArray[%d] = %d\n", i, someArray[i]);

   printf("\n");

   /* -- Now reverse the array's contents and print -- */

   for(int i = 0, j = SIZE(someArray) - 1; i < j; i ++, j --)
   {
      int tmp      = someArray[i];
      someArray[i] = someArray[j];
      someArray[j] = tmp;
   }

   for(int i = 0; i < SIZE(someArray); i ++)
      printf("someArray[%d] = %d\n", i, someArray[i]);

   printf("\n");

   /* -- Now triple each element and print -- */

   for(int i = 0; i < SIZE(someArray); i ++)
      someArray[i] = someArray[i] * 3;

   for(int i = 0; i < SIZE(someArray); i ++)
      printf("someArray[%d] = %d\n", i, someArray[i]);

   return(0);
}
