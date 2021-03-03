using System;
using System.Collections.Generic;

namespace ProgrimoireCSharpExamples
{
    internal static class GrowableArrayLengthExample
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
            
            PrintList(iList);

            Console.WriteLine();

            Console.WriteLine("The number of items in the list is: {0}\n\n", iList.Count);
        }

        private static void PrintList(List<int> list)
        {
            Console.Write("{ ");
            
            for(var i = 0; i < list.Count; i++)
                Console.Write("{0}{1}", i == 0 ? "" : ", ", list[i]);
            
            Console.Write(" }\n");
        }
    }
}
