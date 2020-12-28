#include <stdio.h>

int main()
{
   int x = 42;
   int y = 24;

   /* -- All three compound conditions are true so all calls
         to printf will be executed -- */

   if(x > 10 && y > 10)
      printf("x and y were both more than ten ...\n");

   if(x == 42 && y == 24)
      printf("x was forty two and y was twenty four ...\n");

   if(x < 50 && y < 50)
      printf("x and y were both less than fifty ...\n");

   return(0);
}
