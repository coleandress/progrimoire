using System;
using System.Collections.Generic;

namespace ProgrimoireCSharpExamples
{
    internal static class ReadLineExample
    {
        public static void Main(string[] args)
        {
            var theLines = new List<string>();
            
            while (true)
            {
                Console.WriteLine("Enter some text (or 'exit' to end): ");

                string theInput = Console.ReadLine();

                if (theInput == "exit")
                    break;
                
                theLines.Add(theInput);
            }

            Console.WriteLine(string.Join("\n", theLines));
            
            /* -- Keep program running until a key is pressed -- */

            Console.WriteLine("Press End key to exit.");

            while (Console.ReadKey().Key != ConsoleKey.End) { }
        }
    }
}