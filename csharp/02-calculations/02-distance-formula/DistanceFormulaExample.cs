using System;

namespace ProgrimoireCSharpExamples
{
    internal static class DistanceFormulaExample
    {
        private static double GetDistance(double x1, double y1, double x2, double y2)
        {
            return Math.Sqrt(Math.Pow(x2 - x1, 2) + Math.Pow(y2 - y1, 2));
        }
        
        public static void Main(string[] args)
        {
            var x1 = 0.0;
            var y1 = 0.0;

            var x2 = 4.0;
            var y2 = 3.0;

            var distance = Math.Sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

            Console.WriteLine($"Distance from: ({x1}, {y1}) to: ({x2}, {y2}) is: {distance}");
            
            var xDelta = (x2 - x1);
            var yDelta = (y2 - y1);

            distance = Math.Sqrt(xDelta * xDelta + yDelta * yDelta);

            Console.WriteLine($"Distance from: ({x1}, {y1}) to: ({x2}, {y2}) is: {distance}");
            Console.WriteLine($"Distance from: ({x1}, {y1}) to: ({x2}, {y2}) is: {GetDistance(x1, y1, x2, y2)}");
        }
    }
}