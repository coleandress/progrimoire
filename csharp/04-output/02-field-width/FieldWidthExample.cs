using System;

namespace ProgrimoireCSharpExamples
{
    internal static class FieldWidthExample
    {
        public static void Main(string[] args)
        {
            var greeting = "Hello, World!";
            var value = 42;

            Console.WriteLine("|{0, 20}|", greeting);
            Console.WriteLine($"|{greeting, 20}|");

            Console.WriteLine("|{0, 20}|", value);
            Console.WriteLine($"|{value, 20}|");

            Console.WriteLine("|12345678901234567890|");

            Console.WriteLine();

            Console.WriteLine("|{0, 15}|{1, 5}|{2, 25}|{3, 15}|", greeting, value, greeting, value);
            Console.WriteLine($"|{greeting, 15}|{value, 5}|{greeting, 25}|{value, 15}|");
            Console.WriteLine("|123456789012345|12345|1234567890123456789012345|123456789012345|\n");
        }
    }
}