using System;
using System.Collections.Generic;

namespace ProgrimoireCSharpExamples
{
    internal static class ForOneToTenExample
    {
        public static void Main(string[] args)
        {
            /* -- Count from one to ten using a for loop, not the
                  differing start/stop conditions -- */
            
            for (var i = 1; i <= 10; i++)
                Console.WriteLine($"i: {i}");

            Console.WriteLine();
            
            for (var i = 0; i < 10; i++)
                Console.WriteLine($"i: {i + 1}");

            Console.WriteLine();
            
            /* -- Count through a list of numbers with a foreach loop -- */
            
            var numbers = new List<int>() {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
            
            foreach (var n in numbers)
                Console.WriteLine($"{numbers.IndexOf(n)}: {n}");

            Console.WriteLine();
        }
    }
}
