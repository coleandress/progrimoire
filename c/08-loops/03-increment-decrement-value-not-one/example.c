#include <stdio.h>

int main()
{
   /* -- Increment and decrement by a value other
         than one using a for loop -- */

   for(int i = 0; i <= 20; i += 2)
      printf("i: %d\n", i);

   printf("\n");

   for(int i = 30; i >= 0; i -= 3)
      printf("i: %d\n", i);

   printf("\n");

   /* -- Do the same thing with while loops -- */

   int i = 0;

   while(i <= 20)
   {
      printf("i: %d\n", i);
      i += 2;
   }

   printf("\n");

   i = 30;

   while(i >= 0)
   {
      printf("i: %d\n", i);
      i -= 3;
   }

   printf("\n");

   /* -- Do the same thing with do-while loops -- */

   i = 0;

   do
   {
      printf("i: %d\n", i);
      i += 2;

   }  while(i <= 20);

   printf("\n");

   i = 30;

   do
   {
      printf("i: %d\n", i);
      i -= 3;

   }  while(i >= 0);

   return(0);
}
