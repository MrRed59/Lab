using System;

namespace Lab10_csharp
{
    class Program
    {
        static void Main(string[] args)
        {
            byte option = 546 % 16 - 1; // Вариант 1
            Console.WriteLine("Лабораторная работа № 10. Вариант " + option + ".");
            Console.Read();

            int TaskNum = 5;


            while (TaskNum != 0)
            {
                Console.WriteLine("1. Создание иерархии классов\n" +
                                    "2. Динамическая идентификация типов\n" +
                                    "3. Абстрактные классы и интерфейсы\n" +
                                    "0. Выход");
                TaskNum = ReadAndConvToInt();
                switch (TaskNum)
                {
                    case 1:
                        {
                            Console.Clear();
                            Console.WriteLine("Задача 1.");
                            Task1();
                            Console.WriteLine("Нажмите любую клавишу для перехода в выбор задач");
                            Console.ReadLine();
                            Console.Clear();
                            break;
                        }
                    case 2:
                        {
                            Console.Clear();
                            Console.WriteLine("Задача 2.");
                            Task2();
                            Console.WriteLine("Нажмите любую клавишу для перехода в выбор задач");
                            Console.ReadLine();
                            Console.Clear();
                            break;
                        }
                    case 3:
                        {
                            Console.Clear();
                            Console.WriteLine("Задача 3.");
                            Task3();
                            Console.WriteLine("Нажмите любую клавишу для перехода в выбор задач");
                            Console.ReadLine();
                            Console.Clear();
                            break;
                        }
                    case 0:
                        break;
                    default:
                        {
                            Console.WriteLine("Команда не распознана.");
                            break;
                        }
                }
            }
        }

        public static int ReadAndConvToInt()
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

        public static double ReadAndConvToDouble()
        {
            string str;
            double value;
            while (true)
            {
                str = Console.ReadLine();
                try { value = Convert.ToDouble(str); return value; }
                catch { Console.WriteLine("Ошибка конвертации, значение должно быть double"); }
            }
        }
    }
}
