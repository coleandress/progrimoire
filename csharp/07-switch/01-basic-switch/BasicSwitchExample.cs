using System;

namespace ProgrimoireCSharpExamples
{
    internal static class BasicSwitchExample
    {
        public static void Main(string[] args)
        {
            for (var i = 1; i <= 100; i++)
            {
                Console.Write($"{i}: ");

                switch (i % 15)
                {
                    case 0:
                    {
                        Console.Write("divisible by both 3 and 5\n");
                        break;
                    }
                    
                    /* -- You can "stack" the case labels so that
                          the same block of code applies to multiple
                          cases -- */

                    case 3:
                    case 6:
                    case 9:
                    case 12:
                    {
                        Console.Write("divisible by 3\n");
                        break;
                    }

                    case 5:
                    case 10:
                    {
                        Console.Write("divisible by 5\n");
                        break;
                    }
                    
                    /* -- If none of the listed cases match, we'll end up
                          at the default case -- */

                    default:
                        /* -- Braces are optional for all case statements -- */
                        
                        Console.Write("divisible by neither 3 nor 5\n");
                        break;
                }
            }
        }
    }
}
