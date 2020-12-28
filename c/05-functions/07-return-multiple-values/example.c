#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define SIZE(x) ( sizeof(x) / sizeof(x[0]))

struct Point
{
   int mX;
   int mY;
};

static int getRandomValue()
{
   static bool first = true;

   if(first)
   {
      first = false;
      srand((int)time(0));
   }

   return(rand());
}

/* -- Here we "return" our two values by assigning them
      both via reference -- */

static void getRandomPoint3(int *xPtr, int *yPtr)
{
   *xPtr = getRandomValue();
   *yPtr = getRandomValue();
}

/* -- Here, we return one value and assign the
      other by reference -- */

static int getRandomPoint2(int *yPtr)
{
   *yPtr = getRandomValue();

   return(getRandomValue());
}

/* -- Here we return multipe values by collecting them
      into a struct which we return -- */

static struct Point getRandomPoint()
{
   struct Point p = { 0, 0 };

   p.mX = getRandomValue();
   p.mY = getRandomValue();

   return(p);
}

int main()
{
   /* -- By returning a struct, we allow any number of values
         to be returned by a function -- */

   struct Point p = getRandomPoint();

   printf("x: %d, y: %d\n", p.mX, p.mY);

   int x = 0;
   int y = 0;

   /* -- Another way would be to return one of the values we need
         and acquire the other by passing in a pointer -- */

   x = getRandomPoint2(&y);
   printf("x: %d, y: %d\n", x, y);

   /* -- Finally, we can "return" multiple values by passing them
         all in as pointers without returning anything -- */

   getRandomPoint3(&x, &y);
   printf("x: %d, y: %d\n", x, y);

   return(0);
}
