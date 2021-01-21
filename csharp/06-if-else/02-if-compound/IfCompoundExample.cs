using System;

namespace ProgrimoireCSharpExamples
{
    internal static class IfCompoundExample
    {
        public static void Main(string[] args)
        {
            var x = 42;
            var y = 24;
            
            /* -- All three compound conditions are true so all calls
                  to 'WriteLine()' will be executed. Consider extracting
                  significantly compound logic statements into easy to
                  read functions like 'IsInRange()' --*/
            
            if (x > 10 && y > 10)
                Console.WriteLine("x and y were both more than ten ...");
            
            if (x == 42 && y == 24)
                Console.WriteLine("x was forty two and y was twenty four ...");
            
            if (IsLessThanFifty(x, y))
                Console.WriteLine("x and y were both less than fifty ...\n");
        }

        private static bool IsLessThanFifty(int x, int y)
        {
            return x < 50 && y < 50;
        }
    }
}
