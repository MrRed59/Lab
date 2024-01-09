using System;

namespace Lab10_csharp
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Лабораторная работа № 10.");

            int TaskNum = 5;


            while (TaskNum != 0)
            {
                Console.WriteLine(  "1. Создание иерархии классов\n" +
                                    "2. Динамическая идентификация типов\n" +
                                    "3. Абстрактные классы и интерфейсы\n" +
                                    "0. Выход");
                TaskNum = ReadAndConvToInt();
                Console.Clear();
                switch (TaskNum)
                {
                    case 1:
                        {
                            Console.WriteLine("Создание иерархии классов");
                            Task1();
                            break;
                        }
                    case 2:
                        {
                            Console.WriteLine("Динамическая идентификация типов");
                            Task2();
                            break;
                        }
                    case 3:
                        {
                            Console.WriteLine("Абстрактные классы и интерфейсы");
                            Task3();
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

        static void Task1()
        {
            byte option = 546 % 16 - 1; // Вариант 1
            Console.WriteLine("Вариант " + option + ".");

        }

        static void Task2()
        {
            byte option = 546 % 50 - 1; // Вариант 45
            Console.WriteLine("Вариант " + option + ".");

        }

        static void Task3()
        {

        }

        //Считывание ввода из консоли и преобразование полученной строки в uint
        //Возвращает считанную строку с типом uint
        static uint ReadAndConvToUInt()
        {
            string str;
            uint value;
            while (true)
            {
                str = Console.ReadLine();
                try
                {
                    value = Convert.ToUInt32(str);
                    return value;
                }
                catch
                {
                    Console.WriteLine("Ошибка конвертации, значение должно быть uint");
                }
            }
        }

        //Считывание ввода из консоли и преобразование полученной строки в double
        //Возвращает считанную строку с типом double
        static double ReadAndConvToDouble()
        {
            string str;
            double value;
            while (true)
            {
                str = Console.ReadLine();
                try
                {
                    value = Convert.ToDouble(str);
                    return value;
                }
                catch
                {
                    Console.WriteLine("Ошибка конвертации, значение должно быть double");
                }
            }
        }

        //Считывание ввода из консоли и преобразование полученной строки в int
        //Возвращает считанную строку с типом int
        static int ReadAndConvToInt()
        {
            string str;
            int value;
            while (true)
            {
                str = Console.ReadLine();
                try
                {
                    value = Convert.ToInt32(str);
                    return value;
                }
                catch
                {
                    Console.WriteLine("Ошибка конвертации, значение должно быть int");
                }
            }
        }
    }
}
