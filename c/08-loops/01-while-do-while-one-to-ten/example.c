#include <stdio.h>

int main()
{
   /* -- Count from one to ten using both a while
         loop and a do-white loop -- */

   int i = 1;

   while(i <= 10)
      printf("i: %d\n", i ++);

   printf("\n");

   i = 1;

   do
   {
      printf("i: %d\n", i ++);

   } while(i <= 10);

   return(0);
}
