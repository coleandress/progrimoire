#include <stdio.h>

int main()
{
   const char *greeting = "Hello, World!";
   const int  value     = 42;

   printf("|%20s|\n", greeting);
   printf("|%20d|\n", value);
   printf("|%-20s|\n", greeting);
   printf("|%-20d|\n", value);
   printf("|12345678901234567890|\n\n");

   printf("|%-15s|%-5d|%25s|%15d|\n", greeting, value, greeting, value);
   printf("|123456789012345|12345|1234567890123456789012345|123456789012345|\n");

   return(0);
}
