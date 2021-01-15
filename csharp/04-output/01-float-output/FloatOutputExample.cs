using System;

namespace ProgrimoireCSharpExamples
{
    internal static class FloatOutputExample
    {
        public static void Main(string[] args)
        {
            /* -- The number after the '.' specifies the number
                  of decimal places to display -- */

            Console.WriteLine($"{Math.PI:N0}");
            Console.WriteLine($"{Math.PI:N1}");
            Console.WriteLine($"{Math.PI:N2}");
            Console.WriteLine($"{Math.PI:N3}");
            Console.WriteLine($"{Math.PI:N4}");
            Console.WriteLine($"{Math.PI:N5}");
            Console.WriteLine($"{Math.PI:N6}");
            Console.WriteLine($"{Math.PI:N7}");
            Console.WriteLine($"{Math.PI:N8}");
            Console.WriteLine($"{Math.PI:N9}");

            Console.WriteLine();

            /* -- Using a loop with the ToString() format
                  argument to achieve the same result. -- */
            
            for (var i = 0; i <= 9; i++)
            {
                Console.WriteLine(Math.PI.ToString("N" + i));
            }

            Console.WriteLine();
        }
    }
}