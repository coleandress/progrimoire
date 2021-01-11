#include <string.h>
#include <stdio.h>

static const char *getSubstring(
   const char *src, int srcOffset, int srcCount, char *dest, int destCapacity
)
{
   int srcLength = strlen(src);

   for(int i = 0, j = 0; i < srcCount; i ++)
   {
      if(srcOffset + i < srcLength)
      {
         if(j < destCapacity - 1)
         {
            dest[j++] = src[srcOffset + i];

            if(j + 1 == destCapacity)
               dest[j] = '\0';
         }
      }
   }

   return(dest);
}

int main()
{
   const char *theString = "abcdefghijklmnopqrstuvwxyz";
   char buffer[255] = { '\0' };

   for(int i = 1; i < 8; i ++)
      printf("'%s'\n", getSubstring(theString, i, 2 * i, buffer, sizeof(buffer)));

   return(0);
}
