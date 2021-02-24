using System;

namespace ProgrimoireCSharpExamples
{
    internal static class Print2DArrayExample
    {
        public static void Main(string[] args)
        {
            /* -- Print the contents of 'someArray' -- */
            
            var someArray = new int[,]
            {
                {  2,  3,  5,  7, 11 },
                { 13, 17, 19, 23, 29 },
                { 31, 37, 41, 43, 47 },
                { 53, 57, 59, 61, 67 }
            };

            for (var i = 0; i < someArray.GetLength(0); i++)
            {
                Console.Write("{ ");
                
                for (var j = 0; j < someArray.GetLength(1); j++)
                    Console.Write("{0}{1,3}", j == 0 ? "" : ", ", someArray[i, j]);
                
                Console.Write(" }\n");
            }

            Console.WriteLine();
            
            /* -- Print again using a foreach loop -- */

            var totalColumns = someArray.GetLength(1);
            var currentColumn = 0;
            
            foreach (var num in someArray)
            {
                Console.Write("{0}", currentColumn == 0 ? "{ " : ", ");
                
                Console.Write($"{num,3}");

                if (++currentColumn >= totalColumns)
                {
                    Console.Write(" }\n");
                    currentColumn = 0;
                }
            }
            
            Console.WriteLine();
        }
    }
}
