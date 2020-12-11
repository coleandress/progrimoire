using System;

namespace ProgrimoireCSharpExamples
{
    /* -- Static classes cannot be instantiated and
          all of their members must be static -- */
    
    internal static class ConstStaticGlobalExample
    {
        /* -- One way to declare a constant, however
              this changes the value at compile time,
              requiring a recompile of all files that
              use this value!! -- */
        
        private const int TheAnswer = 42;
        
        /* -- Const that is a reference that is
              accessed at runtime.  Less performant,
              but more safe -- */
        
        private static readonly int StillTheAnswer = 42;
        
        public static void Main(string[] args)
        {
            /* -- Global values in C# must be static
                  members of a class.*/
            
            Cat.GlobalCounter++;
            
            Cat cat1 = new Cat("Tom");
            Console.WriteLine(cat1);
            
            /* -- A static member variable will maintain
                  its value -- */
            
            Console.WriteLine($"Number of cats: {Cat.NumberOfCats}\n");
            
            Cat cat2 = new Cat("Sylvester");
            Console.WriteLine(cat2);
            
            Console.WriteLine($"Number of cats: {Cat.NumberOfCats}\n");
            
            /* -- Static member functions are called
                  from the base class -- */

            Console.WriteLine($"The cat goes {Cat.SoundACatMakes()}\n");

            Console.WriteLine($"Global counter: {++Cat.GlobalCounter}");
        }
    }
    
    public class Cat
    {
        public static int GlobalCounter = 0;
        public static int NumberOfCats { get; private set; }
        /* -- Can be initialized in constructor -- */
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