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
            Salary = 0;
            placeWork = "-";
        }

        //конструктор с параметрами
        public Employee(string _firstName, string _secondName, double _salary, string _placeWork) :base(_firstName, _secondName)
        {
            Salary = _salary;
            PlaceWork = _placeWork;
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
