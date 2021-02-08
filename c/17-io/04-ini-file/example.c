#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

typedef struct
{
   char mText[255];

} Line;

/* -- Arrange to have the calling line number and file name
      displayed if malloc fails -- */

#define EMALLOC(x) emalloc(x, __FILE__, __LINE__)

static void *emalloc(int size, char *file, int line)
{
   void *ptr = malloc(size);

   if(!ptr)
   {
      printf("[file: %s, line: %d] Could not allocate %d bytes\n", file, line, size);
      exit(1);
   }

   return(ptr);
}

/* -- A heuristic to identify a section, we simply look to see
      if the first non-whitespace character of the line is '[' -- */

static bool isSection(const char *line)
{
   for(int i = 0; line[i]; i ++)
      if(!isspace(line[i]))
         return(line[i] == '[');

   return(false);
}

static bool sectionMatches(const char *sectionName, const char *line)
{
   /* -- Bypass leading whitespace -- */

   int i = 0;

   while(line[i] && isspace(line[i]))
      i++;

   if(!line[i] || line[i] != '[')
      return(false);

   /* -- Allow for whitespace between the '[' and the section name -- */

   for(i++; line[i] && isspace(line[i]); i ++)
      ;

   if(!line[i])
      return(false);

   /* -- Now, we should find 'sectionName' -- */

   int n = strlen(sectionName);

   if(strncmp(line + i, sectionName, n) != 0)
      return(false);

   /* -- Bypass whitespace -- */

   for(i += n; line[i] && isspace(line[i]); i ++)
      ;

   if(!line[i] || line[i] != ']')
      return(false);

   /* -- Ensure that only whitespace is found to the right of ']' -- */

   for(i++; line[i]; i ++)
      if(!isspace(line[i]))
         return(false);

   return(true);
}

static char *getValue(const char *key, const char *line)
{
   /* -- Bypass leading whitespace -- */

   int i = 0;

   while(line[i] && isspace(line[i]))
      i++;

   if(!line[i])
      return(NULL);

   /* -- Next, we should find our key -- */

   int n = strlen(key);

   if(strncmp(line + i, key, n) != 0)
      return(NULL);

   i += n;

   /* -- Allow optional whitespace before and after the '=' -- */

   while(line[i] && isspace(line[i]))
      i++;

   if(!line[i] || line[i] != '=')
      return(NULL);

   for(i++; line[i] && isspace(line[i]); i ++)
      ;

   if(!line[i])
      return(NULL);

   n = strlen(line + i) + 1;

   char *ptr = EMALLOC(n);

   for(int j = 0; j < n; j ++)
   {
      if(j + 1 == n)
         ptr[j] = '\0';

      else
         ptr[j] = line[i++];
   }

   return(ptr);
}

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

static bool getLines(const char *fileName, int *nLinesPtr, Line **linesPtr)
{
   FILE *f = openFile(fileName, "r");

   if(!f)
      return(false);

   *nLinesPtr = 0;

   for(;;)
   {
      int c = fgetc(f);

      if(c == EOF)
         break;

      if(c == '\n')
         ++(*nLinesPtr);
   }

   rewind(f);

   Line *ptr = EMALLOC(*nLinesPtr * sizeof(Line));

   Line theLine = { 0 };
   int i        = 0;

   while(fgets(theLine.mText, sizeof(theLine.mText), f))
   {
      char *np = strchr(theLine.mText, '\n');

      if(np)
         *np = '\0';

      ptr[i++] = theLine;
   }

   *linesPtr = ptr;
   fclose(f);

   return(true);
}

static char *findValue(Line *lines, int nLines, const char *section, const char *key)
{
   for(int i = 0; i < nLines; i ++)
   {
      if(sectionMatches(section, lines[i].mText))
      {
         int j = i + 1;

         while(j < nLines && !isSection(lines[j].mText))
         {
            char *v = getValue(key, lines[j].mText);

            if(v)
               return(v);

            j++;
         }
      }
   }

   return(NULL);
}

static void doFindValue(Line *lines, int nLines, const char *section, const char *key)
{
   char *ptr = findValue(lines, nLines, section, key);

   if(ptr)
   {
      printf("%s.%s = '%s'\n", section, key, ptr);
      free(ptr);
   }
   else
   {
      printf("section: '%s', key: '%s' (not found)\n", section, key);
   }
}

int main()
{
   Line *lines = NULL;
   int nLines  = 0;

   if(!getLines("example.ini", &nLines, &lines))
   {
      printf("Error reading ini file\n");
   }
   else
   {
      for(int i = 0; i < nLines; i ++)
         printf("'%s'\n", lines[i].mText);

      printf("\n");

      doFindValue(lines, nLines, "sectionOne", "keyOne");
      doFindValue(lines, nLines, "sectionone", "keyOne");

      doFindValue(lines, nLines, "sectionTwo", "foo");
      doFindValue(lines, nLines, "sectionTwo", "bar");
      doFindValue(lines, nLines, "sectionTwo", "keyTwo");
      doFindValue(lines, nLines, "sectionTwo", "keyThree");

      doFindValue(lines, nLines, "sectionThree", "a");
      doFindValue(lines, nLines, "sectionThree", "b");
      doFindValue(lines, nLines, "sectionThree", "c");
      doFindValue(lines, nLines, "sectionThree", "d");
      doFindValue(lines, nLines, "sectionThree", "e");
      doFindValue(lines, nLines, "sectionThree", "f");

      doFindValue(lines, nLines, "sectionThree", "aa");
      doFindValue(lines, nLines, "sectionThree", "bb");
      doFindValue(lines, nLines, "sectionThree", "cc");
      doFindValue(lines, nLines, "sectionThree", "dd");
      doFindValue(lines, nLines, "sectionThree", "ee");
      doFindValue(lines, nLines, "sectionThree", "ff");

      doFindValue(lines, nLines, "sectionFour", "someMissingKey");

      free(lines);
   }

   return(0);
}
