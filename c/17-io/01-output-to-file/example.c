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


int main()
{
   const char *nameOne = "hello.txt";
   const char *nameTwo = "z:\\y\\x\\hello.txt";

   FILE *f = openFile(nameOne, "w");

   if(!f)
   {
      printf("Could not open file: [%s] for writing\n", nameOne);
   }
   else
   {
      fprintf(f, "Hello World\n");
      fclose(f);

      printf("Successfully wrote file: [%s]\n", nameOne);
   }

   f = openFile(nameTwo, "w");

   if(!f)
   {
      printf("Could not open file: [%s] for writing\n", nameTwo);
   }
   else
   {
      fprintf(f, "Hello World\n");
      fclose(f);

      printf("Successfully wrote file: [%s]\n", nameTwo);
   }

   return(0);
}
