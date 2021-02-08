#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#define EMALLOC(x) emalloc(x, __FILE__, __LINE__)
#define BUFFER_SIZE (255)

/* -- A key and value -- */

typedef struct
{
   char mKey[BUFFER_SIZE];
   char mValue[BUFFER_SIZE];

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

static Node *makeNode(const char *key, const char *value)
{
   Node *n = EMALLOC(sizeof(Node));

   n->mNext = NULL;

   copyString(n->mPair.mKey,   key);
   copyString(n->mPair.mValue, value);

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

void dictSet(Dictionary *dictPtr, const char *key, const char *value)
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
            if(strcmp(n->mPair.mValue, value) != 0)
               copyString(n->mPair.mValue, value);

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

const char *dictGet(Dictionary *dictPtr, const char *key)
{
   unsigned long hValue = dictValue(dictPtr, key);

   if(!dictPtr->mNodes[hValue])
      return(NULL);

   Node *n = dictPtr->mNodes[hValue];

   while(n)
   {
      if(strcmp(n->mPair.mKey, key) == 0)
         return(n->mPair.mValue);

      n = n->mNext;
   }

   return(NULL);
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

static void dictShowKeys(Dictionary *dictPtr, bool showValues)
{
   for(int i = 0; i < dictPtr->mSize; i ++)
   {
      Node *n = dictPtr->mNodes[i];

      while(n)
      {
         printf("Key: '%s'", n->mPair.mKey);

         if(showValues)
            printf(", Value: '%s'", n->mPair.mValue);

         printf("\n");

         n = n->mNext;
      }
   }
}

/* -- create a random string of length: 'nLetters' -- */

static void getRandomString(char *dest, int nLetters)
{
   static const char *letters = "abcdefghijklmnopqrstuvwxyz";
   static int         length  = 0;

   if(!length)
   {
      length = strlen(letters);
      srand((int)time(0));
   }

   for(int i = 0; i < nLetters; i ++)
      dest[i] = letters[rand() % length]; 

   dest[nLetters] = '\0';
}

static void loadDictionary(Dictionary *ptr)
{
   const int FACTOR = 10;
   const int LENGTH = 10;

   char kRandom[BUFFER_SIZE] = { '\0' };
   char vRandom[BUFFER_SIZE] = { '\0' };

   printf("Loading the dictionary ...\n");

   int nItems = FACTOR * ptr->mSize;

   for(int i = 0; i < nItems; i ++)
   {
      getRandomString(kRandom, LENGTH); 
      getRandomString(vRandom, LENGTH); 

      dictSet(ptr, kRandom, vRandom);

      if(i % ptr->mSize == 0)
         printf(".");
   }

   printf("\n");
   printf("Done!\n");
}

/* -- main -- */

int main()
{
   const int SIZE = 103;

   Dictionary dictionary = makeDictionary(SIZE);

   loadDictionary(&dictionary);

   dictShowKeys(&dictionary, false);

   dictFree(&dictionary);

   return(0);
}
