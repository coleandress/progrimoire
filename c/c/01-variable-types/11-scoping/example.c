#include <stdio.h>

static void someFunction(int x)
{
   /* -- This 'x' is not the same as the 'x' inside main,
         they occupy two different memory locations even though
         they have the same name -- */

   printf("x in someFunction: %d\n", x);
}


int main()
{
   int x = 42;
   int y = 24;
   int z = 0;

   printf("x in main: %d\n", x);

   someFunction(x);

   printf("y in main: %d\n", y);

   someFunction(y);

   /* -- Here, we don't even pass a variable - we just pass a
         literal.  This shows (again) that the 'x' variable in
         'someFunction' has nothing to do with any of the variables
         (x or y) declared inside 'main' -- */

   someFunction(12345);

   printf("z: %d\n", z);

   if(x > y)
   {
      /* -- This is a tighter scope than 'main', variables
            declared here override (or shadow) the ones
            we declared above.  This will often produce
            a warning if our compiler settings are
            stringent enough -- */

      int z = 54321;
      int a = 12345;

      printf("z: %d, a: %d\n", z, a);
   }

   /* -- Here, the scope created by our 'if' statement
         has ended so 'a' is no longer in scope (and the
         following will cause a compile error if you change
         '#if 0' to '#if 1').  Also, the shadow version of
         'z' is also no longer in scope so 'z' will
         contain its original value -- */

#if 0
   printf("a: %d\n", a);
#endif

   printf("z: %d\n", z);

   return(0);
}
