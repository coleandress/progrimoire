#include <stdio.h>

int main()
{
   printf("The size of an int is: %d bytes\n\n", sizeof(int));

   int theInteger = 0x7fffffff; /* -- 2147483647 -- */

   printf("theInteger: %d (hex: %x)\n", theInteger, theInteger);

   theInteger -= 147483647;

   printf("theInteger: %d (hex: %x)\n", theInteger, theInteger);

   /* -- Using '-2147483648' directly causes a warning about
         applying a '-' to an unsigned variable, the expression
         below works around that warning -- */

   theInteger = -2147483647 - 1;

   printf("theInteger: %d\n", theInteger);
   
   /* -- This will underflow as we're already at the
         min allowed value for an integer -- */

   theInteger = theInteger - 1;

   printf("theInteger: %d\n", theInteger);

   theInteger = 2147483647;

   /* -- This will overflow as we're already at
         the max allowed value for an integer -- */

   theInteger = theInteger + 1;

   printf("theInteger: %d\n", theInteger);

   /* -- This code is heavily depending upon the fact that
          sizeof(int) == 4, if that is not the case, see
          'example2.c' for a size-independent version of
          this code -- */

   return(0);
}
