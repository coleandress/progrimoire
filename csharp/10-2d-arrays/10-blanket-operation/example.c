#include <stdlib.h>
#include <stdio.h>

typedef int (*TransformFunction)(int);

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

/* -- Call 'tf' to update each element in 'array' -- */

static void apply(int **array, int rows, int columns, TransformFunction tf)
{
   for(int i = 0; i < rows; i ++)
      for(int j = 0; j < columns; j ++)
         array[i][j] = tf(array[i][j]);
}

static int doubleIt(int x)
{
   return(2 * x);
}

static int squareIt(int x)
{
   return(x * x);
}

static void showArray(int **array, int rows, int columns)
{
   for(int i = 0; i < rows; i ++)
   {
      printf("{ ");

      for(int j = 0; j < columns; j ++)
         printf("%s%3d",  j == 0 ? "" : ", ", array[i][j]);

      printf(" }\n");
   }

   printf("\n");
}

int main()
{
   const int ROWS    = 3;
   const int COLUMNS = 5;

   int **array = EMALLOC(ROWS * sizeof(int *));

   for(int i = 0; i < ROWS; i ++)
      array[i] = EMALLOC(COLUMNS * sizeof(int));

   for(int i = 0, k = 1; i < ROWS; i ++)
      for(int j = 0; j < COLUMNS; j ++)
         array[i][j] = k++;

   showArray(array, ROWS, COLUMNS);

   apply(array, ROWS, COLUMNS, doubleIt);

   showArray(array, ROWS, COLUMNS);

   apply(array, ROWS, COLUMNS, squareIt);

   showArray(array, ROWS, COLUMNS);

   for(int i = 0; i < ROWS; i ++)
      free(array[i]);

   free(array);

   return(0);
}
