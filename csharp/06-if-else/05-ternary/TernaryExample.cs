using System;

namespace ProgrimoireCSharpExamples
{
    internal static class TernaryExample
    {
        public static void Main(string[] args)
        {
            var x = 42;
            
            /* -- The ternary operator is essentially an in-line, shorthand
                  for an if/else statement.  It evaluates to the first term
                  if the test is true or the second term if it is not -- */

            Console.WriteLine("x is {0} ...\n", x % 2 == 0 ? "even" : "odd");

            var y = 24;
            
            /* -- Parens added for clarity, not required -- */

            var max = (x >= y) ? x : y;

            Console.WriteLine($"max: {max}\n");
        }
    }
}
