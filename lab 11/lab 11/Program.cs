using System;
using ClassLibraryLab10;

namespace lab_11
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Лабораторная работа № 10.");
            byte option = 546 % 30 - 1; // Вариант 5
            Console.WriteLine("Вариант " + option + ".");

            Console.WriteLine("//////////////////////////////////");

            TestCollection t = new(1000);


            /*TestCollection t = new(4);
            t.Show();
            t.Remove(new Student("Alex", "Alex", 'M', 33, 2, "A"));
            t.Remove(new Student("Alex", "Alex", 'M', 22, 3, "A"));*/

        }
    }
}
