using System;

namespace ProgrimoireCSharpExamples
{
    internal static class DoubleExample
    {
        public static void Main(string[] args)
        {
            Console.WriteLine($"The size of a double is: {sizeof(double)} bytes\n");
            
            var theDouble = 123.456;

            Console.WriteLine($"theDouble: {theDouble}\n");

            theDouble = 45.1234;

            Console.WriteLine($"theDouble: {theDouble}\n");

            theDouble = 0.123456789;
            
            Console.WriteLine($"theDouble: {theDouble}\n");

            Console.WriteLine($"theDouble: {theDouble:C9}");
            Console.WriteLine($"theDouble: {theDouble:C8}");
            Console.WriteLine($"theDouble: {theDouble:C7}");
            Console.WriteLine($"theDouble: {theDouble:C6}");
            Console.WriteLine($"theDouble: {theDouble:C5}");
            Console.WriteLine($"theDouble: {theDouble:C4}");
            Console.WriteLine($"theDouble: {theDouble:C3}");
            Console.WriteLine($"theDouble: {theDouble:C2}");
            Console.WriteLine($"theDouble: {theDouble:C1}\n");
            
            /* -- For financial calculations, use decimal -- */
            
            Console.WriteLine($"The size of a decimal is: {sizeof(decimal)} bytes\n");
            
            var theDecimal = 123.456M;

            Console.WriteLine($"theDecimal: {theDecimal}\n");

            theDecimal = 45.1234M;

            Console.WriteLine($"theDecimal: {theDecimal}\n");

            theDecimal = 0.123456789M;
            
            Console.WriteLine($"theDecimal: {theDecimal}\n");

            Console.WriteLine($"theDecimal: {theDecimal:C9}");
            Console.WriteLine($"theDecimal: {theDecimal:C8}");
            Console.WriteLine($"theDecimal: {theDecimal:C7}");
            Console.WriteLine($"theDecimal: {theDecimal:C6}");
            Console.WriteLine($"theDecimal: {theDecimal:C5}");
            Console.WriteLine($"theDecimal: {theDecimal:C4}");
            Console.WriteLine($"theDecimal: {theDecimal:C3}");
            Console.WriteLine($"theDecimal: {theDecimal:C2}");
            Console.WriteLine($"theDecimal: {theDecimal:C1}");
            
        }
    }
}