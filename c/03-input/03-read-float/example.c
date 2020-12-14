#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

typedef enum { S_VALID, S_INVALID, S_OVERFLOW, S_UNDERFLOW } Status;

static Status parseFloat(const char *input, double *valuePtr)
{
   char *endPtr = NULL;

   *valuePtr = strtod(input, &endPtr);

   /* -- When strtod finishes, endPtr will point to where the
         parsing left off.  We want only whitespace to be to
         the right of endPtr and it's an error otherwise -- */
      
   while(*endPtr)
   {
      if(!isspace(*endPtr))
         return(S_INVALID);

      ++endPtr;
   }

   if(errno == ERANGE)
      return(*valuePtr == HUGE_VAL ? S_OVERFLOW : S_UNDERFLOW);

   return(S_VALID);
}

int main()
{
   char buffer[255] = { '\0' };

   printf("Enter a floating point number: ");

   fgets(buffer, sizeof(buffer), stdin);

   double value = 0;

   switch(parseFloat(buffer, &value))
   {
      case S_VALID    : printf("You entered: %f\n", value);              break;
      case S_INVALID  : printf("Invalid input: %s", buffer);             break;
      case S_UNDERFLOW: printf("Invalid input (underflow): %s", buffer); break;
      case S_OVERFLOW : printf("Invalid input (overflow): %s", buffer);  break;
   }

   return(0);
}
