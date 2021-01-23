using System;

namespace ProgrimoireCSharpExamples
{
    internal static class NestedLoopsExample
    {
        public static void Main(string[] args)
        {
            /* -- Output times from 1 o'clock to 12:45, show
                  every 15 minutes -- */
            
            for (var hour = 1; hour <= 12; hour++)
                for (var minute = 0; minute < 60; minute += 15)
                    Console.WriteLine($"{hour}:{minute:D2}");

            Console.WriteLine();
            
            /* -- A set of three nested while loops -- */

            var i = 0;

            while (i < 2)
            {
                var j = 0;

                while (j < 2)
                {
                    var k = 0;

                    while (k < 2)
                    {
                        Console.WriteLine($"{i} {j} {k}");
                        k++;
                    }

                    j++;
                }

                i++;
            }

            Console.WriteLine();
        }
    }
}
