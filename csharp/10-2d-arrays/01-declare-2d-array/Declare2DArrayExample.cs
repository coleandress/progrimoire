using System;
using System.Collections.Generic;

namespace ProgrimoireCSharpExamples
{
    internal static class Declare2DArrayExample
    {
        private const int Rows = 4;
        private const int Columns = 5;
        
        public static void Main(string[] args)
        {
            /* -- Declare an array with dimensions: ROWS x COLUMNS, fill
                  the array with zeroes -- */

            var someArray = new int[Rows, Columns];

            for (var i = 0; i < Rows; i++)
            {
                Console.Write("{ ");
                
                for (var j = 0; j < Columns; j++)
                    Console.Write("{0}{1}", j == 0 ? "" : ", ", someArray[i, j]);
                
                Console.Write(" }\n");
            }

            Console.WriteLine();
            
            /* -- Now, declare an array with values we specify
                  explicitly -- */

            var anotherArray = new int[Rows, Columns]
            {
                {  2,  3,  5,  7, 11 },
                { 13, 17, 19, 23, 29 },
                { 31, 37, 41, 43, 47 },
                { 53, 57, 59, 61, 67 }
            };

            for (var i = 0; i < Rows; i++)
            {
                Console.Write("{ ");

                for (var j = 0; j < Columns; j++)
                    Console.Write("{0}{1:D2}", j == 0 ? "" : ", ", anotherArray[i, j]);

                Console.Write(" }\n");
            }

            Console.WriteLine();
            
            /* -- A 2D list -- */

            var someList = new List<List<int>>();
            someList.Add(new List<int>() {  2,  3,  5,  7, 11 });
            someList.Add(new List<int>() { 13, 17, 19, 23, 29 });
            someList.Add(new List<int>() { 31, 37, 41, 43, 47 });
            someList.Add(new List<int>() { 53, 57, 59, 61, 67 });

            for (var i = 0; i < someList.Count; i++)
            {
                Console.Write("{ ");
                
                for (var j = 0; j < someList[i].Count; j++)
                    Console.Write("{0}{1:D2}", j == 0 ? "" : ", ", someList[i][j]);
                
                Console.Write(" }\n");
            }

            Console.WriteLine();
        }
    }
}
