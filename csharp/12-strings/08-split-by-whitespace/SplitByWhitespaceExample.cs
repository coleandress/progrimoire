using System;

namespace ProgrimoireCSharpExamples
{
    internal static class SplitByWhitespaceExample
    {
        public static void Main(string[] args)
        {
            const string s = "a string with words separated by whitespace";
            Console.WriteLine(s);

            Console.WriteLine();
            
            var splitString = s.Split(' ');
            
            foreach (var word in splitString)
                Console.WriteLine(word);
        }
    }
}