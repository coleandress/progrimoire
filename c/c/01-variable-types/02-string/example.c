#include <string.h>
#include <stdio.h>

#define STRING_SIZE (255)

/***********************************************************************
 * Since 'strcpy' and 'strncpy' tend to cause warnings about their
 * being unsafe (which they are) and 'strlcpy' isn't standard, here
 * we use our own 'copyString' which makes sure we don't exceed
 * the capacity of 'dest' as we copy 'src' to it.
 ***********************************************************************/

static const char *copyString(
   char *dest, int destCapacity, const char *src
)
{
   if(destCapacity < 1)
      return(dest);

   int i = 0;

   while(i + 1 < destCapacity  && src[i])
   {
      dest[i] = src[i];
      i++;
   }

   dest[i] = '\0';

   return(dest);
}

int main()
{
   /* -- Initialize 'someString' to be an empty string -- */

   char someString[STRING_SIZE] = { '\0' };

   /* -- Give 'someOtherString' an initial value -- */

   char someOtherString[STRING_SIZE] = "another string entirely";

   /* -- Here 'theString' doesn't "own" the text it points to
         so changing that text is undefined behavior -- */

   const char *theString = "Hello world and hello kitty ...";

   copyString(someString, STRING_SIZE, theString);

   printf("someString: '%s'\n", someString);
   printf("someOtherString: '%s'\n", someOtherString);

   someString[0] = '\0';

   printf("someString: '%s'\n", someString);

   return(0);
}
