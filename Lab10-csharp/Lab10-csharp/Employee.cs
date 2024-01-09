using System;

namespace Lab10_csharp
{
    class Employee:Person
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
        public void Init(string _firstName, string _secondName, double _salary, string _placeWork)
        {
            base.Init(_firstName, _secondName);
            Salary = _salary;
            PlaceWork = _placeWork;
        }

        //Ввод данных в класс автоматически
        public override void RandomInit()
        {
            base.RandomInit();

            Random random = new Random();
            salary = (double)random.Next(30000);

            switch (random.Next(6))
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

        //вывод на экран
        public override void Show()
        {
            base.Show();
            Console.WriteLine(  $"Место работы: {placeWork}\n" +
                                $"Зарплата: {salary}");
        }
    }
}
