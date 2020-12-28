#include <stdio.h>

int main()
{
   /* -- First, here's a for loop that uses multiple loop variables  -- */

   for(int i = 0, j = 1, k = 10; i < 10; i ++, j += 2, k --)
      printf("i: %d, j: %d, k: %d\n", i, j, k);

   printf("\n");

   /* -- Now, a while loop example that uses multiple
         loop variables -- */

   int i = 2;
   int j = 3;
   int k = 5;

   while(i + j + k < 50)
   {
      printf("i: %d, j: %d, k: %d\n", i, j, k);

      i ++;
      j *= 2;
      k += 3;
   }

   printf("\n");

   /* -- And finally, a do-while loop example using multiple loop variables -- */

   i = j = k = 0;

   do
   {
      printf("i: %d, j: %d, k: %d\n", i, j, k);

      i += 2;
      j += 3;
      k += 5;
   }
   while(i + j + k < 50);

   return(0);
}
