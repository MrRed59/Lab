using System;

namespace Lab1_csharp
{
    class Program
    {
        static void Main(string[] args)
        {
            byte option = 546 % 25 - 1; // Вариант 20
            Console.WriteLine("Лабораторная работа № 1. Вариант " + option + ".");
            int TaskNum = 5;


            while (TaskNum != 0)
            {
                Console.WriteLine("Выберите задачу: 1 | 2 | 3 или 0 для выхода из программы.");
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

        static void Task1()
        {
            Console.Write("Введите значение n: ");
            int n = ReadAndConvToInt();
            Console.Write("Введите значение m: ");
            int m = ReadAndConvToInt();
            // 1.
            Console.WriteLine("1) n++*--m = " + (n++ * --m) + " | " + $"n = {n}; m = {m}.");
            // 2.
            Console.WriteLine("2) n--<m++ = " + (n-- < m++) + " | " + $"n = {n}; m = {m}.");
            // 3.
            Console.WriteLine("3) --n>--m = " + (--n > --m) + " | " + $"n = {n}; m = {m}.");
            // 4.
            Console.WriteLine("Введите значение х: ");
            double x = ReadAndConvToDouble();
            Console.Write("4) 5x^3((1/x^2)+1/(x^3))^1/5 = ");
            Console.WriteLine(5 * (Math.Pow(x, 3)) * Math.Pow(((1 / (Math.Pow(x, 2))) + (1 / (Math.Pow(x, 3)))), 1.0 / 5.0));
        }

        static void Task2()
        {
            Console.WriteLine("Введите значение х: ");
            double x = ReadAndConvToDouble();
            Console.WriteLine("Введите значение y: ");
            double y = ReadAndConvToDouble();
            if ((x <= 0 && y >= 0 && y <= x + 5) || (x >= 0 && y >= 0 && y <= -x + 5) || (x >= 0 && y <= 0 && y >= (x * 7 / 5) - 7))
                Console.WriteLine($"Точка {x}:{y} принадлежит заданной области");
            else
                Console.WriteLine($"Точка {x}:{y} не принадлежит заданной области");

        }

        static void Task3()
        {
            Console.WriteLine("Тип данных Float");
            float a = 1000, b = (float)0.0001;
            Console.WriteLine("((a-b)^2-(a^2-2ab))/b^2 = " + ((Math.Pow((a - b), 2) - (Math.Pow(a, 2) - 2 * a * b)) / Math.Pow(b, 2)));
            Console.WriteLine("Тип данных Double");
            double x = 1000, y = 0.0001;
            Console.WriteLine("((a-b)^2-(a^2-2ab))/b^2 = " + ((Math.Pow((x - y), 2) - (Math.Pow(x, 2) - 2 * x * y)) / Math.Pow(y, 2)));

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

        static double ReadAndConvToDouble()
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
