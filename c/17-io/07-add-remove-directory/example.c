#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifdef _WIN32
#  include <windows.h>
#else
#  include <sys/stat.h>
#  include <dirent.h>
#  include <errno.h>
#endif

#define EMALLOC(x) emalloc(x, __FILE__, __LINE__)

static void *emalloc(int size, char *file, int line)
{
   void *ptr = malloc(size);

   if(!ptr)
   {
      printf(
         "[file: %s, line: %d] Could not allocate %d bytes\n",
         file, line, size
      );

      exit(1);
   }

   return(ptr);
}

#ifdef _WIN32

#  define SEPARATOR "\\"

static bool DirectoryExists(const char *path)
{
   int value = GetFileAttributes(path);

   return(value != INVALID_FILE_ATTRIBUTES && (value & FILE_ATTRIBUTE_DIRECTORY));
}

static bool makeDirectory(const char *dir)
{
   char *buffer = EMALLOC(strlen(dir) + 1);

   for(int i = 0; true; i ++)
   {
      buffer[i] = dir[i];

      if(!dir[i])
         break;
   }

   bool returnValue = true;
   char *sepPtr     = strchr(buffer, '\\');

   while(returnValue)
   {
      char *next = NULL;

      if(sepPtr)
      {
         next    = strchr(sepPtr + 1, '\\');
         *sepPtr = '\0';
      }

      if(!DirectoryExists(buffer) && !CreateDirectory(buffer, NULL))
      {
         returnValue = false;
      }
      else
      {
         if(!sepPtr)
            break;

         *sepPtr = '\\';
         sepPtr  = next;
      }
   }

   free(buffer);
   return(returnValue);
}

#else

#  define SEPARATOR "/"

static bool DirectoryExists(const char *path)
{
   DIR *d = opendir(path);

   if(d)
   {
      closedir(d);
      return(true);
   }

   return(false);
}

static bool makeDirectory(const char *dir)
{
   char *buffer = EMALLOC(strlen(dir) + 1);

   for(int i = 0; true; i ++)
   {
      buffer[i] = dir[i];

      if(!dir[i])
         break;
   }

   bool returnValue = true;
   char *sepPtr     = strchr(buffer, '/');

   if(sepPtr == buffer)
      sepPtr = strchr(buffer + 1, '/');

   while(returnValue)
   {
      char *next = NULL;

      if(sepPtr)
      {
         next    = strchr(sepPtr + 1, '/');
         *sepPtr = '\0';
      }

      if(!DirectoryExists(buffer) && mkdir(buffer, 0777) != 0)
      {
         returnValue = false;
      }
      else
      {
         if(!sepPtr)
            break;

         *sepPtr = '/';
         sepPtr  = next;
      }
   }

   free(buffer);
   return(returnValue);
   return(false);
}

#endif

int main()
{
   const char *dir =
      "test" SEPARATOR "a" SEPARATOR "b" SEPARATOR "c" SEPARATOR "d";

   if(makeDirectory(dir))
      printf("Successfully created: [%s]\n", dir);

   else
      printf("Could not create: [%s]\n", dir);

   return(0);
}
