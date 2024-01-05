using System;

namespace Lab1_csharp
{
    class Program
    {
        static void Main(string[] args)
        {
            byte option = 546 % 25 - 1; // Вариант 20
            Console.WriteLine("Лабораторная работа № 1. Вариант " + option + ".");

            int value = ReadAndConvToInt();
            Console.WriteLine(value);

            Console.ReadLine();

            
        }

        static int ReadAndConvToInt()
        {
            string str; 
            int value;
            while (true)
            {
                str = Console.ReadLine();
                try { value = Convert.ToInt32(str); return value; }
                catch { Console.WriteLine("Ошибка конвертации, значение должно быть int"); }
            }            
        }
    }
}
