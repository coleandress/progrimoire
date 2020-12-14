#include <string.h>
#include <stdio.h>

static const double PI = 3.1415926535897932384626433832795;

int main()
{
   /* -- The number after the '.' specifies the numbr
         of decimal places to display -- */

   printf("%.0f\n", PI);
   printf("%.1f\n", PI);
   printf("%.2f\n", PI);
   printf("%.3f\n", PI);
   printf("%.4f\n", PI);
   printf("%.5f\n", PI);
   printf("%.6f\n", PI);
   printf("%.7f\n", PI);
   printf("%.8f\n", PI);
   printf("%.9f\n", PI);

   printf("\n");

   /* -- Now, do it with a loop by dynamically
         constructing the format string.  Set index
         to the offset of the '0' in 'format' -- */

   char format[255] = { "%.0f\n" };
   int index        = (strchr(format, '0') - format);

   for(int i = 0; i <= 9; i ++)
   {
      format[index] = (char)('0' + i);
      printf(format, PI);
   }

   return(0);
}
