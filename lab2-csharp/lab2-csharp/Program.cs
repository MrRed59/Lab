using System;

namespace lab2_csharp
{
    class Program
    {
        static void Main(string[] args)
        {
            byte option = 546 % 25 - 1; // Вариант 20
            Console.WriteLine("Лабораторная работа № 1. Вариант " + option + ".");
            int taskNum = 5;


            while (taskNum != 0)
            {
                Console.WriteLine("Выберите задачу: 1 | 2 | 3 или 0 для выхода из программы.");
                taskNum = ReadAndConvToInt();
                switch (taskNum)
                {
                    case 1:
                        {
                            Console.Clear();
                            Console.WriteLine("Задача 1 (3).");
                            Task1();
                            Console.WriteLine("Нажмите любую клавишу для перехода в выбор задач");
                            Console.ReadLine();
                            Console.Clear();
                            break;
                        }
                    case 2:
                        {
                            Console.Clear();
                            Console.WriteLine("Задача 2 (25).");
                            Task2();
                            Console.WriteLine("Нажмите любую клавишу для перехода в выбор задач");
                            Console.ReadLine();
                            Console.Clear();
                            break;
                        }
                    case 3:
                        {
                            Console.Clear();
                            Console.WriteLine("Задача 3 (54).");
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
            Console.WriteLine("Дана последовательность из n целых чисел. Найти сумму элементов с четными номерами из этой последовательности.");
            Console.WriteLine("Введите длину последовательности: ");
            uint sequenceLenght = 0; //Задается длина последовательности, затем используется для проверки на четность
            int sumEvenElements = 0; //Сумма элементов последовательности

            while (true) //Проверка корректности ввода, не позволяя установить значение < 0
            {
                sequenceLenght = ReadAndConvToUInt();

                if (sequenceLenght == 0)
                    Console.WriteLine("Ошибка. Длина последовательности не может быть 0");
                else
                    break;
            }

            for (int i = 1; i <= sequenceLenght; i++)//Считываем число последовательности. Если четное, то суммируем его с sumEvenElements
            {
                Console.Write("Введите число: ");
                int sequenceNumber = ReadAndConvToInt();
                if ((i % 2) == 0)
                    sumEvenElements += sequenceNumber;
            }

            if (sequenceLenght == 1)
                Console.WriteLine("Ошибка. Нет четных чисел");
            else
                Console.WriteLine ("Сумма элементов с четными номерами: " + sumEvenElements);
        }

        static void Task2()
        {
            Console.WriteLine("Дана последовательность целых чисел, за которой следует 0. Найти номер минимального элемента в этой последовательности");
            int currentNumber = 0;  //текущее число последовательности 
            int lastNumber = 0;     //предыдущее число последовательности
            int minNumber = 0;      //минимальное число последовательности
            int numMinNumber = 0;   //номер минимального числа последовательности
            int counter = 0;        //текущий номер элемента последовательности
            
            do
            {
                Console.Write("Введите число последовательности или 0 для конца последовательности: ");
                currentNumber = ReadAndConvToInt();
                if (currentNumber < minNumber && currentNumber != 0 || counter == 0) 
                {
                    numMinNumber = counter;
                    minNumber = currentNumber;
                }

                lastNumber = currentNumber;                
                counter++;
            } while (currentNumber != 0);

            if (counter != 1)
                Console.WriteLine($"Минимальное число последовательности: {minNumber}, с номером {numMinNumber + 1}");
            else
                Console.WriteLine("Ошибка. Длина последовательности не может быть 0.");
        }

        static void Task3()
        {
            Console.WriteLine("S=(1/a)+(1/a^2)+(1/a^4)+...+(1/a^(n-1)");
            Console.Write("Введите a: ");
            double a = ReadAndConvToDouble();

            while (a == 0)
            {
                Console.Write("a не может быть 0\n");
                a = ReadAndConvToDouble();
            }            
            
            Console.Write("Введите n: ");
            double n = ReadAndConvToDouble();

            double sum = 0.0;

            for (int i = 1; i <= n; i++)
            {
                sum += 1 / Math.Pow(a, 2 * i - 1);
            }

            Console.WriteLine($"S = {sum}");
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
    }
}
