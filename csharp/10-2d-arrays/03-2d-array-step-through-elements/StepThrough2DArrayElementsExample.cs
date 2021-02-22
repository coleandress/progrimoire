using System;

namespace ProgrimoireCSharpExamples
{
    internal static class StepThrough2DArrayElementsExample
    {
        public static void Main(string[] args)
        {
            /* -- Step through each element in 'someArray' adding
                  the values to 'sum' -- */
            
            var someArray = new int[,]
            {
                {  2,  3,  5,  7, 11 },
                { 13, 17, 19, 23, 29 },
                { 31, 37, 41, 43, 47 },
                { 53, 57, 59, 61, 67 }
            };

            var sum = 0;

            foreach (var num in someArray)
                sum += num;

            Console.WriteLine($"sum: {sum}");

            Console.WriteLine();
            
            /* -- Add to each element, the value of the previous element -- */

            var lastElement = 0;

            for (var i = 0; i < someArray.GetLength(0); i++)
            {
                for (var j = 0; j < someArray.GetLength(1); j++)
                {
                    var current = someArray[i, j];
                    someArray[i, j] += lastElement;
                    lastElement = current;
                }
            }
            
            /* -- Now, display the array -- */

            var totalCols = someArray.GetLength(1);
            var currentCol = 0;

            foreach (var num in someArray)
            {
                Console.Write("{0}{1, 3}", currentCol == 0 ? "{ " : ", ", num);

                if (++currentCol >= totalCols)
                {
                    Console.Write(" }\n");
                    currentCol = 0;
                }
            }

            Console.WriteLine();
            
            /* -- or display the same way as previous examples -- */

            for (var i = 0; i < someArray.GetLength(0); i++)
            {
                Console.Write("{ ");

                for (var j = 0; j < someArray.GetLength(1); j++)
                    Console.Write("{0}{1, 3}", j == 0 ? "" : ", ", someArray[i, j]);
                
                Console.Write(" }\n");
            }

            Console.WriteLine();
        }
    }
}
