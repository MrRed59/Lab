#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
    //srand(time(NULL));
    setlocale(LC_ALL, "ru");
    const int N = 20;
    int num, change = 0; //Обьявляем переменную, отвечающую за количество элементов массива
    int arr[N], arr_for_3[N - 1]; //Обьявляем два массива с n элементами (один - основной, второй - для 3 задания, третий - для 4 задания)
    cout << "Массив: ";
    for (int i = 0; i < N; i++) //Цикл для первого массива. присваиваем значения каждому элементу
    {
        arr[i] = rand() % 100 - 50;  //Присваиваем случайное число
        cout << arr[i] << "; ";
    }

    cout << "\n";

    //cout << "Введите число, которое убрать из массива: ";
    //cin >> change;

    bool bolean = 0;

    for (int i = N - 1; i < N; i--)
    {
        if (arr[i] != change)
        {
            if (bolean && i != change)
                arr[i] = arr_for_3[i-1];
            else
                arr[i] = arr_for_3[i];
        }
        else
            bolean = 1;

        if (!bolean && i == 0)
        {
            cout << "Не найдено символов с значением \'0\'. Введите число, которое убрать из массива: ";
            cin >> change;
            i = N - 1;
        }
    }

    cout << "\nВведите номер элемента массива, перед которым необходимо поставить число \"100\": ";
    cin >> num;
    for (int i = 0; i < N; i++) //Цикл для третьего массива. присваиваем значения каждому элементу до заданного индекса элемента
    {    
        if (i = num)
        {
            arr[i] = 100;
        }
        else
        {
            arr[i] = arr_for_3[i];
            cout << arr[i] << "; ";
        }
    }
    //for (int i = num + 1; N < i; i++) //Цикл для присваивания значения каждому элементу
    //{
    //    if ()
    //        arr[i] = 100;
    //    else
    //        arr[i] = arr_for_3[ - 1];
    //    cout << arr[i] << "; ";
    //}
    return 0;
}