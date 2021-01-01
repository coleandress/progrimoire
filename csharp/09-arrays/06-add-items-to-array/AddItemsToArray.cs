using System;

namespace ProgrimoireCSharpExamples
{
    internal static class AddItemsToArrayExample
    {
        private const int Items = 20;
        private const int N = 6;
        
        public static void Main(string[] args)
        {
            /* -- Initialize array and resize -- */
            
            var someArray = new int[] { 2, 3, 5, 7, 11, 13 };
            Array.Resize(ref someArray, Items);
            
            /* -- Now let's store elements in the unused locations --*/

            for (int i = N, j = -1; i < Items; i++, j--)
                someArray[i] = j;
            
            for (int i = 0, n = someArray.Length; i < n; i++)
                Console.WriteLine($"someArray[{i}] = {someArray[i]}");

            Console.WriteLine();
        }
    }
}