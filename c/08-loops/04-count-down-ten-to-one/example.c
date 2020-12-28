#include <stdio.h>

int main()
{
   /* -- Count down starting from ten to one using a while,
         do-while and for loop -- */

   int i = 10;

   while(i >= 1)
      printf("i: %d\n", i --);

   printf("\n");

   i = 10;

   do
   {
      printf("i: %d\n", i);
      i -= 1;

   } while(i >= 1);

   printf("\n");

   for(i = 10; i > 0; i --)
      printf("i: %d\n", i);

   return(0);
}
