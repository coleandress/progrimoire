using System;

namespace ProgrimoireCSharpExamples
{
    internal static class ReadIntegerExample
    {
        public static void Main(string[] args)
        {
            Console.Write("Enter an integer: ");
            string theStringInput = Console.ReadLine();

            bool isValidInput = int.TryParse(theStringInput, out int theInteger);

            if (isValidInput)
                Console.WriteLine($"You entered: {theInteger}");
            else
                Console.WriteLine($"error: invalid input [{theStringInput}]");
        }
    }
}