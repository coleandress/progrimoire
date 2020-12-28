#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>

/* -- These functions both accept parameters and also
      return a value -- */

static bool getBool(bool first, bool second)
{
   if(first)
      return(first);

   return(second);
}

static char getChar(char first, char second)
{
   if(first >= second)
      return(first);
   
   return(second);
}

static const char *getString(const char *first, const char *second)
{
   if(strcmp(first, second) >= 0)
      return(first);

   return(second);
}

static unsigned char getByte(unsigned char first, unsigned char second)
{
   if(first >= second)
      return(first);

   return(second);
}

static int8_t getInt8(int8_t first, int8_t second)
{
   if(first >= second)
      return(first);

   return(second);
}

static uint8_t getUInt8(uint8_t first, uint8_t second)
{
   if(first >= second)
      return(first);

   return(second);
}

static short getShort(short first, short second)
{
   if(first >= second)
      return(first);

   return(second);
}

static int16_t getInt16(int16_t first, int16_t second)
{
   if(first >= second)
      return(first);

   return(second);
}

static uint16_t getUInt16(uint16_t first, uint16_t second)
{
   if(first >= second)
      return(first);

   return(second);
}

static int getInt(int first, int second)
{
   if(first >= second)
      return(first);

   return(second);
}

static int32_t getInt32(int32_t first, int32_t second)
{
   if(first >= second)
      return(first);

   return(second);
}

static uint32_t getUInt32(uint32_t first, uint32_t second)
{
   if(first >= second)
      return(first);

   return(second);
}

static long long getLongLong(long long first, long long second)
{
   if(first >= second)
      return(first);

   return(second);
}

static int64_t getInt64(int64_t first, int64_t second)
{
   if(first >= second)
      return(first);

   return(second);
}

static uint64_t getUInt64(uint64_t first, uint64_t second)
{
   if(first >= second)
      return(first);

   return(second);
}

static float getFloat(float first, float second)
{
   if(first >= second)
      return(first);

   return(second);
}

static double getDouble(double first, double second)
{
   if(first >= second)
      return(first);

   return(second);
}

int main()
{
   /* -- Call our functions and output the
         returned results -- */

   printf("getBool    : %d\n", getBool(true, false));
   printf("getChar    : %c\n", getChar('a', 'A'));
   printf("getString  : %s\n", getString("foo", "bar"));
   printf("getByte    : %u\n", getByte(0xff, 0xfe));
   printf("getInt16   : %d\n", getInt16(-1, -2));
   printf("getUInt16  : %u\n", getUInt16(0xff, 0xfe));
   printf("getShort   : %d\n", getShort(20000, 30000));
   printf("getInt16   : %d\n", getInt16(30000, 32767));
   printf("getUInt16  : %u\n", getUInt16(30000, 40000));
   printf("getInt     : %d\n", getInt(2147483647, 2147483646));
   printf("getInt32   : %d\n", getInt(2147483647, -2147483647 - 1));
   printf("getUInt32  : %u\n", getInt(2222222222, 3333333333));

   printf(
      "getLongLong: %lld\n",
      getLongLong(1234567890123456789LL, 1234567890123456788LL)
   );

   printf(
      "getInt64   : %lld\n",
      getInt64(-1234567890123456789LL, -1234567890123456788LL)
   );

   printf(
      "getUInt64  : %llu\n",
      getUInt64(12345678901234567890ULL, 12345678901234567880ULL)
   );

   printf("getFloat   : %.10f\n", getFloat(123.456f, 123.457f));
   printf("getDouble  : %.10f\n", getDouble(123.4567890, 123.4567899));

   return(0);
}
