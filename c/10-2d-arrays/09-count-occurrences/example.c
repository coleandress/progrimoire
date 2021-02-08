#include <stdbool.h>
#include <stdio.h>

#define ROWS    (4)
#define COLUMNS (5)

int main()
{
   int someArray[ROWS][COLUMNS] =
   {
      {  1,  2,  2,  3,  3 },
      {  3,  4,  4,  4,  4 },
      {  5,  5,  5,  5,  5 },
      {  1,  2,  3,  4,  5 }
   };

   for(int number = 1; number < 6; number ++)
   {
      int count = 0;

      for(int i = 0; i < ROWS; i ++)
         for(int j = 0; j < COLUMNS; j ++)
            if(someArray[i][j] == number)
               count ++;

      printf("number: %d, count: %d\n", number, count);
   }

   return(0);
}
