using System;

namespace ProgrimoireCSharpExamples
{
    internal static class ByteExample2
    {
        public static void Main(string[] args)
        {
            sbyte theByteOne = 0x7f; // int8_t equivalent
            byte theByteTwo = 0xff; // uint8_t equivalent
            
            Console.WriteLine($"theByteOne: {theByteOne} (hex: {theByteOne})");
            Console.WriteLine($"theByteTwo: {theByteTwo} (hex: {theByteTwo})");
            Console.WriteLine();

            theByteOne -= 27;
            theByteTwo -= 55;
            
            Console.WriteLine($"theByteOne: {theByteOne} (hex: {theByteOne})");
            Console.WriteLine($"theByteTwo: {theByteTwo} (hex: {theByteTwo})");
            Console.WriteLine();

            theByteOne = 0x7f;
            theByteTwo = 0xff;
            
            Console.WriteLine($"theByteOne: {theByteOne} (hex: {theByteOne})");
            Console.WriteLine($"theByteTwo: {theByteTwo} (hex: {theByteTwo})");
            Console.WriteLine();
            
            /* -- These will overflow if unchecked, see ex 1 -- */

            theByteOne++;
            theByteTwo++;
            
            Console.WriteLine($"theByteOne: {theByteOne} (hex: {theByteOne})");
            Console.WriteLine($"theByteTwo: {theByteTwo} (hex: {theByteTwo})");
            Console.WriteLine();

            theByteOne = -0x7f - 1;
            theByteTwo = 0;
            
            Console.WriteLine($"theByteOne: {theByteOne} (hex: {theByteOne})");
            Console.WriteLine($"theByteTwo: {theByteTwo} (hex: {theByteTwo})");
            Console.WriteLine();
            
            /* -- These will underflow if unchecked, see ex 1 -- */

            theByteOne--;
            theByteTwo--;
            
            Console.WriteLine($"theByteOne: {theByteOne} (hex: {theByteOne})");
            Console.WriteLine($"theByteTwo: {theByteTwo} (hex: {theByteTwo})");
            Console.WriteLine();
        }
    }
}