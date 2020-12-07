using System;

namespace ProgrimoireCSharpExamples
{
    internal static class CharExample
    {
        public static void Main(string[] args)
        {
            var someCharacter = 'Q';
            
            Console.WriteLine($"someCharacter: '{someCharacter}'");

            someCharacter = 'X';
            
            Console.WriteLine($"someCharacter: '{someCharacter}");

            someCharacter++;

            Console.WriteLine($"someCharacter: '{someCharacter}");
        }
    }
}