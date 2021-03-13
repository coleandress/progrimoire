using System;

namespace ProgrimoireCSharpExamples
{
    internal static class RemoteWhitespaceExample
    {
        public static void Main(string[] args)
        {
            var aString = "There is a bit of whitespace in this string";
            var bString = "ThisOneOnTheOtherHandDoesn'tHaveAny";

            var aStringNoWhitespace = aString.Replace(" ", "");
            var bStringNoWhitespace = bString.Replace(" ", "");
            
            Console.WriteLine($"{aStringNoWhitespace}");
            Console.WriteLine($"{bStringNoWhitespace}");
        }
    }
}