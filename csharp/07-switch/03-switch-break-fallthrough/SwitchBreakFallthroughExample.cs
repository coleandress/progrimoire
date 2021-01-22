using System;

namespace ProgrimoireCSharpExamples
{
    internal static class SwitchBreakFallthroughExample
    {
        public static void Main(string[] args)
        {
            for (var i = 0; i <= 10; i++)
            {
                Console.Write($"i: {i} ");
                ShowExample(i);
            }
        }

        /* -- C# allows multiple cases for the same execution
              block but will not allow you to omit the break 
              statement.  Fallthrough is not possible. -- */
        
        private static void ShowExample(int x)
        {
            switch (x)
            {
                case 0:
                case 1:
                case 2:
                {
                    Console.Write("(0, 1, or 2)\n");
                    break;
                }

                case 3:
                case 4:
                case 5:
                {
                    Console.Write("(3, 4, or 5)\n");
                    break; // will not compile if omitted
                }
                
                case 6:
                case 7:
                case 8:
                {
                    Console.Write("(6, 7, or 8)\n");
                    break;
                }

                case 9:
                {
                    Console.Write("(9)\n");
                    break;
                }

                case 10:
                {
                    Console.Write("(10)\n");
                    break;
                }
            }
        }
    }
}
