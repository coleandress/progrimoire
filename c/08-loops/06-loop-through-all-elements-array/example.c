#include <stdio.h>

#define SIZE(x) ( sizeof(x) / sizeof(x[0]) )

int main()
{
   int someArray[] = { 2, 3, 5, 7, 11, 13 };

   for(int i = 0; i < SIZE(someArray); i ++)
      printf("someArray[%d] = %d\n", i,  someArray[i]);

   printf("\n");

   /* -- Here, we're reading memory that we don't own,
         the values we encounter will be random/garbage
         but the program won't generally crash -- */

   for(int i = 20; i < 30; i ++)
      printf("someArray[%d] = %d\n", i,  someArray[i]);

   printf("\n");

   /* -- Once you start setting values that are outside
         the memory you own things are more dicey and
         it's much more likely your code will crash
         (though it might not, accessing out of bounds
         memory produces undefined behavior which means
         there are no restrictions as to how the program
         can respond in response to this situation) -- */

   for(int i = -100; i < 0; i ++)
      someArray[i] = i;

   return(0);
}
