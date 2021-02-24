#include "char-count.h"

int countCharacters(const char *theString, char theChar)
{
   int count = 0;
   int i     = 0;

   while(theString[i])
   {
      if(theString[i] == theChar)
         count++;

      i++;
   }

   return(count);
}
