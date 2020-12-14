using System;

namespace ProgrimoireCSharpExamples
{
    internal static class MathExample
    {
        public static void Main(string[] args)
        {
            const int value = -12345;

            Console.WriteLine($"The square root of: 64.0 is: {Math.Sqrt(64.0)}");
            Console.WriteLine($"The sin of: {Math.PI} is: {Math.Sin(Math.PI)}");
            Console.WriteLine($"The cos of: {Math.PI} is: {Math.Cos(Math.PI)}");
            Console.WriteLine($"The natural log of: 2.0 is: {Math.Log(2.0)}");
            Console.WriteLine($"The log base 10 of: 1000.0 is: {Math.Log(1000.0)}");
            Console.WriteLine($"The value of: exp(1.0) is: {Math.Exp(1.0)}");
            Console.WriteLine($"The value of: 2.0^3.0 is: {Math.Pow(2.0, 3.0)}");
            Console.WriteLine($"The absolute value of: {value} is: {Math.Abs(value)}");
        }
    }
}