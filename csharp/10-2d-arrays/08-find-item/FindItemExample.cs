using System;

namespace ProgrimoireCSharpExamples
{
    internal static class FindItemExample
    {
        public static void Main(string[] args)
        {
            var someArray = new int[,]
            {
                { 2,  3,  5,  7, 11},
                {13, 17, 19, 23, 29},
                {31, 37, 41, 43, 47},
                {53, 57, 59, 61, 67}
            };

            for (var number = 2; number < 70; number++)
            {
                /* -- Scan each element in 'someArray', use
                      the boolean flag 'found' to allow us to
                      stop searching as soon as we've found the
                      element we're looking for -- */

                var found = false;
                
                for (var i = 0; !found && i < someArray.GetLength(0); i++)
                    for (var j = 0; !found && j < someArray.GetLength(1); j++)
                        if (someArray[i, j] == number)
                            found = true;

                Console.WriteLine("{0} was {1}", number, found ? "found" : "not found");
            }

            Console.WriteLine();
        }
    }
}
