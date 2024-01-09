using System;

namespace Lab10_csharp
{
    public class Person
    {
        protected string firstName;
        protected string secondName;

        public string FirstName
        {
            get => firstName;
            set
            {
                if (value.Length > 1)
                    firstName = value;
                else
                {
                    Console.WriteLine("Ошибка. Имя не может быть меньше 2 символов");
                    firstName = "-";
                }
            }
        }

        public string SecondtName
        {
            get => secondName;
            set
            {
                if (value.Length > 1)
                    secondName = value;
                else
                {
                    Console.WriteLine("Ошибка. Фамилия не может быть меньше 2 символов");
                    secondName = "-";
                }
            }
        }

        //конструктор без параметров
        public Person()
        {
            firstName = "-";
            secondName = "-";
        }

        //конструктор с параметрами
        public Person(string _firstName, string _secondName)
        {

            FirstName = _firstName;
            SecondtName = _secondName;
        }

        //вывод на экран
        public virtual void Show()
        {
            Console.WriteLine($"Фамилия и имя: {secondName} {firstName}.");
        }
    }
}
