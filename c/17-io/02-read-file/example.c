#include <stdio.h>

FILE *openFile(const char *fileName, const char *mode)
{
#  ifdef _WIN32
#     pragma warning(push)
#     pragma warning(disable : 4996)
#  endif

   FILE *f = fopen(fileName, mode);

#  ifdef _WIN32
#     pragma warning(pop)
#  endif

   return(f);
}

static void showFile(const char *fileName)
{
   printf("----------------------------------------\n");
   printf("fileName: [%s]\n", fileName);
   printf("----------------------------------------\n\n");

   FILE *f = openFile(fileName, "r");

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
