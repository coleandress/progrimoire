#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifdef _WIN32
#  include <windows.h>
#else
#  include <sys/stat.h>
#  include <dirent.h>
#  include <unistd.h>
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

/* -- Assumes 'dest' has enough room for s1, s2, s3 and the null terminator -- */

static const char *copyStringThree(
   char *dest, const char *s1, const char *s2, const char *s3
)
{
   int j = 0;

   for(int i = 0, n1 = strlen(s1); i < n1; i ++)
      dest[j++] = s1[i];

   for(int i = 0, n2 = strlen(s2); i < n2; i ++)
      dest[j++] = s2[i];

   for(int i = 0, n3 = strlen(s3); i < n3; i ++)
      dest[j++] = s3[i];

   dest[j] = '\0';

   return(dest);
}

/* -- Assumes 'dest' has enough room for s1, s2 and the null terminator -- */

static const char *copyStringTwo(
   char *dest, const char *s1, const char *s2
)
{
   return(copyStringThree(dest, s1, s2, ""));
}


#ifdef _WIN32

#  define SEPARATOR "\\"
#  define SUFFIX    "\\*"

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

static bool removeDirectory(const char *dir)
{
   char *thePath = EMALLOC(strlen(dir) + strlen(SUFFIX) + 1);

   copyStringTwo(thePath, dir, SUFFIX);

   WIN32_FIND_DATA ffd;
   HANDLE          fileHandle  = FindFirstFile(thePath, &ffd);
   bool            returnValue = true;

   if(fileHandle == INVALID_HANDLE_VALUE)
   {
      returnValue = false;
   }
   else
   {
      do
      {
         if(strcmp(ffd.cFileName, ".") != 0 &&
            strcmp(ffd.cFileName, "..") != 0)
         {
            char *fullPath =
               EMALLOC(strlen(dir) + strlen(SEPARATOR) + strlen(ffd.cFileName) + 1);

            copyStringThree(fullPath, dir, SEPARATOR, ffd.cFileName);

            if(ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            {
               if(!removeDirectory(fullPath))
                  returnValue = false;
            }
            else
            {
               if(!DeleteFile(fullPath))
                  returnValue = false;
            }

            free(fullPath);
         }
      }
      while(returnValue && FindNextFile(fileHandle, &ffd) != 0);
   }

   if(returnValue)
   {
      if(!RemoveDirectory(dir))
         returnValue = false;
   }

   free(thePath);

   return(returnValue);
}

#else

#  define SEPARATOR "/"
#  define TYPE_DIRECTORY 4

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
}

static bool removeDirectory(const char *dir)
{
   DIR *d = opendir(dir);

   if(!d)
      return(false);

   bool returnValue     = true;
   struct dirent *entry = NULL;

   while(returnValue && (entry = readdir(d)) != NULL)
   {
      if(strcmp(entry->d_name, ".") != 0 &&
         strcmp(entry->d_name, "..") != 0)
      {
         char *fullPath = EMALLOC(
            strlen(dir) + strlen(SEPARATOR) + strlen(entry->d_name) + 1
         );

         copyStringThree(fullPath, dir, SEPARATOR, entry->d_name);

         if((entry->d_type & TYPE_DIRECTORY) != 0)
         {
            if(!removeDirectory(fullPath))
               returnValue = false;
         }
         else
         {
            if(unlink(fullPath) != 0)
               returnValue = false;
         }

         free(fullPath);
      }
   }

   closedir(d);

   if(rmdir(dir) != 0)
      returnValue = false;

   return(returnValue);
}

#endif

#define BASE "test"

int main()
{
   const char *dir =
      BASE SEPARATOR "a" SEPARATOR "b" SEPARATOR "c" SEPARATOR "d";

   if(makeDirectory(dir))
   {
      printf("Successfully created: [%s]\n", dir);

      if(!removeDirectory(BASE))
         printf("Error removing: [%s]\n", BASE);

      else
         printf("Successfully removed: [%s]\n", BASE);
   }
   else
   {
      printf("Could not create: [%s]\n", dir);
   }

   return(0);
}
