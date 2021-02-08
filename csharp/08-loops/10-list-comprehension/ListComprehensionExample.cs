using System;
using System.Collections.Generic;
using System.Linq;

namespace ProgrimoireCSharpExamples
{
    internal static class ListComprehensionExample
    {
        public static void Main(string[] args)
        {
            List<int> numbers = new List<int>();
            
            for (var i = 0; i < 100000; i++)
                numbers.Add(i);

            /* -- Find all the primes in a list of numbers using Linq -- */
            
            var primes = numbers.Where(IsPrime).Select(x => x).ToList();
            
            foreach (var num in primes)
                Console.WriteLine($"{num}");

            Console.WriteLine();
            
            /* -- Double all numbers from 0 to 100 -- */

            var doubledNumbers = from x in Enumerable.Range(0, 101)
                select x * 2;
            
            foreach (var num in doubledNumbers)
                Console.WriteLine($"{num}");
            
            /* -- Square all numbers in the numbers list that are less than 50 -- */

            var squaredNumbers = from x in numbers
                where x < 50
                select x * x;
            
            foreach (var num in squaredNumbers)
                Console.WriteLine($"{num}");
        }

        private static bool IsPrime(int num)
        {
            if (num < 2)
                return false;
            
            for (var i = 2; i <= num / 2; i++)
            {
                if (num % i == 0)
                    return false;
            }

            return true;
        }
    }
}
