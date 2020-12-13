using System;

namespace ProgrimoireCSharpExamples
{
    internal static class RoundingExample
    {
        public static void Main(string[] args)
        {
            var valueOne   = 1.4f;
            var valueTwo   = 1.5f;
            var valueThree = 1.6f;

            var valueFour = -1.4f;
            var valueFive = -1.5f;
            var valueSix  = -1.6f;

            Console.WriteLine($"{valueOne} => {Math.Round(valueOne)}");
            Console.WriteLine($"{valueTwo} => {Math.Round(valueTwo)}");
            Console.WriteLine($"{valueThree} => {Math.Round(valueThree)}");
            Console.WriteLine($"{valueFour} => {Math.Round(valueFour)}");
            Console.WriteLine($"{valueFive} => {Math.Round(valueFive)}");
            Console.WriteLine($"{valueSix} => {Math.Round(valueSix)}");
        }
    }
}