using System;

namespace ProgrimoireCSharpExamples
{
    internal static class BlanketOperationExample
    {
        public static void Main(string[] args)
        {
            var someArray = new int[] { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };

            ShowArray(someArray);

            Apply(someArray, DoubleIt);
            
            ShowArray(someArray);
            
            Apply(someArray, SquareIt);
            
            ShowArray(someArray);
        }

        private static void ShowArray(int[] arr)
        {
            for (var i = 0; i < arr.Length; i++)
                Console.Write("{0}{1}", i == 0 ? "" : ", ", arr[i]);

            Console.WriteLine();
        }

        private static void Apply(int[] arr, Func<int, int> theFunction)
        {
            for (var i = 0; i < arr.Length; i++)
                arr[i] = theFunction(arr[i]);
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