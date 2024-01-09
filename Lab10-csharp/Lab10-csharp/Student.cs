using System;

namespace Lab10_csharp
{
    class Student:Person
    {
        protected ushort averageGrade;      //средний балл
        protected string educInstitution;   //учебное заведение

        public ushort AverageGrade
        {
            get => averageGrade;
            set
            {
                if (averageGrade >= 2 && averageGrade <= 5)
                    averageGrade = value;
                else
                {
                    Console.WriteLine("Ошибка. Средний балл не может быть менее 2 и не более 5");
                    averageGrade = 2;
                }
            }
        }

        public string EducInstitution
        {
            get => educInstitution;
            set
            {
                if (educInstitution.Length > 2)
                    educInstitution = value;
                else
                {
                    Console.WriteLine("Ошибка. Учебное заведение не может быть меньше 3 символов");
                    educInstitution = "";
                }
            }
        }

        //конструктор без параметров
        public Student() : base()
        {
            averageGrade = 2;
            educInstitution = "";
        }

        //конструктор с параметрами
        public Student(string _firstName, string _secondName, ushort _averageGrade, string _educInstitution) : base(_firstName, _secondName)
        {
            AverageGrade = _averageGrade;
            EducInstitution = _educInstitution;
        }

        //вывод на экран
        public void Show()
        {
            base.Show();
            Console.WriteLine(  $"Учебное заведение: {educInstitution}\n" +
                                $"Средний балл: {averageGrade}");
        }
    }
}
