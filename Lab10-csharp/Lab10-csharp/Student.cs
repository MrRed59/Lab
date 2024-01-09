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
                while (true)
                {
                    Console.Write("Средний балл: ");
                    if (averageGrade >= 2)
                    {
                        averageGrade = value;
                        break;
                    }
                    else
                        Console.WriteLine("Ошибка. Средний балл не может быть меньше 2");
                }
            }
        }

        public string EducInstitution
        {
            get => educInstitution;
            set
            {
                while (true)
                {
                    Console.Write("Учебное заведение: ");
                    if (educInstitution.Length > 3)
                    {
                        educInstitution = value;
                        break;
                    }
                    else
                        Console.WriteLine("Ошибка. Учебное заведение не может быть меньше 3 символов");
                }
            }
        }
    }
}
