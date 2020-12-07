#include <stdint.h>
#include <stdio.h>

int main()
{
   int16_t  theShortOne = 0x7fff;
   uint16_t theShortTwo = 0xffff;

   printf("theShortOne: %d (hex: %x)\n", theShortOne, theShortOne);
   printf("theShortTwo: %u (hex: %x)\n", theShortTwo, theShortTwo);
   printf("\n");

   theShortOne -= 2767;
   theShortTwo -= 5535;

   printf("theShortOne: %d (hex: %x)\n", theShortOne, theShortOne);
   printf("theShortTwo: %u (hex: %x)\n", theShortTwo, theShortTwo);
   printf("\n");

   theShortOne = 0x7fff;
   theShortTwo = 0xffff;

   printf("theShortOne: %d (hex: %x)\n", theShortOne, theShortOne);
   printf("theShortTwo: %u (hex: %x)\n", theShortTwo, theShortTwo);
   printf("\n");

   /* -- These will overflow -- */

   theShortOne++;
   theShortTwo++;

   printf("theShortOne: %d (hex: %x)\n", theShortOne, theShortOne);
   printf("theShortTwo: %u (hex: %x)\n", theShortTwo, theShortTwo);
   printf("\n");

   theShortOne = -0x7fff - 1;
   theShortTwo = 0;

   printf("theShortOne: %d (hex: %x)\n", theShortOne, theShortOne);
   printf("theShortTwo: %u (hex: %x)\n", theShortTwo, theShortTwo);
   printf("\n");

   /* -- These will underflow -- */

   theShortOne--;
   theShortTwo--;

   printf("theShortOne: %d (hex: %x)\n", theShortOne, theShortOne);
   printf("theShortTwo: %u (hex: %x)\n", theShortTwo, theShortTwo);
   printf("\n");

   return(0);
}
