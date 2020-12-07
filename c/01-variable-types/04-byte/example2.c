#include <stdint.h>
#include <stdio.h>

int main()
{
   int8_t  theByteOne = 0x7f;
   uint8_t theByteTwo = 0xff;

   printf("theByteOne: %d (hex: %x)\n", theByteOne, theByteOne);
   printf("theByteTwo: %d (hex: %x)\n", theByteTwo, theByteTwo);
   printf("\n");

   theByteOne -= 27;
   theByteTwo -= 55;

   printf("theByteOne: %d (hex: %x)\n", theByteOne, theByteOne);
   printf("theByteTwo: %d (hex: %x)\n", theByteTwo, theByteTwo);
   printf("\n");

   theByteOne = 0x7f;
   theByteTwo = 0xff;

   printf("theByteOne: %d (hex: %x)\n", theByteOne, theByteOne);
   printf("theByteTwo: %d (hex: %x)\n", theByteTwo, theByteTwo);
   printf("\n");

   /* -- These will overflow -- */

   theByteOne++;
   theByteTwo++;

   printf("theByteOne: %d (hex: %x)\n", theByteOne, theByteOne);
   printf("theByteTwo: %d (hex: %x)\n", theByteTwo, theByteTwo);
   printf("\n");

   theByteOne = -0x7f - 1;
   theByteTwo = 0;

   printf("theByteOne: %d (hex: %x)\n", theByteOne, theByteOne);
   printf("theByteTwo: %d (hex: %x)\n", theByteTwo, theByteTwo);
   printf("\n");

   /* -- These will underflow -- */

   theByteOne--;
   theByteTwo--;

   printf("theByteOne: %d (hex: %x)\n", theByteOne, theByteOne);
   printf("theByteTwo: %d (hex: %x)\n", theByteTwo, theByteTwo);
   printf("\n");

   return(0);
}
