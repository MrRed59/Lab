using System;

namespace ClassLibraryLab10
{
    public class Student :Person
    {
        protected ushort averageGrade;      //средний балл
        protected string educInstitution;   //учебное заведение

        public ushort AverageGrade
        {
            get => averageGrade;
            set
            {
                if (value >= 2 && value <= 5)
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
                if (value.Length > 2)
                    educInstitution = value;
                else
                {
                    Console.WriteLine("Ошибка. Учебное заведение не может быть меньше 3 символов");
                    educInstitution = "-";
                }
            }
        }

        //конструктор без параметров
        public Student() : base()
        {
            averageGrade = 2;
            educInstitution = "-";
        }

        //конструктор с параметрами
        public Student(string _firstName, string _secondName, ushort _averageGrade, string _educInstitution) : base(_firstName, _secondName)
        {
            AverageGrade = _averageGrade;
            EducInstitution = _educInstitution;
        }

        //Ввод данных в класс вручную
        public void Init(string _firstName, string _secondName, ushort _averageGrade, string _educInstitution)
        {
            base.Init(_firstName, _secondName);
            AverageGrade = _averageGrade;
            EducInstitution = _educInstitution;
        }

        //Ввод данных в класс автоматически
        public override void RandomInit()
        {
            base.RandomInit();

            Random random = new Random();
            averageGrade = (ushort)random.Next(2,5);

            switch (random.Next(6))
            {
                case 1:
                    {
                        educInstitution = "ПНИПУ";
                        break;
                    }
                case 2:
                    {
                        educInstitution = "ПГНИУ";
                        break;
                    }
                case 3:
                    {
                        educInstitution = "ПГМУ";
                        break;
                    }
                case 4:
                    {
                        educInstitution = "ПГГПУ";
                        break;
                    }
                case 5:
                    {
                        educInstitution = "НИУ ВШЭ в Перми";
                        break;
                    }
                case 6:
                    {
                        educInstitution = "Пермский ГАТУ";
                        break;
                    }
            }
        }

        //метод для сравнения объектов
        public override bool Equals(object obj)
        {
            if (obj is Student student)
            {
                return  FirstName == student.FirstName 
                        && SecondName == student.SecondName 
                        && AverageGrade == student.AverageGrade 
                        && EducInstitution == student.EducInstitution;
            }
            else
                return false;
        }

        public override string ToString()
        {
            return base.ToString()  + $"\nУчебное заведение: {educInstitution}\n"
                                    + $"Средний балл: {averageGrade}";
        }

        //вывод на экран как виртуальный метод
        public override void Show()
        {
            base.Show();
            Console.WriteLine(  $"Учебное заведение: {educInstitution}\n" 
                                + $"Средний балл: {averageGrade}");
        }

        //вывод на экран как перегрузка
        public new void ShowOverload()
        {
            base.ShowOverload();
            Console.WriteLine(  $"Учебное заведение: {educInstitution}\n" +
                                $"Средний балл: {averageGrade}");
        }
    }
}
