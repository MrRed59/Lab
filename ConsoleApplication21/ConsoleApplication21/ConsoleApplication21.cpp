#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
    //srand(time(NULL));
    setlocale(LC_ALL, "ru");
    const int N = 6;
    int num; //Обьявляем переменную, отвечающую за количество элементов массива
    int arr[N], arr_for_3[N - 1]; //Обьявляем два массива с n элементами (один - основной, второй - для 3 задания)
    cout << "Массив: ";
    for (int i = 0; i < N; i++) //Цикл для первого массива. присваиваем значения каждому элементу
    {
        arr[i] = rand() % 100 - 50;  //Присваиваем случайное число
        cout << arr[i] << "; ";
    }

    arr[3] = 0;

    cout << "\n";

    bool bolean = 0;

    for (int i = 0; i < N; i++)
    {
        if (arr[i] == 0)
        {
            bolean = 1;
            break;
        }
    }

    if (bolean)
    {
        for (int i = N - 1; i != -1; i--)
        {
            if (arr[i] == 0)
                bolean = 0;
            else if (!bolean)
            {
                arr_for_3[i] = arr[i];
            }
            else
                arr_for_3[i - 1] = arr[i];
        }

        for (int i = 0; i < N -1; i++)
        {
            cout << arr_for_3[i] << "; ";
        }

        bolean = 0;

        cout << "\nВведите номер элемента массива, перед которым необходимо поставить число \"100\": ";
        cin >> num;
        if (num > (N - 1) || num < 0)
            cout << "Ошибка. Не верный номер ячейки." << endl;
        else
        {
            for (int i = 0; i < N; i++) //Цикл для третьего массива. присваиваем значения каждому элементу до заданного индекса элемента
            {
                if (i == num)
                {
                    arr[i] = 100;
                    bolean = 1;
                    cout << arr[i] << "; ";
                }
                else if (!bolean)
                {
                    arr[i] = arr_for_3[i];
                    cout << arr[i] << "; ";
                }
                else
                {
                    arr[i] = arr_for_3[i - 1];
                    cout << arr[i] << "; ";
                }
            }
        }
    }
    else
    {
        cout << "Не найдены элементы с равные нулю" << endl;
        int arr_for_4[N + 1];
        bolean = 0;
        cout << "\nВведите номер элемента массива, перед которым необходимо поставить число \"100\": ";
        cin >> num;
        if (num > N || num < 0)
            cout << "Ошибка. Не верный номер ячейки." << endl;
        else
        {
            for (int i = 0; i < N + 1; i++) //Цикл для третьего массива. присваиваем значения каждому элементу до заданного индекса элемента
            {
                if (i == num)
                {
                    arr_for_4[i] = 100;
                    bolean = 1;
                    cout << arr_for_4[i] << "; ";
                }
                else if (!bolean)
                {
                    arr_for_4[i] = arr[i];
                    cout << arr_for_4[i] << "; ";
                }
                else
                {
                    arr_for_4[i] = arr[i - 1];
                    cout << arr_for_4[i] << "; ";
                }
            }
        }
    }
    return 0;
}