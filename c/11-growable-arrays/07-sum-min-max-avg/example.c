#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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

   /* -- Although -1 is a perfectly valid integer value, we
         use it as an indicator of trouble as otherwise we'd have
         to complicate the api for this function significantly
         (i.e. return a struct or receive the value via a pointer) -- */

   return(-1);
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


int main()
{
   IntArray iArray = makeIntArray();

   for(int i = 0; i < 10; i ++)
      appendIntArray(&iArray, getRandomValue());

   printIntArray(&iArray);

   int min = 0;
   int max = 0;
   int sum = 0;

   for(int i = 0; i < iArray.mSize; i ++)
   {
      int value = getIntArray(&iArray, i);

      if(i == 0)
      {
         min = max = value;
      }
      else
      {
         if(value < min)
            min = value;

         else if(value > max)
            max = value;
      }

      sum += value;
   }

   printf(
      "min: %d, max: %d, sum: %d, avg: %.2f\n",
      min, max, sum, (double)sum / iArray.mSize
   );

   destroyIntArray(&iArray);

   return(0);
}
