using System;

namespace ProgrimoireCSharpExamples
{
    internal static class FindCharacterLocationExample
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

            Console.WriteLine();

            FindLettersLastIndex(s3);

            Console.WriteLine();

            const string vowels = "aeiouAEIOU";

            FindIndexOfFirstCharInString(s1, vowels);

            Console.WriteLine();
            
            FindIndexOfFirstCharInString("qwrmnpz", vowels);
        }

        private static void FindLetters(string s)
        {
            for (var i = 'a'; i <= 'z'; i++)
                if (s.Contains(i.ToString()))
                    Console.WriteLine($"char: '{i}', location: {s.IndexOf(i)}");
            
            for (var i = 'A'; i <= 'Z'; i++)
                if (s.Contains(i.ToString()))
                    Console.WriteLine($"char: '{i}', location: {s.IndexOf(i)}");
        }
        
        private static void FindLettersLastIndex(string s)
        {
            for (var i = 'a'; i <= 'z'; i++)
                if (s.Contains(i.ToString()))
                    Console.WriteLine($"char: '{i}', location: {s.LastIndexOf(i)}");
            
            for (var i = 'A'; i <= 'Z'; i++)
                if (s.Contains(i.ToString()))
                    Console.WriteLine($"char: '{i}', location: {s.LastIndexOf(i)}");
        }

        private static void FindIndexOfFirstCharInString(string theString, string theChars)
        {
            var indexOfFirstVowel = theString.IndexOfAny(theChars.ToCharArray());

            Console.WriteLine("{0}",
                indexOfFirstVowel < 0
                    ? $"No vowel found in '{theString}'"
                    : $"Index of first vowel in '{theString}': {indexOfFirstVowel}");
        }
    }
}