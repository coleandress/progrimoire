using System;

namespace ProgrimoireCSharpExamples
{
    internal static class ArrayPrintExample
    {
        public static void Main(string[] args)
        {
            /* -- Create and print our initial array the easy way -- */
            
            int[] someArray = { 2, 3, 5, 7, 11 };
            
            Console.WriteLine(string.Join(", ", someArray));

            Console.WriteLine();
            
            /* -- The easy way but one arg per line -- */
            
            Console.WriteLine(string.Join("\n", someArray));

            Console.WriteLine();
            
            /* -- The conventional way -- */

            for (var i = 0; i < someArray.Length; i++)
            {
                Console.WriteLine($"someArray[{i}] = {someArray[i]}");
            }

            Console.WriteLine();
            
            /* -- Printing each element with a foreach loop -- */

            foreach (var num in someArray)
            {
                Console.WriteLine(num);
            }

            Console.WriteLine();
            
            /* -- Printing each element with the static ForEach method -- */
            
            Array.ForEach(someArray, Console.WriteLine);
            Console.WriteLine();
            
            /* -- Using our own method -- */
            
            Array.ForEach(someArray, PrintArray);
            Console.WriteLine();
            
            /* -- Using a lambda -- */

            Array.ForEach(someArray, (num) => Console.WriteLine(num));
            Console.WriteLine();
        }

        private static void PrintArray(int num)
        {
            Console.WriteLine(num);
        }
    }
}