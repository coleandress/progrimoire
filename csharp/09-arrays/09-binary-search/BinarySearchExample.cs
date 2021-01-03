using System;

namespace ProgrimoireCSharpExamples
{
    internal static class BinarySearchExample
    {
        public static void Main(string[] args)
        {
            var someArray = new int[] { 31, 3, 7, 23, 11, 13, 2, 17, 19, 5, 29 };
            
            /* -- Array must be sorted for binary search -- */
            
            Array.Sort(someArray);

            foreach (var num in someArray)
            {
                Console.WriteLine(num);
            }

            Console.WriteLine();

            /* -- Array.BinarySearch() returns the index of the found value or
                  a negative number if the value is not found.  If the array
                  is not sorted, the wrong, or even a negative value will be
                  returned. -- */
            
            for (var i = 0; i < 40; i++)
            {
                var foundIndex = Array.BinarySearch(someArray, i);
                Console.WriteLine("{0} was {1}", i, foundIndex >= 0 ? "found" : "not found");
            }
        }
    }
}