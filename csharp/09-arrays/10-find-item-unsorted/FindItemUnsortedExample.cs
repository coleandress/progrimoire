using System;

namespace ProgrimoireCSharpExamples
{
    internal static class FindItemUnsortedExample
    {
        public static void Main(string[] args)
        {
            var someArray = new int[] { 31, 3, 7, 23, 11, 13, 2, 17, 19, 5, 29 };

            /* -- C# provides many methods for searching for an item in an array
                  that all begin with 'Find' -- */
            
            for (var i = 0; i < 40; i++)
            {
                /* -- Returns the index -- */
                var index = Array.FindIndex(someArray, (num) => num == i);
                Console.WriteLine("{0} was {1}", i, index >= 0 ? "found" : "not found");
            }

            Console.WriteLine();
            
            for (var i = 0; i < 40; i++)
            {
                /* -- Returns the value or 0 if not found -- */
                var index = Array.Find(someArray, (num) => num == i);
                Console.WriteLine("{0} was {1}", i, index != 0 ? "found" : "not found");
            }

            Console.WriteLine();
            
            /* -- Other methods include FindLast(), which searches from the back
                  and returns the value, FindLastIndex(), which appropriately returns
                  the last index of the value that matches the specified search, and
                  FindAll(), which returns all values that match the specified search.
                  within an array --*/
            
            /* -- FindAll() example -- */
            
            var valuesGreaterThanTen = Array.FindAll(someArray, (num) => num > 10);

            foreach (var num in valuesGreaterThanTen)
            {
                Console.WriteLine(num);
            }
        }
    }
}