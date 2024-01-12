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
        Console.WriteLine("Сумма элементов с четными номерами: " + sumEvenElements);
}