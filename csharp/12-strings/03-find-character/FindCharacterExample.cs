using System;

namespace ProgrimoireCSharpExamples
{
    internal static class FindCharacterExample
    {
        public static void Main(string[] args)
        {
            const string s1 = "pack my box with five dozen liquor jugs";
            const string s2 = "THE FIVE BOXING WIZARDS JUMP QUICKLY";
            const string s3 = "ThE qUiCk BrOwN fOx JuMpEd OvEr ThE lAzY dOg";

            FindLetters(s1);

            Console.WriteLine();
            
            FindLetters(s2);

            Console.WriteLine();

            FindLetters(s3);
        }

        private static void FindLetters(string s)
        {
            for (var i = 'a'; i <= 'z'; i++)
                if (s.Contains(i.ToString()))
                    Console.WriteLine($"Found char '{i}'");
                else
                    Console.WriteLine($"Did not find char '{i}'");
            
            for (var i = 'A'; i <= 'Z'; i++)
                if (s.Contains(i.ToString()))
                    Console.WriteLine($"Found char '{i}'");
                else
                    Console.WriteLine($"Did not find char '{i}'");
        }
    }
}