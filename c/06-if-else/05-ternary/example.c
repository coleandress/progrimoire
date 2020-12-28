#include <stdio.h>

int main()
{
   int x = 42;

   /* -- The ternary operator is essentially an in-line, shorthand
         for an if/else statement.  It evaluates to the first term
         if the test is true or the second term if it is not -- */

   printf(
      "x is %s ...\n", x % 2 == 0 ? "even" : "odd"
   );

   int y = 24;

   int max = (x >= y ? x : y);

   printf("max: %d\n", max);

   return(0);
}
