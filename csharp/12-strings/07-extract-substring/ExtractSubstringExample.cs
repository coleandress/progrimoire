using System;

namespace ProgrimoireCSharpExamples
{
    internal static class ExtractSubstringExample
    {
        public static void Main(string[] args)
        {
            const string theString = "abcdefghijklmnopqrstuvwxyz";
            
            for (var i = 1; i < 8; i++)
                Console.WriteLine($"'{theString.Substring(i, 2 * i)}'");
        }
    }
}