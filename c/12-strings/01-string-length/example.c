#include <stdio.h>
#include <string.h>

static int stringLength(const char *s)
{
   int count = 0;

   while(s[count])
      count++;

   return(count);
}

int main()
{
   const char *theString = "abcdefghijklmnopqrstuvwxyz";

   printf("length of: '%s' is: %d\n", theString, strlen(theString));
   printf("length of: '%s' is: %d\n", theString, stringLength(theString));

   return(0);
}
