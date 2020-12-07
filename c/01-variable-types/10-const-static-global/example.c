#include <stdio.h>

/* -- Here's one way to declare a constant in c -- */

#define VALUE (42)

/* -- This variable is visible to everything in this source file
      but not visible to other source files because it is
      declared 'static' -- */

static int fiveHundred = 500;

/* -- This variable is visible to the entire program (not limited
      to this source file only) -- */

int oneThousand = 1000;

static void someFunction()
{
   /* -- A local, static variable - it "hangs on to" its value through
         successive calls to this function, the non-static version
         does not -- */

   static int count = 0;
   int anotherCount = 0;

   printf(
      "someFuntion called, count: %d, anotherCount: %d, fiveHundred: %d, oneThousand: %d\n",
      ++count, ++anotherCount, fiveHundred, oneThousand
   );
}


int main()
{
   const int ANOTHER_VALUE = 24;

   printf("value: %d, another_value: %d\n", VALUE, ANOTHER_VALUE);

   /* -- These lines are invalid, if you change '#if 0' to '#if 1' this
         code will not compile -- */

#if 0

   VALUE = VALUE + 1;
   ANOTHER_VALUE = ANOTHER_VALUE - 1;

#endif

   someFunction();
   someFunction();
   someFunction();

   return(0);
}
