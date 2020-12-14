using System;

namespace ProgrimoireCSharpExamples
{
    internal static class TruncationExample
    {
        public static void Main(string[] args)
        {
            var valueOne   = 1.4f;
            var valueTwo   = 1.5f;
            var valueThree = 1.9f;

            var valueFour = -1.4f;
            var valueFive = -1.5f;
            var valueSix  = -1.9f;

            Console.WriteLine($"{valueOne} => {(int)valueOne}");
            Console.WriteLine($"{valueTwo} => {(int)valueTwo}");
            Console.WriteLine($"{valueThree} => {(int)valueThree}");
            Console.WriteLine($"{valueFour} => {(int)valueFour}");
            Console.WriteLine($"{valueFive} => {(int)valueFive}");
            Console.WriteLine($"{valueSix} => {(int)valueSix}");
        }
    }
}