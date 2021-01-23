using System;

namespace ProgrimoireCSharpExamples
{
    internal static class BreakContinueExample
    {
        public static void Main(string[] args)
        {
            /* -- Using 'break' causes us to exit the loop
                  immediately -- */

            for (var i = 0; i < 10; i++)
            {
                Console.WriteLine($"i: {i}");

                if (i == 4)
                    break;
            }

            Console.WriteLine();
            
            /* -- break with a foreach loop -- */

            var someArray = new int[] {2, 4, 6, 7, 8, 10};

            foreach (var n in someArray)
            {
                if (n % 2 != 0)
                    break;
                
                Console.WriteLine($"i: {n}");
            }

            Console.WriteLine();
            
            /* -- 'continue' skips over any remaining code, sending
                  execution back to the top of the loop -- */

            for (var i = 0; i < 10; i++)
            {
                if (i % 2 != 0)
                    continue;

                Console.WriteLine($"i: {i}");
            }

            Console.WriteLine();
            
            /* -- 'continue' with a foreach loop -- */

            foreach (var n in someArray)
            {
                if (n % 2 != 0)
                    continue;

                Console.WriteLine($"i: {n}");
            }

            Console.WriteLine();
            
            /* -- With a nested loop, our 'break' only breaks us out of
                  the immediately enclosing loop -- */

            for (var i = 0; i < 5; i++)
            {
                for (var j = 0; j < 5; j++)
                {
                    if (j > 1)
                        break;

                    Console.WriteLine($"i {i}, j: {j}");
                }
            }

            Console.WriteLine();
            
            /* -- As above, 'continue' only affects the innermost
                  enclosing loop -- */

            for (var i = 0; i < 5; i++)
            {
                for (var j = 0; j < 5; j++)
                {
                    if (j % 2 == 0)
                        continue;

                    Console.WriteLine($"i: {i}, j: {j}");
                }
            }

            Console.WriteLine();
        }
    }
}
