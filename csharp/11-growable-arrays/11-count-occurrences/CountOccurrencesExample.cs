using System;
using System.Collections.Generic;
using System.Linq;

namespace ProgrimoireCSharpExamples
{
    internal static class CountOccurrencesExample
    {
        private static readonly Random Random = new Random();
        
        public static void Main(string[] args)
        {
            var iList = new List<int>();

            while (iList.Count < 20)
            {
                var value = GetRandomIntValue() % 100;
                
                if (IsPrime(value))
                    iList.Add(value);
            }
            
            PrintList(iList);
            Console.WriteLine();

            /* -- Print the numbers in the list and number of times
                  they occur -- */
            
            var groups = iList.GroupBy(x => x);

            foreach (var g in groups)
                Console.WriteLine($"number: {g.Key, 2}, count: {g.Count()}");

            Console.WriteLine();
            
            /* -- Check the list for specific numbers from 0 to 9 -- */

            for (var i = 0; i < 10; i++)
            {
                var count = 0;
                
                foreach (var num in iList)
                    if (num == i)
                        count++;

                if (count > 0)
                    Console.WriteLine($"number: {i, 2}, count: {count}");
            }

            Console.WriteLine();
        }

        private static int GetRandomIntValue()
        {
            return Random.Next();
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
            
            Console.Write(" }\n");
        }
    }
}
