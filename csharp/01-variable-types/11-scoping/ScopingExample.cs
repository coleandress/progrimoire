using System;

namespace ProgrimoireCSharpExamples
{
    /* -- internal - can only be accessed by files
          within the same assembly -- */
    
    internal static class ScopingExample
    {
        public static void Main(string[] args)
        {
            int x = 42;
            int y = 24;
            int z = 0;

            Console.WriteLine($"x in main: {x}\n");
            
            someFunction(x);

            Console.WriteLine($"y in main: {y}\n");
            
            someFunction(y);
            
            /* -- Here, we don't even pass a variable - we just pass a
                  literal.  This shows (again) that the 'x' variable in
                  'someFunction' has nothing to do with any of the variables
                  (x or y) declared inside 'main' -- */
            
            someFunction(12345);

            Console.WriteLine($"z: {z}\n");

            if (x > y)
            {
                /* -- This is tighter scope than 'main', whereas some
                      languages will let you declare a variable with the
                      same name in this scope (override/shadow), C# will
                      not compile -- */

                // var z = 54321; // will not compile
                var a = 12345;

                Console.WriteLine($"a: {a}\n");
            }

            /* -- This statement is invalid because a is not in scope -- */
            
            // Console.WriteLine($"a: {a}"); // will not compile
        }

        private static void someFunction(int x)
        {
            /* -- This 'x" is not the same 'x' inside main,
                  they occupy two different memory locations even though
                  they have the same name -- */

            Console.WriteLine($"x in someFunction: {x}\n");
        }
    }
    
    public class Cat
    {
        /* -- public members are accessible outside
              of the class -- */
        
        public static int GlobalCounter = 0;
        
        /* -- Properties can have their access specified.
              This one can be read, but not changed outside
              of the class -- */
        
        public static int NumberOfCats { get; private set; }
        
        /* -- Can be accessed in this class and any
              classes that inherit from this class -- */

        protected string Species;
        
        /* -- Can be initialized in constructor, but
              otherwise cannot be changed. -- */
        
        private readonly string _catName;

        public Cat(string catName)
        {
            _catName = catName;
            NumberOfCats++;
        }

        public static string SoundACatMakes()
        {
            return "MEOW";
        }

        public override string ToString()
        {
            return $"Cat name: {_catName}\n";
        }
    }
}