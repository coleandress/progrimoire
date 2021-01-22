using System;
using System.Collections.Generic;

namespace ProgrimoireCSharpExamples
{
    internal static class NonIntegralSwitchExample
    {
        public static void Main(string[] args)
        {
            /* -- Using a switch to do a different behavior based
                  on the string that gets passed in -- */
            
            var theColors = new List<string>() {"red", "yellow"};
            var currentColor = "";

            foreach (var c in theColors)
            {
                Console.Write($"Color: {c} is ");
                switch (c)
                {
                    case "red":
                    {
                        currentColor = c;
                        Console.Write("now the current color.");
                        break;
                    }

                    case "green":
                    {
                        currentColor = c;
                        Console.Write("now the current color.");
                        break;
                    }

                    case "blue":
                    {
                        currentColor = c;
                        Console.Write("now the current color.");
                        break;
                    }

                    default:
                    {
                        Console.Write("not in the list of available colors!");
                        break;
                    }
                }

                Console.WriteLine();
            }
        }
    }
}
