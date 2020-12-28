#include <stdio.h>

int main()
{
   /* -- Count from one to ten using a for loop, note the
         differing start/stop conditions -- */

   for(int i = 1; i <= 10; i ++)
      printf("i: %d\n", i);

   printf("\n");

   for(int i = 0; i < 10; i ++)
      printf("i: %d\n", i + 1);

   return(0);
}
