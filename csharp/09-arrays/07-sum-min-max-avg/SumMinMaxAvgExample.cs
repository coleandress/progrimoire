﻿using System;

namespace ProgrimoireCSharpExamples
{
    internal static class SumMinMaxAvgExample
    {
        public static void Main(string[] args)
        {
            var someArray = new int[] { 31, 3, 7, 23, 11, 13, 2, 17, 19, 5, 29 };
            var min       = 0;
            var max       = 0;
            var sum       = 0;
            
            /* -- Set min/max to the first element and then
                  update those values when we encounter a
                  smaller/larger value -- */

            for (var i = 0; i < someArray.Length; i++)
            {
                sum += someArray[i];

                if (i == 0)
                {
                    min = max = someArray[i];
                }
                else
                {
                    if (someArray[i] < min)
                        min = someArray[i];
                    
                    else if (someArray[i] > max)
                        max = someArray[i];
                }
            }
            
            /* -- Note we have to cast 'sum' to a floating
                  point type in order to avoid integer division
                  when calculating our average -- */
            
            Console.WriteLine($"min: {min}, max: {max}, sum: {sum}, average: {(double)sum / someArray.Length:F}");

            
            /* -- Another way to accomplish the same task -- */
            
            sum = 0;
            min = max = someArray[0];

            foreach (var num in someArray)
            {
                sum += num;
                
                if (num < min)
                    min = num;
                
                else if (num > max)
                    max = num;
            }
            
            Console.WriteLine($"min: {min}, max: {max}, sum: {sum}, average: {(double)sum / someArray.Length:F}");
            
            
            /* -- Yet another way to accomplish the same task -- */
            
            sum = 0;
            min = max = someArray[0];
            
            Array.ForEach(someArray, (num) =>
            {
                sum += num;
                
                if (num < min)
                    min = num;
                
                else if (num > max)
                    max = num;
            });
            
            Console.WriteLine($"min: {min}, max: {max}, sum: {sum}, average: {(double)sum / someArray.Length:F}");
        }
    }
}