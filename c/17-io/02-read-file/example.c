#include <stdio.h>

static void showFile(const char *fileName)
{
   printf("----------------------------------------\n");
   printf("fileName: [%s]\n", fileName);
   printf("----------------------------------------\n\n");

   FILE *f = fopen(fileName, "r");

   if(!f)
   {
      printf("Could not open file: [%s]\n", fileName);
   }
   else
   {
      int c = 0;

      while((c = fgetc(f)) != EOF)
         putc(c, stdout);

      fclose(f);
   }
}

int main()
{
   showFile(__FILE__);
   showFile("some-non-existent-file.txt");

   return(0);
}
