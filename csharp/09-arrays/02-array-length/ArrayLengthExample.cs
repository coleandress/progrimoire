using System;

namespace ProgrimoireCSharpExamples
{
    internal static class ArrayLengthExample
    {
        public static void Main(string[] args)
        {
            int[] someArray = { 2, 3, 5, 7, 11 };

            for (var i = 0; i < someArray.Length; i++)  // C# gives arrays a Length property
            {
                Console.WriteLine($"someArray[{i}] = {someArray[i]}");
            }
        }
    }
}