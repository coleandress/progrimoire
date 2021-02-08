#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

typedef struct _Node
{
   int mValue;
   struct _Node *mLeft;
   struct _Node *mRight;

} Node;

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

static Node *makeNode(int value)
{
   size_t size = sizeof(Node);
   Node   *n   = EMALLOC(size);

   if(!n)
   {
      printf("makeNode - could not allocate: %lu bytes\n", size);
      exit(1);
   }

   n->mLeft  = n->mRight = NULL;
   n->mValue = value;

   return(n);
}

/************************************************************************
 * 1) Create a new Node object for 'value'
 *
 * 2) If 'root' is NULL, our new Node object becomes our root
 *
 * 3) Set 'current' to the root node, if 'value' is less than current's
 *    'mValue', look for an empty location under the left Node and insert.
 *
 * 4) If 'value' is greater than current's 'mValue', look for an empty
 *    location under the right node and insert.
 ************************************************************************/

static Node *insert(Node *root, int value)
{
   Node *newNode = makeNode(value);

   if(!root)
      return(newNode);

   Node *current = root;
   Node *parent  = NULL;

   for(;;)
   {
      parent = current;

      if(value < parent->mValue)
      {
         current = current->mLeft;

         if(!current)
         {
            parent->mLeft = newNode;
            break;
         }
      }
      else
      {
         current = current->mRight;

         if(!current)
         {
            parent->mRight = newNode;
            break;
         }
      }
   }

   return(root);
}

static int contains(Node *root, int value)
{
   Node *current = root;

   while(current)
   {
      if(current->mValue == value)
         return(1);

      if(current->mValue > value)
         current = current->mLeft;

      else
         current = current->mRight;
   }

   return(0);
}

static void printTree(Node *tree)
{
   if(tree)
   {
      printTree(tree->mLeft);
      printf("%d\n", tree->mValue);
      printTree(tree->mRight);
   }
}

static void freeTree(Node *tree)
{
   if(tree)
   {
      freeTree(tree->mLeft);
      freeTree(tree->mRight);

      free(tree);
   }
}

static void recursiveSizeCount(Node *tree, int *sizePtr)
{
    if(tree)
    {
       (*sizePtr)++;

       recursiveSizeCount(tree->mLeft, sizePtr);
       recursiveSizeCount(tree->mRight, sizePtr);
    }
}

static int getSize(Node *tree)
{
   int size = 0;
   recursiveSizeCount(tree, &size);
   return(size);
}

static bool isPrime(int value)
{
   if(value <= 2 || value % 2 == 0)
      return(value == 2);

   int stop = (int)sqrt(value);

   for(int i = 3; i <= stop; i += 2)
      if(value % i == 0)
         return(false);

   return(true);
}

static int getRandomValue(int maxValue)
{
   bool first = true;

   if(first)
   {
      first = false;
      srand((int)time(0));
   }

   return(rand() % maxValue);
}

static int loadTree(Node **rootPtr, int nPrimes)
{
   /* -- Create an array containing the first 'nPrimes' primes -- */

   int *primes = EMALLOC(nPrimes * sizeof(int));

   int count  = 0;
   int number = 2;

   while(count < nPrimes)
   {
      if(isPrime(number))
         primes[count++] = number;

      number++;
   }

   /* -- Now, randomize them via the fisher-yates shuffle -- */

   for(int i = nPrimes - 1; i > 1; i --)
   {
      int index = getRandomValue(i + 1);

      if(i != index)
      {
         int tmp       = primes[i];
         primes[i]     = primes[index];
         primes[index] = tmp;
      }
   }

   /* -- Add to our tree -- */

   for(int i = 0; i < nPrimes; i ++)
      *rootPtr = insert(*rootPtr, primes[i]);

   free(primes);

   return(number);
}
int main()
{
   static const int N = 10000;
   Node *root = NULL;

    loadTree(&root, N);

    for(int i = 0; i < 20; i ++)
    {
       if(contains(root, i))
          printf("Prime: %d\n", i);

       else
          printf("Not a prime: %d\n", i);
    }

    freeTree(root);

    return(0);
}
