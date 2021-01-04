#include <stdio.h>

#define ROWS    (4)
#define COLUMNS (5)

int main()
{
   /* -- Step through each element in 'someArray' adding
         the values to 'sum' -- */

   int someArray[ROWS][COLUMNS] =
   {
      {  2,  3,  5,  7, 11 },
      { 13, 17, 19, 23, 29 },
      { 31, 37, 41, 43, 47 },
      { 53, 57, 59, 61, 67 }
   };

   int sum = 0;

   for(int i = 0; i < ROWS; i ++)
      for(int j = 0; j < COLUMNS; j ++)
         sum += someArray[i][j];

   printf("sum: %d\n", sum);

   printf("\n");

   /* -- Add to each element, the value of the previous element -- */

   int lastElement = 0;

   for(int i = 0; i < ROWS; i ++)
   {
      for(int j = 0; j < COLUMNS; j ++)
      {
         int current = someArray[i][j];
         someArray[i][j] += lastElement;
         lastElement = current;
      }
   }

   /* -- Now, display the array -- */

   for(int i = 0; i < ROWS; i ++)
   {
      printf("{ ");

      for(int j = 0; j < COLUMNS; j ++)
         printf("%s%3d",  j == 0 ? "" : ", ", someArray[i][j]);

      printf(" }\n");
   }

   return(0);
}
