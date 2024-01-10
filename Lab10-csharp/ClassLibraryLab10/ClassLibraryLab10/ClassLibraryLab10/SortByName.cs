using System;
using System.Collections;

namespace ClassLibraryLab10
{
    public class SortByName: IComparer
    {
        public int Compare(object x, object y)
        {
            Person pX = (Person)x;
            Person pY = (Person)y;
            if (pX is null || pY is null)
                throw new ArgumentException("Некорректное значение параметра");

            if (pX.Age < pY.Age)
                return -1;

            if (pX.Age == pY.Age)
                return 0;
            else
                return 1;
        }
    }
}
