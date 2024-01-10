using System;
using ClassLibraryLab10;

namespace Lab10_csharp
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Лабораторная работа № 10.");
            byte option = 546 % 16 - 1; // Вариант 1
            Console.WriteLine("Вариант " + option + ".");

            Person[] p = new Person[0];

            int TaskNum = 5;

            while (TaskNum != 0)
            {
                Console.WriteLine(  "1. Создание иерархии классов\n" +
                                    "2. Динамическая идентификация типов\n" +
                                    "3. Абстрактные классы и интерфейсы\n" +
                                    "4. Вывод массива на экран\n" +
                                    "0. Выход");
                TaskNum = ReadAndConvToInt();
                Console.Clear();
                switch (TaskNum)
                {
                    case 1:
                        {
                            Console.WriteLine("Создание иерархии классов");
                            Task1(ref p);
                            Console.Clear();
                            break;
                        }
                    case 2:
                        {
                            Console.WriteLine("Динамическая идентификация типов");
                            Task2(ref p);
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
                    case 4:
                        {
                            ShowArr(ref p);
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

        static void Task1(ref Person[] person)
        {
            uint lenghtArr = 0;

            while (true)
            {
                Console.Write("Введите длину массива: ");
                lenghtArr = ReadAndConvToUInt();
                if (lenghtArr > 0)
                    break;
                else
                    Console.WriteLine("Ошибка. Массив не может быть длиной 0.");
            }

            Person[] arrPerson = new Person[lenghtArr];

            uint iter = 0; //итератор записи в массив
            int typeArrElement = 5; //выбор класса для заполнения в массив

            for (int i = 0; i < lenghtArr; i++)
            {
                Console.WriteLine("1. Класс Персона \n" +
                                    "2. Класс Студент\n" +
                                    "3. Класс Сотрудник\n" +
                                    "4. Класс Преподаватель\n" +
                                    "0. Выход");
                typeArrElement = ReadAndConvToInt();
                Console.Clear();
                Console.WriteLine(  "1. Заполнить вручную\n" +
                                    "2. Заполнить автоматически при помощи ДСЧ\n" +
                                    "Или любую кнопку, чтобы выйти назад");
                uint choiseFill = ReadAndConvToUInt();
                switch (typeArrElement)
                {
                    case 1:
                        {
                            if (choiseFill == 1)
                            {
                                Person personTemp = new Person();

                                Console.Write("Введите Имя: ");
                                string strName = Console.ReadLine();
                                Console.Write("Введите Фамилию: ");
                                string strSecName = Console.ReadLine();
                                Console.Write("Введите Пол (м или ж): ");
                                char gender = CheckGender();

                                personTemp.Init(strName, strSecName, gender);

                                arrPerson[iter] = personTemp;
                                iter++;
                            }
                            else if (choiseFill == 2)
                            {
                                Person personTemp = new Person();
                                personTemp.RandomInit();
                                arrPerson[iter] = personTemp;
                                iter++;
                            }
                            break;
                        }
                    case 2:
                        {
                            if (choiseFill == 1)
                            {
                                Student studentTemp = new Student();

                                Console.Write("Введите Имя: ");
                                string strName = Console.ReadLine();
                                Console.Write("Введите Фамилию: ");
                                string strSecName = Console.ReadLine();
                                Console.Write("Введите Пол (м или ж): ");
                                char gender = CheckGender();
                                Console.Write("Введите средний балл: ");
                                ushort averageGrade = (ushort)ReadAndConvToUInt();
                                Console.Write("Введите место учебы: ");
                                string educ = Console.ReadLine();

                                studentTemp.Init(strName, strSecName, gender, averageGrade, educ);

                                arrPerson[iter] = studentTemp;
                                iter++;
                            }
                            else if (choiseFill == 2)
                            {
                                Student studentTemp = new Student();
                                studentTemp.RandomInit();
                                arrPerson[iter] = studentTemp;
                                iter++;
                            }
                            break;
                        }
                    case 3:
                        {
                            
                            if (choiseFill == 1)
                            {
                                Employee employeeTemp = new Employee();

                                Console.Write("Введите Имя: ");
                                string strName = Console.ReadLine();
                                Console.Write("Введите Фамилию: ");
                                string strSecName = Console.ReadLine();
                                Console.Write("Введите Пол (м или ж): ");
                                char gender = CheckGender();
                                Console.Write("Введите зарплату: ");
                                double salary = ReadAndConvToDouble();
                                Console.Write("Введите место работы: ");
                                string workPlace = Console.ReadLine();

                                employeeTemp.Init(strName, strSecName, gender, salary, workPlace);

                                arrPerson[iter] = employeeTemp;
                                iter++;
                            }
                            else if (choiseFill == 2)
                            {
                                Employee employeeTemp = new Employee();
                                employeeTemp.RandomInit();
                                arrPerson[iter] = employeeTemp;
                                iter++;
                            }
                            break;
                        }
                    case 4:
                        {
                            if (choiseFill == 1)
                            {
                                Teacher teacherTemp = new Teacher();

                                Console.Write("Введите Имя: ");
                                string strName = Console.ReadLine();
                                Console.Write("Введите Фамилию: ");
                                string strSecName = Console.ReadLine();
                                Console.Write("Введите Пол (м или ж): ");
                                char gender = CheckGender();
                                Console.Write("Введите зарплату: ");
                                double salary = ReadAndConvToDouble();
                                Console.Write("Введите место работы: ");
                                string workPlace = Console.ReadLine();
                                Console.Write("Введите преподаваемый предмет: ");
                                string subjectTaught = Console.ReadLine();

                                teacherTemp.Init(strName, strSecName, gender, salary, workPlace, subjectTaught);

                                arrPerson[iter] = teacherTemp;
                                iter++;
                            }
                            else if (choiseFill == 2)
                            {
                                Teacher teacherTemp = new Teacher();
                                teacherTemp.RandomInit();
                                arrPerson[iter] = teacherTemp;
                                iter++;
                            }
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

            if (iter > 0)
            {
                uint i = 0;
                Console.WriteLine("Bывод массива на экран при помощи перегрузки");
                foreach (Person p in arrPerson)
                {
                    Console.WriteLine("////////////////////////////////////////");
                    Console.WriteLine($"arr[{i}] :");
                    p.ShowOverload();
                    Console.WriteLine("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
                    i++;
                }

                Console.WriteLine("\n++++++++++++++++++++++++++++++++++++++++\n");
                i = 0;
                Console.WriteLine("Bывод массива на экран при помощи виртуальных функций");
                foreach (Person p in arrPerson)
                {
                    Console.WriteLine("////////////////////////////////////////");
                    Console.WriteLine($"arr[{i}] :");
                    p.Show();
                    Console.WriteLine("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
                    i++;
                }
            }
            Console.WriteLine("Нажмите \"Enter\" для продолжения");
            Console.ReadLine();
            person = arrPerson;
        }

        

        static void Task2(ref Person[] p)
        {
            Console.WriteLine("Нажмите \"Enter\" для продолжения");
            Console.ReadLine();
        }

        static void Task3()
        {

        }

        static void ShowArr(ref Person[] person)
        {
            if (person.Length > 0)
            {
                uint i = 0;
                foreach (Person p in person)
                {
                    Console.WriteLine("////////////////////////////////////////");
                    Console.WriteLine($"arr[{i}]:");
                    p.Show();
                    Console.WriteLine("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
                    i++;
                }
                Console.WriteLine("Нажмите \"Enter\" для продолжения");
                Console.ReadLine();
            }
            else
                Console.WriteLine("Массив пустой.");
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

        static char CheckGender()
        {
            char gender;
            while (true)
            {
                gender = ReadAndConvToChar();
                if (gender == 'м' || gender == 'ж')
                    return gender;
                else
                    Console.WriteLine("Ошибка ввода. Пол может быть м или ж.");
            }
        }

        //Считывание ввода из консоли и преобразование полученной строки в char
        //Возвращает считанную строку с типом char
        static char ReadAndConvToChar()
        {
            string str;
            char ch;
            while (true)
            {
                str = Console.ReadLine();
                try
                {
                    ch = Convert.ToChar(str);
                    return ch;
                }
                catch
                {
                    Console.WriteLine("Ошибка конвертации, значение должно быть char");
                }
            }
        }
    }
}
