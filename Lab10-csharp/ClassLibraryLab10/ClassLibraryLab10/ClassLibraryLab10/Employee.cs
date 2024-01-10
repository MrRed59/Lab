using System;

namespace ClassLibraryLab10
{
    public class Employee:Person
    {
        protected double salary;
        protected string placeWork;

        protected double Salary { get; set; }

        public string PlaceWork
        {
            get => placeWork;
            set
            {
                if (value.Length > 2)
                    placeWork = value;
                else
                {
                    Console.WriteLine("Ошибка. Место работы не может быть меньше 3 символов");
                    placeWork = "-";
                }
            }
        }

        //конструктор без параметров
        public Employee(): base()
        {
            salary = 0;
            placeWork = "-";
        }

        //конструктор с параметрами
        public Employee(string _firstName, string _secondName, double _salary, string _placeWork) :base(_firstName, _secondName)
        {
            Salary = _salary;
            PlaceWork = _placeWork;
        }

        //Ввод данных в класс вручную
        public void Init(string _firstName, string _secondName, char _gender, double _salary, string _placeWork)
        {
            base.Init(_firstName, _secondName, _gender);
            Salary = _salary;
            PlaceWork = _placeWork;
        }

        //Ввод данных в класс автоматически
        public override void RandomInit()
        {
            base.RandomInit();

            Random random = new Random();
            salary = (double)random.Next(30000);

            switch (random.Next(1, 6))
            {
                case 1:
                    {
                        placeWork = "ПНИПУ";
                        break;
                    }
                case 2:
                    {
                        placeWork = "ПГНИУ";
                        break;
                    }
                case 3:
                    {
                        placeWork = "ПГМУ";
                        break;
                    }
                case 4:
                    {
                        placeWork = "ПГГПУ";
                        break;
                    }
                case 5:
                    {
                        placeWork = "НИУ ВШЭ в Перми";
                        break;
                    }
                case 6:
                    {
                        placeWork = "Пермский ГАТУ";
                        break;
                    }
            }
        }

        //метод для сравнения объектов
        public override bool Equals(object obj)
        {
            if (obj is Employee employee)
            {
                return  FirstName == employee.FirstName
                        && SecondName == employee.SecondName
                        && Gender == employee.Gender
                        && Salary == employee.Salary
                        && PlaceWork == employee.PlaceWork;
            }
            else
                return false;
        }

        public override string ToString()
        {
            return base.ToString()  + $"\nМесто работы: {placeWork}\n" 
                                    + $"Зарплата: {salary}";
        }

        //вывод на экран как виртуальный метод
        public override void Show()
        {
            base.Show();
            Console.WriteLine(  $"Место работы: {placeWork}\n" +
                                $"Зарплата: {salary}");
        }

        //вывод на экран как перегрузка
        public new void ShowOverload()
        {
            base.ShowOverload();
            Console.WriteLine(  $"Место работы: {placeWork}\n" +
                                $"Зарплата: {salary}");
        }
    }
}
