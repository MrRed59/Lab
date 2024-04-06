using System;
using System.Collections.Generic;

namespace ClassLibraryLab10
{
    public class Person : IInit, IComparable, ICloneable
    {
        protected string firstName;
        protected string secondName;
        protected char gender;
        protected byte age;

        private readonly Dictionary<int, string> firstNameArr = new()
        {
            {0, "Алексей" },
            {1, "Иван" },
            {2, "Александр" },
            {3, "Максим" },
            {4, "Сергей" },
            {5, "Николай" },
            {6, "Данил" },
            {7, "Антон" },
            {8, "Андрей" },
            {9, "Владимир" },
            {10, "Владислав" },
            {11, "Илья" },
            {12, "Макар" },
            {13, "Дарья" },
            {14, "Анна" },
            {15, "Валентина" },
            {16, "Анастасия" },
            {17, "Ольга" },
            {18, "Людмила" },
            {19, "Мария" },
            {20, "Татьяна" },
            {21, "Евгения" },
            {22, "Елена" },
            {23, "Ирина" },
            {24, "Валерия" },
            {25, "Надежда" }

        };

        private readonly Dictionary<int, string> secondNameArr = new()
        {
            {0, "Иванов" },
            {1, "Петров" },
            {2, "Смирнов" },
            {3, "Кузнецов" },
            {4, "Соколов" },
            {5, "Попов" },
            {6, "Лебедев" },
            {7, "Козлов" },
            {8, "Морозов" },
            {9, "Волков" },
            {10, "Белкин" },
            {11, "Авдеев" },
            {12, "Глухов" },
            {13, "Баженов" },
            {14, "Елиссев" },
            {15, "Давыдов" },
            {16, "Жуков" },
            {17, "Казакова" },
            {18, "Дроздов" },
            {19, "Демидов" }
        };


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

        public char Gender
        {
            get => gender;
            set
            {
                if (value == 'м' || value == 'ж')
                    gender = value;
                else
                {
                    Console.WriteLine("Ошибка. Пол может быть мужской (м) или женский (ж)");
                    gender = '-';
                }
            }
        }

        public byte Age 
        { 
            get => age; 
            set => age = value; 
        }

        //конструктор без параметров
        public Person()
        {
            firstName = "-";
            secondName = "-";
            gender = '-';
            Age = 0;
        }

        //конструктор с параметрами
        public Person(string _firstName, string _secondName, char _gender, byte _age)
        {
            FirstName = _firstName;
            SecondName = _secondName;
            Gender = _gender;
            Age = _age;
        }

        public virtual object Clone() => new Person(FirstName, SecondName, Gender, Age);

        public virtual object ShallowCopy() => (Person)MemberwiseClone();

        public int CompareTo(object obj)
        {
            if (obj is Person p)
            {
                return string.Compare(SecondName, p.SecondName);
            }

            throw new ArgumentException("Некорректное значение параметра");            
        }

        //Ввод данных в класс вручную
        public virtual void Init()
        {
            Console.Write("Введите Имя: ");
            FirstName = Console.ReadLine();
            Console.Write("Введите Фамилию: ");
            SecondName = Console.ReadLine();
            Console.Write("Введите Пол (м или ж): ");
            Gender = CheckGender();
            Console.Write("Введите возраст: ");
            Age = ReadAndConvToByte(12, 85);
        }


        //Ввод данных в класс в автомате
        public virtual void RandomInit()
        {
            Random random = new Random();
            int randName = random.Next(25);

            firstName = firstNameArr[randName];
            secondName = secondNameArr[random.Next(19)];

            if (randName > 12)
            {
                secondName += "а";
                gender = 'ж';
            }
            else
                gender = 'м';

            Age = (byte)random.Next(18, 85);
        }

        //метод для сравнения объектов
        public override bool Equals(object obj)
        {
            if (obj is Person person)
            {
                return  FirstName == person.FirstName 
                        && SecondName == person.SecondName 
                        && Gender == person.Gender
                        && Age == person.Age;
            }
            else
                return false;
        }

        public override string ToString()
        {
            return $"Фамилия и имя: {secondName} {firstName}. Пол: {gender}. Возраст: {age}. ";
        }

        //вывод на экран как виртуальный метод
        public virtual void Show()
        {
            Console.WriteLine($"Фамилия и имя: {secondName} {firstName}.\tПол: {gender}.\tВозраст: {Age}");
        }

        //вывод на экран как перегрузка
        public void ShowOverload()
        {
            Console.WriteLine($"Фамилия и имя: {secondName} {firstName}. Пол: {gender}. Возраст: {Age}");
        }

        //Считывание ввода из консоли и преобразование полученной строки в byte
        //Возвращает считанную строку с типом byte
        protected static byte ReadAndConvToByte(int minValue = 0, int maxValue = 255)
        {
            string str;
            byte value;
            while (true)
            {
                str = Console.ReadLine();
                try
                {
                    value = Convert.ToByte(str);
                    if (value >= minValue && value <= maxValue)
                        return value;
                    else
                        Console.WriteLine($"Значение вне диапазона {minValue}...{maxValue}");
                }
                catch
                {
                    Console.WriteLine("Ошибка конвертации, значение должно быть byte");
                }
            }
        }

        //Считывание ввода из консоли и преобразование полученной строки в uint
        //Возвращает считанную строку с типом uint
        protected static uint ReadAndConvToUInt()
        {
            string str;
            uint value;
            while (true)
            {
                str = Console.ReadLine();
                try
                {
                    value = Convert.ToUInt32(str);
                    return value;
                }
                catch
                {
                    Console.WriteLine("Ошибка конвертации, значение должно быть uint");
                }
            }
        }

        //Считывание ввода из консоли и преобразование полученной строки в double
        //Возвращает считанную строку с типом double
        protected static double ReadAndConvToDouble()
        {
            string str;
            double value;
            while (true)
            {
                str = Console.ReadLine();
                try
                {
                    value = Convert.ToDouble(str);
                    return value;
                }
                catch
                {
                    Console.WriteLine("Ошибка конвертации, значение должно быть double");
                }
            }
        }


        protected static char CheckGender()
        {
            char gender;
            while (true)
            {
                gender = ReadAndConvToChar();
                if (gender == 'м' || gender == 'ж')
                    return gender;
                else
                    Console.WriteLine("Ошибка ввода. Пол может быть м или ж.");
            }
        }

        //Считывание ввода из консоли и преобразование полученной строки в char
        //Возвращает считанную строку с типом char
        protected static char ReadAndConvToChar()
        {
            string str;
            char ch;
            while (true)
            {
                str = Console.ReadLine();
                try
                {
                    ch = Convert.ToChar(str);
                    return ch;
                }
                catch
                {
                    Console.WriteLine("Ошибка конвертации, значение должно быть char");
                }
            }
        }
    }
}
