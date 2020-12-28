#include <stdio.h>

#define SIZE(x) (sizeof(x) / sizeof(x[0]))

int main()
{
   /* -- In C, you can only perform a switch on an integral
         type.  You cannot (for example) use a string or
         a floating point value.  To check a string (for example)
         against a list of possible matches, we have to loop
         through the values manually and compare -- */

   const char colorOne[] = "red";
   const char colorTwo[] = "yellow";

   const char *list[] =
   {
      "red",
      "green",
      "blue"
   };

   int index = -1;

   for(int i = 0; index == -1 && i < SIZE(list); i ++)
      if(strcmp(colorOne, list[i]) == 0)
         index = i;

   printf(
      "Color: '%s' %s found in 'list'\n", colorOne, index == -1 ? "was not" : "was"
   );

   index = -1;

   for(int i = 0; index == -1 && i < SIZE(list); i ++)
      if(strcmp(colorTwo, list[i]) == 0)
         index = i;

   printf(
      "Color: '%s' %s found in 'list'\n", colorTwo, index == -1 ? "was not" : "was"
   );

   return(0);
}
