using System;

namespace ProgrimoireCSharpExamples
{
    internal static class PassByReferenceExample
    {
        public static void Main(string[] args)
        {
            var someArray      = new int[] {2, 3, 5, 7, 11};
            var someOtherArray = new int[] {11, 2, 7, 3, 5, 13};

            var minValue = 0;
            var maxValue = 0;
            
            /* -- Here we pass 'minValue' and 'maxValue' by value which means
                  'GetMinMaxBad' only receives a copy and cannot modify the
                  original variables -- */

            GetMinMaxBad(someArray, minValue, maxValue);
            Console.WriteLine($"min: {minValue}, max: {maxValue}");

            GetMinMaxBad(someOtherArray, minValue, maxValue);
            Console.WriteLine($"min: {minValue}, max: {maxValue}");

            Console.WriteLine();
            
            /* -- Here, we pass out values by address which does allow
                  'GetMinMax' to modify the original variables -- */

            GetMinMax(someArray, ref minValue, ref maxValue);
            Console.WriteLine($"min: {minValue}, max: {maxValue}");

            GetMinMax(someOtherArray, ref minValue, ref maxValue);
            Console.WriteLine($"min: {minValue}, max: {maxValue}");

            Console.WriteLine();
            
            /* -- Here's an example with C# out values.  Out values
                  can be initialized and passed in or initialized
                  in the argument of the function call.  -- */

            GetMinMaxOut(someArray, out int minOutValue, out int maxOutValue);
            Console.WriteLine($"min: {minOutValue}, max: {maxOutValue}");
            
            GetMinMaxOut(someOtherArray, out minOutValue, out maxOutValue);
            Console.WriteLine($"min: {minOutValue}, max: {maxOutValue}");
        }
        
        /* -- Since min/max are passed by value (not by reference) this
              function will not work, it cannot alter the values min/max
              for the caller -- */

        private static void GetMinMaxBad(int[] array, int min, int max)
        {
            min = max = 0;

            for (var i = 0; i < array.Length; i++)
            {
                if (i == 0)
                {
                    min = max = array[i];
                }
                else
                {
                    if (array[i] < min)
                        min = array[i];
                    
                    else if (array[i] > max)
                        max = array[i];
                }
            }
        }
        
        /* -- Find the min/max value in 'array', those values are stored
              in the addresses of the variables passed in as arguments -- */

        private static void GetMinMax(int[] array, ref int min, ref int max)
        {
            min = max = 0;

            for (var i = 0; i < array.Length; i++)
            {
                if (i == 0)
                {
                    min = max = array[i];
                }
                else
                {
                    if (array[i] < min)
                        min = array[i];
                    
                    else if (array[i] > max)
                        max = array[i];
                }
            }
        }

        /* -- Methods with our parameters are useful because the variables
              MUST assign a value to the variable within the method. It is
              useful when multiple values need to be returned.  -- */
        
        private static void GetMinMaxOut(int[] array, out int min, out int max)
        {
            min = max = 0;

            for (var i = 0; i < array.Length; i++)
            {
                if (i == 0)
                {
                    min = max = array[i];
                }
                else
                {
                    if (array[i] < min)
                        min = array[i];
                    
                    else if (array[i] > max)
                        max = array[i];
                }
            }
        }
    }
}
