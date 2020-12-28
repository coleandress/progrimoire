#include <stdio.h>

int main()
{
   /* -- C does not support local functions, macros are
         about as close as you can get with C -- */

#define MAX(x, y) ((x) >= (y) ? (x) : (y))

   int valueOne = 24;
   int valueTwo = 42;

   printf("max: %d\n", MAX(valueOne, valueTwo));

   /* -- Since macros are just text substitution, everything
         in scope when they are utilized is accessible -- */

#define ADD_ONE() value++;

   int value = 40;

   ADD_ONE();
   ADD_ONE();

   printf("value: %d\n", value);

   return(0);
}
