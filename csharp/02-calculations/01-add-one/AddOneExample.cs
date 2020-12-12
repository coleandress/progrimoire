using System;

namespace ProgrimoireCSharpExamples
{
    internal static class AddOneExample
    {
        public static void Main(string[] args)
        {
            var someNumber = 42;
            var ten        = 10;

            Console.WriteLine($"someNumber: {someNumber}");
            
            /* -- Add one in the most vanilla way -- */

            someNumber = someNumber + 1;

            Console.WriteLine($"someNumber: {someNumber}");
            
            /* -- Add one in a moderately slicker way -- */

            someNumber += 1;
            
            Console.WriteLine($"someNumber: {someNumber}");
            
            /* -- Add one in the most succinct way -- */

            someNumber++;
            
            Console.WriteLine($"someNumber: {someNumber}\n");

            Console.WriteLine($"ten: {ten}");
            Console.WriteLine($"ten++: {ten++}");
            Console.WriteLine($"++ten: {++ten}");
            Console.WriteLine($"ten: {ten}");
        }
    }
}