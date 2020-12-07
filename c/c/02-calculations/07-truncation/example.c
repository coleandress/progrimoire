#include <stdio.h>

int main()
{
   float valueOne   = 1.4f;
   float valueTwo   = 1.5f;
   float valueThree = 1.9f;

   float valueFour   = -1.4f;
   float valueFive   = -1.5f;
   float valueSix    = -1.9f;

   printf("%f => %d\n", valueOne, (int)valueOne);
   printf("%f => %d\n", valueTwo, (int)valueTwo);
   printf("%f => %d\n", valueThree, (int)valueThree);
   printf("%f => %d\n", valueFour, (int)valueFour);
   printf("%f => %d\n", valueFive, (int)valueFive);
   printf("%f => %d\n", valueSix, (int)valueSix);

   return(0);
}
