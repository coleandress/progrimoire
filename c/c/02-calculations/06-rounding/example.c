#include <stdio.h>

static int doRound(float x)
{
   float theValue = x;

   if(theValue >= 0)
      theValue += 0.5;

   else
      theValue -= 0.5;

   return((int)theValue);
}

int main()
{
   float valueOne   = 1.4f;
   float valueTwo   = 1.5f;
   float valueThree = 1.6f;

   float valueFour   = -1.4f;
   float valueFive   = -1.5f;
   float valueSix    = -1.6f;

   printf("%f => %d\n", valueOne, doRound(valueOne));
   printf("%f => %d\n", valueTwo, doRound(valueTwo));
   printf("%f => %d\n", valueThree, doRound(valueThree));
   printf("%f => %d\n", valueFour, doRound(valueFour));
   printf("%f => %d\n", valueFive, doRound(valueFive));
   printf("%f => %d\n", valueSix, doRound(valueSix));


   return(0);
}
