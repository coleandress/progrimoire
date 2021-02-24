#include <stdbool.h>
#include <stdio.h>
#include "char-count.h"

static void demo(const char *theString)
{
   printf("theString: %s\n", theString);

   bool isPangram = true;

   for(char c = 'a'; c <= 'z'; c ++)
   {
      int count = countCharacters(theString, c);
    
      printf("char: '%c', count: %d\n", c, count);

      if(count < 1)
         isPangram = false;
   }

   printf("theString %s a pangram\n", isPangram ? "is" : "is not");
   printf("\n");
}

int main()
{
   const char *theStringOne = "the quick brown fox jumps over the lazy dog";
   const char *theStringTwo = "the quick brown fox jumps over the lethargic dog";

   demo(theStringOne);
   demo(theStringTwo);

   return(0);
}
