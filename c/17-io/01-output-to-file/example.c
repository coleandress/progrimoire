#include <stdio.h>

int main()
{
   const char *nameOne = "hello.txt";
   const char *nameTwo = "z:\\y\\x\\hello.txt";

   FILE *f = fopen(nameOne, "w");

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

   f = fopen(nameTwo, "w");

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
