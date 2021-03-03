using System;
using System.Collections.Generic;

namespace ProgrimoireCSharpExamples
{
    internal static class GrowableArrayStepThroughElementsExample
    {
        public static void Main(string[] args)
        {
            var iList = new List<int>();

            /* -- Add primes up to 49 to the List -- */
            
            for (var i = 2; i < 50; i++)
            {
                var divisors = 0;
                
                for (var j = 2; j < i; j++)
                    if (i % j == 0)
                        divisors++;

                if (divisors == 0)
                    iList.Add(i);
            }
            
            /* -- Step through elements with foreach loop -- */
            
            foreach (var num in iList)
                Console.WriteLine(num);

            Console.WriteLine();
            
            /* -- foreach with indexes assuming no duplicates -- */
            
            foreach (var num in iList)
                Console.WriteLine($"iList[{iList.IndexOf(num)}] = {num}");

            Console.WriteLine();
            
            /* -- for loop -- */

            for (var i = 0; i < iList.Count; i++)
                Console.WriteLine($"iList[{i}] = {iList[i]}");
        }
    }
}
