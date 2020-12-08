using System;

namespace ProgrimoireCSharpExamples
{
    internal static class ShortExample
    {
        public static void Main(string[] args)
        {
            Console.WriteLine($"The size of a short is: {sizeof(short)}\n");

            short theShortOne  = 0x7fff;
            ushort theShortTwo = 0xffff;
            
            Console.WriteLine($"theShortOne: {theShortOne} (hex: {theShortOne:x8})");
            Console.WriteLine($"theShortTwo: {theShortTwo} (hex: {theShortTwo:x8})\n");

            theShortOne -= 2767;
            theShortTwo -= 5535;
            
            Console.WriteLine($"theShortOne: {theShortOne} (hex: {theShortOne:x8})");
            Console.WriteLine($"theShortTwo: {theShortTwo} (hex: {theShortTwo:x8})\n");

            theShortOne = -0x7fff - 1;
            theShortTwo = 0;
            
            Console.WriteLine($"theShortOne: {theShortOne} (hex: {theShortOne:x8})");
            Console.WriteLine($"theShortTwo: {theShortTwo} (hex: {theShortTwo:x8})\n");
            
            /* -- Will underflow as we're already at the min value
                  we can store in both variables -- */

            try
            {
                checked
                {
                    theShortOne = (short) (theShortOne - 1);
                }
            }
            catch (Exception e)
            {
                Console.WriteLine($"theShortOne underflow\n");
            }
            
            try
            {
                checked
                {
                    theShortTwo = (ushort) (theShortTwo - 1);
                }
            }
            catch (Exception e)
            {
                Console.WriteLine($"theShortTwo underflow\n");
            }

            theShortOne = (short) (theShortOne - 1);
            theShortTwo = (ushort) (theShortTwo - 1);
            
            Console.WriteLine($"theShortOne: {theShortOne} (hex: {theShortOne:x8})");
            Console.WriteLine($"theShortTwo: {theShortTwo} (hex: {theShortTwo:x8})\n");

            theShortOne = 0x7fff;
            theShortTwo = 0xffff;
            
            Console.WriteLine($"theShortOne: {theShortOne} (hex: {theShortOne:x8})");
            Console.WriteLine($"theShortTwo: {theShortTwo} (hex: {theShortTwo:x8})\n");
            
            /* -- Will overflow as we're already at the max value
                  we can store in both variables -- */

            theShortOne = (short) (theShortOne + 1);
            theShortTwo = (ushort) (theShortTwo + 1);
            
            Console.WriteLine($"theShortOne: {theShortOne} (hex: {theShortOne:x8})");
            Console.WriteLine($"theShortTwo: {theShortTwo} (hex: {theShortTwo:x8})\n");
            
            /* -- This code is heavily dependent upon the
                  assumption that sizeof(short) == 2.  See
                  example2.c for a size-independent version -- */
        }
    }
}