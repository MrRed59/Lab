using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ClassLibraryLab10;

namespace lab_11
{
    class TestCollection
    {
        public Stack<Student> stackStudent = new(); // Коллекция_1 <TValue>
        public Stack<string> stackString = new(); // Коллекция_1 <string>
        public Dictionary<Person, Student> dPerson = new(); //Коллекция_2 <TKey, TValue>
        public Dictionary<string, Student> dString = new(); //Коллекция_2 <string, TValue>

        public TestCollection(int length)
        {
            /*var a = new Student("Alex", "Alex", 'M', 22, 3, "A");
            stackStudent.Push(a);
            stackString.Push(a.BasePerson.ToString());
            dPerson.Add(a.BasePerson, a);
            dString.Add(a.BasePerson.ToString(), a);*/

            for (int i = 0; i < length; i++)
            {
                try
                {
                    var temp = new Student();
                    temp.RandomInit();
                    dString.Add(temp.BasePerson.ToString(), temp);
                    stackStudent.Push(temp);
                    stackString.Push(temp.BasePerson.ToString());
                    dPerson.Add(temp.BasePerson, temp);                    
                }
                catch (Exception)
                {
                    --i;
                }                
            }

            /*a = new Student("Alex", "Alex", 'M', 33, 2, "A");
            stackStudent.Push(a);
            stackString.Push(a.BasePerson.ToString());
            dPerson.Add(a.BasePerson, a);
            dString.Add(a.BasePerson.ToString(), a);*/
        }

        public void Show()
        {
            Console.WriteLine("Вывод элементов коллекции \"Stack <Student>\"");
            foreach (Student item in stackStudent)
            {
                item.Show();
                Console.WriteLine();
            }

            Console.WriteLine("\n\nВывод элементов коллекции \"Stack <string>\"");
            foreach (var item in stackString)
            {
                Console.WriteLine(item);
            }

            Console.WriteLine("\n\nВывод элементов коллекции \"Dictionary<Person, Student>\"");
            foreach (KeyValuePair<Person, Student> item in dPerson)
            {
                Console.WriteLine("KEY:");
                item.Key.Show();
                Console.WriteLine("\nVALUE:");
                item.Value.Show();
            }

            Console.WriteLine("\n\nВывод элементов коллекции \"Dictionary<string, Student>\"");
            foreach (KeyValuePair<string, Student> item in dString)
            {
                Console.WriteLine("KEY:");
                Console.Write(item.Key);
                Console.WriteLine("\nVALUE:");
                item.Value.Show();
            }
        }

        // Добавить элемент в коллекции
        public void Add(Student temp)
        {
            stackStudent.Push(temp);
            stackString.Push(temp.BasePerson.ToString());
            dPerson.Add(temp.BasePerson, temp);
            dString.Add(temp.BasePerson.ToString(), temp);
        }

        
        // Удалить элемент из всех коллекций
        public void Remove(Student item)
        {
            RemoveToStack(ref stackStudent, item);
            RemoveToStack(ref stackString, item.ToString());

            dPerson.Remove(item.BasePerson);
            dString.Remove(item.BasePerson.ToString());
        }

        // удалить элемент из стека
        // возвращает: true - элемент удален / false - не смог удалить
        public bool RemoveToStack<T>(ref Stack<T> stack, T item) where T : class
        {
            string tempItem = item.ToString();

            if (!stack.Contains(item) || stack.Count == 0)  //стек пустой или элемент не найден
                return false;

            if (stack.Peek().ToString() == tempItem)               
            {
                stack.Pop();
                return true;
            }

            T[] tempArr = new T[stack.Count];       //массив для переноса данных из стека

            int i = 0;
            int lenght = stack.Count;

            for (; i < lenght; i++)
            {                
                if (stack.Peek().ToString() == tempItem)
                {
                    stack.Pop();
                    break;
                }
                else
                    tempArr[i] = stack.Pop();                                    
            }

            for (; i >= 0; --i)
            {
                stack.Push(tempArr[i]);
            }

            return true;
        }
    }
}
