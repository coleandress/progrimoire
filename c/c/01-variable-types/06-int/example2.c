#include <stdio.h>

int main()
{
   printf("The size of an int is: %d bytes\n\n", sizeof(int));

   int maxValue = 0;

   for(int i = 0, n = sizeof(int); i < n; i ++)
      maxValue |= (i + 1 == n ? 0x7f : 0xff) << (i * 8);

   int theInteger = maxValue;

   printf("theInteger: %d (hex: %x)\n", theInteger, theInteger);

   theInteger -= 147483647;

   printf("theInteger: %d (hex: %x)\n", theInteger, theInteger);

   theInteger = -maxValue - 1;

   printf("theInteger: %d\n", theInteger);
   
   /* -- This will underflow as we're already at the
         min allowed value for an integer -- */

   theInteger = theInteger - 1;

   printf("theInteger: %d\n", theInteger);

   theInteger = maxValue;

   /* -- This will overflow as we're already at
         the max allowed value for an integer -- */

   theInteger = theInteger + 1;

   printf("theInteger: %d\n", theInteger);

   return(0);
}
