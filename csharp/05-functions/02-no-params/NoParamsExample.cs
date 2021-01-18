using System;

namespace ProgrimoireCSharpExamples
{
    internal static class NoParamsExample
    {
        public static void Main(string[] args)
        {
            /* -- Invoke each function and print out the
                  return value -- */

            var bValue = GetBool();

            Console.WriteLine($"bValue: {bValue}\n");
            
            var sValue = GetString();

            Console.WriteLine($"sValue: {sValue}\n");
            
            var cValue = GetChar();
            
            Console.WriteLine($"cValue: {cValue}\n");
            
            var b1 = GetByteOne();
            var b2 = GetByteTwo();
            
            Console.WriteLine($"{b1} {b2}\n");
            
            var s1 = GetShortOne();
            var s2 = GetShortTwo();
            
            Console.WriteLine($"{s1} {s2}\n");
            
            var i1 = GetIntOne();
            var i2 = GetIntTwo();
            var i3 = GetIntThree();
            
            Console.WriteLine($"{i1} {i2} {i3}\n");
            
            var v1 = GetLongOne();
            var v2 = GetLongTwo();
            var v3 = GetLongThree();
            
            Console.WriteLine($"{v1} {v2} {v3}\n");
            
            var f = GetFloat();
            var d = GetDouble();
            var m = GetDecimal();
            
            Console.WriteLine($"{f:N10} {d:N10} {m:N10}\n", f, d);
        }
        
        /* -- All these functions take no arguments but do
              return a value -- */
        private static bool GetBool()
        {
            return false;
        }

        private static string GetString()
        {
            return "some string";
        }

        private static char GetChar()
        {
            return 'X';
        }

        private static byte GetByteOne()
        {
            return 0xff;
        }

        private static sbyte GetByteTwo()
        {
            return 127;
        }

        private static short GetShortOne()
        {
            return 30000;
        }

        private static ushort GetShortTwo()
        {
            return 34000;
        }

        private static int GetIntOne()
        {
            return 2147483647;
        }

        private static Int32 GetIntTwo()
        {
            return -GetIntOne() - 1;
        }

        private static uint GetIntThree()
        {
            return 3333333333;
        }

        private static long GetLongOne()
        {
            return 1234567890123456789L;
        }

        private static Int64 GetLongTwo()
        {
            return -GetLongOne();
        }

        private static ulong GetLongThree()
        {
            return 12345678901234567890UL;
        }

        private static float GetFloat()
        {
            return 123.456f;
        }

        private static double GetDouble()
        {
            return 123.4567890;
        }

        private static decimal GetDecimal()
        {
            return 50.86M;
        }
    }
}
