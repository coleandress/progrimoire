#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define GET_SIZE(x) ( sizeof(x) / sizeof(x[0]) )
#define HEIGHT      (4)
#define WIDTH       (5)

int main()
{
   int someArray[] = { 2, 3, 5, 7, 11 };

   int n = GET_SIZE(someArray);

   for(int i = 0; i < n; i ++)
   {
      if(i > 0)
         printf(", ");

      printf("%d", someArray[i]);
   }
   
   printf("\n\n");

   int someOtherArray[][3] =
   {
      {  1,  2,  3 },
      {  4,  5,  6 },
      {  7,  8,  9 },
      { 10, 11, 12 }
   };

   n = GET_SIZE(someOtherArray);

   for(int i = 0; i < n; i ++)
   {
      int nn = GET_SIZE(someOtherArray[i]);

      for(int j = 0; j < nn; j ++)
      {
         if(j > 0)
            printf(", ");

         printf("%2d", someOtherArray[i][j]);
      }

      printf("\n");
   }

   printf("\n");

   int yetOneMoreArray[HEIGHT][WIDTH] =
   {
      {  2,  3,  5,  7, 11 },
      { 13, 17, 19, 23, 29 },
      { 31, 37, 41, 43, 47 },
      { 53, 59, 61, 67, 71 }
   };

   for(int i = 0; i < HEIGHT; i ++)
   {
      for(int j = 0; j < WIDTH; j ++)
      {
         if(j > 0)
            printf(", ");

         printf("%2d", yetOneMoreArray[i][j]);
      }

      printf("\n");
   }

   return(0);
}
