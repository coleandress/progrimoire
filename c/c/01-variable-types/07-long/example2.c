#include <stdio.h>

int main()
{
   printf("The size of a long long is %d bytes\n\n", sizeof(long long));

   long long maxValue = 0;

   for(int i = 0, n = sizeof(long long); i < n; i ++)
   {
      long long current = (i + 1 == n ? 0x7f : 0xff);

      maxValue |= current << (i * 8);
   }

   long long theValue = maxValue;

   printf("theValue: %lld\n", theValue);

   /* -- This will overflow as we're at the
         max value for 'long long' already -- */

   theValue += 1;

   printf("theValue: %lld\n", theValue);

   theValue = -maxValue - 1;

   printf("theValue: %lld\n", theValue);

   /* -- This will underflow as we're at the
         min value for 'long long' already -- */

   theValue -= 1;

   printf("theValue: %lld\n", theValue);

   return(0);
}
