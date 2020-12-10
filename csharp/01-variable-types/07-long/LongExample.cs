using System;

namespace ProgrimoireCSharpExamples
{
    internal static class LongExample
    {
        public static void Main(string[] args)
        {
            Console.WriteLine($"The size of a long is {sizeof(long)} bytes\n");

            var theValue = 0x7FFFFFFFFFFFFFFF;

            Console.WriteLine($"theValue: {theValue}\n");
            
            /* -- This will overflow as we're at the
                  max value for 'long' already -- */

            theValue += 1;

            Console.WriteLine($"theValue: {theValue}\n");

            theValue = -0x7FFFFFFFFFFFFFFF - 1;
            
            Console.WriteLine($"theValue: {theValue}\n");
            
            /* -- This will underflow as we're at the
                  min value for 'long' already -- */

            theValue -= 1;
            
            Console.WriteLine($"theValue: {theValue}\n");
        }
    }
}