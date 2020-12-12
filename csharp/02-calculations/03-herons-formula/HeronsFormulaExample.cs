using System;

namespace ProgrimoireCSharpExamples
{
    internal static class HeronsFormulaExample
    {
        public static void Main(string[] args)
        {
            /* -- Heron's formula gives the area of a triangle,
                  given the length of the three sides -- */

            var x1 = 0.0;
            var y1 = 0.0;

            var x2 = 4.0;
            var y2 = 3.0;

            var x3 = 4.0;
            var y3 = 0.0;
            
            /* -- Find the length of each side using the distance formula -- */

            var a = Math.Sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
            var b = Math.Sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
            var c = Math.Sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
            
            /* -- Calculate the "semi-perimeter" of this triangle -- */

            var s = (a + b + c) / 2;
            
            /* -- Now, find its area -- */

            var area = Math.Sqrt(s * (s - a) * (s - b) * (s - c));

            Console.WriteLine($"Triangle: ({x1}, {y1}) ({x2}, {y2}) ({x3}, {y3}) has area: {area}");
        }
    }
}