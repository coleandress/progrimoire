using System;

namespace ProgrimoireCSharpExamples
{
    internal static class LongExample3
    {
        public static void Main(string[] args)
        {
            Int64 theLongOne = 0x7fffffffffffffff;
            UInt64 theLongTwo = 0xffffffffffffffff;

            Console.WriteLine($"theLongOne: {theLongOne} (hex: {theLongOne:x8})");
            Console.WriteLine($"theLongTwo: {theLongTwo} (hex: {theLongTwo:x8})\n");
            
            theLongOne -= 223372036854775807L;
            theLongTwo -= 446744073709551615L;
            
            Console.WriteLine($"theLongOne: {theLongOne} (hex: {theLongOne:x8})");
            Console.WriteLine($"theLongTwo: {theLongTwo} (hex: {theLongTwo:x8})\n");
            
            theLongOne = 0x7fffffffffffffff;
            theLongTwo = 0xffffffffffffffff;
            
            Console.WriteLine($"theLongOne: {theLongOne} (hex: {theLongOne:x8})");
            Console.WriteLine($"theLongTwo: {theLongTwo} (hex: {theLongTwo:x8})\n");
            
            /* -- These will overflow -- */

            theLongOne++;
            theLongTwo++;
            
            Console.WriteLine($"theLongOne: {theLongOne} (hex: {theLongOne:x8})");
            Console.WriteLine($"theLongTwo: {theLongTwo} (hex: {theLongTwo:x8})\n");
            
            theLongOne = -0x7fffffffffffffff - 1;
            theLongTwo = 0;
            
            Console.WriteLine($"theLongOne: {theLongOne} (hex: {theLongOne:x8})");
            Console.WriteLine($"theLongTwo: {theLongTwo} (hex: {theLongTwo:x8})\n");
            
            /* -- These will underflow -- */

            theLongOne--;
            theLongTwo--;
            
            Console.WriteLine($"theLongOne: {theLongOne} (hex: {theLongOne:x8})");
            Console.WriteLine($"theLongTwo: {theLongTwo} (hex: {theLongTwo:x8})\n");
        }
    }
}