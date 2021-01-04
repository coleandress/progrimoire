#include <stdio.h>

#define ROWS    (4)
#define COLUMNS (5)

int main()
{
   /* -- Declare an array with dimensions: ROWS x COLUMNS, fill
         the array with zeros -- */

   int someArray[ROWS][COLUMNS] = { 0 };

   for(int i = 0; i < ROWS; i ++)
   {
      printf("{ ");

      for(int j = 0; j < COLUMNS; j ++)
         printf("%s%d",  j == 0 ? "" : ", ", someArray[i][j]);

      printf(" }\n");
   }

   printf("\n");

   /* -- Now, declare an array with values we specify
         explicitly -- */

   int anotherArray[ROWS][COLUMNS] =
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
         printf("%s%2d",  j == 0 ? "" : ", ", anotherArray[i][j]);

      printf(" }\n");
   }

   printf("\n");

   return(0);
}
