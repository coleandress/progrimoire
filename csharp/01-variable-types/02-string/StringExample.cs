using System;

namespace ProgrimoireCSharpExamples
{
    internal static class StringExample
    {
        public static void Main(string[] args)
        {
            // -- Initialize 'someString' to be an empty string --

            var someString = "";
            
            /* -- Give 'someOtherString' an initial value
                  Declared as const because they don't change 
                  in this program -- */
            
            const string someOtherString = "another string entirely";

            const string theString = "Hello world and hello kitty ...";

            someString = string.Copy(theString);
            
            Console.WriteLine($"someString: {someString}");
            Console.WriteLine($"someOtherString: {someOtherString}");
            Console.WriteLine($"theString: {theString}");

            var charArray = new char[theString.Length];

            theString.CopyTo(0, charArray, 0, theString.Length);
            
            foreach (var c in charArray)
                Console.Write(c);
        }
    }
}