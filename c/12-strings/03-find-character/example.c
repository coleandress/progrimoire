#include <string.h>
#include <stdio.h>

static void findLetters(const char *s, const char *alphabet)
{
   printf("String: [%s]\n", s);

   for(int i = 0; alphabet[i]; i ++)
   {
      if(strchr(s, alphabet[i]) != NULL)
         printf("Found char '%c'\n", alphabet[i]);
      else
         printf("Did not find char '%c'\n", alphabet[i]);
   }
}

int main()
{
   const char *alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
   const char *s1 = "pack my box with five dozen liquor jugs";
   const char *s2 = "THE FIVE BOXING WIZARDS JUMP QUICKLY";

   findLetters(s1, alphabet);

   printf("\n");

   findLetters(s2, alphabet);

   return(0);
}


