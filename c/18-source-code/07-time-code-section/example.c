#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

static bool isPrime(int x)
{
   if(x <= 2 || x % 2 == 0)
      return(false);

   int stop = (int)sqrt(x);

   for(int i = 3; i <= stop; i += 2)
      if(x % i == 0)
         return(false);

   return(true);
}

static int countPrimes(int maxValue)
{
   int count = 0;

   for(int i = 0; i <= maxValue; i ++)
      if(isPrime(i))
         count++;

   return(count);
}

static void doTimeOne(int maxValue)
{
   time_t start = time(0);

   int count = countPrimes(maxValue);

   time_t end = time(0);

   printf(
      "Number of primes <= %d is: %d (seconds elapsed: %llu)\n",
      maxValue, count, end - start
   );
}

static void doTimeTwo(int maxValue)
{
   clock_t start = clock();

   int count = countPrimes(maxValue);

   clock_t end = clock();

   printf(
      "Number of primes <= %d is: %d (seconds elapsed: %f)\n",
      maxValue, count, (double)(end - start) / CLOCKS_PER_SEC
   );
}

int main()
{
   /* -- First, time using number of seconds elapsed -- */

   doTimeOne(10000000);
   doTimeOne(20000000);
   doTimeOne(40000000);

   printf("\n");

   /* -- Now, use a more fine-grained timing mechanism to time
         operations that take less than one second -- */

   doTimeTwo(100000);
   doTimeTwo(200000);
   doTimeTwo(400000);

   return(0);
}
