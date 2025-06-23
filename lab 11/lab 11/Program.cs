using System;
using ClassLibraryLab10;

namespace lab_11
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Лабораторная работа № 10.");
            byte option = 546 % 30 - 1; // Вариант 5
            Console.WriteLine("Вариант " + option + ".");

            Console.WriteLine("//////////////////////////////////");

            TestCollection t = new(1000);


            /*TestCollection t = new(4);
            t.Show();
            t.Remove(new Student("Alex", "Alex", 'M', 33, 2, "A"));
            t.Remove(new Student("Alex", "Alex", 'M', 22, 3, "A"));*/

            int TaskNum = 5;

            while (TaskNum != 0)
            {
                Console.WriteLine(  "1. Поиск первого элемента\n" +
                                    "2. Поиск среднего элемента\n" +
                                    "3. Поиск последнего элемента\n" +
                                    "4. Поиск элемента, не входящего в коллекцию\n" +
                                    "5. Вывод массива на экран\n" +
                                    "0. Выход");
                TaskNum = ReadAndConvToInt();
                Console.Clear();
                switch (TaskNum)
                {
                    case 1:
                        {
                            Console.WriteLine("Поиск первого элемента");
                            SearchFirstElement(t);
                            Console.Clear();
                            break;
                        }
                    case 2:
                        {
                            Console.WriteLine("Поиск среднего элемента");
                            Console.Clear();
                            break;
                        }
                    case 3:
                        {
                            Console.WriteLine("Поиск последнего элемента");
                            Console.Clear();
                            break;
                        }
                    case 4:
                        {
                            Console.WriteLine("Поиск элемента, не входящего в коллекцию");
                            Console.Clear();
                            break;
                        }
                    case 5:
                        {
                            t.Show();
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

        private static void SearchFirstElement(TestCollection testCollection)
        {
            
            Person[] array = testCollection.stackStudent.ToArray();
            Person last = array[array.Length - 1];
            Console.WriteLine("Поиск первого элемента в списках:");

            /*var firstElement = TestCollection.stackStudent.Peek();
            Console.WriteLine("Поиск первого элемента в списках:");
            TimeList(TestCollection.stackStudent, firstElement);
            TimeList(TestCollection.stackString, firstElement.BasePerson.ToString());
            Console.WriteLine("Поиск первого элемента в словорях:");
            TimeDictionary(TestCollection.dPerson, firstElement.BasePerson);
            TimeDictionary(TestCollection.dString, firstElement.BasePerson.ToString());*/
        }



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

        private static void TimeList<T>(List<T> list, T item)
        {
            var stopWatch = new Stopwatch();
            stopWatch.Start();
            var found = list.Contains(item);
            stopWatch.Stop();
            if (found)
            {
                Console.WriteLine("Элемент найден.");
                Console.WriteLine("Время поиска: " + stopWatch.Elapsed.ToString(@"m\:ss\.ffffff"));
            }
            else
            {
                Console.WriteLine("Элемент не найден");
                Console.WriteLine("Время поиска: " + stopWatch.Elapsed.ToString(@"m\:ss\.ffffff"));
            }
        }

        private static void TimeDictionary<T, K>(Dictionary<T, K> dict, T value)
        {
            var stopWatch = new Stopwatch();
            stopWatch.Start();
            var found = dict.ContainsKey(value);
            stopWatch.Stop();
            if (found)
            {
                Console.WriteLine("Элемент найден.");
                Console.WriteLine("Время поиска: " + stopWatch.Elapsed.ToString(@"m\:ss\.ffffff"));
            }
            else
            {
                Console.WriteLine("Элемент не найден");
                Console.WriteLine("Время поиска: " + stopWatch.Elapsed.ToString(@"m\:ss\.ffffff"));
            }
        }
    }
}

    }
}
