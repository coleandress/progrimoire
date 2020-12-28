#include <stdio.h>

int main()
{
   int x = 42;

   /* -- All these conditions are true so all the
         'printf' lines will be executed -- */
      
   if(x > 10)
      printf("x was more than ten ...\n");

   if(x == 42)
      printf("x was forty two ...\n");

   if(x < 50)
      printf("x was less than fifty ...\n");

   return(0);
}
