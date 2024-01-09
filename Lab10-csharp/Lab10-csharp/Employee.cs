using System;

namespace Lab10_csharp
{
    class Employee:Person
    {
        protected double salary;

        protected double Salary { get; set; }

        //конструктор без параметров
        public Employee(): base()
        {
            Salary = 0;
        }

        //конструктор с параметрами
        public Employee(string _firstName, string _secondName, double _salary) :base(_firstName, _secondName)
        {
            Salary = _salary;
        }

        //вывод на экран
        public void Show()
        {
            base.Show();
            Console.WriteLine($"Зарплата: {salary}");
        }
    }
}
