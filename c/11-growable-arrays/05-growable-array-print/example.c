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

   printf("{ ");

   for(int i = 0; i < iArray.mSize; i ++)
      printf("%s%d", i == 0 ? "" : ", ", getIntArray(&iArray, i));

   printf(" }\n");
            
   destroyIntArray(&iArray);

   return(0);
}
