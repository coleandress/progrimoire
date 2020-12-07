#include <stdio.h>

int main()
{
   printf("The size of a byte is: %d\n", sizeof(unsigned char));

   unsigned char theByte = 0xff;

   printf("theByte: %d (hex: %x)\n", theByte, theByte);

   theByte = theByte - 55;

   printf("theByte: %d (hex: %x)\n", theByte, theByte);

   theByte = 0xff;

   /* -- This will overflow as 0xff is the max value
         we can fit into a byte -- */

   theByte++;

   printf("theByte: %d (hex: %x)\n", theByte, theByte);

   theByte = 0;

   /* -- This will underflow as 0 is the min value
         we can fit into a byte -- */

   theByte--;

   printf("theByte: %d (hex: %x)\n", theByte, theByte);

   return(0);
}
