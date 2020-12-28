#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

/* -- All these functions take no arguments but do
      return a value  -- */  

static bool getBool()
{
   return(false);
}

static char *getString()
{
   return("some string");
}

static char getChar()
{
   return('X');
}

static unsigned char getByteOne()
{
   return(0xff);
}

static int8_t getByteTwo()
{
   return(0xfe);
}

static uint8_t getByteThree()
{
   return(0xfd);
}

static short getShortOne()
{
   return(30000);
}

static int16_t getShortTwo()
{
   return(32000);
}

static uint16_t getShortThree()
{
   return(34000);
}

static int getIntOne()
{
   return(2147483647);
}

static int32_t getIntTwo()
{
   return(-getIntOne() - 1);
}

static uint32_t getIntThree()
{
   return(3333333333);
}

static long long int getLLOne()
{
   return(1234567890123456789LL);
}

static int64_t getLLTwo()
{
   return(-getLLOne());
}

static uint64_t getLLThree()
{
   return(12345678901234567890ULL);
}

static float getFloat()
{
   return(123.456f);
}

static double getDouble()
{
   return(123.4567890);
}

int main()
{
   /* -- Invoke each function and print out the
         returned value -- */

   bool bValue = getBool();

   printf("bValue: %d\n", bValue);

   const char *sValue = getString();

   printf("sValue: %s\n", sValue);

   char cValue = getChar();

   printf("cValue: %c\n", cValue);

   unsigned char b1 = getByteOne();
   int8_t        b2 = getByteTwo();
   uint8_t       b3 = getByteThree();

   printf("%u %d %u\n", b1, b2, b3);

   short    s1 = getShortOne();
   int16_t  s2 = getShortTwo();
   uint16_t s3 = getShortThree();

   printf("%d %d %u\n", s1, s2, s3);

   int      i1 = getIntOne();
   int32_t  i2 = getIntTwo();
   uint32_t i3 = getIntThree();

   printf("%d %d %u\n", i1, i2, i3);

   long long int v1 = getLLOne();
   int64_t       v2 = getLLTwo();
   uint64_t      v3 = getLLThree();

   printf("%lld %lld %llu\n", v1, v2, v3);

   float f = getFloat();
   double d = getDouble();

   printf("%.10f %.10f\n", f, d);

   return(0);
}
