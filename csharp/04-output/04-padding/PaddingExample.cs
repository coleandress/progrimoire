using System;

namespace ProgrimoireCSharpExamples
{
    internal static class PaddingExample
    {
        public static void Main(string[] args)
        {
            var value = 42;
            
            /* -- Padding a number with '0's on left or right. -- */
            
            Console.WriteLine($"|{value, 20}|");
            Console.WriteLine($"|{value.ToString().PadLeft(20, '0')}|");
            Console.WriteLine($"|{value, -20}|");
            Console.WriteLine("|{0}|", value.ToString().PadRight(20, '0'));

            /* -- Padding a string with '-'s on left or right -- */
            var greeting = "Hello, World";
            Console.WriteLine($"|{greeting.PadLeft(20, '-'), 20}|");
            Console.WriteLine("|{0}|", greeting.PadRight(20, '-'));

            /* -- Adding padding to left and right side of a string -- */
            
            var resultStringSize = 20;
            var paddingForLeftSide = (resultStringSize - greeting.Length) * 2;

            var newPaddedString = greeting.PadLeft(paddingForLeftSide, '=')
                .PadRight(resultStringSize, '=');
            
            Console.WriteLine($"|{newPaddedString}|");
            Console.WriteLine("|12345678901234567890|\n");
        }
    }
}