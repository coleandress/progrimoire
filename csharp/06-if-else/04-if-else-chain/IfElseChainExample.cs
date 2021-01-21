using System;

namespace ProgrimoireCSharpExamples
{
    internal static class IfElseChainExample
    {
        public static void Main(string[] args)
        {
            var x = 42;
            
            /* -- Either: x is less than 42, x is greater than 42 or
                  x equals 42 - three mutually exclusive alternatives -- */
            
            if (x < 42)
                Console.WriteLine("x is less than forty two ...\n");
            
            else if (x > 42)
                Console.WriteLine("x is greater than forty two ... \n");

            else
                Console.WriteLine("x equals forty two ... \n");
            
            /* -- Blank lines not required between if-else blocks, but
                  added for clarity.  Use or don't use based on 
                  personal preference. -- */
        }
    }
}
