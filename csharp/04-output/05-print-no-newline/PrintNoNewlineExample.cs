using System;

namespace ProgrimoireCSharpExamples
{
    internal static class PrintNoNewlineExample
    {
        public static void Main(string[] args)
        {
            Console.Write("Hello, ");
            Console.Write("World!\n\n");
            
            for (var c = 'a'; c <= 'z'; c++)
                Console.Write($"{c}");

            Console.WriteLine();
        }
    }
}