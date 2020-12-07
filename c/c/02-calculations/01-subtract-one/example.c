#include <stdio.h>

int main()
{
   int someNumber = 42;
   int ten        = 10;

   printf("someNumber: %d\n", someNumber);

   /* -- Add one in the most vanilla way -- */

   someNumber = someNumber + 1;

   printf("someNumber: %d\n", someNumber);

   /* -- Add one in a moderately slicker way -- */

   someNumber += 1;

   printf("someNumber: %d\n", someNumber);

   /* -- Add one in the most succinct way -- */

   someNumber++;

   printf("someNumber: %d\n", someNumber);
   printf("\n");

   printf("ten: %d\n", ten);

   printf("ten++: %d\n", ten++);

   printf("++ten: %d\n", ++ten);

   printf("ten: %d\n", ten);

   return(0);
}
