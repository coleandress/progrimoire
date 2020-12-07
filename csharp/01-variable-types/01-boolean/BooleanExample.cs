using System;

namespace ProgrimoireCSharpExamples
{
    internal static class BooleanExample
    {
        public static void Main(string[] args)
        {
            /* -- Set our flag to false initially (no divisors found yet) -- */

            var divisorFound = false;
            
            /* -- Look for divisors of 'number' starting with 2 -- */
            
            const int number = 31;
            var i      = 2;
            
            while(i < number)
            {
                if(number % i == 0)
                {
                     divisorFound = true;
                     break; 
                }
            
                i++;
            }
            
            if (divisorFound)
                Console.WriteLine($"Found a divisor for: {number}");
            else
                Console.WriteLine($"Looks like: {number} is a prime number");
            
            Console.WriteLine($"The flag 'divisorFound is: {divisorFound}");
            
            /* -- Make true into false or vice versa -- */
            
            divisorFound = !divisorFound;
            
            Console.WriteLine($"The flag 'divisorFound' is now: {divisorFound}");
        }
    }
}