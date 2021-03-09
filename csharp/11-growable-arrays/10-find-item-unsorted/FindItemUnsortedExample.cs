using System;
using System.Collections.Generic;

namespace ProgrimoireCSharpExamples
{
    internal static class FindItemUnsortedExample
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
            
            /* -- Search our list for numbers 1 through 100 -- */

            for (var i = 0; i < 100; i++)
            {
                if (iList.Contains(i))
                    Console.WriteLine($"{i, 2} is in the list.");
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
