#include <stdbool.h>
#include <stdio.h>

int main()
{
   /* -- On windows, we need 'wb' instead of just 'w' to
         write a binary file.  Many other platforms don't
         require the 'b' but it does not harm so it's
         best to include it across the board -- */

   const char *fileName = "output.dat";
   FILE *f = fopen(fileName, "wb");

   if(!f)
   {
      printf("Could not open file: [%s]\n", fileName);
   }
   else
   {
      /* -- Write the numbers from 1,000,000 to 2,000,000
            to the file.   Note that each integer will only
            take up sizeof(int) bytes -- */

      bool valid = true;

      for(int i = 1000000; valid && i < 2000000; i ++)
      {
         if(fwrite(&i, sizeof(int), 1, f) != 1)
         {
            printf("Call to 'fwrite' failed\n");
            valid = false;
         }
      }

      fclose(f);

      if(valid)
         printf("Successfully wrote file: [%s]\n", fileName);
   }
}
