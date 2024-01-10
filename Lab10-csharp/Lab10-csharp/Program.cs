using System;
using libLab10;

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
                            Console.Clear();
                            break;
                        }
                    case 2:
                        {
                            Console.WriteLine("Динамическая идентификация типов");
                            Task2();
                            Console.Clear();
                            break;
                        }
                    case 3:
                        {
                            Console.WriteLine("Абстрактные классы и интерфейсы");
                            Task3();
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
            byte option = 546 % 16 - 1; // Вариант 1
            Console.WriteLine("Вариант " + option + ".");

            /*Console.WriteLine("Имя: ");
            FirstName = Console.ReadLine();
            Console.WriteLine("Фамилия: ");
            SecondName = Console.ReadLine();*/

            Person person = new Person();
            Person person1 = new Person("Alex", "Alexovich");

            Student student = new Student();
            Student student1 = new Student("Alex", "Erypalov", (ushort)4.2, "PNIPU");

            Employee employee = new Employee();
            Employee employee1 = new Employee("Alex", "Alexov", 50000, "Ice cream factory");

            Teacher teacher = new Teacher();
            Teacher teacher1 = new Teacher("Alex", "Alexov", 50000, "Ice cream factory", "Matan");

            Person[] arr = { person, person1, student, student1, employee, employee1, teacher, teacher1 };

            foreach (Person s in arr)
            {
                Console.WriteLine("////////////////////////////////////////");
                s.Show();
                Console.WriteLine("////////////////////////////////////////");
                
            }

            

            Console.ReadLine();
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
