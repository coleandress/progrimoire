using System;

namespace ProgrimoireCSharpExamples
{
    internal static class RecursiveExample
    {
        public static void Main(string[] args)
        {
            for (var i = 0; i <= 10; i++)
                Console.WriteLine($"GetSumRecursive({i}) = {Sum.GetSumRecursive(i)}");

            Console.WriteLine();

            for (var i = 0; i <= 10; i++)
                Console.WriteLine($"GetFactorialRecursive({i}) = {Factorial.GetFactorialRecursive(i)}");

            Console.WriteLine();

            var someArray      = new int[] {2, 3, 5, 7, 11};
            var someOtherArray = new int[] {11, 7, 5, 3, 2};

            Console.WriteLine($"maxValue: {ArrayFunctions.GetMaxRecursive(someArray)}");
            Console.WriteLine($"maxValue: {ArrayFunctions.GetMaxRecursive(someOtherArray)}");
            Console.WriteLine($"minValue: {ArrayFunctions.GetMinRecursive(someArray)}");
            Console.WriteLine($"minValue: {ArrayFunctions.GetMinRecursive(someOtherArray)}");

            Console.WriteLine();
            
            for (var i = 0; i < 100; i++)
                if (Prime.IsPrimeRecursive(i))
                    Console.WriteLine($"{i}");

            Console.WriteLine();
        }
    }

    /* -- Sum the numbers from: 1 ... n -- */
    
    public static class Sum
    {
        public static int GetSumRecursive(int n)
        {
            if (n <= 0)
                return 0;

            return n + GetSumRecursive(n - 1);
        }
    }
    
    /* -- Find the product of the numbers
          from 1 ... n -- */

    public static class Factorial
    {
        public static int GetFactorialRecursive(int n)
        {
            if (n <= 0)
                return 1;

            return n * GetFactorialRecursive(n - 1);
        }
    }

    public static class ArrayFunctions
    {
        /* -- Find the max value in 'array' -- */
        
        public static int GetMaxRecursive(int[] array)
        {
            return GetMaxRecursiveHelper(array, 0);
        }

        /* -- Find the min value in 'array' -- */
        
        public static int GetMinRecursive(int[] array)
        {
            return GetMinRecursiveHelper(array, 0);
        }

        /* -- Helper function to assist 'GetMaxRecursive' in
              recursively finding the maximum value in 'array' -- */
        
        private static int GetMaxRecursiveHelper(int[] array, int offset)
        {
            var current = array[offset];

            if (offset + 1 == array.Length)
                return current;

            var rest = GetMaxRecursiveHelper(array, offset + 1);

            return current >= rest ? current : rest;
        }

        /* -- Helper function to assist 'GetMinRecursive' in
              recursively finding the minimum value in 'array' -- */
        
        private static int GetMinRecursiveHelper(int[] array, int offset)
        {
            var current = array[offset];

            if (offset + 1 == array.Length)
                return current;

            var rest = GetMinRecursiveHelper(array, offset + 1);

            return current <= rest ? current : rest;
        }
    }

    public static class Prime
    {
        /* -- Is 'x' a prime number? -- */

        public static bool IsPrimeRecursive(int x)
        {
            if (x <= 2 || x % 2 == 0)
                return x == 2;

            return IsPrimeRecursiveHelper(x, 3);
        }
        
        /* -- Helper function to assist IsPrimeRecursive
              in recursively determining if 'x' is
              a prime number -- */

        private static bool IsPrimeRecursiveHelper(int x, int current)
        {
            if (current == x)
                return true;

            return x % current != 0 && IsPrimeRecursiveHelper(x, current + 1);
        }
    }
}
