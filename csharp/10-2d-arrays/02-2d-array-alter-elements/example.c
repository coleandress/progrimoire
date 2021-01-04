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

   for(int i = 0; i < ROWS; i ++)
   {
      printf("{ ");

      for(int j = 0; j < COLUMNS; j ++)
         printf("%s%2d",  j == 0 ? "" : ", ", someArray[i][j]);

      printf(" }\n");
   }

   printf("\n");

   int n = ROWS * COLUMNS;

   for(int i = 0, j = n - 1; i < j; i ++, j --)
   {
      int iRow    = i / COLUMNS;
      int iColumn = i % COLUMNS;

      int jRow    = j / COLUMNS;
      int jColumn = j % COLUMNS;

      int tmp = someArray[iRow][iColumn];
      someArray[iRow][iColumn] = someArray[jRow][jColumn];
      someArray[jRow][jColumn] = tmp;
   }

   for(int i = 0; i < ROWS; i ++)
   {
      printf("{ ");

      for(int j = 0; j < COLUMNS; j ++)
         printf("%s%2d",  j == 0 ? "" : ", ", someArray[i][j]);

      printf(" }\n");
   }

   printf("\n");

   /* -- Now, double the value of each element -- */

   for(int i = 0; i < ROWS; i ++)
      for(int j = 0; j < COLUMNS; j ++)
         someArray[i][j] *= 2;

   for(int i = 0; i < ROWS; i ++)
   {
      printf("{ ");

      for(int j = 0; j < COLUMNS; j ++)
         printf("%s%3d",  j == 0 ? "" : ", ", someArray[i][j]);

      printf(" }\n");
   }

   return(0);
}
