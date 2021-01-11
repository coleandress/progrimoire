#include <string.h>
#include <stdio.h>

#define MAX_LENGTH (80)

const char *reverseString(char *theString)
{
   for(int i = 0, j = strlen(theString) - 1; i < j; i ++, j --)
   {
      char c       = theString[i];
      theString[i] = theString[j];
      theString[j] = c;
   }

   return(theString);
}

int main()
{
   char stringList[][MAX_LENGTH] =
   {
      "The lazy major was fixing Cupid's broken quiver.",
      "The public was amazed to view the quickness and dexterity of the juggler.",
      "The quick brown fox jumps over the lazy dog.",
      "We promptly judged antique ivory buckles for the next prize.",
      "Whenever the black fox jumped the squirrel gazed suspiciously."
   };

   int size = sizeof(stringList) / sizeof(stringList[0]);

   for(int i = 0; i < size; i ++)
   {
      printf("'%s'\n", stringList[i]);
      printf("'%s'\n\n", reverseString(stringList[i]));
   }
}
