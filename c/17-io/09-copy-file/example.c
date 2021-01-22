#include <stdbool.h>
#include <stdio.h>

#ifdef _WIN32
#  include <windows.h>
#endif

#ifdef _WIN32

static bool doCopy(const char *src, const char *dest)
{
   return(CopyFile(src, dest, false));
}

#else

static bool doCopy(const char *src, const char *dest)
{
   FILE *in  = NULL;
   FILE *out = NULL;

   if((in = fopen(src, "rb")) == NULL)
      return(false);

   if((out = fopen(dest, "wb")) == NULL)
   {
      fclose(in);
      return(false);
   }

   unsigned char buffer[4096] = { 0 };
   size_t        n            = 0;

   while((n = fread(buffer, 1, sizeof(buffer), in)) > 0)
      fwrite(buffer, 1, n, out);

   fclose(in);
   fclose(out);

   return(true);
}

#endif

static void test(const char *src, const char *dest)
{
   if(!doCopy(src, dest))
      printf("Error copying: [%s] to: [%s]\n", src, dest);
   else
      printf("Successfully copied: [%s] to: [%s]\n", src, dest);
}

int main()
{
   test("example.c", "test.c");
   return(0);
}
