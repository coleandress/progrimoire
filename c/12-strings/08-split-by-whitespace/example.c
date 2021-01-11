#include <string.h>
#include <stdio.h>
#include <ctype.h>

const char *split(const char *s, int *offsetPtr, int *lengthPtr)
{
   int n = strlen(s);
   int i = *offsetPtr;

   while(i < n && s[i] && isspace(s[i]))
      i++;

   if(!s[i])
      return(NULL);

   int size = 1;

   for(int j = i + 1; j < n && s[j] && !isspace(s[j]); j ++)
      size++;

   *offsetPtr = i + size;
   *lengthPtr = size;

   return(s + i);
}

int main()
{
   const char *s = "a string with words separated by whitespace";

   int offset = 0;
   int length = 0;

   for(;;)
   {
      const char *ptr = split(s, &offset, &length);

      if(!ptr)
         break;

      printf("'%.*s'\n", length, ptr);
   }
}
