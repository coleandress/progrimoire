#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

/* -- These functions return nothing but are passed one
      or more parameters -- */

static void showValuesOne(
   bool          boolValue,
   char          cValue,
   const char   *sValue,
   unsigned char b1,
   int8_t        b2,
   uint8_t       b3
)
{
   printf(
      "boolValue: %d, cValue; %c, sValue: %s, b1: %u, b2: %d, b3: %u\n",
      boolValue, cValue, sValue, b1, b2, b3
   );
}

static void showValuesTwo(
   short    s1,
   int16_t  s2,
   uint16_t s3,
   int      i1,
   int32_t  i2,
   uint32_t i3
)
{
   printf(
      "s1: %d, s2: %d, s3: %u, i1: %d, i2: %d, i3: %u\n",
      s1, s2, s3, i1, i2, i3
   );
}

static void showValuesThree(
   long long v1,
   int64_t   v2,
   uint64_t  v3,
   float      fValue,
   double     dValue
)
{
   printf(
      "v1: %lld, v2: %lld, v3: %llu, fValue: %.10f, dValue: %.10f",
      v1,  v2, v3, fValue, dValue
   );
}

int main()
{
   /* -- Call our 'showValues' functions to output a variety
         of variable types -- */

   showValuesOne(
      true,
      'z',
      "some silly string",
      0xff,
      0xfe,
      0xfd
   );

   showValuesTwo(
      30000,
      32000,
      34000,
      2147483647,
      -2147483647 - 1,
      3333333333
   ); 

   showValuesThree(
      1234567890123456789LL,
      -1234567890123456789LL,
      12345678901234567890ULL,
      123.456f,
      123.4567890
   );

   return(0);
}
