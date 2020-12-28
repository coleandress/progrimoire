#include <stdio.h>

#define SIZE(x) ( sizeof(x) / sizeof(x[0]))

/* -- Find the min/max value in 'array', those values are stored
      in *minPtr and *maxPtr -- */

static void getMinMax(int *array, int size, int *minPtr, int *maxPtr)
{
   *minPtr = *maxPtr = 0;

   for(int i = 0; i < size; i ++)
   {
      if(i == 0)
      {
         *minPtr = *maxPtr = array[i];
      }
      else
      {
         if(array[i] < *minPtr)
            *minPtr = array[i];

         else if(array[i] > *maxPtr)
            *maxPtr = array[i];
      }
   }
}

/* -- Since min/max are passed by value (not be reference) this
      function will not work, it cannot alter the values of min/max
      for the caller -- */

static void getMinMaxBad(int *array, int size, int min, int max)
{
   min = max = 0;

   for(int i = 0; i < size; i ++)
   {
      if(i == 0)
      {
         min = max = array[i];
      }
      else
      {
         if(array[i] < min)
            min = array[i];

         else if(array[i] > max)
            max = array[i];
      }
   }
}

int main()
{
   int someArray[]      = { 2, 3, 5, 7, 11 };
   int someOtherArray[] = { 11, 2, 7, 3, 5, 13 };

   int minValue = 0;
   int maxValue = 0;

   /* -- Here we pass 'minValue' and 'maxValue' by value which means
         'getMinMaxBad' only receives a copy and cannot modify the
         original variables -- */

   getMinMaxBad(someArray, SIZE(someArray), minValue, maxValue);
   printf("min: %d, max: %d\n", minValue, maxValue);

   getMinMaxBad(someOtherArray, SIZE(someOtherArray), minValue, maxValue);
   printf("min: %d, max: %d\n", minValue, maxValue);

   printf("\n");

   /* -- Here, we pass our values by address which does allow
         'getMinMax' to modify the original variables -- */

   getMinMax(someArray, SIZE(someArray), &minValue, &maxValue);
   printf("min: %d, max: %d\n", minValue, maxValue);

   getMinMax(someOtherArray, SIZE(someOtherArray), &minValue, &maxValue);
   printf("min: %d, max: %d\n", minValue, maxValue);

   return(0);
}
