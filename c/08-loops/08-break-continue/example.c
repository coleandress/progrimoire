#include <stdio.h>

int main()
{
   /* -- Using 'break' causes us to exit the loop
         immediately -- */

   for(int i = 0; i < 10; i ++)
   {
      printf("i: %d\n", i);

      if(i == 4)
         break;
   }

   printf("\n");

   /* -- Continue skips over any remaining code, sending
         execution back to the top of the loop -- */

   for(int i = 0; i < 10; i ++)
   {
      if(i % 2 != 0)
         continue;

      printf("i: %d\n", i);
   }

   printf("\n");

   /* -- With a nested loop, our 'break' only breaks us out of
         the immediately enclosing loop -- */

   for(int i = 0; i < 5; i ++)
   {
      for(int j = 0; j < 5; j ++)
      {
         if(j > 1)
            break;

         printf("i: %d, j: %d\n", i, j);
      }
   }

   printf("\n");

   /* -- As above, 'continue' only affects the innermost
         enclosing loop -- */

   for(int i = 0; i < 5; i ++)
   {
      for(int j = 0; j < 5; j ++)
      {
         if(j % 2 == 0)
            continue;

         printf("i: %d, j: %d\n", i, j);
      }
   }

   return(0);
}
