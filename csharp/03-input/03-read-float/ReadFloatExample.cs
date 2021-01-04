using System;

namespace ProgrimoireCSharpExamples
{
    internal static class ReadFloatExample
    {
        public static void Main(string[] args)
        {
            /* -- This works the same for double or decimal -- */
            
            Console.Write("Enter a float: ");
            string theStringInput = Console.ReadLine();

            bool isValidInput = float.TryParse(theStringInput, out float theFloat);

            if (isValidInput)
                Console.WriteLine($"You entered: {theFloat}");
            else
                Console.WriteLine($"error: invalid input [{theStringInput}]");
        }
    }
}