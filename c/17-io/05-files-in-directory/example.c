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

   for(int i = 0; i < s1[i]; i ++)
      dest[j++] = s1[i];

   for(int i = 0; i < s2[i]; i ++)
      dest[j++] = s2[i];

   for(int i = 0; i < s3[i]; i ++)
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

static bool showFiles(const char *dir)
{
   const char *separator = "\\";
   const char *suffix    = "\\*";

   char *thePath = EMALLOC(strlen(dir) + strlen(suffix) + 1);

   copyStringTwo(thePath, dir, suffix);

   HANDLE fileHandle;
   WIN32_FIND_DATA ffd;

   bool returnValue = false;

   if((fileHandle = FindFirstFile(thePath, &ffd)) != INVALID_HANDLE_VALUE)
   {
      bool showSum           = true;
      returnValue            = true;
      unsigned long long sum = 0ULL;

      do
      {
         /* -- Skip directories -- */

         if(ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            continue;

         char *fullPath =
            EMALLOC(strlen(dir) + strlen(separator) + strlen(ffd.cFileName) + 1);

         copyStringThree(fullPath, dir, separator, ffd.cFileName);

         struct __stat64 st;

         if(__stat64(fullPath, &st))
         {
            printf("Could not find file size: %s\n", ffd.cFileName);
            showSum = false;
         }
         else
         {
            printf("%s => %llu\n", ffd.cFileName, st.st_size);
            sum += st.st_size;
         }

         free(fullPath);
      }
      while (showSum && FindNextFile(fileHandle, &ffd) != 0);

      printf("\n");

      if(showSum)
         printf("sum of file sizes: %llu\n", sum);
   }

   free(thePath);

   return(returnValue);
}

#else

#include <dirent.h>

static bool showFiles(const char *dir)
{
   const char *separator = "/";
   DIR *d = opendir(dir);

   if(!d)
      return(false);

   struct dirent *entry = NULL;
   unsigned long long sum = 0LL;
   bool showSum           = true;

   while(showSum && (entry = readdir(d)) != NULL)
   {
      char *fullPath = EMALLOC(
         strlen(dir) + strlen(separator) + strlen(entry->d_name) + 1
      );

      copyStringThree(fullPath, dir, separator, entry->d_name);

      struct stat64 info;

      if(stat64(fullPath, &info))
      {
         printf("Could not stat: %s\n", fullPath);
         showSum = false;
      }
      else if(S_ISREG(info.st_mode))
      {
         printf("%s => %lld\n", entry->d_name, info.st_size);
         sum += info.st_size;
      }

      free(fullPath);
   }

   printf("\n");

   if(showSum)
      printf("sum of file sizes: %llu\n", sum);

   closedir(d);

   return(true);
}

#endif

int main()
{
   const char *path = ".";

   if(!showFiles(path))
      printf("Could not process directory: [%s]\n", path);

    return(0);
}

