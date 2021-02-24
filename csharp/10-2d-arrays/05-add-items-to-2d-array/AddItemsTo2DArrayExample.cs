using System;
using System.Collections.Generic;

namespace ProgrimoireCSharpExamples
{
    internal static class AddItemsTo2DArrayExample
    {
        public static void Main(string[] args)
        {
            var someArray = new int[][]
            {
                new int[] {  2,  3,  5,  7, 11, 13 },
                new int[] { 17, 19, 23, 29, 31, 37 },
            };
            
            /* -- You could alternatively declare the array with
                  default values and change them after, resizing creates
                  new arrays.  The best thing to do would be to use a list -- */

            for (var i = 0; i < someArray.GetLength(0); i++)
                Array.Resize(ref someArray[i], 10);

            PrintArray(someArray);

            Console.WriteLine();
            
            /* -- If the array has room (each row's capacity is 10 but only 6
                  elements have been stored in the row) we can store elements
                  in the unused locations -- */

            var k = 100;
            
            foreach (var numArray in someArray)
                for (var j = 6; j < numArray.Length; j++)
                    numArray[j] = k++;
            
            PrintArray(someArray);

            Console.WriteLine();
            
            /* -- A list is going to be a better option for this scenario -- */
            
            var someList = new List<List<int>>
            {
                new List<int>() {  2,  3,  5,  7, 11, 13 }, 
                new List<int>() { 17, 19, 23, 29, 31, 37 }, 
            };

            PrintList(someList);

            k = 100;
            const int elementsToAdd = 4;
            
            foreach (var numList in someList)
                for (var i = 0; i < elementsToAdd; i++)
                    numList.Add(k++);

            PrintList(someList);

            Console.WriteLine();
        }

        private static void PrintArray(int[][] arr)
        {
            for (var i = 0; i < arr.Length; i++)
            {
                Console.Write("{ ");
                
                for (var j = 0; j < arr[i].Length; j++)
                    Console.Write("{0}{1,2}", j == 0 ? "" : ", ", arr[i][j]);
                
                Console.Write(" }\n");
            }
        }

        private static void PrintList(List<List<int>> list)
        {
            foreach (var sublist in list)
            {
                Console.Write("{ ");
                
                for (var i = 0; i < sublist.Count; i++)
                    Console.Write("{0}{1,2}", i == 0 ? "" : ", ", sublist[i]);
                
                Console.Write(" }\n");
            }
        }
    }
}
