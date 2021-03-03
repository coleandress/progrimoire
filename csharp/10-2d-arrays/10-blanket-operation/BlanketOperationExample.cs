using System;

namespace ProgrimoireCSharpExamples
{
    internal static class BlanketOperationExample
    {
        private delegate int Del(int x);
        
        public static void Main(string[] args)
        {
            const int rows = 3;
            const int cols = 5;
            
            var someArray = new int[rows, cols];

            for (int i = 0, k = 1; i < someArray.GetLength(0); i++)
                for (var j = 0; j < someArray.GetLength(1); j++)
                    someArray[i, j] = k++;

            PrintArray(someArray);

            Apply(someArray, DoubleIt);
            
            PrintArray(someArray);

            Apply(someArray, SquareIt);
            
            PrintArray(someArray);

            Console.WriteLine();
        }

        private static void PrintArray(int[,] arr)
        {
            for (var i = 0; i < arr.GetLength(0); i++)
            {
                Console.Write("{ ");

                for (var j = 0; j < arr.GetLength(1); j++)
                    Console.Write("{0}{1,3}", j == 0 ? "" : ", ", arr[i, j]);

                Console.Write(" }\n");
            }

            Console.WriteLine();
        }

        private static void Apply(int[,] arr, Del theFunction)
        {
            for (var i = 0; i < arr.GetLength(0); i++)
                for (var j = 0; j < arr.GetLength(1); j++)
                    arr[i, j] = theFunction(arr[i, j]);
        }

        private static int DoubleIt(int x)
        {
            return 2 * x;
        }

        private static int SquareIt(int x)
        {
            return x * x;
        }
    }
}
