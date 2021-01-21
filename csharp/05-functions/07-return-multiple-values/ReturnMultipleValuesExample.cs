using System;

namespace ProgrimoireCSharpExamples
{
    internal static class ReturnMultipleValuesExample
    {
        public static void Main(string[] args)
        {
            /* -- Using a static function of a class to return
                  a constructed object, effectively returning
                  multiple values -- */

            Point p = Point.GetRandomPoint();

            Console.WriteLine(p);

            /* -- We can return one value and initialize the other
                  variable an out parameter -- */
            
            var x = 0;
            x = Point.GetRandomPoint(out int y);
            Point p2 = new Point(x, y);

            Console.WriteLine(p2);
            
            /* -- We can also return both values via out parameters
               -- */

            Point.GetRandomPoint(out int xOut, out int yOut);
            Point p3 = new Point(xOut, yOut);

            Console.WriteLine(p3);
            
            /* -- Finally, we have a newer way to return multiple
                  values in a clearer way -- */

            (int newX, int newY) = Point.GetRandomPointNew();
            Point p4 = new Point(newX, newY);

            Console.WriteLine(p4);
        }

        private class Point
        {
            private readonly int _x;
            private readonly int _y;

            public Point(int x, int y)
            {
                _x = x;
                _y = y;
            }
            
            /* -- Random number function -- */
            
            private static readonly Random GetRandomIntValue = new Random();
            
            /* -- Here we return multiple values by collecting them
                  into an object which we return -- */

            public static Point GetRandomPoint()
            {
                var x = GetRandomIntValue.Next(int.MinValue, int.MaxValue);
                var y = GetRandomIntValue.Next(int.MinValue, int.MaxValue);
                
                return new Point(x, y);
            }
            
            /* -- Return one value via out parameter and the other
                  via a normal function return -- */
            
            public static int GetRandomPoint(out int y)
            {
                y = GetRandomIntValue.Next(int.MinValue, int.MaxValue);

                return GetRandomIntValue.Next(int.MinValue, int.MaxValue);
            }

            /* -- Return both values via out parameters -- */
            
            public static void GetRandomPoint(out int x, out int y)
            {
                x = GetRandomIntValue.Next(int.MinValue, int.MaxValue);
                y = GetRandomIntValue.Next(int.MinValue, int.MaxValue);
            }
            
            /* -- New method of returning values in a more clear way -- */
            
            public static (int x, int y) GetRandomPointNew()
            {
                return (GetRandomIntValue.Next(int.MinValue, int.MaxValue),
                GetRandomIntValue.Next(int.MinValue, int.MaxValue));
            }
            
            public override string ToString()
            {
                return $"x: {_x}, y: {_y}\n";
            }
        }
    }
}
