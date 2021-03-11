﻿using System;
using System.Collections.Generic;

namespace ProgrimoireCSharpExamples
{
    internal static class BlanketOperationExample
    {
        private static readonly Random Random = new Random();
        
        public static void Main(string[] args)
        {
            var iList = new List<int>();

            while (iList.Count < 20)
            {
                var value = GetRandomIntValue() % 100;
                
                if (IsPrime(value))
                    iList.Add(value);
            }
            
            PrintList(iList);
            Console.WriteLine();

            Apply(iList, DoubleIt);
            PrintList(iList);
            Console.WriteLine();

            Apply(iList, SquareIt);
            PrintList(iList);
            Console.WriteLine();
        }

        private static int GetRandomIntValue()
        {
            return Random.Next();
        }

        private static bool IsPrime(int x)
        {
            if (x <= 2 || x % 2 == 0)
                return x == 2;

            var stop = (int) Math.Sqrt(x);
            
            for (var i = 3; i <= stop; i += 2)
                if (x % i == 0)
                    return false;

            return true;
        }

        private static void PrintList(List<int> list)
        {
            Console.Write("{ ");
            
            for (var i = 0; i < list.Count; i++)
                Console.Write("{0}{1}", i == 0 ? "" : ", ", list[i]);
            
            Console.Write(" }\n");
        }

        private static void Apply(List<int> list, Func<int, int> function)
        {
            for (var i = 0; i < list.Count; i++)
                list[i] = function(list[i]);
        }

        private static int DoubleIt(int x)
        {
            return 2 * x;
        }

        private static int SquareIt(int x)
        {
            return x * x;
        }
    }
}
