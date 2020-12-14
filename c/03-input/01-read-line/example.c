#include <string.h>
#include <stdio.h>

int main()
{
   /* -- We store the line we read from the user in this variable -- */

   char buffer[255] = { '\0' };

   /* -- Loop "forever" -- */

   for(;;)
   {
      printf("Please enter whatever you like, enter: quit to exit ...\n");

      /* -- Read into 'buffer', with a limit of 'sizeof(buffer)' bytes
            from the console (stdin).  Note that fgets won't read
            sizeof(buffer) bytes, at a maximum it'll read sizeof(buffer) - 1
            bytes to leave room for the null terminator -- */
            
      fgets(buffer, sizeof(buffer), stdin);

      /* -- Remove the trailing '\n' if it is present, it will be present
            unless the user entered a string that was too long for buffer -- */

      char *ptr = strchr(buffer, '\n');

      if(ptr)
         *ptr = '\0';

      if(strcmp(buffer, "quit") == 0)
      {
         printf("Exiting ...\n");
         break;
      }

      printf("You entered: '%s'\n", buffer);
   }

   return(0);
}
