using System;
using System.Collections.Generic;
using System.Linq;

namespace ProgrimoireCSharpExamples
{
    internal static class SumMinMaxAvgExample
    {
        private static readonly Random Random = new Random();
        
        public static void Main(string[] args)
        {
            var iList = new List<int>();
            
            for (var i = 0; i < 10; i++)
                iList.Add(GetRandomIntValue());
            
            PrintList(iList);

            Console.WriteLine();

            var min = iList.Min();
            var max = iList.Max();
            var sum = iList.Sum();
            var avg = iList.Average();

            Console.WriteLine($"min: {min}, max: {max}, sum: {sum}, avg: {avg:F2}");

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
    }
}
