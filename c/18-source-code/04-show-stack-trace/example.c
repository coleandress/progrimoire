#include <stdio.h>

#define SHOW_INFO() \
do { printf("[ %s | line: %d ]\n", __func__, __LINE__); } while(0)

static void functionTwo(int value)
{
   SHOW_INFO();
   printf("value: %d\n", value);
}

static void functionOne(int value)
{
   SHOW_INFO();
   functionTwo(value);
}

int main()
{
   /* -- We can't access the call stack in C, the best we can do is use
         the __func__ and __LINE__ macros in each of our functions
         to manually output the information we need -- */
         
   SHOW_INFO();
   functionOne(42);
   return(0);
}
