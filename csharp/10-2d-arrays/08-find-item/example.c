#include <stdbool.h>
#include <stdio.h>

#define ROWS    (4)
#define COLUMNS (5)

int main()
{
   int someArray[ROWS][COLUMNS] =
   {
      {  2,  3,  5,  7, 11 },
      { 13, 17, 19, 23, 29 },
      { 31, 37, 41, 43, 47 },
      { 53, 57, 59, 61, 67 }
   };

   for(int number = 2; number < 70; number ++)
   {
      /* -- Scan each element in 'someArray', use
            the boolean flag 'found' to allow us to
            stop searching as soon as we've found the
            element we're looking for -- */

      bool found = false;

      for(int i = 0; !found && i < ROWS; i ++)
         for(int j = 0; !found && j < COLUMNS; j ++)
            if(someArray[i][j] == number)
               found = true;

      printf("%d was %s\n", number, found ? "found" : "not found");
   }

   return(0);
}
