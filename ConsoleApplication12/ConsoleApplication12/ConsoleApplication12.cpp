#include <iostream>
#include<ctime>
#include<ctype.h>
#include<conio.h>

using namespace std;

int GetRand(int n)
{
    return rand() % n;
}

void CreateArray(int**& arr_fst, int **&arr_last, const short& size_rows, const short &size_cols) // создание двумерных массивов (arr_last имеет размерность на одну меньше, чем arr_fst)
{
    for (int i = 0; i < size_rows; i++)
    {
        arr_fst[i] = new int[size_cols];
        arr_last[i] = new int[size_cols - 1];
    }
}

void FillArray(int**& arr_fst, const short& size_rows, const short& size_cols) //заполнение массива случайными числами
{
    for (int i = 0; i < size_rows; i++)
    {
        for (int j = 0; j < size_cols; j++)
        {
            arr_fst[i][j] = GetRand(100);
        }
    }
}

void ShowArray(int **& const arr, const short& size_rows, const short& size_cols) //вывод массива на экран
{
    for (int i = 0; i < size_rows; i++)
    {
        for (int j = 0; j < size_cols; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void Change(short &num) // выбор столбца для удаления
{
    for (bool i = false; i != true;)
    {
        cout << "Какой столбец удалить? " << endl;
        num = _getche();
        cout << endl;
        if (num < 48 || num > 58)
            cout << "Ошибка. Введите число от 0 до 9" << endl;
        else
        {
            i = true;
            num -= 49;
        }
    }
}

void pop_back(int**& arr_fst, int**& arr_last, const short& size_rows, const short& size_cols, const short &num) // перенос данных из arr_fst в arr_last
{
    for (int i = 0; i < size_rows; i++)
    {
        for (int j = 0; j < (size_cols-1); j++) 
        {
            if (num > j) // если выбранный столбец больше, чем итератор цикла, то присваивание значений напрямую
                arr_last[i][j] = arr_fst[i][j];
            else // иначе присваивание следующего элемента строки в исходном массиве
                arr_last[i][j] = arr_fst[i][j+1];
        }
    }
}


void main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));

    short size_cols, size_rows; // объявляем переменные. size_cols - количество колонок массива, size_rows - количество столбцов

    cout << "Введите количество строк массива\n";
    cin >> size_rows;

    cout << "Введите количество столбцов массива\n";
    cin >> size_cols;

    int** arr_fst = new int* [size_rows], **arr_last = new int*[size_rows]; /*объявляем массивы.arr_fst - изначальный массив
    arr_last - промежуточный массив*/
    

    CreateArray(arr_fst, arr_last, size_rows, size_cols);

    FillArray(arr_fst, size_rows, size_cols);

    cout << "Двумерный массив: " << endl;

    ShowArray(arr_fst, size_rows, size_cols);

    cout << endl << endl;

    short num = 0; // переменная для выбранного числа

    Change(num);

    pop_back(arr_fst, arr_last, size_rows, size_cols, num);

    for (int i = 0; i < size_rows; i++) // цикл для удаление одномерных массивов двумерного динамического массива
    {
        delete[] arr_fst[i];
    }

    delete[] arr_fst; // очистка памяти от двумерного массива

    arr_fst = arr_last; // присваивание адреса полученного массива исходному
    size_cols--; // декремент переменной (для уменьшения количества столбцов на один)

    ShowArray(arr_fst, size_rows, size_cols);

    for (int i = 0; i < size_rows; i++) // цикл для удаление одномерных массивов двумерного динамического массива
    {
        delete[] arr_fst[i];
    }
    delete[] arr_fst; // очистка памяти от двумерного массива 
}