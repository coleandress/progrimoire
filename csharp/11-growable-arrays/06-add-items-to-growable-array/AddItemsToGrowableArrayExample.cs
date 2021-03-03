using System;
using System.Collections.Generic;

namespace ProgrimoireCSharpExamples
{
    internal static class AddItemsToGrowableArrayExample
    {
        public static void Main(string[] args)
        {
            /* -- Create a list of 0 elements and add primes
                  from 0 to 99 to that list -- */
            
            var iList = new List<int>();

            const int amountOfPrimes = 100;

            for (var i = 0; i < amountOfPrimes; i++)
                if (IsPrime(i))
                    iList.Add(i);

            PrintList(iList);
        }

        private static bool IsPrime(int x)
        {
            if (x <= 2 || x % 2 == 0)
                return x == 2;

            var stop = (int) Math.Sqrt(x);
            
            for (var i = 3; i <= stop; i += 2)
                if (x % i == 0)
                    return false;

            return true;
        }

        private static void PrintList(List<int> list)
        {
            Console.Write("{ ");
            
            for (var i = 0; i < list.Count; i++)
                Console.Write("{0}{1}", i == 0 ? "" : ", ", list[i]);
            
            Console.Write(" }");
        }
    }
}
