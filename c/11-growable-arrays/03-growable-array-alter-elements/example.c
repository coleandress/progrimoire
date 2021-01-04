#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

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

static int getIntArray(IntArray *iaPtr, int index)
{
   if(index >= 0 && index < iaPtr->mSize)
      return(iaPtr->mArray[index]);

   return(-1);
}

static void printIntArray(IntArray *iaPtr)
{
   printf("{ ");

   for(int i = 0; i < iaPtr->mSize; i ++)
      printf("%s%d", i == 0 ? "" : ", ", iaPtr->mArray[i]);

   printf(" }\n");

}

int main()
{
   IntArray iArray = makeIntArray();

   for(int i = 2; i < 50; i ++)
   {
      int divisors = 0;

      for(int j = 2; j < i; j ++)
         if(i % j == 0)
            divisors++;

      if(divisors == 0)
         appendIntArray(&iArray, i);
   }

   printIntArray(&iArray);

   printf("\n");

   for(int i = 0, j = iArray.mSize - 1; i < j; i ++, j --)
   {
      int tmp = getIntArray(&iArray, i);
      setIntArray(&iArray, getIntArray(&iArray, j), i);
      setIntArray(&iArray, tmp, j);
   }

   printIntArray(&iArray);

   destroyIntArray(&iArray);

   return(0);
}
