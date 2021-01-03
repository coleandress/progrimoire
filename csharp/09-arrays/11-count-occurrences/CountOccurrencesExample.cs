using System;
using System.Linq;

namespace ProgrimoireCSharpExamples
{
    internal static class CountOccurrencesExample
    {
        public static void Main(string[] args)
        {
            var someArray = new int[] { 1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5 };

            /* -- Using the Array.FindAll() method -- */
            
            for (var i = 0; i < 6; i++)
            {
                var foundItems = Array.FindAll(someArray, (num) => num == i);
                Console.WriteLine("{0} was found {1} time{2}", i, foundItems.Length, foundItems.Length == 1 ? "" : "s");
            }

            Console.WriteLine();
            
            /* -- Without making use of the Array.FindAll() method -- */

            for (var i = 0; i < 6; i++)
            {
                var count = 0;

                foreach (var num in someArray)
                    if (num == i)
                        count++;

                Console.WriteLine("{0} was found {1} time{2}", i, count, count == 1 ? "" : "s");
            }

            Console.WriteLine();
            
            /* -- Using LINQ -- */

            for (var i = 0; i < 6; i++)
            {
                var count = someArray.Count(num => num == i);

                Console.WriteLine("{0} was found {1} time{2}", i, count, count == 1 ? "" : "s");
            }
        }
    }
}