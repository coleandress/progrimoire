using System;
using System.Collections.Generic;
using System.Linq;

namespace ProgrimoireCSharpExamples
{
    internal static class ReverseStringExample
    {
        public static void Main(string[] args)
        {
            var stringList = new List<string>
            {
                 "The lazy major was fixing Cupid's broken quiver.",
                "The public was amazed to view the quickness and dexterity of the juggler.",
                "The quick brown fox jumps over the lazy dog.",
                "We promptly judged antique ivory buckles for the next prize.",
                "Whenever the black fox jumped the squirrel gazed suspiciously."
            };

            foreach (var s in stringList)
            {
                Console.WriteLine($"'{s}'");
                
                /* -- Some Linq options -- */
                
                // Console.WriteLine($"'{new string(s.Reverse().ToArray())}'");

                // Console.WriteLine($"'{string.Concat(s.Reverse())}'");
                
                /* -- or a non-Linq option -- */

                var reversedString = "";

                foreach (var c in s)
                    reversedString = c + reversedString;

                Console.WriteLine($"'{reversedString}'");
                
                /* -- or if you want to use a char array -- */

                /*var charArray = s.ToCharArray();
                
                for (int i = 0, j = charArray.Length - 1; i < j; i++, j--)
                {
                    var tmp = charArray[i];
                    charArray[i] = charArray[j];
                    charArray[j] = tmp;
                }

                Console.WriteLine($"'{string.Concat(charArray)}'");*/

                Console.WriteLine();
            }
        }
    }
}