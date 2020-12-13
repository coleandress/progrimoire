using System;

namespace ProgrimoireCSharpExamples
{
    internal static class DivisionExample
    {
        public static void Main(string[] args)
        {
            var valueOne = 3;
            var valueTwo = 2;
            
            /* -- If we perform integer division and then cast to float,
                  we're too late - we need to use floating point division
                  from the start -- */

            var notGoodEnough = (float)(valueOne / valueTwo);
            var floatDivision = (float)valueOne / valueTwo;
            
            /* -- Integer division -- */

            Console.WriteLine($"dividing: {valueOne} by {valueTwo} yields: {valueOne / valueTwo}");
            
            /* -- Still integer division -- */
            
            Console.WriteLine($"dividing: {valueOne} by {valueTwo} yields: {notGoodEnough}");
            
            /* -- Now, float division -- */
            
            Console.WriteLine($"dividing: {valueOne} by {valueTwo} yields: {floatDivision}");
            
            /* -- This also works -- */
            
            Console.WriteLine($"dividing: {valueOne} by {valueTwo} yields: {valueOne / (float)valueTwo}");
            
            /* -- So does this -- */

            var valueThree = 2.0f;
            
            Console.WriteLine($"dividing: {valueOne} by {valueTwo} yields: {valueOne/valueThree}");
        }
    }
}