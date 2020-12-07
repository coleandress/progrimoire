#include <stdio.h>

int main()
{
   short maxValue = 0;

   for(int i = 0, n = sizeof(short); i < n; i ++)
      maxValue |= (i + 1 == n ? 0x7f : 0xff) << (i * 8);

   short theShort = maxValue;

   printf("theShort: %d (hex: %x)\n", theShort, theShort);

   theShort -= 2767;

   printf("theShort: %d (hex: %x)\n", theShort, theShort);

   theShort = -maxValue - 1;

   printf("theShort: %d\n", theShort);

   /* -- Will underflow as we're already at the
         min value we can store in a short -- */

   theShort = theShort - 1;

   printf("theShort: %d\n", theShort);

   theShort = maxValue;

   /* -- Will overflow as we're already at the
         max value we can store in a short -- */

   theShort = theShort + 1;

   printf("theShort: %d\n", theShort);

   return(0);
}
