#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>

#define EMALLOC(x) emalloc(x, __FILE__, __LINE__)
#define BUFFER_SIZE (255)

/* -- A key and value -- */

typedef struct
{
   char mKey[BUFFER_SIZE];
   int  mValue;

} Pair;

/* -- Linked list node, for collisions -- */

typedef struct _Node
{
   Pair          mPair;
   struct _Node *mNext;

} Node;

/* -- Our dictionary structure, contains an array of pointers with each
      being the first element in a linked list -- */

typedef struct
{
   Node **mNodes;
   int    mSize;

} Dictionary;

static void *emalloc(int nBytes, const char *file, int line)
{
   void *ptr = malloc(nBytes);

   if(!ptr)
   {
      printf("[%s | %d] Could not allocate: %d bytes\n", file, line, nBytes);
      exit(1);
   }

   return(ptr);
}

/* -- Assumes 'dest' has enough room for 'src'
      and the terminating null character -- */

static void copyString(char *dest, const char *src)
{
   int j = 0;

   for(int i = 0, n = strlen(src); i < n; i ++)
      dest[j++] = src[i];

   dest[j] = '\0';
}

/* -- Our hash function, from K&R -- */

unsigned long hash(unsigned char *str)
{
   unsigned long hashValue = 5381;

   for(int i = 0; str[i]; i ++)
   {
      /* -- hashValue * 33 + c -- */

      hashValue = ((hashValue << 5) + hashValue) + str[i];
   }

   return(hashValue);
}

/* -- Create a new 'Node' object -- */

static Node *makeNode(const char *key, int value)
{
   Node *n = EMALLOC(sizeof(Node));

   n->mNext = NULL;

   copyString(n->mPair.mKey,   key);
   n->mPair.mValue = value;

   return(n);
}

/* -- Initialize our dictionary -- */

static Dictionary makeDictionary(int size)
{
   Dictionary dictionary = { 0 };

   dictionary.mSize  = size;
   dictionary.mNodes = EMALLOC(dictionary.mSize * sizeof(Node *));

   for(int i = 0; i < dictionary.mSize; i ++)
      dictionary.mNodes[i] = NULL;

   return(dictionary);
}

/* -- get the slot number for 'key' -- */

unsigned long dictValue(Dictionary *dictPtr, const char *key)
{
   return(hash((unsigned char *)key) % dictPtr->mSize);
}

/* -- set element with key: 'key' to value: 'value', creates the node
      if it does not exist already -- */

void dictSet(Dictionary *dictPtr, const char *key, int value)
{
   unsigned long hValue = dictValue(dictPtr, key);
   Node *n              = dictPtr->mNodes[hValue];

   if(!n)
   {
      dictPtr->mNodes[hValue] = makeNode(key, value);
   }
   else
   {
      while(n)
      {
         /* -- If we find 'key', we're done - we only need
               to see if we need to update 'value' or not -- */

         if(strcmp(n->mPair.mKey, key) == 0)
         {
            if(n->mPair.mValue != value)
               n->mPair.mValue = value;

            return;
         }

         n = n->mNext;
      }

      /* -- Create a new 'Node' object and make it the first
            item in our list -- */

      n = makeNode(key, value);

      n->mNext                = dictPtr->mNodes[hValue];
      dictPtr->mNodes[hValue] = n;
   }
}

/* -- fetch the value corresponding to 'key' -- */

bool dictGet(Dictionary *dictPtr, const char *key, int *valuePtr)
{
   *valuePtr = 0;

   unsigned long hValue = dictValue(dictPtr, key);

   if(!dictPtr->mNodes[hValue])
      return(false);

   Node *n = dictPtr->mNodes[hValue];

   while(n)
   {
      if(strcmp(n->mPair.mKey, key) == 0)
      {
         *valuePtr = n->mPair.mValue;
         return(true);
      }

      n = n->mNext;
   }

   return(false);
}

/* -- fetch the value corresponding to 'key' -- */

static bool dictRemove(Dictionary *dictPtr, const char *key)
{
   unsigned long hValue = dictValue(dictPtr, key);
   Node *n              = dictPtr->mNodes[hValue];

   if(!n)
      return(false);

   Node *last = NULL;

   while(n)
   {
      if(strcmp(n->mPair.mKey, key) == 0)
      {
         if(!last)
            dictPtr->mNodes[hValue] = n->mNext;

         else
            last->mNext = n->mNext;

         free(n);
         return(true);
      }

      last = n;
      n    = n->mNext;
   }

   return(false);
}

/* -- free our dictionary -- */

static void dictFree(Dictionary *dictPtr)
{
   for(int i = 0; i < dictPtr->mSize; i ++)
   {
      Node *n = dictPtr->mNodes[i];

      while(n)
      {
         Node *next = n->mNext;
         free(n);

         n = next;
      }

      dictPtr->mNodes[i] = NULL;
   }

   free(dictPtr->mNodes);
   dictPtr->mNodes = NULL;
}

