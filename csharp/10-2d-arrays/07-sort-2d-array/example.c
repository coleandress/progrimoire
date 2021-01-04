#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define COLUMNS (5)

typedef struct
{
   int mX;
   int mY;

} Point;

static double distance(Point p)
{
   return(sqrt(p.mX * p.mX + p.mY * p.mY));
}

static Point getRandomPoint()
{
   static bool first = true;

   if(first)
   {
      first = false;
      srand((int)time(0));
   }

   int x = rand() % 20;
   int y = rand() % 20;

   Point thePoint = { 0 };

   thePoint.mX = x;
   thePoint.mY = y;
   
   return(thePoint);
}

int main()
{
   int anArray[][COLUMNS] =
   {
      { 111,   2,   75, -4, 34 },
      { 200, 300, -101,  0, 12 },
      {   1,   3,    5,  7,  9 },
      {   9,   1,    7,  5,  3 }
   };

   int rows  = sizeof(anArray) / sizeof(anArray[0]);
   int total = COLUMNS * rows;

   for(int i = 0; i < rows; i ++)
   {
      printf("{ ");

      for(int j = 0; j < COLUMNS; j ++)
         printf("%s%3d", j == 0 ? "" : ", ", anArray[i][j]);

      printf(" }\n");
   }

   printf("\n");

   /* -- Sort the array using a selection sort, note that
         we essentially treat the 2d array as a 1d array
         of size 'total' -- */

   for(int i = 0; i < total - 1; i ++)
   {
      int minIndex = i;

      for(int j = minIndex + 1; j < total; j ++)
      {
         int r1 = j / COLUMNS;
         int c1 = j % COLUMNS;

         int r2 = minIndex / COLUMNS;
         int c2 = minIndex % COLUMNS;

         if(anArray[r1][c1] < anArray[r2][c2])
            minIndex = j;
      }

      if(minIndex != i)
      {
         int r1 = i / COLUMNS;
         int c1 = i % COLUMNS;

         int r2 = minIndex / COLUMNS;
         int c2 = minIndex % COLUMNS;

         int tmp         = anArray[r1][c1];
         anArray[r1][c1] = anArray[r2][c2];
         anArray[r2][c2] = tmp;
      }
   }

   for(int i = 0; i < rows; i ++)
   {
      printf("{ ");

      for(int j = 0; j < COLUMNS; j ++)
         printf("%s%3d", j == 0 ? "" : ", ", anArray[i][j]);

      printf(" }\n");
   }

   printf("\n");

   Point anotherArray[][COLUMNS] =
   {
      { 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0 }
   };

   rows = sizeof(anotherArray) / sizeof(anotherArray[0]);

   for(int i = 0; i < rows; i ++)
      for(int j = 0; j < COLUMNS; j ++)
         anotherArray[i][j] = getRandomPoint();

   for(int i = 0; i < rows; i ++)
   {
      printf("{ ");

      for(int j = 0; j < COLUMNS; j ++)
         printf("%s(%2d,%2d)", j == 0 ? "" : ", ",
            anotherArray[i][j].mX, anotherArray[i][j].mY);

      printf(" }\n");
   }

   printf("\n");

   total = rows * COLUMNS;

   /* -- Sort 'anotherArray', again we use the selection sort but our
         comparison function is 'distance' so we're ordering from
         closest to the origin to farthest from the origin -- */

   for(int i = 0; i < total - 1; i ++)
   {
      int minIndex = i;

      for(int j = minIndex + 1; j < total; j ++)
      {
         int r1 = j / COLUMNS;
         int c1 = j % COLUMNS;

         int r2 = minIndex / COLUMNS;
         int c2 = minIndex % COLUMNS;

         if(distance(anotherArray[r1][c1]) < distance(anotherArray[r2][c2]))
            minIndex = j;
      }

      if(minIndex != i)
      {
         int r1 = i / COLUMNS;
         int c1 = i % COLUMNS;

         int r2 = minIndex / COLUMNS;
         int c2 = minIndex % COLUMNS;

         Point tmp            = anotherArray[r1][c1];
         anotherArray[r1][c1] = anotherArray[r2][c2];
         anotherArray[r2][c2] = tmp;
      }
   }

   for(int i = 0; i < rows; i ++)
   {
      printf("{ ");

      for(int j = 0; j < COLUMNS; j ++)
         printf("%s(%2d,%2d)", j == 0 ? "" : ", ",
            anotherArray[i][j].mX, anotherArray[i][j].mY);

      printf(" }\n");
   }

   return(0);
}
