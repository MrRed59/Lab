using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ClassLibraryLab10;

namespace lab_11
{
    class MyCollection<T> where T:Person, new ()
    {
        T[] collection;
        int currentLenght = 0;
        int delta = 10;
        public int Lenght { get { return currentLenght; } }         //текущая длина
        public int Capacity { get { return collection.Length; } }   //емкость


        //конструктор без параметров
        public MyCollection()
        {
            collection = new T[delta];
            currentLenght = 0;
        }

        //конструктор с параметром (массив)
        public MyCollection(params T[] mas)
        {
            collection = new T[mas.Length];
            for (int i = 0; i < mas.Length; i++)
                collection[i] = mas[i];

            currentLenght = mas.Length;
        }

        //конструктор с параметром
        public MyCollection(int size)
        {
            collection = new T[size];
            for (int i = 0; i < size; i++)
            {
                T item = new T();
                collection[i] = item;
            }
            currentLenght = size;
        }

        //вывод на экран
        public void ShowCollection()
        {
            if (currentLenght == 0)
            {
                Console.WriteLine("Empty Collection");
                return;
            }
            for (int i = 0; i < currentLenght; i++)
                Console.WriteLine($"{i} = {collection[i]}");
        }

        //добавить элемент
        public void Add(T item)
        {
            if (currentLenght < collection.Length)
            {
                collection[currentLenght] = item;
                currentLenght++;
            }
            else
            {
                T[] temp = new T[collection.Length + delta];
                for (int i = 0; i < collection.Length; i++)
                    temp[i] = collection[i];

                currentLenght = collection.Length;
                temp[currentLenght] = item;
                currentLenght++;
                collection = temp;
            }
        }
    }
}
