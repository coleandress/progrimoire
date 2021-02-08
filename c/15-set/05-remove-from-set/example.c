#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

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

static int getMinValueR(Node *tree, int currentMin)
{
   if(!tree)
      return(0);

   if(tree->mValue < currentMin)
      currentMin = tree->mValue;

   if(tree->mLeft)
   {
      int v = getMinValueR(tree->mLeft, currentMin);

      if(v < currentMin)
         currentMin = v;
   }

   if(tree->mRight)
   {
      int v = getMinValueR(tree->mRight, currentMin);

      if(v < currentMin)
         currentMin = v;
   }

   return(currentMin);
}

static int getMinValue(Node *tree)
{
   return(getMinValueR(tree, tree->mValue));
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

static Node *removeNodeEx(Node *root, Node *parent, int theValue)
{
   Node *current = root;

   while(current)
   {
      if(current->mValue == theValue)
      {
         bool doFree = true;

         /* -- If this node has no children -- */

         if(!current->mLeft && !current->mRight)
         {
            /* -- If this is the root node, free it and
                  indicate the tree is now empty -- */
                  
            if(!parent)
            {
               free(current);
               return(NULL);
            }

            /* -- Not the root node - detach from our parent -- */

            if(parent->mLeft == current)
               parent->mLeft = NULL;

            else
               parent->mRight = NULL;
         }

         /* -- If it has only a right node -- */

         else if(!current->mLeft && current->mRight)
         {
            if(!parent)
            {
               root = current->mRight;
            }
            else
            {
               if(parent->mLeft == current)
                  parent->mLeft = current->mRight;

               else
                  parent->mRight = current->mRight;
            }
         }

         /* -- If it has only a left node -- */

         else if(current->mLeft && !current->mRight)
         {
            if(!parent)
            {
               root = current->mLeft;
            }
            else
            {
               if(parent->mLeft == current)
                  parent->mLeft = current->mLeft;

               else
                  parent->mRight = current->mLeft;
            }
         }
         else
         {
            /* -- Node to be deleted has two children, the
                  most complex case -- */

            int minValue = getMinValue(current->mRight);

            current->mValue = minValue;

            removeNodeEx(current->mRight, current, minValue);

            doFree = false;
         }

         if(doFree)
            free(current);

         break;
      }
      else
      {
         parent = current;

         if(current->mValue >theValue)
            current = current->mLeft;

         else
            current = current->mRight;
      }
   }

   return(root);
}

static Node *removeNode(Node *root, int theValue)
{
   return(removeNodeEx(root, NULL, theValue));
}

int main()
{
   static const int N = 100;
   Node *root = NULL;

   int stop = loadTree(&root, N);

   printTree(root);

   printf("\n");

   /* -- Now, remove from our tree any element that contains a seven -- */

   for(int i = 0; i < stop; i ++)
   {
      bool hasSeven = false;
      int  value    = i;

      while(value)
      {
         int digit = value % 10;

         if(digit == 7)
         {
            hasSeven = true;
            break;
         }

         value /= 10;
      }

      if(hasSeven)
         root = removeNode(root, i);
   }

   printTree(root);
   freeTree(root);

   return(0);
}
