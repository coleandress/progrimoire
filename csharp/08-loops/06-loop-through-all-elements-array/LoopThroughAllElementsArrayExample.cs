using System;

namespace ProgrimoireCSharpExamples
{
    internal static class LoopThroughAllElementsArrayExample
    {
        public static void Main(string[] args)
        {
            var someArray = new int[] {2, 3, 5, 7, 11, 13};
            
            for (var i = 0; i < someArray.Length; i++)
                Console.WriteLine($"someArray[{i}] = {someArray[i]}");

            Console.WriteLine();
            
            /* -- Using a foreach loop to step through the array -- */

            foreach (var n in someArray)
                Console.WriteLine($"someArray[{Array.IndexOf(someArray, n)}] = {n}");
            
            /* -- C# will thrown an exception if you go out of bounds
                  of the array -- */
            
            /*for (var i = 20; i < 30; i++)
                Console.WriteLine($"someArray[{i}] = {someArray[i]}");

            for (var i = -100; i < 0; i++)
                someArray[i] = i;*/

            Console.WriteLine();
        }
    }
}
