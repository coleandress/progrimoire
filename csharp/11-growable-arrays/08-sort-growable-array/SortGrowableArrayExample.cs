using System;
using System.Collections.Generic;

namespace ProgrimoireCSharpExamples
{
    internal static class SortGrowableArrayExample
    {
        private static readonly Random Random = new Random();
        
        public static void Main(string[] args)
        {
            var iList = new List<int>();
            
            for (var i = 0; i < 10; i++)
                iList.Add(GetRandomIntValue());
            
            PrintList(iList);

            Console.WriteLine();
            
            /* -- First, sort the array manually using a selection sort -- */

            for (var i = 0; i < iList.Count - 1; i++)
            {
                var minIndex = -1;
                
                for (var j = i; j < iList.Count; j++)
                    if (minIndex == -1 || iList[j] < iList[minIndex])
                        minIndex = j;

                if (minIndex != i)
                {
                    var tmp = iList[minIndex];
                    iList[minIndex] = iList[i];
                    iList[i] = tmp;
                }
            }
            
            PrintList(iList);
            
            Console.WriteLine();
            
            /* -- Now we use the sort included with C# -- */

            iList.Clear();
            
            for (var i = 0; i < 10; i++)
                iList.Add(GetRandomIntValue());
            
            PrintList(iList);

            Console.WriteLine();

            iList.Sort();
            
            PrintList(iList);

            Console.WriteLine();

            var points = new List<Point>();
            
            for (var i = 0; i < 5; i++)
                points.Add(new Point(GetRandomIntValue(), GetRandomIntValue()));

            PrintPoints(points);

            Console.WriteLine();

            points.Sort();
            
            Console.WriteLine();

            PrintPoints(points);

            Console.WriteLine();
        }

        private static int GetRandomIntValue()
        {
            return Random.Next(100);
        }

        private static void PrintList(List<int> list)
        {
            Console.Write("{ ");
            
            for (var i = 0; i < list.Count; i++)
                Console.Write("{0}{1}", i == 0 ? "" : ", ", list[i]);
            
            Console.Write(" }\n");
        }

        private static void PrintPoints(List<Point> list)
        {
            Console.Write("{ ");
            
            for (var i = 0; i < list.Count; i++)
                Console.Write("{0}({1}, {2})", i == 0 ? "" : ", ", list[i].X, list[i].Y);
            
            Console.Write(" }");
        }
    }

    public class Point : IComparable<Point>
    {
        public int X { get; private set; }
        public int Y { get; private set; }
        public double Distance { get; private set; }

        public Point(int x, int y)
        {
            X = x; 
            Y = y;
            Distance = GetDistance();
        }

        private double GetDistance()
        {
            return Math.Sqrt(X * X + Y * Y);
        }

        public int CompareTo(Point comparePoint)
        {
            if (comparePoint == null)
                return 1;

            else
                return Distance.CompareTo(comparePoint.Distance);
        }
    }
}
