using System;

namespace ProgrimoireCSharpExamples
{
    internal static class PrintAggregateExample
    {
        public static void Main(string[] args)
        {
            var someArray = new int[] {2, 3, 5, 7, 11};

            /* -- The simplest C# way -- */

            Console.WriteLine(string.Join(", ", someArray));

            /* -- The regular way -- */

            for (var i = 0; i < someArray.Length; i++)
            {
                if (i > 0)
                    Console.Write(", ");

                Console.Write($"{someArray[i]}");
            }

            Console.WriteLine("\n");

            var someOtherArray = new int[][]
            {
                new int[] {1, 2, 3},
                new int[] {4, 5, 6},
                new int[] {7, 8, 9},
                new int[] {10, 11, 12}
            };

            /* -- One way, but difficult to format output because
                  string.Join() returns a complete string for each row -- */
            
            foreach (var row in someOtherArray)
            {
                Console.WriteLine(string.Join(", ", row));
            }

            Console.WriteLine();

            /* -- A better way to print out a matrix -- */

            for (var i = 0; i < someOtherArray.Length; i++)
            {
                for (var j = 0; j < someOtherArray[i].Length; j++)
                {
                    if (j > 0)
                        Console.Write(", ");

                    Console.Write($"{someOtherArray[i][j],2}");
                }

                Console.WriteLine();
            }

            Console.WriteLine();

            /* -- Same as the last example, but with a foreach loop -- */

            foreach (var row in someOtherArray)
            {
                for (var col = 0; col < row.Length; col++)
                {
                    if (col > 0)
                        Console.Write(", ");

                    Console.Write($"{row[col],2}");
                }

                Console.WriteLine();
            }

            Console.WriteLine();

            var aJaggedArray = new int[][]
            {
                new int[] {2, 3},
                new int[] {13, 17, 19, 23, 29, 5, 7, 11},
                new int[] {31, 37, 41, 43},
                new int[] {53, 59, 61, 67, 71, 47}
            };

            /* -- Print a jagged array, left justified -- */
            
            for (var i = 0; i < aJaggedArray.Length; i++)
            {
                for (var j = 0; j < aJaggedArray[i].Length; j++)
                {
                    if (j > 0)
                        Console.Write(", ");

                    Console.Write($"{aJaggedArray[i][j], 2}");
                }

                Console.WriteLine();
            }

            Console.WriteLine();
        }
    }
}
