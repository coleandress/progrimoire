#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>


int main()
{
   printf("true: %d\n", true);
   printf("false: %d\n\n", false);

   const char *s = "here-is-the-string";

   printf("someString: '%s' [%s]\n\n", s, s);

   char x = 'x';

   printf("[%c] [%c]\n\n", x, x + 1);

   unsigned char value = 0xff;
   uint8_t value2      = value - 55;
   int8_t  value3      = -1;

   printf("value: %u, value2: %u, value3: %d\n\n", value, value2, value3);

   short          sValue  = 30000;
   int16_t        sValue2 = 32767;
   unsigned short sValue3 = 40000;
   uint16_t       sValue4 = 50000;

   printf(
      "sValue: %d, sValue2: %d, sValue3: %u, sValue5: %u\n\n",
      sValue, sValue2, sValue3, sValue4
   );

   int          iValue  = 42;
   int32_t      iValue2 = 24;
   unsigned int iValue3 = 222222222;
   uint32_t     iValue4 = 333333333;

   printf(
      "iValue: %d, iValue2: %d, iValue3: %u, iValue4: %u\n\n",
      iValue, iValue2, iValue3, iValue4
   );

   long long int bigValue  = 1234567890123456789LL;
   int64_t       bigValue2 = -bigValue;
   uint64_t      bigValue3 = 12345678901234567890ULL;

   printf(
      "bigValue: %lld, bigValue2: %lld, bigValue3: %llu\n\n",
      bigValue, bigValue2, bigValue3
   );

   float f  = 0.5f;
   double d = 0.5;

   /* -- Note the improved precision associated with 'd'
         (the double) vs 'f' (the float) -- */

   for(int i = 0; i < 10; i ++, f /= 3, d /= 3)
      printf("f: %.15f, d: %.15f\n", f, d);

   return(0);
}
