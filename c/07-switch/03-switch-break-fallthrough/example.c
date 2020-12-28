#include <stdio.h>

static void showExample(int x)
{
   switch(x)
   {
      case 0: case 1: case 2:
      {
         printf("(0, 1 or 2)\n");
      }
      break;

      case 3: case 4: case 5:
      {
         printf("(3, 4 or 5)\n");
      }

      /* -- Without a 'break', we will "fall through"
            to the next section of code -- */

      case 6: case 7: case 8:
      {
         printf("(6, 7 or 8)\n");
      }
      break;

      case 9:
      {
         printf("(9)\n");
      }

      /* -- No 'break', as above -- */

      case 10:
      {
         printf("(10)\n");
      }
      break;
   }
}

int main()
{
   for(int i = 0; i <= 10; i ++)
   {
      printf("i: %d ", i);
      showExample(i);
   }

   return(0);
}
