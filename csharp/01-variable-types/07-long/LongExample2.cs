using System;

namespace ProgrimoireCSharpExamples
{
    internal static class LongExample2
    {
        public static void Main(string[] args)
        {
            Console.WriteLine($"The size of a long is {sizeof(long)} bytes\n");

            long maxValue = 0;

            for (int i = 0, n = sizeof(long); i < n; i++)
            {
                long current = (i + 1 == n ? 0x7f : 0xff);

                maxValue |= current << (i * 8);
            }

            var theValue = maxValue;

            Console.WriteLine($"theValue: {theValue}\n");
            
            /* -- This will overflow as we're at the
                  max value for 'long' already -- */

            theValue += 1;
            
            Console.WriteLine($"theValue: {theValue}\n");

            theValue = -maxValue - 1;
            
            Console.WriteLine($"theValue: {theValue}\n");
            
            /* -- This will underflow as we're at the
                  min value for 'long' already -- */

            theValue -= 1;
            
            Console.WriteLine($"theValue: {theValue}\n");
        }
    }
}