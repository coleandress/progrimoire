/***************************************************************************
 * We need to include <stdbool.h> in order to use the 'bool' type
 ***************************************************************************/

#include <stdbool.h>
#include <stdio.h>

int main()
{
   /* -- Set our flag to false initially (no divisors found yet) -- */

   bool divisorFound = false;

   /* -- Look for divisors of 'number' starting with 2 -- */

   int number = 31;
   int i      = 2;

   while(i < number)
   {
      if(number % i == 0)
      {
         divisorFound = 1;
         break;
      }

      i++;
   }

   if(divisorFound)
      printf("Found a divisor for: %d\n", number);
   else
      printf("Looks like: %d is a prime number\n", number);

   /* -- There's no special format specifier for
         type bool, we just use %d -- */

   printf("The flag 'divisorFound' is: %d\n", divisorFound);

   /* -- Make true into false or vice versa -- */

   divisorFound = !divisorFound;

   printf("The flag 'divisorFound' is now: %d\n", divisorFound);

   return(0);
}
