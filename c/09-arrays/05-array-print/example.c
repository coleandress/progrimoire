#include <stdio.h>

#define N       (10)
#define SIZE(x) ( sizeof(x) / sizeof(x[0]) )

static void printArray(int *array, int n)
{
   for(int i = 0; i < n; i ++)
   {
      if(i == 0)
         printf("{ ");

      /* -- Precede our number by nothingness if this is
            the first element in our array or by ", " if
            it's any other element -- */

      printf("%s%d", i == 0 ? "" : ", ", array[i]);

      if(i + 1 == n)
         printf(" }");
   }

   printf("\n");
}

int main()
{
   /* -- Here we print an array with a defined size -- */

   int someArray[N] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };

   for(int i = 0; i < N; i ++)
      printf("someArray[%d] = %d\n", i, someArray[i]);

   printf("\n");

   /* -- Here we determine the array's size dynamically -- */

   int anotherArray[] = { 2, 3, 5, 7, 11 };

   for(int i = 0; i < SIZE(anotherArray); i ++)
      printf("anotherArray[%d] = %d\n", i, anotherArray[i]);

   printf("\n");

   /* -- Call a function to print the array's contents -- */

   printArray(anotherArray, SIZE(anotherArray));

   return(0);
}
