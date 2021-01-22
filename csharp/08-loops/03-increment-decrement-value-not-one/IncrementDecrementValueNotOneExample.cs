using System;

namespace ProgrimoireCSharpExamples
{
    internal static class IncrementDecrementValueNotOneExample
    {
        public static void Main(string[] args)
        {
            /* -- Increment and decrement by a value other
                  than one using a for loop -- */
            
            for (var i = 0; i <= 20; i += 2)
                Console.WriteLine($"i: {i}");

            Console.WriteLine();

            for (var i = 30; i >= 0; i -= 3)
                Console.WriteLine($"i: {i}");

            Console.WriteLine();
            
            /* -- Do the same thing with while loops -- */
            
            var j = 0;

            while (j <= 20)
            {
                Console.WriteLine($"j: {j}");
                j += 2;
            }

            Console.WriteLine();

            j = 30;

            while (j >= 0)
            {
                Console.WriteLine($"j: {j}");
                j -= 3;
            }

            Console.WriteLine();
            
            /* -- Do the same thing with do-while loops -- */

            j = 0;

            do
            {
                Console.WriteLine($"j: {j}");
                j += 2;
                
            } while (j <= 20);

            Console.WriteLine();

            j = 30;

            do
            {
                Console.WriteLine($"j: {j}");
                j -= 3;
                
            } while (j >= 0);

            Console.WriteLine();
        }
    }
}
