#include <stdio.h>

#define SIZE (10)

int main()
{
   /* -- Here, we fill 'someArray' with zeros -- */

   int someArray[SIZE] = { 0 };

   for(int i = 0; i < SIZE; i ++)
      printf("someArray[%d] = %d\n", i, someArray[i]);

   printf("\n");

   /* -- Now, fill 'anotherArray' with explicit values -- */

   int anotherArray[SIZE] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };

   for(int i = 0; i < SIZE; i ++)
      printf("anotherArray[%d] = %d\n", i, anotherArray[i]);

   return(0);
}
