using System;

namespace ProgrimoireCSharpExamples
{
    internal static class IfElseExample
    {
        public static void Main(string[] args)
        {
            var x = 42;
            
            /* -- Either 'x == 42' or it does not, this determines
                  which branch will be followed and which 'WriteLine()'
                  statement will be executed -- */
            
            if (x == 42)
                Console.WriteLine("x equals forty two ...\n");

            else
                Console.WriteLine("x does not equal forty two ...\n");
            
            /* -- A space is not required between the if and else blocks.
                  One has been added for clarity but it's personal
                  preference. -- */
        }
    }
}
