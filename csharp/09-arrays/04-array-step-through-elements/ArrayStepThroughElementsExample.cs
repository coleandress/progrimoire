using System;

namespace ProgrimoireCSharpExamples
{
    internal static class ArrayStepThroughElementsExample
    {
        public static void Main(string[] args)
        {
            /* -- Create and print our initial array -- */
            
            int[] someArray = { 2, 3, 5, 7, 11 };

            for (var i = 0; i < someArray.Length; i++)
            {
                Console.WriteLine($"someArray[{i}] = {someArray[i]}");
            }

            Console.WriteLine();
            
            /* -- Now print it backwards -- */

            for (var i = someArray.Length - 1; i >= 0; i--)
            {
                Console.WriteLine($"someArray[{i}] = {someArray[i]}");
            }

            Console.WriteLine();
            
            /* -- Now, print every other element -- */

            for (var i = 0; i < someArray.Length; i += 2)
            {
                Console.WriteLine($"someArray[{i}] = {someArray[i]}");
            }
        }
    }
}