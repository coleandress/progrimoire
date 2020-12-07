#include <stdint.h>
#include <stdio.h>

int main()
{
   int64_t  theLongOne = 0x7fffffffffffffff;
   uint64_t theLongTwo = 0xffffffffffffffff;

   printf("theLongOne: %lld (hex: %llx)\n", theLongOne, theLongOne);
   printf("theLongTwo: %llu (hex: %llx)\n", theLongTwo, theLongTwo);
   printf("\n");

   theLongOne -= 223372036854775807LL;
   theLongTwo -= 446744073709551615LL;

   printf("theLongOne: %lld (hex: %llx)\n", theLongOne, theLongOne);
   printf("theLongTwo: %llu (hex: %llx)\n", theLongTwo, theLongTwo);
   printf("\n");

   theLongOne = 0x7fffffffffffffff;
   theLongTwo = 0xffffffffffffffff;

   printf("theLongOne: %lld (hex: %llx)\n", theLongOne, theLongOne);
   printf("theLongTwo: %llu (hex: %llx)\n", theLongTwo, theLongTwo);
   printf("\n");

   /* -- These will overflow -- */

   theLongOne++;
   theLongTwo++;

   printf("theLongOne: %lld (hex: %llx)\n", theLongOne, theLongOne);
   printf("theLongTwo: %llu (hex: %llx)\n", theLongTwo, theLongTwo);
   printf("\n");

   theLongOne = -0x7fffffffffffffff - 1;
   theLongTwo = 0;

   printf("theLongOne: %lld (hex: %llx)\n", theLongOne, theLongOne);
   printf("theLongTwo: %llu (hex: %llx)\n", theLongTwo, theLongTwo);
   printf("\n");

   /* -- These will underflow -- */

   theLongOne--;
   theLongTwo--;

   printf("theLongOne: %lld (hex: %llx)\n", theLongOne, theLongOne);
   printf("theLongTwo: %llu (hex: %llx)\n", theLongTwo, theLongTwo);
   printf("\n");

   return(0);
}
