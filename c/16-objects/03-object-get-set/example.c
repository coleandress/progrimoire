#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define EMALLOC(x) emalloc(x, __FILE__, __LINE__)

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

static void freeColor(Color *colorPtr)
{
   free(colorPtr->mInternal);
   colorPtr->mInternal = NULL;
}

static unsigned char colorGetRed(Color c)
{
   ColorInternal *internal = (ColorInternal *)c.mInternal;
   return(internal->mRed);
}

static unsigned char colorGetGreen(Color c)
{
   ColorInternal *internal = (ColorInternal *)c.mInternal;
   return(internal->mGreen);
}

static unsigned char colorGetBlue(Color c)
{
   ColorInternal *internal = (ColorInternal *)c.mInternal;
   return(internal->mBlue);
}

static void colorSetRed(Color c, unsigned char red)
{
   ColorInternal *internal = (ColorInternal *)c.mInternal;
   internal->mRed = red;
}

static void colorSetGreen(Color c, unsigned char green)
{
   ColorInternal *internal = (ColorInternal *)c.mInternal;
   internal->mGreen = green;
}

static void colorSetBlue(Color c, unsigned char blue)
{
   ColorInternal *internal = (ColorInternal *)c.mInternal;
   internal->mBlue = blue;
}


int main()
{
   Color c = makeColor(255, 0, 0);

   /* -- Use our 'get' functions to access our private data -- */

   printf(
      "red: %d, green: %d, blue: %d\n",
      colorGetRed(c), colorGetGreen(c), colorGetBlue(c)
   );

   /* -- Now, invert the values via our 'set' functions -- */

   colorSetRed  (c, 255 - colorGetRed(c));
   colorSetGreen(c, 255 - colorGetGreen(c));
   colorSetBlue (c, 255 - colorGetBlue(c));

   printf(
      "red: %d, green: %d, blue: %d\n",
      colorGetRed(c), colorGetGreen(c), colorGetBlue(c)
   );

   freeColor(&c);

   return(0);
}
