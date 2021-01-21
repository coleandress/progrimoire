using System;

namespace ProgrimoireCSharpExamples
{
    internal static class IfExample
    {
        public static void Main(string[] args)
        {
            var x = 42;
            
            /* -- All these conditions are true so all the
                  'WriteLine()' lines will be executed -- */
            
            if (x > 10)
                Console.WriteLine("x was more than ten ...");
            
            if (x == 42)
                Console.WriteLine("x was forty two ...");
            
            if (x < 50)
                Console.WriteLine("x was less than fifty ...\n");
        }
    }
}
