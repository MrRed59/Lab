#include <iostream>
#include<vector>
#include<cstdlib>

typedef std::vector<int>Vec; //определяем тип для работы с вектором
Vec make_vector(int n) //функция для формирования вектора
{
    Vec v; //пустой вектор
    for (int i = 0; i < n; i++)
    {
        int a = rand() % 100 - 50;
        v.push_back(a); //добавляем а в конец вектора
    }
    return v;
}

void print_vector(Vec v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        if (i)
            std::cout << ';' << v[i];
        else
            std::cout << v[i];
    }
    std::cout << "." << std::endl;
}

int arithmetic_mean(Vec v)
{
    int s = 0;

    for (size_t i = 0; i < v.size(); i ++) //перебор вектора
    {
        s += v[i];
    }
    int n = v.size(); //количество элментов вектора
    return s / n;
}

void add_vector(Vec& v, int el, int pos)
{
    v.insert(v.begin() + pos, el); //добавляем на место pos элемент el
}

int max(Vec v)
{
    int m = v[0];
    int n = 0;
    for (size_t i = 0; i < v.size(); i++)
    {
        if (m < v[i])
        {
            m = v[i];
            n = i;
        }
    }
    return n;
}

void del_vector(Vec& v, int pos)
{
    v.erase(v.begin() + pos);
}

int min(const Vec& v)
{
    int m = v[0];
    int n = 0;
    for (size_t i = 0; i < v.size(); i++)
    {
        if (m > v[i])
        {
            m = v[i];
            n = i;
        }
    }
    return n;
}

void division(Vec& v)
{
    int m = min(v);
    for (size_t i = 0; i < v.size(); i++)
    {
        v[i] /= v[m];
    }
}


int main()
{
    try
    {
        std::vector<int> v;
        std::vector<int>::iterator vi = v.begin();
        int n;
        std::cout << "N? ";
        std::cin >> n;
        v = make_vector(n); //формирование вектора
        print_vector(v); //печать вектора

        int el = arithmetic_mean(v); //вычисление среднего - арифметического значения
        std::cout << "Position? ";
        int pos;
        std::cin >> pos;

        if (pos > v.size()) //если позиция вставки больше размера вектора
            throw 1;

        add_vector(v, el, pos); //вызов функции для добавления
        std::cout << "add_vector: " << std::endl;
        print_vector(v); //печать вектора

        //

        int n_max = max(v); //найти номер максимального
        del_vector(v, n_max); //удалить элемент с таким номером
        std::cout << "del_vector: " << std::endl;
        print_vector(v);

        //

        division(v); //каждый элемент разделить на минимальное значение вектора
        std::cout << "division: " << std::endl;
        print_vector(v);
    }
    catch (int)
    {
        std::cout << "Error!" << std::endl;
    }

    return 0;
}