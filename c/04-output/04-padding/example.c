#include <stdio.h>

int main()
{
   const int value = 42;

   /* -- Note that padding with zeros and left aligning
         shows nothing as the zero padding is applied to the
         left -- */
         
   printf("|%20d|\n", value);
   printf("|%020d|\n", value);
   printf("|%-20d|\n", value);
   printf("|%-020d|\n", value);
   printf("|12345678901234567890|\n");

   return(0);
}
