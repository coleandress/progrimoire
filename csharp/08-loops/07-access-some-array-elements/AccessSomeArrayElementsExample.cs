using System;

namespace ProgrimoireCSharpExamples
{
    internal static class AccessSomeArrayElementsExample
    {
        public static void Main(string[] args)
        {
            var someArray = new int[] {2, 3, 5, 7, 11, 13};
            
            /* -- Show every other element -- */
            
            for (var i = 0; i < someArray.Length; i += 2)
                Console.WriteLine($"someArray[{i}] = {someArray[i]}");

            Console.WriteLine();
            
            /* -- Show the first half of the array -- */
            
            for (var i = 0; i < someArray.Length / 2; i++)
                Console.WriteLine($"someArray[{i}] = {someArray[i]}");

            Console.WriteLine();
            
            /* -- Now the last half of the array -- */
            
            for (var i = someArray.Length / 2; i < someArray.Length; i++)
                Console.WriteLine($"someArray[{i}] = {someArray[i]}");

            Console.WriteLine();
        }
    }
}
