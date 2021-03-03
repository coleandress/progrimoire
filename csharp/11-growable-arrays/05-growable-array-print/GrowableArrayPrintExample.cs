using System;
using System.Collections.Generic;

namespace ProgrimoireCSharpExamples
{
    internal static class GrowableArrayPrintExample
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

            /* -- One line print each element -- */

            iList.ForEach(Console.WriteLine);

            Console.WriteLine();

            /* -- Join the elements together in a string -- */
            
            var joinedList = String.Join(", ", iList);
            Console.WriteLine($"{{ {joinedList} }}");

            Console.WriteLine();
            
            /* -- Print with a for loop -- */
            
            Console.Write("{ ");
            
            for (var i = 0; i < iList.Count; i++)
                Console.Write("{0}{1}", i == 0 ? "" : ", ", iList[i]);
            
            Console.Write(" }");

            Console.WriteLine();
        }
    }
}
