using System;

namespace Lab10_csharp
{
    class Teacher:Employee
    {
        protected string subjectTaught; //преподаваемый предмет

        public string SubjectTaught
        {
            get => subjectTaught;
            set
            {
                if (value.Length > 2)
                    subjectTaught = value;
                else
                {
                    Console.WriteLine("Ошибка. Преподаваемый предмет не может быть меньше 3 символов");
                    subjectTaught = "-";
                }
            }
        }

        //конструктор без параметров
        public Teacher():base()
        {
            subjectTaught = "-";
        }

        //конструктор с параметрами
        public Teacher( string _firstName, string _secondName, double _salary, string _placeWork, string _subjectTaught) 
                        :base(_firstName, _secondName, _salary, _placeWork)
        {
            SubjectTaught = _subjectTaught;
        }

        //вывод на экран
        public override void Show()
        {
            base.Show();
            Console.WriteLine($"Преподаваемый предмет: {subjectTaught}");
        }
    }
}
