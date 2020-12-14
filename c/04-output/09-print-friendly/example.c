#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef struct
{
   int mX;
   int mY;
   char mBuffer[255];

} Entry;

static Entry makeEntry(int x, int y, const char *theString)
{
   Entry theEntry = { 0, 0, '\0' };

   theEntry.mX = x;
   theEntry.mY = y;

   int n = sizeof(theEntry.mBuffer);
   int j = 0;

   for(int i = 0; i < n - 1; i ++, j ++)
   {
      if(!theString[i])
         break;

      theEntry.mBuffer[i] = theString[i];
   }

   theEntry.mBuffer[j] = '\0';

   return(theEntry);
}

static void showEntry(const Entry *ptr)
{
   printf("{ mX: %d, mY: %d, mBuffer: '%s' }\n", ptr->mX, ptr->mY, ptr->mBuffer);
}

int main()
{
   Entry e1 = makeEntry(1, 2, "buckle my shoe");
   Entry e2 = makeEntry(3, 4, "open the door");

   showEntry(&e1);
   showEntry(&e2);

   return(0);
}

