using System;

namespace ProgrimoireCSharpExamples
{
    internal static class ByteExample
    {
        public static void Main(string[] args)
        {
            Console.WriteLine($"The size of a byte is: {sizeof(byte)}");

            byte theByte = 0xff;
            
            Console.WriteLine($"theByte: {theByte} (hex: {theByte:x8})");

            theByte = (byte)(theByte - 55);
            
            Console.WriteLine($"theByte: {theByte} (hex: {theByte:x8})");

            theByte = 0xff;
            
            /* -- This will overflow as 0xff is the max value
                  we can fit into a byte.  If not checked,
                  value will wrap around and throw no error -- */

            try
            {
                checked
                {
                    theByte++;
                }
            }
            catch (Exception e)
            {
                Console.WriteLine("overflow, value would be 00 if unchecked");
            }

            Console.WriteLine($"theByte: {theByte} (hex: {theByte:x8})");

            theByte = 0;
            
            /* -- This will underflow as 0 is the min value
                  we can fit into a byte.  If not checked,
                  value will wrap around and throw no error -- */

            try
            {
                checked
                {
                    theByte--;
                }
            }
            catch (Exception e)
            {
                Console.WriteLine("underflow, value would be FF if unchecked");
            }
            
            Console.WriteLine($"theByte: {theByte} (hex: {theByte:x8})");
        }
    }
}