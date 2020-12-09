using System;

namespace ProgrimoireCSharpExamples
{
    internal static class ShortExample3
    {
        public static void Main(string[] args)
        {
            Int16 theShortOne = 0x7fff;
            UInt16 theShortTwo = 0xffff;
            
            Console.WriteLine($"theShortOne: {theShortOne} (hex: {theShortOne:x8})");
            Console.WriteLine($"theShortTwo: {theShortTwo} (hex: {theShortTwo:x8})\n");

            theShortOne -= 2767;
            theShortTwo -= 5535;
            
            Console.WriteLine($"theShortOne: {theShortOne} (hex: {theShortOne:x8})");
            Console.WriteLine($"theShortTwo: {theShortTwo} (hex: {theShortTwo:x8})\n");

            theShortOne = 0x7fff;
            theShortTwo = 0xffff;
            
            Console.WriteLine($"theShortOne: {theShortOne} (hex: {theShortOne:x8})");
            Console.WriteLine($"theShortTwo: {theShortTwo} (hex: {theShortTwo:x8})\n");
            
            /* -- These will overflow -- */

            theShortOne++;
            theShortTwo++;
            
            Console.WriteLine($"theShortOne: {theShortOne} (hex: {theShortOne:x8})");
            Console.WriteLine($"theShortTwo: {theShortTwo} (hex: {theShortTwo:x8})\n");

            theShortOne = -0x7fff - 1;
            theShortTwo = 0;
            
            Console.WriteLine($"theShortOne: {theShortOne} (hex: {theShortOne:x8})");
            Console.WriteLine($"theShortTwo: {theShortTwo} (hex: {theShortTwo:x8})\n");
            
            /* -- These will underflow -- */

            theShortOne--;
            theShortTwo--;
            
            Console.WriteLine($"theShortOne: {theShortOne} (hex: {theShortOne:x8})");
            Console.WriteLine($"theShortTwo: {theShortTwo} (hex: {theShortTwo:x8})\n");
        }
    }
}