#include <stdio.h>

#define ROWS    (4)
#define COLUMNS (5)
#define SIZE(x) ( sizeof(x) / sizeof(x[0]) )

int main()
{
   /* -- Print the contents of 'someArray' -- */

   int someArray[ROWS][COLUMNS] =
   {
      {  2,  3,  5,  7, 11 },
      { 13, 17, 19, 23, 29 },
      { 31, 37, 41, 43, 47 },
      { 53, 57, 59, 61, 67 }
   };

   for(int i = 0; i < ROWS; i ++)
   {
      printf("{ ");

      for(int j = 0; j < COLUMNS; j ++)
         printf("%s%3d",  j == 0 ? "" : ", ", someArray[i][j]);

      printf(" }\n");
   }

   printf("\n");

   /* -- Print the contents of 'anotherArray', note that the
         first dimension (rows) isn't hard-coded, instead we
         determine the size dynamically -- */

   int anotherArray[][COLUMNS] =
   {
      { 1, 2, 3, 4, 5 },
      { 0, 1, 2, 3, 4 },
      { 2, 3, 4, 5, 6 }
   };

   for(int i = 0, n = SIZE(anotherArray); i < n; i ++)
   {
      printf("{ ");

      for(int j = 0; j < COLUMNS; j ++)
         printf("%s%3d",  j == 0 ? "" : ", ", anotherArray[i][j]);

      printf(" }\n");
   }

   return(0);
}
