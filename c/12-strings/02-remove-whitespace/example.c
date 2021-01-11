#include <string.h>
#include <stdio.h>
#include <ctype.h>

static const char *copyString(char *dest, int destSize, char *src)
{
   for(int i = 0; i < destSize; i ++)
      if((dest[i] = src[i]) == '\0')
         break;

   return(dest);
}

static const char *removeWhiteSpace(char *theString)
{
   int n = strlen(theString);
   int i = 0;

   while(theString[i])
   {
      if(isspace(theString[i]))
         copyString(theString + i, n, theString + i + 1);

      else
         i++;
   }

   return(theString);
}

int main()
{
   char aString[] = "There is a bit of whitespace in this string";
   char bString[] = "ThisOneOnTheOtherHandDoesn'tHaveAny";

   printf("%s\n", removeWhiteSpace(aString));
   printf("%s\n", removeWhiteSpace(bString));

   return(0);
}
