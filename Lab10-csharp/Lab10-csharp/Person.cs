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
                while (true)
                {
                    Console.Write("Имя: ");
                    if (firstName.Length > 1)
                    {
                        firstName = value;
                        break;
                    }
                    else
                        Console.WriteLine("Ошибка. Имя не может быть меньше 2 символов");
                }
            }
        }

        public string SecondtName
        {
            get => secondName;
            set
            {
                while (true)
                {
                    Console.Write("Фамилия: ");
                    if (secondName.Length > 1)
                    {
                        secondName = value;
                        break;
                    }
                    else
                        Console.WriteLine("Ошибка. Фамилия не может быть меньше 2 символов");
                }                
            }
        }

        public Person()
        {
            firstName = "";
            secondName = "";
        }

        public Person(string _firstName, string _secondName)
        {
            FirstName = _firstName;
            SecondtName = _secondName;
        }

        public void Show()
        {
            Console.WriteLine($"Фамилия и имя: {secondName} {firstName}.");
        }
    }
}
