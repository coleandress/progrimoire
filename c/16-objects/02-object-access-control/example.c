#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define EMALLOC(x) emalloc(x, __FILE__, __LINE__)

/* -- Point2D -- */

typedef struct
{
   int mX;
   int mY;

} Point2D;

/* -- Color -- */

typedef struct
{
   void *mInternal;

} Color;

typedef struct
{
   unsigned char mRed;
   unsigned char mGreen;
   unsigned char mBlue;

} ColorInternal;

typedef struct
{
   const int mFirst;
   const int mSecond;

} TwinPrimes;

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

static Point2D makePoint2D(int x, int y)
{
   Point2D theObject = { 0 };

   theObject.mX = x;
   theObject.mY = y;

   return(theObject);
}

static void printPoint2D(Point2D p)
{
   printf("{ x: %d, y: %d }\n", p.mX, p.mY);
}

static Color makeColor(unsigned char r, unsigned char g, unsigned char b)
{
   ColorInternal *internal = EMALLOC(sizeof(ColorInternal));

   internal->mRed   = r;
   internal->mGreen = g;
   internal->mBlue  = b;

   Color theColor = { 0 };

   theColor.mInternal = internal;

   return(theColor);
}

static void printColor(Color c)
{
   ColorInternal *internal = (ColorInternal *)c.mInternal;

   printf(
      "{ red: %d, green: %d, blue: %d }\n",
      internal->mRed, internal->mGreen, internal->mBlue
   );
}

static void freeColor(Color *colorPtr)
{
   free(colorPtr->mInternal);
   colorPtr->mInternal = NULL;
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

static TwinPrimes makeTwinPrimes(int first, int second)
{
   /* -- Can't initialize directly as 'first' and 'second'
         are not constants, so we have to cast away the
         constness to set mFirst and mSecond -- */

   TwinPrimes primes;

   *((int *)&primes.mFirst)  = first;
   *((int *)&primes.mSecond) = second;

   return(primes);
}


int main()
{
   Point2D p1 = makePoint2D(2, 3);
   printPoint2D(p1);

   /* -- In C, struct members are public by default, and there's
         no equivalent of 'protected' -- */
      
   p1.mX++;
   p1.mY++;
   printPoint2D(p1);

   /* -- However, we can simulate 'private' data via an opaque
         internal pointer -- */

   Color c = makeColor(255, 0, 0);

   printColor(c);

   freeColor(&c);

   /* -- C does not allow static fields inside a struct but
         we can make our fields 'const' so as to prohibit
         modification by the outside world, change '#if 0'
         to '#if 1' below and the code won't compile -- */

   TwinPrimes tp = makeTwinPrimes(5, 7);

   printf("first: %d, second: %d\n", tp.mFirst, tp.mSecond);

#if 0
   tp.mFirst++;
#endif

   return(0);
}
