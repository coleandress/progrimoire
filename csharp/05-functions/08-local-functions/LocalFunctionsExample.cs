using System;

namespace ProgrimoireCSharpExamples
{
    internal static class LocalFunctionsExample
    {
        public static void Main(string[] args)
        {
            /* -- Use a local function to add one -- */
            
            var value = 40;
            AddOne();

            void AddOne()
            {
                value++;
            }
            
            /* -- Use a lambda expression to add one.
                  Warning: there are heal allocation advantages
                  to using local functions over lambdas:
                  https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/classes-and-structs/local-functions-- */

            Action addOneAlso = () => value++;

            addOneAlso();

            Console.WriteLine($"value: {value}\n");
            
            /* -- Local function with parameters and a return value -- */

            var valueOne = 24;
            var valueTwo = 42;
            
            /* -- This could also use arrow notation -- */
            
            int GetMax(int x, int y)
            {
                return (x >= y) ? x : y;  // Parens not required, just for clarity
            }

            Console.WriteLine($"max: {GetMax(valueOne, valueTwo)}\n");
            
            /* -- A lambda expression with getMin -- */

            Func<int> getMin = () => (valueOne <= valueTwo) ? valueOne : valueTwo;

            Console.WriteLine($"min: {getMin()}\n");
        }
    }
}
