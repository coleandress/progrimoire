#include <stdio.h>

int main()
{
   int x = 42;

   /* -- Either 'x == 42' or it does not, this determines
         which branch will be followed and which printf
         statement will be excuted -- */

   if(x == 42)
      printf("x equals forty two ...\n");

   else
      printf("x does not equal forty two ...\n");

   return(0);
}
