using System;

namespace ProgrimoireCSharpExamples
{
    internal static class StringLengthExample
    {
        public static void Main(string[] args)
        {
            var theString = "abcdefghijklmnopqrstuvwxyz";

            /* -- String objects have a Length property -- */
            
            Console.WriteLine($"length of: '{theString}' is {theString.Length}");
        }
    }
}