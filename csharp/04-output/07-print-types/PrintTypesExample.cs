using System;

namespace ProgrimoireCSharpExamples
{
    internal static class PrintTypesExample
    {
        public static void Main(string[] args)
        {
            PrintBool();

            const string s = "here-is-the-string";
            PrintString(s);

            const char x = 'x';
            PrintChar(x);

            const byte value = 0xff;
            byte value2      = (byte)(value - 55);
            sbyte value3     = -1;
            PrintBytes(value, value2, value3);

            short   sValue = 30000;
            Int16  sValue2 = 32767;
            ushort sValue3 = 40000;
            UInt16 sValue4 = 50000;
            PrintShorts(sValue, sValue2, sValue3, sValue4);

            int     iValue = 42;
            Int32  iValue2 = 24;
            uint   iValue3 = 222222222;
            UInt32 iValue4 = 333333333;
            PrintInts(iValue, iValue2, iValue3, iValue4);
            
            long bigValue    = 1234567890123456789L;
            Int64 bigValue2  = -bigValue;
            UInt64 bigValue3 = 12345678901234567890L;
            PrintLongs(bigValue, bigValue2, bigValue3);

            float   f = 0.5f;
            double  d = 0.5;
            decimal m = 0.5M;
            PrintFloatingPointNumbers(f, d, m);
        }

        private static void PrintBool()
        {
            Console.WriteLine($"true: {true}");
            Console.WriteLine($"false: {false}\n");
        }

        private static void PrintString(string s)
        {
            Console.WriteLine($"someString: '{s}' [{s}]\n");
        }
        
        private static void PrintChar(char c)
        {
            Console.WriteLine($"[{c}] [{(char)(c + 1)}]\n");
        }
        
        private static void PrintBytes(byte value, byte value2, sbyte value3)
        {
            Console.WriteLine($"value: {value}, value2: {value2}, value3: {value3}\n");
        }
        
        private static void PrintShorts(short sValue, short sValue2, ushort sValue3, ushort sValue4)
        {
            Console.WriteLine($"sValue: {sValue}, sValue2: {sValue2}, sValue3: {sValue3}, sValue4: {sValue4}\n");
        }
        
        private static void PrintInts(int iValue, int iValue2, uint iValue3, uint iValue4)
        {
            Console.WriteLine($"iValue: {iValue}, iValue2: {iValue2}, iValue3: {iValue3}, iValue4: {iValue4}\n");
        }
        
        private static void PrintLongs(long bigValue, long bigValue2, ulong bigValue3)
        {
            Console.WriteLine($"bigValue: {bigValue}, bigValue2: {bigValue2}, bigValue3: {bigValue3}\n");
        }
        
        private static void PrintFloatingPointNumbers(float f, double d, decimal m)
        {
            for (var i = 0; i < 10; i++, f /= 3, d /= 3, m /= 3)
                Console.WriteLine($"f: {f:N25}, d: {d:N25}, m: {m:N25}");

            Console.WriteLine();
        }
    }
}
