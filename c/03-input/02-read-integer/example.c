#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <ctype.h>
#include <stdio.h>

typedef enum { S_VALID, S_INVALID, S_OVERFLOW, S_UNDERFLOW } Status;

static Status parseInt32(const char *input, int *valuePtr)
{
   /* -- This code does not assume sizeof(long int) > sizeof(int), only
         that long int is no smaller than int which the spec guarantees -- */
      
   char *endPtr   = NULL;
   long int value = strtol(input, &endPtr, 10);

   /* -- After strtol returns, endPtr will point to where the parsing
         left off, there shouldn't be anything to our right
         but whitespace -- */
      
   while(*endPtr)
   {
      if(!isspace(*endPtr))
         return(S_INVALID);

      ++endPtr;
   }

   if(value == LONG_MIN || value == LONG_MAX)
   {
      if(errno == ERANGE)
         return(value == LONG_MIN ? S_UNDERFLOW : S_OVERFLOW);
   }

   *valuePtr = (int)value;

   return(S_VALID);
}

int main()
{
   char buffer[255] = { '\0' };

   printf("Enter an integer: ");

   fgets(buffer, sizeof(buffer), stdin);

   int value = 0;

   switch(parseInt32(buffer, &value))
   {
      case S_VALID    : printf("You entered: %d\n", value);                break;
      case S_INVALID  : printf("Invalid input: %s\n", buffer);             break;
      case S_UNDERFLOW: printf("Invalid input (underflow): %s\n", buffer); break;
      case S_OVERFLOW : printf("Invalid input (overflow): %s\n", buffer);  break;
   }

   return(0);
}
