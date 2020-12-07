#include <stdio.h>

int main()
{
   printf("The size of a short is: %d\n\n", sizeof(short));

   short theShortOne          = 0x7fff;
   unsigned short theShortTwo = 0xffff;

   printf("theShortOne: %d (hex: %x)\n", theShortOne, theShortOne);
   printf("theShortTwo: %d (hex: %x)\n", theShortTwo, theShortTwo);
   printf("\n");

   theShortOne -= 2767;
   theShortTwo -= 5535;

   printf("theShortOne: %d (hex: %x)\n", theShortOne, theShortOne);
   printf("theShortTwo: %d (hex: %x)\n", theShortTwo, theShortTwo);
   printf("\n");

   theShortOne = -0x7fff - 1;
   theShortTwo = 0;

   printf("theShortOne: %d (hex: %x)\n", theShortOne, theShortOne);
   printf("theShortTwo: %d (hex: %x)\n", theShortTwo, theShortTwo);
   printf("\n");

   /* -- Will underflow as we're already at the min value
         we can store in both variables -- */
      
   theShortOne = theShortOne - 1;
   theShortTwo = theShortTwo - 1;

   printf("theShortOne: %d (hex: %x)\n", theShortOne, theShortOne);
   printf("theShortTwo: %d (hex: %x)\n", theShortTwo, theShortTwo);
   printf("\n");

   theShortOne = 0x7fff;
   theShortTwo = 0xffff;

   printf("theShortOne: %d (hex: %x)\n", theShortOne, theShortOne);
   printf("theShortTwo: %d (hex: %x)\n", theShortTwo, theShortTwo);
   printf("\n");

   /* -- Will overflow as we're already at the max value
         we can store in both variables -- */

   theShortOne = theShortOne + 1;
   theShortTwo = theShortTwo + 1;

   printf("theShortOne: %d (hex: %x)\n", theShortOne, theShortOne);
   printf("theShortTwo: %d (hex: %x)\n", theShortTwo, theShortTwo);
   printf("\n");

   /* -- This code is heavily dependent upon the
         assumption that sizeof(short) == 2.  See
         example2.c for a size-independent version -- */

   return(0);
}
