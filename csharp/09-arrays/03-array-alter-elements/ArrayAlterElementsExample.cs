using System;
using System.Linq;

namespace ProgrimoireCSharpExamples
{
    internal static class ArrayAlterElementsExample
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
            
            /* -- Now reverse the array's contents and print -- */

            for (int i = 0, j = someArray.Length - 1; i < j; i++, j--)
            {
                var tmp = someArray[i];
                someArray[i] = someArray[j];
                someArray[j] = tmp;
            }

            for (var i = 0; i < someArray.Length; i++)
            {
                Console.WriteLine($"someArray[{i}] = {someArray[i]}");
            }

            Console.WriteLine();
            
            /* -- Use the static Array function to reverse array and print -- */
            
            Array.Reverse(someArray);
            
            for (var i = 0; i < someArray.Length; i++)
            {
                Console.WriteLine($"someArray[{i}] = {someArray[i]}");
            }

            Console.WriteLine();
            
            /* -- Now triple each element and print -- */

            for (var i = 0; i < someArray.Length; i++)
            {
                someArray[i] *= 3;
            }
            
            for (var i = 0; i < someArray.Length; i++)
            {
                Console.WriteLine($"someArray[{i}] = {someArray[i]}");
            }
        }
    }
}