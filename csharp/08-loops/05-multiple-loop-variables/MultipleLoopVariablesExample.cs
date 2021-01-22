using System;

namespace ProgrimoireCSharpExamples
{
    internal static class MultipleLoopVariablesExample
    {
        public static void Main(string[] args)
        {
            /* -- First, here's a for loop that uses multiple loop variables -- */
            
            for (int i = 0, j = 1, k = 10; i < 10; i++, j += 2, k--)
                Console.WriteLine($"i: {i}, j: {j}, k: {k}");

            Console.WriteLine();
            
            /* -- Now, a while loop example that uses multiple
                  loop variables -- */

            var m = 2;
            var n = 3;
            var o = 5;

            while (m + n + o < 50)
            {
                Console.WriteLine($"m: {m}, n: {n}, o: {o}");

                m++;
                n *= 2;
                o += 3;
            }

            Console.WriteLine();
            
            /* -- And finally, a do-while loop example using multiple loop variables -- */

            m = n = o = 0;

            do
            {
                Console.WriteLine($"m: {m}, n: {n}, o: {o}");

                m += 2;
                n += 3;
                o += 5;
                
            } while (m + n + o < 50);

            Console.WriteLine();
        }
    }
}
