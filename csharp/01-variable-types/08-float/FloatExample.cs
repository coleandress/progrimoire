using System;

namespace ProgrimoireCSharpExamples
{
    internal static class FloatExample
    {
        public static void Main(string[] args)
        {
            Console.WriteLine($"The size of a float is: {sizeof(float)} bytes\n");
            
            /* -- Add 'f' to to specify var as float
                  instead of the default: double -- */

            var theFloat = 123.456f;

            Console.WriteLine($"theFloat: {theFloat}\n");

            theFloat = 45.1234f;

            Console.WriteLine($"theFloat: {theFloat}\n");

            theFloat = 0.123456789f;
            
            Console.WriteLine($"theFloat: {theFloat}\n");

            Console.WriteLine($"theFloat: {theFloat:C9}");
            Console.WriteLine($"theFloat: {theFloat:C8}");
            Console.WriteLine($"theFloat: {theFloat:C7}");
            Console.WriteLine($"theFloat: {theFloat:C6}");
            Console.WriteLine($"theFloat: {theFloat:C5}");
            Console.WriteLine($"theFloat: {theFloat:C4}");
            Console.WriteLine($"theFloat: {theFloat:C3}");
            Console.WriteLine($"theFloat: {theFloat:C2}");
            Console.WriteLine($"theFloat: {theFloat:C1}");
        }
    }
}