using System;

namespace ProgrimoireCSharpExamples
{
    internal static class QuadraticFormulaExample
    {
        public static void Main(string[] args)
        {
            /*
            **   Given a quadratic equation:
            **
            **      ax^2 + bx + c
            **
            **   Use the quadratic formula to find the values of 'x'
            **
            **      x = -b +/- sqrt(b^2 - 4 * a * c)
            **          ----------------------------
            **                       2a
            ** 
            */

            var a = 2.0;
            var b = 3.0;
            var c = 1.0;

            var discriminant = b * b - 4 * a * c;

            if (discriminant < 0.0)
            {
                Console.WriteLine("Cannot proceed, discriminant is negative\n");
            }
            else
            {
                var sd   = Math.Sqrt(discriminant);
                var twoA = 2 * a;

                var x1 = (-b + sd) / twoA;
                var x2 = (-b - sd) / twoA;

                Console.WriteLine($"Roots of {a}x^2 + {b}x + {c} are: {x1} and {x2}");
            }
        }
    }
}