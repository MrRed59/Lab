using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;
using LibraryLab10;
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

        //Поиск первого элемента
        private static void SearchFirstElement(TestCollection testCollection)
        {            
            Person[] array = testCollection.stackStudent.ToArray();
            Person firstElement = array[array.Length - 1];
            Console.WriteLine("Поиск первого элемента в списках:");
            TimeList(TestCollection.stackStudent, firstElement);
            TimeList(TestCollection.stackString, firstElement.BasePerson.ToString());
            Console.WriteLine("Поиск первого элемента в словорях:");
            TimeDictionary(TestCollection.dPerson, firstElement.BasePerson);
            TimeDictionary(TestCollection.dString, firstElement.BasePerson.ToString());*/
        }

        //поиск среднего элемента
         private static void SearchMiddleElement(TestCollections testCollection)
        {
            var middleElement = testCollection.col1[testCollection.col1.Count / 2];
            Console.WriteLine("Поиск среднего элемента в списках:");
            TimeList(testCollection.col1, middleElement);
            TimeList(testCollection.col2, middleElement.BasePerson.ToString());
            Console.WriteLine("Поиск среднего элемента в словорях:");
            TimeDictionary(testCollection.col3, middleElement.BasePerson);
            TimeDictionary(testCollection.col4, middleElement.BasePerson.ToString());
        }

        //поиск последнего элемента
        private static void SearchLastElement(TestCollections testCollection)
        {
            var lastElement = testCollection.col1[testCollection.col1.Count - 1];
            Console.WriteLine("Поиск последнего элемента в списках:");
            TimeList(testCollection.col1, lastElement);
            TimeList(testCollection.col2, lastElement.BasePerson.ToString());
            Console.WriteLine("Поиск последнего элемента в словорях:");
            TimeDictionary(testCollection.col3, lastElement.BasePerson);
            TimeDictionary(testCollection.col4, lastElement.BasePerson.ToString());
        }

        //поиск элемента, не входящего в коллекцию
        private static void outOfBoundsElement(TestCollections testCollection)
        {
            Student outOfBoundsElement = new Student("Ульяна", "Женский", 89, 4);
            Console.WriteLine("Поиск невходящего элемента в списках:");
            TimeList(testCollection.col1, outOfBoundsElement);
            TimeList(testCollection.col2, outOfBoundsElement.BasePerson.ToString());
            Console.WriteLine("Поиск невходящего элемента в словорях:");
            TimeDictionary(testCollection.col3, outOfBoundsElement.BasePerson);
            TimeDictionary(testCollection.col4, outOfBoundsElement.BasePerson.ToString());
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
