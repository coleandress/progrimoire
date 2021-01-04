#include <stdlib.h>
#include <stdio.h>

#define SIZE(x) ( sizeof(x) / sizeof(x[0]) )

#define ITEMS (10)
#define N      (6)
#define ROWS   (5)

int main()
{
   int someArray[][ITEMS] =
   {
      {  2,  3,  5,  7, 11, 13 },
      { 17, 19, 23, 29, 31, 37 }
   };

   /* -- If the array has room (each row's capacity is 20 but only 6
         elements have been stored in the row) we can
         store elements in the unused locations -- */

   int k = 100;

   for(int n = SIZE(someArray), i = 0; i < n; i ++)
      for(int j = N; j < ITEMS; j ++)
         someArray[i][j] = k++;

   for(int i = 0; i < SIZE(someArray); i ++)
   {
      for(int j = 0; j < ITEMS; j ++)
         printf("someArray[%d][%d] = %d\n", i, j, someArray[i][j]);

      printf("\n");
   }

   printf("\n");

   /* -- If the array's capacity is already completely utilized, there's no
         way to add additional elements.   We can, however, use realloc
         to resize our array to a larger capacity -- */

   int **ptr = malloc(ROWS * sizeof(int *));

   if(!ptr)
   {
      printf("Malloc failed\n");
      return(1);
   }

   k = 0;

   for(int i = 0; i < ROWS; i ++)
   {
      int *row = malloc((i + 1) * sizeof(int));

      if(!row)
      {
         for(int j = 0; j < i; j ++)
            free(ptr[j]);

         free(ptr);

         printf("Malloc failed\n");
         return(1);
      }

      for(int j = 0; j <= i; j ++)
         row[j] = k++;

      ptr[i] = row;
   }

   for(int i = 0; i < ROWS; i ++)
   {
      printf("{ ");

      for(int j = 0; j <= i; j ++)
         printf("%s%d", j == 0 ? "" : ", ", ptr[i][j]);

      printf(" }\n");
   }

   printf("\n");

   for(int i = 0; i < ROWS; i ++)
   {
      int *row = realloc(ptr[i], ITEMS * sizeof(int));

      if(!row)
      {
         for(int j = 0; j < i; j ++)
            free(ptr[j]);

         free(ptr);

         printf("Malloc failed\n");
         return(1);
      }

      for(int j = i + 1; j < ITEMS; j ++)
         row[j] = -1;

      ptr[i] = row;
   }

   for(int i = 0; i < ROWS; i ++)
   {
      printf("{ ");

      for(int j = 0; j < ITEMS; j ++)
         printf("%s%2d", j == 0 ? "" : ", ", ptr[i][j]);

      printf(" }\n");
   }

   printf("\n");

   for(int i = 0; i < ROWS; i ++)
      free(ptr[i]);

   free(ptr);

   return(0);
}
