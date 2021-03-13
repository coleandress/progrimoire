using System;

namespace ProgrimoireCSharpExamples
{
    internal static class StepCharByCharExample
    {
        public static void Main(string[] args)
        {
            const string s = "pack my box with five dozen liquor jugs";
            
            for (var i = 0; i < s.Length; i++)
                Console.WriteLine($"s[{i}] = '{s[i]}'");

            Console.WriteLine();

            foreach (var c in s)
                Console.WriteLine($"{(char) (c + 5)}");
        }
    }
}