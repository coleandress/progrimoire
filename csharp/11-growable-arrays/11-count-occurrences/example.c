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

static int compare(const void *a, const void *b)
{
   int ia = *((int *)a);
   int ib = *((int *)b);

   return(ib - ia);
}

static bool isPrime(int x)
{
   if(x <= 2 || x % 2 == 0)
      return(x == 2);

   int stop = (int)sqrt(x);

   for(int i = 3; i <= stop; i += 2)
      if(x % i == 0)
         return(false);

   return(true);
}

int main()
{
   IntArray iArray = makeIntArray();

   while(iArray.mSize < 20)
   {
      int value = getRandomValue() % 10;

      if(isPrime(value))
         appendIntArray(&iArray, value);
   }

   printIntArray(&iArray);
   printf("\n");

   for(int i = 0; i < 10; i ++)
   {
      int count = 0;

      for(int j = 0; j < iArray.mSize; j ++)
         if(getIntArray(&iArray, j) == i)
            count++;

      if(count > 0)
         printf("number: %d, count: %d\n", i, count);
   }

   destroyIntArray(&iArray);

   return(0);
}
