#include <stdio.h>

int main()
{

#if 0

   int x = 1;
   int y = 1;

   /* -- This is a multline comment, because of it, we cannot
         comment-out this section of code by enclosing it within
         multline comments, we need #if -- */

   int z = 2;

#endif

   int x = 0;
   int y = 2;
   int z = 4;

   printf("%d %d %d\n", x, y, z);

   return(0);
}
