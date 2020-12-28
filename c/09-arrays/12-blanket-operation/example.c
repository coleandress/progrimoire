#include <stdlib.h>
#include <stdio.h>

#define SIZE(x) ( sizeof(x) / sizeof(x[0]) )

/* -- Define a typedef for a function that accepts and
      reutrns an int value -- */

typedef int (*TransformFunction)(int);

/* -- Call 'tf' to update each element in 'array' -- */

static void apply(int *array, int count, TransformFunction tf)
{
   for(int i = 0; i < count; i ++)
      array[i] = tf(array[i]);
}

static int doubleIt(int x)
{
   return(2 * x);
}

static int squareIt(int x)
{
   return(x * x);
}

static void showArray(int *array, int size)
{
   for(int i = 0; i < size; i ++)
      printf("%s%d", i == 0 ? "" : ", ", array[i]);

   printf("\n");
}

int main()
{
   int someArray[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };

   /* -- Show the initial array, the array after we've doubled
         the value of each element and the array after we've
         squared each value -- */

   showArray(someArray, SIZE(someArray));

   apply(someArray, SIZE(someArray), doubleIt);

   showArray(someArray, SIZE(someArray));

   apply(someArray, SIZE(someArray), squareIt);

   showArray(someArray, SIZE(someArray));

   return(0);
}
