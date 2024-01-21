using System;

namespace ClassLibraryLab10
{
    public class Student :Person
    {
        protected float averageGrade;      //средний балл
        protected string educInstitution;   //учебное заведение

        public float AverageGrade
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
        public Student( string _firstName, string _secondName, char _gender, byte _age, float _averageGrade, string _educInstitution) 
                        : base(_firstName, _secondName,  _gender, _age)
        {
            AverageGrade = _averageGrade;
            EducInstitution = _educInstitution;
        }

        public override object Clone() => new Student(FirstName, SecondName, Gender, Age , AverageGrade, EducInstitution);

        public override object ShallowCopy() => (Student)MemberwiseClone();

        //Ввод данных в класс вручную
        public override void Init()
        {
            base.Init();
            Console.Write("Введите средний балл: ");
            AverageGrade = (ushort)ReadAndConvToUInt();
            Console.Write("Введите место учебы: ");
            EducInstitution = Console.ReadLine();
        }

        //Ввод данных в класс автоматически
        public override void RandomInit()
        {
            base.RandomInit();

            Random random = new Random();
            averageGrade = (float)Math.Round(((double)random.NextDouble() * (5 - 2) + 2), 2);

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
                default:
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
                        && Gender == student.Gender
                        && Age == student.Age
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
