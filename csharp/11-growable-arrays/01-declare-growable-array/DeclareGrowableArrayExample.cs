using System;
using System.Collections.Generic;

namespace ProgrimoireCSharpExamples
{
    internal static class DeclareGrowableArrayExample
    {
        public static void Main(string[] args)
        {
            /* -- Initialize the List and fill it with five 0s -- */
            
            var iList = new List<int>();

            PrintList(iList);

            for (var i = 0; i < 5; i++)
                iList.Add(0);
            
            PrintList(iList);

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

            /* -- Remove five elements starting at index 0 -- */
            
            iList.RemoveRange(0, 5);
            
            PrintList(iList);

            Console.WriteLine();
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
