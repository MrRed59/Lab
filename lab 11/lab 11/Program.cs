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

            MyCollection<Person> c1 = new MyCollection<Person>();
            c1.ShowCollection();
            c1.Add(new Person());
            Console.WriteLine("Добавление элемента");
            c1.ShowCollection();
            Console.WriteLine($"Current={c1.Lenght}");
            Console.WriteLine($"Lenght={c1.Capacity}");

            Console.WriteLine("//////////////////////////////////");

            MyCollection<int> c2 = new MyCollection<int>(5, 4, 5, 6, 8);
            c2.ShowCollection();
            Console.WriteLine($"Current={c2.Lenght}");
            Console.WriteLine($"Lenght={c2.Capacity}");
            c2.Add(100);
            Console.WriteLine("Добавление элемента");
            c2.ShowCollection();
            Console.WriteLine($"Current={c2.Lenght}");
            Console.WriteLine($"Lenght={c2.Capacity}");
        }
    }
}
