using System;

namespace ClassLibraryLab10
{
    public class Person : IInit, IComparable, ICloneable
    {
        protected string firstName;
        protected string secondName;
        protected char gender;
        protected byte age;

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
            if (obj is Person org)
            {
                return string.Compare(SecondName, org.SecondName);
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
            int randName = random.Next(1, 16);

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

            switch (random.Next(1, 10))
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
                gender = 'ж';
            }
            else
                gender = 'м';

            Age = (byte)random.Next(12, 85);
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
            return $"Фамилия и имя: {secondName} {firstName}. Пол: {gender}";
        }

        //вывод на экран как виртуальный метод
        public virtual void Show()
        {
            Console.WriteLine($"Фамилия и имя: {secondName} {firstName}. Пол: {gender}. Возраст: {Age}");
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

        //Считывание ввода из консоли и преобразование полученной строки в int
        //Возвращает считанную строку с типом int
        protected static int ReadAndConvToInt()
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
