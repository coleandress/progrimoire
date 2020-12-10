using System;

namespace ProgrimoireCSharpExamples
{
    internal static class IntExample2
    {
        public static void Main(string[] args)
        {
            Console.WriteLine($"The size of an int is: {sizeof(int)} bytes\n");

            var maxValue = 0;

            for (int i = 0, n = sizeof(int); i < n; i++)
                maxValue |= (i + 1 == n ? 0x7f : 0xff) << (i * 8);

            var theInteger = maxValue;
            
            Console.WriteLine($"theInteger: {theInteger} (hex: {theInteger:x8})\n");

            theInteger -= 147483647;
            
            Console.WriteLine($"theInteger: {theInteger} (hex: {theInteger:x8})\n");

            theInteger = -maxValue - 1;
            
            Console.WriteLine($"theInteger: {theInteger}\n");
            
            /* -- This will underflow as we're already at the
                  min allowed value for an integer -- */

            theInteger = theInteger - 1;
            
            Console.WriteLine($"theInteger: {theInteger}\n");

            theInteger = maxValue;
            
            /* -- This will overflow as we're already at
                  the max allowed value for an integer -- */

            theInteger = theInteger + 1;
            
            Console.WriteLine($"theInteger: {theInteger}\n");
        }
    }
}