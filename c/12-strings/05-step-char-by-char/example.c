#include <string.h>
#include <stdio.h>

int main()
{
   const char *s = "pack my box with five dozen liquor jugs";

   for(int i = 0; s[i]; i ++)
      printf("s[%d] = '%c'\n", i, s[i]);

   return(0);
}


