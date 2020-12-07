#include <stdio.h>

int main()
{
   char someCharacter = 'Q';

   printf("someCharacter: '%c'\n", someCharacter);

   someCharacter = 'X';

   printf("someCharacter: '%c'\n", someCharacter);

   someCharacter++;

   printf("someCharacter: '%c'\n", someCharacter);

   return(0);
}
