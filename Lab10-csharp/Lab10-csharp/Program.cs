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
                            Task3(ref p);
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

                                personTemp.Init();
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

                                studentTemp.Init();

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

                                employeeTemp.Init();

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

                                teacherTemp.Init();

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
                            i--;
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
            int requestNum = 5;

            while (requestNum != 0)
            {
                Console.WriteLine(  "1. Имена всех лиц мужского или женского пола\n" +
                                    "2. Средний балл больше x\n" +
                                    "3. Вывести имена и фамиили студентов и преподавателей указанного университета\n" +
                                    "0. Выход");
                requestNum = ReadAndConvToInt();
                Console.Clear();
                switch (requestNum)
                {
                    case 1:
                        {
                            Console.Write("Вывести имена всех лиц муского или женского пола? :");
                            Console.WriteLine(AllNamesSelectedGenders(ref p, CheckGender()));
                            break;
                        }
                    case 2:
                        {
                            Console.Write("Вывести имена и фамилии студентов, если средний балл больше или равен :");
                            Console.WriteLine(AllNamesSelectedAverageScore(ref p, AverageScore()));
                            break;
                        }
                    case 3:
                        {
                            Console.WriteLine("Вывести имена и фамиили студентов и преподавателей университета: ");
                            Console.WriteLine(NamesStudentsTeachers(ref p, Console.ReadLine()));
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


                Console.WriteLine("Нажмите \"Enter\" для продолжения");
                Console.ReadLine();
            }
        }

        static void Task3(ref Person[] p)
        {
            Console.WriteLine("Сортировка элементов массива, используя стандартный интерфейс IComparable  и метод Sort класса Array");
            Array.Sort(p);
            Console.WriteLine("Отсортированный массив: ");
            ShowArr(ref p);
            Console.WriteLine("Сортировка элементов массива, используя стандартный интерфейс ICompare  и метод Sort класса Array");
            Array.Sort(p, new SortByAge());
            Console.WriteLine("Отсортированный массив по возрасту: ");
            ShowArr(ref p);
            Console.WriteLine("Бинарный поиск.");
            Console.Write("Введите человека с возрастом: ");
            var i = BinarySearch(ref p, 0, p.Length - 1, ReadAndConvToByte());

            if (i == -1)
                Console.WriteLine("Элемент не найден");
            else
            {
                Console.WriteLine($"Класс: {p[i].GetType().Name}");
                p[i].Show();
            }


            Console.WriteLine("Нажмите \"Enter\" для продолжения");
            Console.ReadLine();
        }

        static int BinarySearch(ref Person[] arr, int start, int end, byte _age)
        {
            while (true)
            {
                if (end < start)
                    return -1;

                int middleIndex = (start + end) / 2;

                if (arr[middleIndex].Age == _age)
                    return middleIndex;

                if (arr[middleIndex].Age > _age)
                {
                    end = middleIndex - 1;
                    continue;
                }

                start = middleIndex + 1;
            }
        }

        //Вывести имена и фамиили студентов и преподавателей указанного университета
        static string NamesStudentsTeachers(ref Person[] arr, string university)
        {
            string nameFromGender = "";

            foreach (Person p in arr)
            {
                if (p is Student z && z.EducInstitution == university)
                    nameFromGender += "Студент " + p.FirstName + " " + p.SecondName + ". Учебное заведение: " + university + '\n';
                if (p is Teacher t && t.PlaceWork == university)
                    nameFromGender += "Преподаватель " + p.FirstName + " " + p.SecondName + ". Учебное заведение: " + university + '\n';
            }

            return nameFromGender;
        }

        //Считывает ввод из консоли и возвращает значение byte в диапазоне 2...5
        static byte AverageScore()
        {
            byte value = 0;
            while (true)
            {
                value = ReadAndConvToByte();
                if (value >= 2 && value <= 5)
                    return value;
                else
                    Console.WriteLine("Средний балл не может быть меньше 2 и больше 5");
            }
        }

        //Возвращает имена и фамилии студентов с средним баллом x
        static string AllNamesSelectedAverageScore(ref Person[] arr, byte x)
        {
            string nameAverScore = "";

            foreach (Student p in arr)
                if (p is Student && p.AverageGrade >= x)
                    nameAverScore += p.FirstName + " ср.балл = " + p.AverageGrade + ", ";

            return nameAverScore.TrimEnd(new char[] { ',', ' ' }); //удалить 2 последних символа и венуть строку
        }

        //Возвращает все мужские или все женские имена
        static string AllNamesSelectedGenders(ref Person[] arr, char _gender)
        {
            string nameFromGender = "";
            foreach (Person p in arr)
                if (p.Gender == _gender)
                    nameFromGender += p.FirstName + ", ";
            return nameFromGender.TrimEnd(new char[] { ',', ' ' }); //удалить 2 последних символа и венуть строку
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

        //Считывание ввода из консоли и преобразование полученной строки в byte
        //Возвращает считанную строку с типом byte
        protected static byte ReadAndConvToByte(int minValue = 0, int maxValue = 255)
        {
            string str;
            byte value;
            while (true)
            {
                str = Console.ReadLine();
                try
                {
                    value = Convert.ToByte(str);
                    if (value >= minValue && value <= maxValue)
                        return value;
                    else
                        Console.WriteLine($"Значение вне диапазона {minValue}...{maxValue}");
                }
                catch
                {
                    Console.WriteLine("Ошибка конвертации, значение должно быть byte");
                }
            }
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
