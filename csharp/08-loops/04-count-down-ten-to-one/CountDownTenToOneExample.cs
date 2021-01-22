using System;

namespace ProgrimoireCSharpExamples
{
    internal static class CountDownTenToOneExample
    {
        public static void Main(string[] args)
        {
            /* -- Count down starting from ten to one using a while,
                  do-while and for loop -- */

            var i = 10;

            while (i >= 1)
                Console.WriteLine($"i: {i--}");

            Console.WriteLine();

            i = 10;

            do
            {
                Console.WriteLine($"i: {i}");
                i -= 1;
                
            } while (i >= 1);
            
            Console.WriteLine();
            
            for (i = 10; i > 0; i--)
                Console.WriteLine($"i: {i}");

            Console.WriteLine();
        }
    }
}
