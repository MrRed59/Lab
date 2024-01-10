using System;

namespace ClassLibraryLab10
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

        public string SecondName
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
            SecondName = _secondName;
        }

        //Ввод данных в класс вручную
        public void Init(string _firstName, string _secondName)
        {
            FirstName = _firstName;
            SecondName = _secondName;
        }

        //Ввод данных в класс в автомате
        public virtual void RandomInit()
        {
            Random random = new Random();
            int randName = random.Next(16);

            switch (randName)
            {
                case 1:
                    {
                        firstName = "Алексей";
                        break;
                    }
                case 2:
                    {
                        firstName = "Иван";
                        break;
                    }
                case 3:
                    {
                        firstName = "Александр";
                        break;
                    }
                case 4:
                    {
                        firstName = "Максим";
                        break;
                    }
                case 5:
                    {
                        firstName = "Сергей";
                        break;
                    }
                case 6:
                    {
                        firstName = "Николай";
                        break;
                    }
                case 7:
                    {
                        firstName = "Данил";
                        break;
                    }
                case 8:
                    {
                        firstName = "Антон";
                        break;
                    }
                    /////////////////////////
                case 9:
                    {
                        firstName = "Дарья";
                        break;
                    }
                case 10:
                    {
                        firstName = "Анна";
                        break;
                    }
                case 11:
                    {
                        firstName = "Валентина";
                        break;
                    }
                case 12:
                    {
                        firstName = "Анастасия";
                        break;
                    }
                case 13:
                    {
                        firstName = "Ольга";
                        break;
                    }
                case 14:
                    {
                        firstName = "Людмила";
                        break;
                    }
                case 15:
                    {
                        firstName = "Мария";
                        break;
                    }
                case 16:
                    {
                        firstName = "Татьяна";
                        break;
                    }
            }

            switch (random.Next(10))
            {
                case 1:
                    {
                        secondName = "Иванов";
                        break;
                    }
                case 2:
                    {
                        secondName = "Петров";
                        break;
                    }
                case 3:
                    {
                        secondName = "Смирнов";
                        break;
                    }
                case 4:
                    {
                        secondName = "Кузнецов";
                        break;
                    }
                case 5:
                    {
                        secondName = "Соколов";
                        break;
                    }
                case 6:
                    {
                        secondName = "Попов";
                        break;
                    }
                case 7:
                    {
                        secondName = "Лебедев";
                        break;
                    }
                case 8:
                    {
                        secondName = "Козлов";
                        break;
                    }
                case 9:
                    {
                        secondName = "Морозов";
                        break;
                    }
                case 10:
                    {
                        secondName = "Волков";
                        break;
                    }
            }

            if (randName > 8)
            {
                secondName += "а";
            }
        }

        //метод для сравнения объектов
        public override bool Equals(object obj)
        {
            if (obj is Person person)
            {
                return FirstName == person.FirstName && SecondName == person.SecondName;
            }
            else
                return false;
        }

        public override string ToString()
        {
            return $"Фамилия и имя: {secondName} {firstName}.";
        }

        //вывод на экран как виртуальный метод
        public virtual void Show()
        {
            Console.WriteLine($"Фамилия и имя: {secondName} {firstName}.");
        }

        //вывод на экран как перегрузка
        public void ShowOverload()
        {
            Console.WriteLine($"Фамилия и имя: {secondName} {firstName}.");
        }
    }
}
