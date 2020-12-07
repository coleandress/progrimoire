#include <stdint.h>
#include <stdio.h>

int main()
{
   int32_t  theIntOne = 0x7fffffff;
   uint32_t theIntTwo = 0xffffffff;

   printf("theIntOne: %d (hex: %x)\n", theIntOne, theIntOne);
   printf("theIntTwo: %u (hex: %x)\n", theIntTwo, theIntTwo);
   printf("\n");

   theIntOne -= 147483647;
   theIntTwo -= 294967295;

   printf("theIntOne: %d (hex: %x)\n", theIntOne, theIntOne);
   printf("theIntTwo: %u (hex: %x)\n", theIntTwo, theIntTwo);
   printf("\n");

   theIntOne = 0x7fffffff;
   theIntTwo = 0xffffffff;

   printf("theIntOne: %d (hex: %x)\n", theIntOne, theIntOne);
   printf("theIntTwo: %u (hex: %x)\n", theIntTwo, theIntTwo);
   printf("\n");

   /* -- These will overflow -- */

   theIntOne++;
   theIntTwo++;

   printf("theIntOne: %d (hex: %x)\n", theIntOne, theIntOne);
   printf("theIntTwo: %u (hex: %x)\n", theIntTwo, theIntTwo);
   printf("\n");

   theIntOne = -0x7fffffff - 1;
   theIntTwo = 0;

   printf("theIntOne: %d (hex: %x)\n", theIntOne, theIntOne);
   printf("theIntTwo: %u (hex: %x)\n", theIntTwo, theIntTwo);
   printf("\n");

   /* -- These will underflow -- */

   theIntOne--;
   theIntTwo--;

   printf("theIntOne: %d (hex: %x)\n", theIntOne, theIntOne);
   printf("theIntTwo: %u (hex: %x)\n", theIntTwo, theIntTwo);
   printf("\n");

   return(0);
}
