using System;

namespace Lab5_csharp
{
    class Program
    {
        static void Main(string[] args)
        {
            byte option = 546 % 25 - 1; // Вариант 20
            Console.WriteLine("Лабораторная работа № 5. Вариант " + option + ".");
            MainMenu();
        }

        static void MainMenu()
        {
            int mainMenuNum = 5;

            while (mainMenuNum != 0)
            {
                Console.WriteLine(  "1. Работа с одномерными массивами\n" +
                                    "2. Работа с двумерными массивами\n" +
                                    "3. Работа с рваными массивами\n" +
                                    "0. Выход");
                mainMenuNum = ReadAndConvToInt();
                Console.Clear();
                switch (mainMenuNum)
                {
                    case 1:
                        {
                            Console.WriteLine("Работа с одномерными массивами");
                            Task1();
                            break;
                        }
                    case 2:
                        {
                            Console.WriteLine("Работа с двумерными массивами");
                            Task2();
                            break;
                        }
                    case 3:
                        {
                            Console.WriteLine("Работа с рваными массивами");
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

        static int MenuTask(string taskText)
        {
            int menuTaskNum = 5;

            while (true)
            {
                Console.WriteLine(  "1. Создать массив\n" +
                                    "2. Напечатать массив\n" +
                                    taskText +
                                    "\n0. Назад");
                menuTaskNum = ReadAndConvToInt();
                if (menuTaskNum > 3 || menuTaskNum < 0)
                    Console.WriteLine("Команда не распознана");
                else
                    return menuTaskNum;
            }
        }

        static int ArrayCreateMenu()
        { 
            int arrayCreateMenuNum = 5;

            while (true)
                {
                    Console.WriteLine(  "1. Создать массив вручную\n" +
                                        "2. Создать массив с помощью ДСЧ\n" +
                                        "0. Назад");
                    arrayCreateMenuNum = ReadAndConvToInt();
                    if (arrayCreateMenuNum > 2 || arrayCreateMenuNum < 0)
                        Console.WriteLine("Команда не распознана");
                    else
                        return arrayCreateMenuNum;
                }
        }

        static void CreateArrManual(ref int [] array, uint length)
        {
            int[] arrTemp = new int[length];

            Console.WriteLine("Введите значения: ");

            for (int i = 0; i < length; i++)
            {
                arrTemp[i] = ReadAndConvToInt();
            }
            array = arrTemp;
        }

        static void CreateArrManual(ref int[,] array, uint arrLines, uint arrColumns)
        {
            int[,] arrTemp = new int[arrLines, arrColumns];

            Console.WriteLine("Введите значения: ");

            for (int i = 0; i < arrLines; i++)
            {
                Console.WriteLine($"Строка {i}");

                for (int j = 0; j < arrColumns; j++)
                    arrTemp[i, j] = ReadAndConvToInt();
            }

            array = arrTemp;
        }

        static void CreateArrManual(ref int[][] array, uint arrLines, uint[] arrColumns)
        {
            int[][] arrTemp = new int[arrLines][];

            for (int i = 0; i < arrLines; i++)
                arrTemp[i] = new int[arrColumns[i]]; 

            Console.WriteLine("Введите значения: ");

            for (int i = 0; i < arrTemp.Length; i++)
            {
                Console.WriteLine($"Строка {i}");
                for (int j = 0; j < arrTemp[i].Length; j++)
                    arrTemp[i][j] = ReadAndConvToInt();
            }

            array = arrTemp;
        }

        static void CreateArrRand(ref int[] array, uint length)
        {
            Random random = new Random();
            int[] arrTemp = new int[length];

            for (int i = 0; i < length; i++)
                arrTemp[i] = random.Next(-100, 100);

            array = arrTemp;
        }

        static void CreateArrRand(ref int[,] array, uint arrLines, uint arrColumns)
        {
            Random random = new Random();
            int[,] arrTemp = new int[arrLines, arrColumns];

            for (int i = 0; i < arrLines; i++)
            {
                for (int j = 0; j < arrColumns; j++)
                    arrTemp[i, j] = random.Next(-100, 100);
            }

            array = arrTemp;
        }

        static void CreateArrRand(ref int[][] array, uint arrLines, uint[] arrColumns)
        {
            Random random = new Random();

            int[][] arrTemp = new int[arrLines][];

            for (int i = 0; i < arrLines; i++)
                arrTemp[i] = new int[arrColumns[i]];

            for (int i = 0; i < arrTemp.Length; i++)
                for (int j = 0; j < arrTemp[i].Length; j++)
                    arrTemp[i][j] = random.Next(-50, 50);

            array = arrTemp;
        }


        static void ShowArr(ref int[] array)
        {
            Console.Write("\nArr = ");
            for (int i = 0; i < array.Length; i++)
                Console.Write($"{array [i]}; ");
            Console.WriteLine();
        }

        static void ShowArr(ref int[,] array)
        {
            Console.WriteLine("\nArr:");
            for (int i = 0; i < array.GetLength(0); i++)
            {
                for (int j = 0; j < array.GetLength(1); j++)
                    Console.Write($"{array[i, j]};\t");
                Console.WriteLine();
            }
                
            
            Console.WriteLine();
        }

        static void ShowArr(ref int[][] array)
        {
            for (int i = 0; i < array.Length; i++)
            {
                Console.Write($"arr [{i}]: ");
                for (int j = 0; j < array[i].Length; j++)
                    Console.Write($"{array[i][j]};\t");
                Console.WriteLine();
            }                

            Console.WriteLine();
        }


        static void DeleteArrElement(ref int[] array, uint numElem)
        {
            if (numElem > array.Length - 1)
            {
                Console.WriteLine("Ошибка. Элемент не существует");
                return;
            }

            int[] arrTemp = new int[array.Length - 1];

            for (uint i = 0; i < numElem; i++)
                arrTemp[i] = array[i];

            for (uint i = numElem + 1; i < array.Length; i++)
                arrTemp[i - 1] = array[i];

            array = arrTemp;
        }

        static void AddLinesForTask2(ref int[,] array)
        {

            int newLines = array.GetLength(0) / 2 + array.GetLength(0);
            int[,] arrTemp = new int[newLines, array.GetLength(1)];
            int[,] arrTransfer = new int[3, array.GetLength(1)];

            for (int y = 0, i = 0; y < newLines; y++)
            {
                for (int x = 0; x < array.GetLength(1); x++)
                {
                    if ((y + 1) % 3 == 0)  
                    {
                        arrTemp[y, x] = 0;
                    }
                    else
                    {
                        arrTemp[y, x] = array[i, x];
                    }
                }
                if ((y + 1) % 3 != 0) 
                    i++;
            }
                

            array = arrTemp;
        }

        static void AddLinesForTask3(ref int[][] array)
        {
            Random random = new Random();

            int[][] arrTemp = new int[array.Length + 1][];

            for (int i = 0; i < array.Length; i++)
            {
                arrTemp[i] = new int[array[i].Length];
                for (int j = 0; j < array[i].Length; j++)
                    arrTemp[i][j] = array[i][j];
            }

            arrTemp[array.Length] = new int[random.Next(10)];
            for (int i = 0; i < arrTemp[i].Length - 1; i++) 
                arrTemp[arrTemp.Length - 1][i] = 0;

            array = arrTemp;
        }


        static void Task1()
        {
            int[] arrTask1 = new int[0];

            int msg = 5;

            while (msg != 0)
            {
                msg = MenuTask("3. Удалить элемент с заданным номером");

                switch (msg)
                {
                    case 1: //Создание массива
                        {
                            Console.WriteLine("Введите количество элементов массива");
                            uint arrLength = ReadAndConvToUInt();

                            if (arrLength == 0)
                            {
                                Console.WriteLine("Ошибка. Длина массива не может быть 0.");
                                break;
                            }

                            int value = ArrayCreateMenu();

                            if (value == 1)
                                CreateArrManual(ref arrTask1, arrLength);
                            else if (value == 2)
                                CreateArrRand(ref arrTask1, arrLength);

                            break;
                        }
                    case 2: //Вывод массива на экран
                        {
                            if (arrTask1.Length != 0)
                                ShowArr(ref arrTask1);
                            else
                                Console.WriteLine("Массив не существует.");

                            break;
                        }
                    case 3: //Удалить элемент с заданным номером
                        {
                            if (arrTask1.Length != 0)
                            {
                                Console.Write("Элемент с каким номером требуется удалить? :");
                                uint numElem = ReadAndConvToUInt();
                                DeleteArrElement(ref arrTask1, numElem);
                            }
                            else
                                Console.WriteLine("Массив не существует.");
                            break;
                        }
                    case 0:
                        break;
                }
            }
        }

        static void Task2()
        {
            int[,] arrTask2 = new int[0,0];

            int msg = 5;

            while (msg != 0)
            {
                msg = MenuTask("3. Добавить строки после каждой четной строки матрицы");

                switch (msg)
                {
                    case 1: //Создание массива
                        {
                            Console.WriteLine("Введите количество столбцов массива");
                            uint arrColumns = ReadAndConvToUInt();
                            if (arrColumns == 0)
                            {
                                Console.WriteLine("Ошибка. Количество столбцов не может быть 0.");
                                break;
                            }

                            Console.WriteLine("Введите количество строк массива");
                            uint arrLines = ReadAndConvToUInt();
                            if (arrLines == 0)
                            {
                                Console.WriteLine("Ошибка. Количество строк не может быть 0.");
                                break;
                            }

                            int value = ArrayCreateMenu();

                            if (value == 1)
                                CreateArrManual(ref arrTask2, arrLines, arrColumns);
                            else if (value == 2)
                                CreateArrRand(ref arrTask2, arrLines, arrColumns);


                            break;
                        }
                    case 2: //Вывод массива на экран
                        {
                            if (arrTask2.GetLength(0) != 0)
                                ShowArr(ref arrTask2);
                            else
                                Console.WriteLine("Массив не существует.");
                            
                            break;
                        }
                    case 3: //Добавить строки после каждого четного столбца матрицы
                        {
                            if (arrTask2.GetLength(0) != 0)
                            {
                                AddLinesForTask2(ref arrTask2);
                            }
                            else
                                Console.WriteLine("Массив не существует.");
                            break;
                        }
                    case 0:
                        break;
                }
            }
        }

        static void Task3()
        {
            int[][] arrTask3 = new int[0][];

            int msg = 5;

            while (msg != 0)
            {
                msg = MenuTask("3. Добавить строку в конец массива");

                switch (msg)
                {
                    case 1: //Создание массива
                        {
                            Console.WriteLine("Введите количество строк массива");
                            uint numLines = ReadAndConvToUInt();
                            if (numLines == 0)
                            {
                                Console.WriteLine("Ошибка. Количество столбцов не может быть 0.");
                                break;
                            }

                            uint[] arrColumns = new uint[numLines];

                            for (int i = 0; i < numLines; i++)
                            {
                                Console.WriteLine($"Введите длину массива [{i}]");
                                arrColumns[i] = ReadAndConvToUInt();
                                if (arrColumns[i] == 0) 
                                {
                                    Console.WriteLine("Ошибка. Длина массива не может быть 0.");
                                    i--;
                                }
                            }                            

                            int value = ArrayCreateMenu();

                            if (value == 1)
                                CreateArrManual(ref arrTask3, numLines, arrColumns);
                            else if (value == 2)
                                CreateArrRand(ref arrTask3, numLines, arrColumns);


                            break;
                        }
                    case 2: //Вывод массива на экран
                        {
                            if (arrTask3.Length != 0)
                                ShowArr(ref arrTask3);
                            else
                                Console.WriteLine("Массив не существует.");

                            break;
                        }
                    case 3: //Добавить строку в конец массива
                        {
                            if (arrTask3.Length != 0)
                            {
                                AddLinesForTask3(ref arrTask3);
                            }
                            else
                                Console.WriteLine("Массив не существует.");
                            break;
                        }
                    case 0:
                        break;
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
