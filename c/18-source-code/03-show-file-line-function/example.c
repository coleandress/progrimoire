#include <stdio.h>

static void sayHello()
{
   printf("current source file: %s\n", __FILE__);
   printf("current line number: %d\n", __LINE__);
   printf("current function   : %s\n", __func__);

   printf("hello, world!\n");
}

int main()
{
   printf("current source file: %s\n", __FILE__);
   printf("current line number: %d\n", __LINE__);
   printf("current function   : %s\n", __func__);

   printf("\n");

   sayHello();

   return(0);
}
