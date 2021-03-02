using System;

namespace ProgrimoireCSharpExamples
{
    internal static class CountOccurrencesExample
    {
        public static void Main(string[] args)
        {
            var someArray = new int[,]
            {
                {  1,  2,  2,  3,  3 },
                {  3,  4,  4,  4,  4 },
                {  5,  5,  5,  5,  5 },
                {  1,  2,  3,  4,  5 }
            };

            for (var number = 2; number < 6; number++)
            {
                var count = 0;
                
                for (var i = 0; i < someArray.GetLength(0); i++)
                    for (var j = 0; j < someArray.GetLength(1); j++)
                        if (someArray[i, j] == number)
                            count++;

                Console.WriteLine($"number: {number}, count: {count}");
            }

            Console.WriteLine();
        }
    }
}
