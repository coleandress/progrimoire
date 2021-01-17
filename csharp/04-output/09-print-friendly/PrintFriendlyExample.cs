using System;

namespace ProgrimoireCSharpExamples
{
    public class Entry
    {
        private readonly int _x;
        private readonly int _y;
        private readonly string _theString;

        public Entry(int x, int y, string theString)
        {
            _x = x;
            _y = y;
            _theString = theString;
        }

        public override string ToString()
        {
            return $"{{ _x: {_x}, _y: {_y}, _theString: {_theString} }}";
        }
    }
    
    internal static class PrintFriendlyExample
    {
        public static void Main(string[] args)
        {
            var e1 = new Entry(1, 2, "buckle my shoe");
            var e2 = new Entry(3, 4, "open the door");

            Console.WriteLine(e1);
            Console.WriteLine(e2);
        }
    }
}
