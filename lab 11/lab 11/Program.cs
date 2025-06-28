using System;
using System.Collections.Generic;
using System.Diagnostics;
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

            int TaskNum = 5;

            while (TaskNum != 0)
            {
                Console.Clear();
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
                            break;
                        }
                    case 2:
                        {
                            Console.WriteLine("Поиск среднего элемента");
                            SearchMiddleElement(t);
                            break;
                        }
                    case 3:
                        {
                            Console.WriteLine("Поиск последнего элемента");
                            SearchLastElement(t);
                            break;
                        }
                    case 4:
                        {
                            Console.WriteLine("Поиск элемента, не входящего в коллекцию");
                            outOfBoundsElement(t);
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

                Console.ReadLine();
            }
        }

        //Поиск первого элемента
        private static void SearchFirstElement(TestCollection testCollection)
        {            
            Student[] array = testCollection.stackStudent.ToArray();
            Student firstElement = array[array.Length - 1];

            Console.WriteLine("Элемент: \n");
            firstElement.Show();

            Console.WriteLine("\nПоиск первого элемента в стэке:");
            TimeStack(testCollection.stackStudent, firstElement);
            TimeStack(testCollection.stackString, firstElement.BasePerson.ToString());
            Console.WriteLine("Поиск первого элемента в словорях:");
            TimeDictionary(testCollection.dPerson, firstElement.BasePerson);
            TimeDictionary(testCollection.dString, firstElement.BasePerson.ToString());
        }

        //поиск среднего элемента
         private static void SearchMiddleElement(TestCollection testCollection)
        {
            Student[] array = testCollection.stackStudent.ToArray();
            Student middleElement = array[array.Length / 2];

            Console.WriteLine("Элемент: \n");
            middleElement.Show();

            Console.WriteLine("\nПоиск среднего элемента в стэке:");
            TimeStack(testCollection.stackStudent, middleElement);
            TimeStack(testCollection.stackString, middleElement.BasePerson.ToString());
            Console.WriteLine("Поиск среднего элемента в словорях:");
            TimeDictionary(testCollection.dPerson, middleElement.BasePerson);
            TimeDictionary(testCollection.dString, middleElement.BasePerson.ToString());
        }

        //поиск последнего элемента
        private static void SearchLastElement(TestCollection testCollection)
        {
            var lastElement = testCollection.stackStudent.Peek();

            Console.WriteLine("Элемент: \n");
            lastElement.Show();

            Console.WriteLine("\nПоиск последнего элемента в стэке:");
            TimeStack(testCollection.stackStudent, lastElement);
            TimeStack(testCollection.stackString, lastElement.BasePerson.ToString());
            Console.WriteLine("Поиск последнего элемента в словорях:");
            TimeDictionary(testCollection.dPerson, lastElement.BasePerson);
            TimeDictionary(testCollection.dString, lastElement.BasePerson.ToString());
        }

        //поиск элемента, не входящего в коллекцию
        private static void outOfBoundsElement(TestCollection testCollection)
        {
            Student outOfBoundsElement = new("Ульяна", "Женский", 'ж', 42, 3, "-");

            Console.WriteLine("Элемент: \n");
            outOfBoundsElement.Show();

            Console.WriteLine("\nПоиск невходящего элемента в стэке:");
            TimeStack(testCollection.stackStudent, outOfBoundsElement);
            TimeStack(testCollection.stackString, outOfBoundsElement.BasePerson.ToString());
            Console.WriteLine("Поиск невходящего элемента в словорях:");
            TimeDictionary(testCollection.dPerson, outOfBoundsElement.BasePerson);
            TimeDictionary(testCollection.dString, outOfBoundsElement.BasePerson.ToString());
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

        private static void TimeStack<T>(Stack<T> stack, T item)
        {
            var stopWatch = new Stopwatch();
            stopWatch.Start();
            var found = stack.Contains(item);
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

        private static void TimeDictionary(Dictionary<Person, Student> dict, Person value)
        {
            var stopWatch = new Stopwatch();
            stopWatch.Start();
            bool found = dict.ContainsKey(value);
            stopWatch.Stop();

            if (found)
                Console.WriteLine("Элемент найден.");
            else
                Console.WriteLine("Элемент не найден");
            
            Console.WriteLine("Время поиска: " + stopWatch.Elapsed.ToString(@"m\:ss\.ffffff"));
        }

        private static void TimeDictionary(Dictionary<string, Student> dict, string value)
        {
            var stopWatch = new Stopwatch();
            stopWatch.Start();
            bool found = dict.ContainsKey(value);
            stopWatch.Stop();

            if(found)
                Console.WriteLine("Элемент найден.");
            else
                Console.WriteLine("Элемент не найден");
            
            Console.WriteLine("Время поиска: " + stopWatch.Elapsed.ToString(@"m\:ss\.ffffff"));
        }
    }
}
