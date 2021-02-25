using System;
using System.Linq;

namespace ProgrimoireCSharpExamples
{
    internal static class SumMinMaxAvgExample
    {
        public static void Main(string[] args)
        {
            var someArray = new[]
            {
                new[] {  2,  3,  5,  7, 11 },
                new[] { 13, 17, 19, 23, 29 },
                new[] { 31, 37, 41, 43, 47 },
                new[] { 53, 57, 59, 61, 67 }
            };

            var min = someArray.Min(x => x.Min());
            var max = someArray.Max(x => x.Max());
            var sum = someArray.Sum(x => x.Sum());

            Console.WriteLine($"sum: {sum}");
            Console.WriteLine($"min: {min}");
            Console.WriteLine($"max: {max}");
            Console.WriteLine("avg: {0:0.##}\n", (double)sum / (someArray.Length * someArray[0].Length));
        }
    }
}
