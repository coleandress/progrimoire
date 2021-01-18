using System;

namespace ProgrimoireCSharpExamples
{
    internal static class ParamsNoReturnExample
    {
        public static void Main(string[] args)
        {
            /* -- Call our 'ShowValues' functions to output a variety
                  of variable types -- */
            
            ShowValuesOne(
                true,
                'z',
                "some silly string",
                0xff,
                127
                );
            
            ShowValuesTwo(
                30000,
                32000,
                34000,
                2147483647,
                -2147483647 - 1,
                3333333333
                );
            
            ShowValuesThree(
                1234567890123456789L,
                -1234567890123456789L,
                12345678901234567890UL,
                123.456f,
                123.4567890,
                50.86M
                );
        }
        
        /* -- These functions return nothing but are passed one
              or more parameters -- */

        private static void ShowValuesOne(
            bool   boolValue,
            char   cValue,
            string sValue,
            byte   b1,
            sbyte  b2
            )
        {
            Console.WriteLine($"boolValue: {boolValue}, cValue: {cValue}, sValue: {sValue}, b1: {b1}, b2: {b2}\n");
        }

        private static void ShowValuesTwo(
            short  s1,
            Int16  s2,
            UInt16 s3,
            int    i1,
            Int32  i2,
            UInt32 i3
            )
        {
            Console.WriteLine($"s1: {s1}, s2: {s2}, s3: {s3}, i1: {i1}, i2: {i2}, i3: {i3}\n");
        }

        private static void ShowValuesThree(
            long    v1,
            Int64   v2,
            UInt64  v3,
            float   fValue,
            double  dValue,
            decimal mValue
            )
        {
            Console.WriteLine($"v1: {v1}, v2: {v2}, v3: {v3}, fValue: {fValue:N10}, dValue: {dValue:N10}, mValue: {mValue:N10}\n");
        }
    }
}
