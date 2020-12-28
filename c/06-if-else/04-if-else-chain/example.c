#include <stdio.h>

int main()
{
   int x = 42;

   /* -- Either: x is less than 42, x is greater than 42 or
         x equals 42 - three mutually exclusive alternatives -- */

   if(x < 42)
      printf("x is less than forty two ...\n");

   else if(x > 42)
      printf("x is greater than forty two ...\n");

   else 
      printf("x equals forty two ...\n");

   return(0);
}
