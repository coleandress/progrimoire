using System;

namespace ProgrimoireCSharpExamples
{
    internal static class IntExample
    {
        public static void Main(string[] args)
        {
            Console.WriteLine($"The size of an int is: {sizeof(int)} bytes\n");

            int theInteger = 0x7fffffff; // 2147483647

            Console.WriteLine($"theInteger: {theInteger} (hex: {theInteger:x8})\n");

            theInteger -= 147483647;
            
            Console.WriteLine($"theInteger: {theInteger} (hex: {theInteger:x8})\n");
            
            theInteger = -2147483648;
            
            Console.WriteLine($"theInteger: {theInteger}\n");
            
            /* -- This will underflow as we're already at the
                  min allowed value for an integer -- */

            theInteger = theInteger - 1;
            
            Console.WriteLine($"theInteger: {theInteger}\n");

            theInteger = 2147483647;
            
            /* -- This will overflow as we're already at
                  the max allowed value for an integer -- */

            theInteger = theInteger + 1;
            
            Console.WriteLine($"theInteger: {theInteger}\n");
            
            /* -- This code is heavily depending upon the fact that
                  sizeof(int) == 4, if that is not the case, see
                  'example2.c' for a size-independent version of
                  this code -- */
        }
    }
}