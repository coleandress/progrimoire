#include <stdbool.h>
#include <stdio.h>

#define SIZE(x) ( sizeof(x) / sizeof(x[0]))

/* -- Sum the numbers from: 1 ... n -- */

static int getSum(int n)
{
   if(n <= 0)
      return(0);

   return(n + getSum(n - 1));
}

/* -- Find the product of the numbers
      from 1 ... n -- */

static int getFactorial(int n)
{
   if(n <= 0)
      return(1);

   return(n * getFactorial(n - 1));
}

/* -- Helper function to assist 'getMax' in recursively
      finding the maximum value in 'array' -- */

static int getMaxHelper(int *array, int size, int offset)
{
   int current = array[offset];

   if(offset + 1 == size)
      return(current);

   int rest = getMaxHelper(array, size, offset + 1);

   return(current >= rest ? current : rest);
}

/* -- Find the max value in 'array' -- */

static int getMax(int *array, int size)
{
   return(getMaxHelper(array, size, 0));
}

/* -- Helper function to assist 'getMin' in recursively
      finding the minimum value in 'array' -- */

static int getMinHelper(int *array, int size, int offset)
{
   int current = array[offset];

   if(offset + 1 == size)
      return(current);

   int rest = getMinHelper(array, size, offset + 1);

   return(current <= rest ? current : rest);
}

/* -- Find the min value in 'array' -- */

static int getMin(int *array, int size)
{
   return(getMinHelper(array, size, 0));
}

/* -- Helper function to assist 'isPrime' in
      recursively determining if 'x' is
      a prime number -- */

static bool isPrimeHelper(int x, int current)
{
   if(current == x)
      return(true);

   return(x % current != 0 && isPrimeHelper(x, current + 1));
}

/* -- Is 'x' a prime number? -- */

static bool isPrime(int x)
{
   if(x <= 2 || x % 2 == 0)
      return(x == 2);

   return(isPrimeHelper(x, 3));
}

int main()
{
   /* -- Call our getSum, getFactorial, getMax, getMin and
         isPrime functions -- */

   for(int i = 0; i <= 10; i ++)
      printf("getSum(%d) = %d\n", i, getSum(i));

   printf("\n");

   for(int i = 0; i <= 10; i ++)
      printf("getFactorial(%d) = %d\n", i, getFactorial(i));

   printf("\n");

   int someArray[]      = { 2, 3, 5, 7, 11 };
   int someOtherArray[] = { 11, 7, 5, 3, 2 };

   printf("maxValue: %d\n", getMax(someArray, SIZE(someArray)));
   printf("maxValue: %d\n", getMax(someOtherArray, SIZE(someOtherArray)));
   printf("minValue: %d\n", getMin(someArray, SIZE(someArray)));
   printf("minValue: %d\n", getMin(someOtherArray, SIZE(someOtherArray)));

   printf("\n");

   for(int i = 0; i < 100; i ++)
      if(isPrime(i))
         printf("%d\n", i);

   return(0);
}
