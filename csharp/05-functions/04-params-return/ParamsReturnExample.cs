using System;

namespace ProgrimoireCSharpExamples
{
    internal static class ParamsReturnExample
    {
        public static void Main(string[] args)
        {
            /* -- Call our functions and output the
                  returned results -- */
            
            Console.WriteLine("GetBool     : {0}", GetBool(true, false));
            Console.WriteLine("GetChar     : {0}", GetChar('a', 'A'));
            Console.WriteLine("GetString   : {0}", GetString("foo", "bar"));
            Console.WriteLine("GetByte     : {0}", GetByte(0xff, 0xfe));
            Console.WriteLine("GetSByte    : {0}", GetSByte(126, 127));
            Console.WriteLine("GetShort    : {0}", GetShort(20000, 30000));
            Console.WriteLine("GetInt16    : {0}", GetInt16(30000, 32767));
            Console.WriteLine("GetUInt16   : {0}", GetUInt16(30000, 40000));
            Console.WriteLine("GetInt      : {0}", GetInt(2147483647, 2147483646));
            Console.WriteLine("GetInt32    : {0}", GetInt32(2147483647, -2147483647 - 1));
            Console.WriteLine("GetUInt32   : {0}", GetUInt32(2222222222, 3333333333));
            Console.WriteLine("GetLong     : {0}", GetLong(1234567890123456789L, 1234567890123456788L));
            Console.WriteLine("GetInt64    : {0}", GetInt64(-1234567890123456789L, -1234567890123456788L));
            Console.WriteLine("GetUInt64   : {0}", GetUInt64(12345678901234567890UL, 12345678901234567880UL));
            Console.WriteLine("GetFloat    : {0:N10}", GetFloat(123.456f, 123.457f));
            Console.WriteLine("GetDouble   : {0:N10}", GetDouble(123.4567890, 123.4567899));
            Console.WriteLine("GetDecimal  : {0:N10}", GetDecimal(100.38M, 100.39M));
        }
        
        /* -- These functions both accept parameters and also
              return a value -- */

        private static bool GetBool(bool first, bool second)
        {
            return first ? first : second;
        }

        private static char GetChar(char first, char second)
        {
            return first >= second ? first : second;
        }

        private static string GetString(string first, string second)
        {
            return string.CompareOrdinal(first, second) >= 0 ? first : second;
        }

        private static byte GetByte(byte first, byte second)
        {
            return first >= second ? first : second;
        }

        private static sbyte GetSByte(sbyte first, sbyte second)
        {
            return first >= second ? first : second;
        }

        private static short GetShort(short first, short second)
        {
            return first >= second ? first : second;
        }

        private static Int16 GetInt16(Int16 first, Int16 second)
        {
            return first >= second ? first : second;
        }

        private static UInt16 GetUInt16(UInt16 first, UInt16 second)
        {
            return first >= second ? first : second;
        }

        private static int GetInt(int first, int second)
        {
            return first >= second ? first : second;
        }

        private static Int32 GetInt32(Int32 first, Int32 second)
        {
            return first >= second ? first : second;
        }

        private static UInt32 GetUInt32(UInt32 first, UInt32 second)
        {
            return first >= second ? first : second;
        }

        private static long GetLong(long first, long second)
        {
            return first >= second ? first : second;
        }

        private static Int64 GetInt64(Int64 first, Int64 second)
        {
            return first >= second ? first : second;
        }

        private static UInt64 GetUInt64(UInt64 first, UInt64 second)
        {
            return first >= second ? first : second;
        }

        private static float GetFloat(float first, float second)
        {
            return first >= second ? first : second;
        }

        private static double GetDouble(double first, double second)
        {
            return first >= second ? first : second;
        }

        private static decimal GetDecimal(decimal first, decimal second)
        {
            return first >= second ? first : second;
        }
    }
}
