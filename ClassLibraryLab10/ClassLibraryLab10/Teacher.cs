using System;

namespace ClassLibraryLab10
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

        //Ввод данных в класс вручную
        public void Init(string _firstName, string _secondName, double _salary, string _placeWork, string _subjectTaught)
        {
            base.Init(_firstName, _secondName, _salary, _placeWork);
            SubjectTaught = _subjectTaught;
        }

        //Ввод данных в класс автоматически
        public override void RandomInit()
        {
            base.RandomInit();

            Random random = new Random();
            switch (random.Next(6))
            {
                case 1:
                    {
                        subjectTaught = "Математика";
                        break;
                    }
                case 2:
                    {
                        subjectTaught = "Физика";
                        break;
                    }
                case 3:
                    {
                        subjectTaught = "Информатика";
                        break;
                    }
                case 4:
                    {
                        subjectTaught = "Биология";
                        break;
                    }
                case 5:
                    {
                        subjectTaught = "Философия";
                        break;
                    }
                case 6:
                    {
                        subjectTaught = "Социология";
                        break;
                    }
            }

        }

        //метод для сравнения объектов
        public override bool Equals(object obj)
        {
            if (obj is Teacher teacher)
            {
                return FirstName == teacher.FirstName
                        && SecondName == teacher.SecondName
                        && Salary == teacher.Salary
                        && PlaceWork == teacher.PlaceWork
                        && SubjectTaught == teacher.SubjectTaught;
            }
            else
                return false;
        }

        public override string ToString()
        {
            return base.ToString() + $"\nПреподаваемый предмет: {subjectTaught}";
        }

        //вывод на экран как виртуальный метод
        public override void Show()
        {
            base.Show();
            Console.WriteLine($"Преподаваемый предмет: {subjectTaught}");
        }

        //вывод на экран как перегрузка
        public new void ShowOverload()
        {
            base.ShowOverload();
            Console.WriteLine($"Преподаваемый предмет: {subjectTaught}");
        }
    }
}