static void incrementCount(Dictionary *dictPtr, const char *key)
{
   int value = 0;

   dictGet(dictPtr, key, &value);
   value++;

   dictSet(dictPtr, key, value);
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

static void wordFrequency(int size, const char *fileName, bool addNewLine)
{
   FILE *f = openFile(fileName, "r");

   if(!f)
   {
      printf("Error opening input file: %s\n", fileName);
      return;
   }

   Dictionary dictionary     = makeDictionary(size);
   char current[BUFFER_SIZE] = { '\0' };
   int  c                    = 0;

   while((c = fgetc(f)) != EOF)
   {
      if(isalpha(c) || c == '\'')
      {
         int length = strlen(current);
         current[length++] = (char)c;
         current[length]   = '\0';
      }
      else if(strlen(current))
      {
         incrementCount(&dictionary, current);
         current[0] = '\0';
      }
   }

   fclose(f);

   if(strlen(current))
      incrementCount(&dictionary, current);

   int         maxCount = 0;
   const char *maxWord  = NULL;

   for(int i = 0; i < dictionary.mSize; i ++)
   {
      Node *n = dictionary.mNodes[i];

      while(n)
      {
         printf("word: '%s', count: %d\n", n->mPair.mKey, n->mPair.mValue);

         if(n->mPair.mValue > maxCount)
         {
            maxWord  = n->mPair.mKey;
            maxCount = n->mPair.mValue;
         }

         n = n->mNext;
      }
   }

   printf("\n");

   printf(
      "Most common word: '%s' (found %d time%s)\n",
      maxWord, maxCount, maxCount == 0 ? "" : "s"
   );

   dictFree(&dictionary);

   if(addNewLine)
      printf("\n");
}

static void letterFrequency(int size, const char *fileName, bool addNewLine)
{
   FILE *f = openFile(fileName, "r");

   if(!f)
   {
      printf("Error opening input file: %s\n", fileName);
      return;
   }

   Dictionary dictionary = makeDictionary(size);
   int  c                = 0;
   char buffer[2]        = { '\0' };

   while((c = fgetc(f)) != EOF)
   {
      if(isalpha(c))
      {
         buffer[0] = (char)tolower(c);
         incrementCount(&dictionary, buffer);
      }
   }

   fclose(f);

   int   maxCount = 0;
   char maxLetter = '\0';

   for(int i = 0; i < dictionary.mSize; i ++)
   {
      Node *n = dictionary.mNodes[i];

      while(n)
      {
         printf("letter: '%s', count: %d\n", n->mPair.mKey, n->mPair.mValue);

         if(n->mPair.mValue > maxCount)
         {
            maxLetter = n->mPair.mKey[0];
            maxCount  = n->mPair.mValue;
         }

         n = n->mNext;
      }
   }

   printf("\n");

   printf(
      "Most common letter: '%c' (found %d time%s)\n",
      maxLetter, maxCount, maxCount == 0 ? "" : "s"
   );

   dictFree(&dictionary);

   if(addNewLine)
      printf("\n");
}

/* -- Using a dictionary to count letter frequencies is overkill, we can
      do it much more simply by just having an array of 26 counts, one
      for each letter -- */

static void letterFrequencyEZ(const char *fileName, bool addNewLine)
{
   FILE *f = openFile(fileName, "r");

   if(!f)
   {
      printf("Error opening input file: %s\n", fileName);
      return;
   }

   int counts[26] = { 0 };
   int  c         = 0;

   while((c = fgetc(f)) != EOF)
   {
      if(isalpha(c))
      {
         char cLower = (char)tolower(c);
         counts[cLower - 'a']++;
      }
   }

   fclose(f);

   int   maxCount = 0;
   char maxLetter = '\0';

   for(int i = 0, n = sizeof(counts) / sizeof(counts[0]); i < n; i ++)
   {
      char letter = (char)('a' + i);

      printf("letter: '%c', count: %d\n", letter, counts[i]);

      if(counts[i] > maxCount)
      {
         maxCount  = counts[i];
         maxLetter = letter;
      }
   }

   printf("\n");

   printf(
      "Most common letter: '%c' (found %d time%s)\n",
      maxLetter, maxCount, maxCount == 0 ? "" : "s"
   );

   if(addNewLine)
      printf("\n");
}

/* -- main -- */

int main()
{
   const char *fileName = "finn.txt";
   const int   SIZE     = 100003;

   wordFrequency(SIZE, fileName, true);

   letterFrequency(SIZE, fileName, true);

   letterFrequencyEZ(fileName, false);

   return(0);
}
