#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define SIZE(x) ( sizeof(x) / sizeof(x[0]) )

struct Point
{
   int mX;
   int mY;
};

static double distance(int x, int y)
{
   return(sqrt(x * x + y * y));
}

static int compare(const void *a, const void *b)
{
   int ia = *((int *)a);
   int ib = *((int *)b);

   return(ia - ib);
}

static int comparePoints(const void *a, const void *b)
{
   struct Point pa = *((struct Point *)a);
   struct Point pb = *((struct Point *)b);

   double da = distance(pa.mX, pa.mY);
   double db = distance(pb.mX, pb.mY);

   /* -- Compare the points by determining which of them
         is closest to the origin -- */

   return(da < db ? -1 : da > db ? 1 : 0);
}

int main()
{
   int someArray[]    = { 31, 3, 7, 23, 11, 13, 2, 17, 19, 5, 29 };
   int anotherArray[] = { 31, 3, 7, 23, 11, 13, 2, 17, 19, 5, 29 };

   /* -- First, sort 'someArray' manually - in this case we
         use the selection sort -- */

   int size = SIZE(someArray);

   for(int i = 0; i < size - 1; i ++)
   {
      int minIndex = -1;

      for(int j = i; j < size; j ++)
         if(minIndex == -1 || someArray[j] < someArray[minIndex])
            minIndex = j;

      if(minIndex != i)
      {
         int tmp             = someArray[minIndex];
         someArray[minIndex] = someArray[i];
         someArray[i]        = tmp;
      }
   }

   for(int i = 0; i < size; i ++)
      printf("%d\n", someArray[i]);

   printf("\n");

   /* -- Now, sort 'anotherArray' using qsort -- */

   qsort(anotherArray, SIZE(anotherArray), sizeof(int), compare);

   for(int i = 0; i < size; i ++)
      printf("%d\n", anotherArray[i]);

   printf("\n");
   
   struct Point points[] =
   {
      { 1, 2 }, { -1, -2 }, { 10, 20 }, { -2, -4 }, { 100, 100 }, { 0, 0 }
   };

   /* -- Sort 'points' using qsort -- */

   qsort(points, SIZE(points), sizeof(struct Point), comparePoints);

   for(int i = 0; i < SIZE(points); i ++)
      printf("{ %d, %d }\n", points[i].mX, points[i].mY);

   return(0);
}
