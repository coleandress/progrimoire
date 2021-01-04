#include <stdbool.h>
#include <stdio.h>

#define ROWS    (4)
#define COLUMNS (5)

int main()
{
   int someArray[ROWS][COLUMNS] =
   {
      {  2,  3,  5,  7, 11 },
      { 13, 17, 19, 23, 29 },
      { 31, 37, 41, 43, 47 },
      { 53, 57, 59, 61, 67 }
   };

   bool first = true;

   int min = 0;
   int max = 0;
   int sum = 0;

   for(int i = 0; i < ROWS; i ++)
   {
      for(int j = 0; j < COLUMNS; j ++)
      {
         sum += someArray[i][j];

         if(first)
         {
            first = false;
            min = max = someArray[i][j];
         }
         else
         {
            if(someArray[i][j] < min)
               min = someArray[i][j];

            else if(someArray[i][j] > max)
               max = someArray[i][j];
         }
      }
   }

   printf("sum: %d\n", sum);
   printf("min: %d\n", min);
   printf("max: %d\n", max);
   printf("avg: %.2f\n", (double)sum / (ROWS * COLUMNS));

   return(0);
}
