using System;

namespace ProgrimoireCSharpExamples
{
    internal static class WhileDoWhileOneToTenExample
    {
        public static void Main(string[] args)
        {
            /* -- Count from one to ten using both a while
                  loop and a do-while loop -- */

            var i = 0;
            
            while (i <= 10)
                Console.WriteLine($"i: {i++}");

            Console.WriteLine();

            i = 1;

            do
            {
                Console.WriteLine($"i: {i++}");
                
            } while (i <= 10);
        }
    }
}
