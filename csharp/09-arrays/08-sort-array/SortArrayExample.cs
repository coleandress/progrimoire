using System;

namespace ProgrimoireCSharpExamples
{
    class Point
    {
        public int X { get; private set; }
        public int Y { get; private set; }

        public Point(int x, int y)
        {
            X = x;
            Y = y;
        }

        public double Distance()
        {
            return Math.Sqrt(Math.Pow(X, 2) + Math.Pow(Y, 2));
        }

        public static int CompareByDistance(Point p1, Point p2)
        {
            return p1.Distance().CompareTo(p2.Distance());
        }
    }
    
    internal static class SortArrayExample
    {
        public static void Main(string[] args)
        {
            var someArray    = new int[] { 31, 3, 7, 23, 11, 13, 2, 17, 19, 5, 29 };
            var anotherArray = new int[] { 31, 3, 7, 23, 11, 13, 2, 17, 19, 5, 29 };
            
            /* -- First, sort 'someArray' manually - in this case we
                  use the selection sort -- */

            for (var i = 0; i < someArray.Length; i++)
            {
                var minIndex = -1;

                for (var j = i; j < someArray.Length; j++)
                    if (minIndex == -1 || someArray[j] < someArray[minIndex])
                        minIndex = j;

                if (minIndex != i)
                {
                    var tmp             = someArray[minIndex];
                    someArray[minIndex] = someArray[i];
                    someArray[i]        = tmp;
                }
            }

            foreach (var num in someArray)
                Console.WriteLine($"{num}");

            Console.WriteLine();

            /* -- Sort 'anotherArray' using the built in Array method -- */
            
            Array.Sort(anotherArray);
            
            foreach (var num in anotherArray)
                Console.WriteLine($"{num}");

            Console.WriteLine();

            var points = new Point[]
            {
                new Point(1, 2), new Point(-1, -2), new Point(10, 20), new Point(-2, -4), new Point(100, 100), new Point(0, 0)  
            };
            
            /* -- Sort 'points' using a static compare method -- */
            
            Array.Sort(points, Point.CompareByDistance);
            
            foreach (var p in points)
                Console.WriteLine($"({p.X}, {p.Y})");
        }
    }
}