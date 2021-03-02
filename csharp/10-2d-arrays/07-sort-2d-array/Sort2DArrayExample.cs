using System;
using System.Collections.Generic;

namespace ProgrimoireCSharpExamples
{
    internal static class Sort2DArrayExample
    {
        public static void Main(string[] args)
        {
            // TODO Sort this the old fashioned way then do Linq with a 2D List
            var someArray = new[]
            {
                new[] { 111,   2,   75, -4, 34 },
                new[] { 200, 300, -101,  0, 12 },
                new[] {   1,   3,    5,  7,  9 },
                new[] {   9,   1,    7,  5,  3 }
            };

            PrintArray(someArray);

            Console.WriteLine();
            
            /* -- Sort the array using a selection sort, note that
                  we essentially treat the 2d array as a 1d array 
                  of size 'total' -- */

            var columns = someArray[0].Length;
            var total = someArray.Length * columns;

            for (var i = 0; i < total - 1; i++)
            {
                var minIndex = i;

                for (var j = minIndex + 1; j < total; j++)
                {
                    var r1 = j / columns;
                    var c1 = j % columns;

                    var r2 = minIndex / columns;
                    var c2 = minIndex % columns;

                    if (someArray[r1][c1] < someArray[r2][c2])
                        minIndex = j;
                }

                if (minIndex != i)
                {
                    var r1 = i / columns;
                    var c1 = i % columns;

                    var r2 = minIndex / columns;
                    var c2 = minIndex % columns;

                    var tmp = someArray[r1][c1];
                    someArray[r1][c1] = someArray[r2][c2];
                    someArray[r2][c2] = tmp;
                }
            }
            
            PrintArray(someArray);

            Console.WriteLine();

            var anotherArray = new Point[][]
            {
                new Point[5],
                new Point[5],
                new Point[5]
            };

            for (var i = 0; i < anotherArray.Length; i++)
                for (var j = 0; j < anotherArray[i].Length; j++)
                    anotherArray[i][j] = new Point();

            PrintPointArray(anotherArray);

            Console.WriteLine();

            var pointColumns = anotherArray[0].Length;
            var totalPoints = anotherArray.Length * columns;
            
            /* -- Sort 'anotherArray', again we use the selection sort but our
                  comparison function is 'Distance' so we're ordering from
                  closest to the origin to farthest from the origin -- */

            for (var i = 0; i < totalPoints - 1; i++)
            {
                var minIndex = i;

                for (var j = minIndex + 1; j < totalPoints; j++)
                {
                    var r1 = j / pointColumns;
                    var c1 = j % pointColumns;

                    var r2 = minIndex / pointColumns;
                    var c2 = minIndex % pointColumns;

                    if (anotherArray[r1][c1].Distance() < anotherArray[r2][c2].Distance())
                        minIndex = j;
                }

                if (minIndex != i)
                {
                    var r1 = i / pointColumns;
                    var c1 = i % pointColumns;

                    var r2 = minIndex / pointColumns;
                    var c2 = minIndex % pointColumns;

                    var tmp = anotherArray[r1][c1];
                    anotherArray[r1][c1] = anotherArray[r2][c2];
                    anotherArray[r2][c2] = tmp;
                }
            }
            
            PrintPointArray(anotherArray);

            Console.WriteLine();
        }

        private static void PrintArray(int[][] arr)
        {
            for (var i = 0; i < arr.Length; i++)
            {
                Console.Write("{ ");
                
                for (var j = 0; j < arr[0].Length; j++)
                    Console.Write("{0}{1,4}", j == 0 ? "" : ", ", arr[i][j]);
                
                Console.Write(" }\n");
            }
        }

        private static void PrintPointArray(Point[][] arr)
        {
            for (var i = 0; i < arr.Length; i++)
            {
                Console.Write("{ ");

                for (var j = 0; j < arr[i].Length; j++)
                    Console.Write("{0}({1,2}, {2,2})", j == 0 ? "" : ", ",
                        arr[i][j].X, arr[i][j].Y);
                
                Console.Write(" }\n");
            }
        }
        
        private static void PrintList(List<List<int>> list)
        {
            for (var i = 0; i < list.Count; i++)
            {
                Console.Write("{ ");
                
                for (var j = 0; j < list[0].Count; j++)
                    Console.Write("{0}{1,4}", j == 0 ? "" : ", ", list[i][j]);
                
                Console.Write(" }\n");
            }
        }
    }

    public class Point
    {
        public int X { get; private set; }
        public int Y { get; private set; }

        private static readonly Random Random = new Random();

        public Point()
        {
            X = Random.Next(51);
            Y = Random.Next(51);
        }

        public double Distance()
        {
            return Math.Sqrt(X * X + Y * Y);
        }
    }
}
