#include <stdio.h>

int main()
{
   printf("The size of a long long is %d bytes\n\n", sizeof(long long));

   long long theValue = 0x7FFFFFFFFFFFFFFF;

   printf("theValue: %lld\n", theValue);

   /* -- This will overflow as we're at the
         max value for 'long long' already -- */

   theValue += 1;

   printf("theValue: %lld\n", theValue);

   theValue = -0x7FFFFFFFFFFFFFFF - 1;

   printf("theValue: %lld\n", theValue);

   /* -- This will underflow as we're at the
         min value for 'long long' already -- */

   theValue -= 1;

   printf("theValue: %lld\n", theValue);

   return(0);
}
