using System;

namespace ProgrimoireCSharpExamples
{
    internal static class ShortExample2
    {
        public static void Main(string[] args)
        {
            short maxValue = 0;

            for (short i = 0, n = sizeof(short); i < n; i++)
                maxValue |= (short)((i + 1 == n ? 0x7f : 0xff) << (i * 8));

            var theShort = maxValue;
            
            Console.WriteLine($"theShort: {theShort} (hex: {theShort:x8})\n");

            theShort -= 2767;
            
            Console.WriteLine($"theShort: {theShort} (hex: {theShort:x8})\n");

            theShort = (short)(-maxValue - 1);
            
            Console.WriteLine($"theShort: {theShort} (hex: {theShort:x8})\n");
            
            /* -- Will underflow as we're already at the
                  min value we can store in a short.
                  Avoid by using checked or comparing to
                  short.MinValue or System.Int16.MinValue -- */

            theShort = (short)(theShort - 1);
            
            Console.WriteLine($"theShort: {theShort} (hex: {theShort:x8})\n");
            
            /* -- Will overflow as we're already at the
                  max value we can store in a short.
                  Avoid by using checked or comparing to
                  short.MaxValue or System.Int16.MaxValue -- */

            theShort = (short)(theShort + 1);
           
            Console.WriteLine($"theShort: {theShort} (hex: {theShort:x8})\n");
        }
    }
}