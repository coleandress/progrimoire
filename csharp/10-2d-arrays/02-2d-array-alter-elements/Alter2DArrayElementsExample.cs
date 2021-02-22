using System;
using System.Collections.Generic;

namespace ProgrimoireCSharpExamples
{
    internal static class Alter2DArrayElementsExample
    {
        public static void Main(string[] args)
        {
            /* -- Create a 2D array -- */
            
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
                    Console.Write("{0}{1, 2}", j == 0 ? "" : ", ", someArray[i, j]);

                Console.Write(" }\n");
            }

            Console.WriteLine();
            
            /* -- Reverse the elements of the 2D Array -- */

            var rows = someArray.GetLength(0);
            var cols = someArray.GetLength(1);
            var totalElements = rows * cols;

            for (int i = 0, j = totalElements - 1; i < j; i++, j--)
            {
                var iRow    = i / cols;
                var iColumn = i % cols;

                var jRow = j / cols;
                var jColumn = j % cols;

                var tmp = someArray[iRow, iColumn];
                someArray[iRow, iColumn] = someArray[jRow, jColumn];
                someArray[jRow, jColumn] = tmp;
            }
            
            for (var i = 0; i < someArray.GetLength(0); i++)
            {
                Console.Write("{ ");

                for (var j = 0; j < someArray.GetLength(1); j++)
                    Console.Write("{0}{1, 2}", j == 0 ? "" : ", ", someArray[i, j]);

                Console.Write(" }\n");
            }

            Console.WriteLine();
            
            /* -- Now, double the value of each element -- */
            
            for (var i = 0; i < someArray.GetLength(0); i++)
                for (var j = 0; j < someArray.GetLength(1); j++)
                    someArray[i, j] *= 2;
            
            for (var i = 0; i < someArray.GetLength(0); i++)
            {
                Console.Write("{ ");

                for (var j = 0; j < someArray.GetLength(1); j++)
                    Console.Write("{0}{1, 3}", j == 0 ? "" : ", ", someArray[i, j]);

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
                    Console.Write("{0}{1, 2}", j == 0 ? "" : ", ", someList[i][j]);
                
                Console.Write(" }\n");
            }

            Console.WriteLine();
            
            /* -- Reversing the elements of a 2D list -- */

            var totalListElements = someList.Count * someList[0].Count;
            var columns = someList[0].Count;

            for (int i = 0, j = totalElements - 1; i < j; i++, j--)
            {
                var iRow = i / columns;
                var iColumn = i % columns;

                var jRow = j / columns;
                var jColumn = j % columns;

                var tmp = someList[iRow][iColumn];
                someList[iRow][iColumn] = someList[jRow][jColumn];
                someList[jRow][jColumn] = tmp;
            }
            
            for (var i = 0; i < someList.Count; i++)
            {
                Console.Write("{ ");
                
                for (var j = 0; j < someList[i].Count; j++)
                    Console.Write("{0}{1, 2}", j == 0 ? "" : ", ", someList[i][j]);
                
                Console.Write(" }\n");
            }

            Console.WriteLine();
            
            /* -- Now, double the value of each element -- */

            for (var i = 0; i < someList.Count; i++)
                for (var j = 0; j < someList[i].Count; j++)
                    someList[i][j] *= 2;
            
            for (var i = 0; i < someList.Count; i++)
            {
                Console.Write("{ ");
                
                for (var j = 0; j < someList[i].Count; j++)
                    Console.Write("{0}{1, 3}", j == 0 ? "" : ", ", someList[i][j]);
                
                Console.Write(" }\n");
            }

            Console.WriteLine();
        }
    }
}
