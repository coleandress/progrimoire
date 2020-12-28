#include <stdlib.h>
#include <stdio.h>

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

/* -- Dynamically allocate an array of integers and fill that
      array with the results provided via 'generator' -- */

static int *doList(int *nPtr, int start, int end, int (*generator)(int))
{
   *nPtr    = (end - start) + 1;
   int *ptr = EMALLOC(sizeof(int) * *nPtr);

   for(int i = start, j = 0; i <= end; i ++)
      ptr[j++] = generator(i);

   return(ptr);
}

static int doubleIt(int x)
{
   return(2 * x);
}

static int squareIt(int x)
{
   return(x * x);
}

int main()
{
   /* -- C doesn't support list comprensions, but we can
         accomplish something somewhat similar -- */

   int count  = 0;
   int *first = doList(&count, 0, 10, doubleIt);

   for(int i = 0; i < count; i ++)
      printf("first[%d] = %d\n", i, first[i]);

   free(first);

   printf("\n");

   int *second = doList(&count, 5, 15, squareIt);

   for(int i = 0; i < count; i ++)
      printf("second[%d] = %d\n", i, second[i]);

   free(second);

   return(0);
}
