#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

typedef struct
{
   int *mArray;
   int  mCapacity;
   int  mSize;

} IntArray;

typedef struct
{
   int mX;
   int mY;

} Point;

typedef struct
{
   Point *mArray;
   int   mCapacity;
   int   mSize;

} PointArray;

/* -- Arrange to have the calling line number and file name
      displayed if realloc fails -- */

#define EREALLOC(ptr, bytes) erealloc(ptr, bytes, __FILE__, __LINE__)

static void *erealloc(void *ptr, int bytes, char *file, int line)
{
   void *thePointer = realloc(ptr, bytes);

   if(!thePointer)
   {
      printf("Could not reallocate to: %d bytes (%s | %d)\n", bytes, file, line);
      exit(1);
   }

   return(thePointer);
}

static IntArray makeIntArray()
{
   IntArray theArray = { NULL, 0, 0 };

   return(theArray);
}

static void destroyIntArray(IntArray *iaPtr)
{
   free(iaPtr->mArray);

   iaPtr->mArray    = NULL;
   iaPtr->mCapacity = 0;
   iaPtr->mSize     = 0;
}

static void appendIntArray(IntArray *iaPtr, int value)
{
   if(iaPtr->mSize == iaPtr->mCapacity)
   {
      if(iaPtr->mCapacity == 0)
         iaPtr->mCapacity = 32;

      else
         iaPtr->mCapacity *= 2;

      iaPtr->mArray = EREALLOC(iaPtr->mArray, sizeof(int) * iaPtr->mCapacity);
   }

   iaPtr->mArray[iaPtr->mSize++] = value;
}

static int getIntArray(IntArray *iaPtr, int index)
{
   if(index >= 0 && index < iaPtr->mSize)
      return(iaPtr->mArray[index]);

   return(-1);
}

static bool setIntArray(IntArray *iaPtr, int value, int index)
{
   bool success = false;

   if(index >= 0 && index < iaPtr->mSize)
   {
      iaPtr->mArray[index] = value;
      success = true;
   }

   return(success);
}

static void printIntArray(IntArray *iaPtr)
{
   printf("{ ");

   for(int i = 0; i < iaPtr->mSize; i ++)
      printf("%s%d", i == 0 ? "" : ", ", iaPtr->mArray[i]);

   printf(" }\n");

}

static PointArray makePointArray()
{
   PointArray theArray = { 0, 0, 0 };

   return(theArray);
}

static void destroyPointArray(PointArray *paPtr)
{
   free(paPtr->mArray);

   paPtr->mArray    = NULL;
   paPtr->mCapacity = 0;
   paPtr->mSize     = 0;
}

static void appendPointArray(PointArray *paPtr, Point value)
{
   if(paPtr->mSize == paPtr->mCapacity)
   {
      if(paPtr->mCapacity == 0)
         paPtr->mCapacity = 32;

      else
         paPtr->mCapacity *= 2;

      paPtr->mArray = EREALLOC(paPtr->mArray, sizeof(Point) * paPtr->mCapacity);
   }

   paPtr->mArray[paPtr->mSize++] = value;
}

static Point getPointArray(PointArray *paPtr, int index)
{
   if(index >= 0 && index < paPtr->mSize)
      return(paPtr->mArray[index]);

   Point thePoint = { -1, -1 };

   return(thePoint);
}

static bool setPointArray(PointArray *paPtr, Point value, int index)
{
   bool success = false;

   if(index >= 0 && index < paPtr->mSize)
   {
      paPtr->mArray[index] = value;
      success = true;
   }

   return(success);
}

static void printPointArray(PointArray *paPtr)
{
   printf("{ ");

   for(int i = 0; i < paPtr->mSize; i ++)
      printf("%s(%d,%d)", i == 0 ? "" : ", ", paPtr->mArray[i].mX, paPtr->mArray[i].mY);

   printf(" }\n");
}

static int getRandomValue()
{
   static bool first = true;

   if(first)
   {
      first = false;
      srand((int)time(0));
   }

   return(rand());
}

static Point getRandomPoint()
{
   Point thePoint = { -1, -1 };

   thePoint.mX = getRandomValue() % 10;
   thePoint.mY = getRandomValue() % 10;

   return(thePoint);
}

static int compare(const void *a, const void *b)
{
   int ia = *((int *)a);
   int ib = *((int *)b);

   return(ib - ia);
}

static double distance(int x, int y)
{
   return(sqrt(x * x + y * y));
}

static int comparePoints(const void *a, const void *b)
{
   Point pa = *((Point *)a);
   Point pb = *((Point *)b);

   double da = distance(pa.mX, pa.mY);
   double db = distance(pb.mX, pb.mY);

   /* -- Compare the points by determining which of them
         is closest to the origin -- */

   return(da < db ? -1 : da > db ? 1 : 0);
}

int main()
{
   IntArray iArray = makeIntArray();

   for(int i = 0; i < 10; i ++)
      appendIntArray(&iArray, getRandomValue());

   printIntArray(&iArray);
   printf("\n");

   /* -- First, sort the array manually using a selection sort -- */

   for(int i = 0; i < iArray.mSize - 1; i ++)
   {
      int minIndex = -1;

      for(int j = i; j < iArray.mSize; j ++)
         if(minIndex == -1 || getIntArray(&iArray, j) < getIntArray(&iArray, minIndex))
            minIndex = j;

      if(minIndex != i)
      {
         int tmp = getIntArray(&iArray, minIndex);
         setIntArray(&iArray, getIntArray(&iArray, i), minIndex);
         setIntArray(&iArray, tmp, i);
      }
   }

   printIntArray(&iArray);
   printf("\n");

   /* -- Now, use qsort -- */

   qsort(iArray.mArray, iArray.mSize, sizeof(int), compare);

   printIntArray(&iArray);
   printf("\n");

   destroyIntArray(&iArray);

   PointArray pArray = makePointArray();

   for(int i = 0; i < 5; i ++)
      appendPointArray(&pArray, getRandomPoint());

   printPointArray(&pArray);
   printf("\n");

   /* -- Now, sort 'pArray' using qsort -- */

   qsort(pArray.mArray, pArray.mSize, sizeof(Point), comparePoints);

   printPointArray(&pArray);
   printf("\n");

   return(0);
}
