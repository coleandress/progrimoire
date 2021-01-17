using System;

namespace ProgrimoireCSharpExamples
{
    internal static class NoParamsNoReturnExample
    {
        public static void Main(string[] args)
        {
            Greet();
        }

        /* -- This function takes no arguments
              and does not return anything -- */
        
        private static void Greet()
        {
            Console.WriteLine("Hello World");
        }
    }
}
