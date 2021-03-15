using System;
using System.Collections.Generic;

namespace ProgrimoireCSharpExamples
{
    internal static class DeclareDictionaryExample
    {
        public static void Main(string[] args)
        {
            var inventory = new Dictionary<string, int>();
            
            inventory.Add("Sword", 1);
            inventory.Add("Shield", 1);
            inventory.Add("Potions", 10);
            
            foreach (var i in inventory)
                Console.WriteLine($"{i.Key, 8}: {i.Value, 2}");
        }
    }
}