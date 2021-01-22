#include <stdbool.h>
#include <stdio.h>

#ifdef _WIN32
#   include <windows.h>
#endif

#ifdef _WIN32

static bool doRename(const char *originalName, const char *newName)
{
   return(MoveFile(originalName, newName));
}

#else

static bool doRename(const char *originalName, const char *newName)
{
   int returnValue = rename(originalName, newName);

   return(returnValue == 0);
}

#endif

static void test(const char *originalName, const char *newName)
{
   if(!doRename(originalName, newName))
      printf("Could not rename: [%s] to: [%s]\n", originalName, newName);

   else
      printf("Successfully renamed: [%s] to: [%s]\n", originalName, newName);
}

int main()
{
   test("hello.txt", "new.txt");
   test("some-directory", "another-directory");

   return(0);
}
