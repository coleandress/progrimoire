#include <string.h>
#include <stdio.h>

static int findIndex(const char *s, char c)
{
   for(int i = 0; s[i]; i ++)
      if(s[i] == c)
         return(i);

   return(-1);
}

static int findIndex2(const char *s, char c)
{
   const char *ptr = strchr(s, c);

   return(ptr ? ptr - s : -1);
}

static void findLetters(const char *s, const char *alphabet)
{
   printf("String: [%s]\n", s);

   for(int i = 0; alphabet[i]; i ++)
   {
      printf(
         "char: '%c', location: (%d, %d)\n",
         alphabet[i], findIndex(s, alphabet[i]), findIndex2(s, alphabet[i])
      );
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
