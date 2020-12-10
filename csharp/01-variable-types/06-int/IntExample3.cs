using System;

namespace ProgrimoireCSharpExamples
{
    internal static class IntExample3
    {
        public static void Main(string[] args)
        {
            Int32 theIntOne  = 0x7fffffff;
            UInt32 theIntTwo = 0xffffffff;
            
            Console.WriteLine($"theIntOne: {theIntOne} (hex: {theIntOne:x8})");
            Console.WriteLine($"theIntTwo: {theIntTwo} (hex: {theIntTwo:x8})\n");

            theIntOne -= 147483647;
            theIntTwo -= 294967295;
            
            Console.WriteLine($"theIntOne: {theIntOne} (hex: {theIntOne:x8})");
            Console.WriteLine($"theIntTwo: {theIntTwo} (hex: {theIntTwo:x8})\n");

            theIntOne = 0x7fffffff;
            theIntTwo = 0xffffffff;
            
            Console.WriteLine($"theIntOne: {theIntOne} (hex: {theIntOne:x8})");
            Console.WriteLine($"theIntTwo: {theIntTwo} (hex: {theIntTwo:x8})\n");
            
            /* -- These will overflow -- */

            theIntOne++;
            theIntTwo++;
            
            Console.WriteLine($"theIntOne: {theIntOne} (hex: {theIntOne:x8})");
            Console.WriteLine($"theIntTwo: {theIntTwo} (hex: {theIntTwo:x8})\n");

            theIntOne = -0x7fffffff - 1;
            theIntTwo = 0;
            
            Console.WriteLine($"theIntOne: {theIntOne} (hex: {theIntOne:x8})");
            Console.WriteLine($"theIntTwo: {theIntTwo} (hex: {theIntTwo:x8})\n");
            
            /* -- These will underflow -- */

            theIntOne--;
            theIntTwo--;
            
            Console.WriteLine($"theIntOne: {theIntOne} (hex: {theIntOne:x8})");
            Console.WriteLine($"theIntTwo: {theIntTwo} (hex: {theIntTwo:x8})\n");
        }
    }
}