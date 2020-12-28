using System;

namespace ProgrimoireCSharpExamples
{
    internal static class DeclareArrayExample
    {
        public static void Main(string[] args)
        {
            /* -- First, we declare an array of size 10
                  The array is filled with the default value
                  of 0. -- */
            
            var someArray = new int[10];

            for (var i = 0; i < someArray.Length; i++)
            {
                Console.WriteLine($"someArray[{i}] = {someArray[i]}");
            }

            Console.WriteLine();
            
            /* -- Arrays can also be filled with values explicitly
                  when declared using two different syntax -- */

            int[] anotherArray = new int[] { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
            int[] yetAnotherArray = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

            for (var i = 0; i < anotherArray.Length; i++)
            {
                Console.WriteLine($"anotherArray[{i}] = {anotherArray[i]}");
            }

            Console.WriteLine();

            var counter = 0;
            foreach (var num in yetAnotherArray)
            {
                Console.WriteLine("yetAnotherArray[{0}] = {1}", counter++, num);
            }
            
            /* -- Declaring two dimensional arrays -- */

            var twoDArrayOne = new int[4, 3];

            int[,] twoDArrayTwo = { { 1, 2, 3 }, { 4, 5, 6 } };

            var jaggedArray = new int[3][];
            jaggedArray[0] = new int[5] { 5, 10, 15, 20, 25 };
            jaggedArray[1] = new int[2];
            jaggedArray[2] = new int [3] {3, 6, 9};

            foreach (var intArray in jaggedArray)
            {
                foreach (var num in intArray)
                {
                    Console.Write("{0,2} ", num);
                }

                Console.WriteLine();
            }
        }
    }
}