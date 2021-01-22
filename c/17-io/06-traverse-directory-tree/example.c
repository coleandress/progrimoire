#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef _WIN32
#  define __USE_LARGEFILE64
#  define _LARGEFILE_SOURCE
#  define _LARGEFILE64_SOURCE
#endif

#include <sys/types.h>
#include <sys/stat.h>

#ifdef _WIN32
#  include <windows.h>
#endif

/* -- Arrange to have the calling line number and file name
      displayed if malloc fails -- */

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

static void showFilesEx(const char *dir, int indent)
{
   const char *separator = "\\";
   const char *suffix    = "\\*";

   char *thePath = EMALLOC(strlen(dir) + strlen(suffix) + 1);

   copyStringTwo(thePath, dir, suffix);

   WIN32_FIND_DATA ffd;
   HANDLE          fileHandle = FindFirstFile(thePath, &ffd);


   if(fileHandle == INVALID_HANDLE_VALUE)
   {
      printf("Error reading directory: [%s]\n", thePath);
   }
   else
   {
      do
      {
         printf("%*s%s\n", indent, "", ffd.cFileName);

         /* -- Recurse into directories, if they're not '.' or '..' -- */

         if(ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY &&
            strcmp(ffd.cFileName, ".") != 0 &&
            strcmp(ffd.cFileName, "..") != 0)
         {
            char *fullPath =
               EMALLOC(strlen(dir) + strlen(separator) + strlen(ffd.cFileName) + 1);

            copyStringThree(fullPath, dir, separator, ffd.cFileName);

            showFilesEx(fullPath, indent + 1);

            free(fullPath);
         }
      }
      while(FindNextFile(fileHandle, &ffd) != 0);
   }

   free(thePath);
}

static void showFiles(const char *dir)
{
   showFilesEx(dir, 0);
}

#else

#include <dirent.h>
#define  TYPE_DIRECTORY 4

static void showFilesEx(const char *dir, int indent)
{
   const char *separator = "/";
   DIR *d = opendir(dir);

   if(!d)
   {
      printf("Error reading directory: [%s]\n", dir);
   }
   else
   {
      struct dirent *entry = NULL;

      while((entry = readdir(d)) != NULL)
      {
         printf("%*s%s\n", indent, "", entry->d_name);

         if((entry->d_type & TYPE_DIRECTORY) != 0 &&
            strcmp(entry->d_name, ".") != 0 &&
            strcmp(entry->d_name, "..") != 0)
         {
            char *fullPath = EMALLOC(
               strlen(dir) + strlen(separator) + strlen(entry->d_name) + 1
            );

            copyStringThree(fullPath, dir, separator, entry->d_name);

            showFilesEx(fullPath, indent + 1);

            free(fullPath);
         }
      }
   }

   closedir(d);
}

static void showFiles(const char *dir)
{
   showFilesEx(dir, 0);
}

#endif

int main(int argc, char **argv)
{
   const char *path = (argc > 1 ? argv[1] : ".");

   showFiles(path);

   return(0);
}

