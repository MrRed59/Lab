using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab_11
{
    class MyCollection<T>
    {
        T[] collection;
        int currentLenght = 0;
        int delta = 10;
        public int Lenght { get { return currentLenght; } }
        public int Capacity { get { return collection.Length; } }

        public MyCollection()
        {
            collection = new T[delta];
            currentLenght = 0;
        }

        public MyCollection(params T[] mas)
        {
            collection = new T[mas.Length];
            for (int i = 0; i < mas.Length; i++)
                collection[i] = mas[i];

            currentLenght = mas.Length;
        }

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
