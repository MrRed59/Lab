#include <iostream>
#include<vector>
#include<cstdlib>

typedef std::vector<float>Vec; //определить тип для работы с вектором
Vec make_vector(int n) //функция для формирования вектора
{
    Vec v; //пустой вектор
    for (int i = 0; i < n; i++)
    {
        float a = rand() % 100 - 50;
        v.push_back(a); //добавить а в конец вектора
    }
    return v;
}

void print_vector(const Vec& v)
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

int arithmetic_mean(const Vec& v)
{
    float s = 0;

    for (size_t i = 0; i < v.size(); i ++) //перебор вектора
    {
        s += v[i];
    }
    float n = v.size(); //кол-во элементов в векторе
    return s / n;
}

void add_vector(Vec& v, int el, int pos)
{
    v.insert(v.begin() + pos, el); //добавить на место pos элемент el
}

int max(const Vec& v)
{
    int m = v[0]; //мин. элемент
    int n = 0; //номер мик. элемента
    for (size_t i = 0; i < v.size(); i++)
    {
        if (m < v[i])
        {
            m = v[i]; //макс. элемент
            n = i; //номер макс. элемента
        }
    }
    return n;
}

void del_vector(Vec& v, int pos) //удалить элемент из позиции pos
{
    v.erase(v.begin() + pos);
}

int min(const Vec& v) //поиск минимального элемента
{
    int m = v[0]; //мин. элемент
    int n = 0; //номер мик. элемента
    for (size_t i = 0; i < v.size(); i++)
    {
        if (m > v[i])
        {
            m = v[i]; //мин. элемент
            n = i; //номер мик. элемента
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
        std::vector<float> v;
        std::vector<float>::iterator vi = v.begin();
        int n;
        std::cout << "N? ";
        std::cin >> n;
        v = make_vector(n); //формирование вектора
        print_vector(v); //печать вектора

        int el = arithmetic_mean(v); //вычисление средне - арифметического значения
        std::cout << "Position? ";
        int pos;
        std::cin >> pos;

        if (pos > v.size()) //генерируется ошибка, если позиция для вставки больше размера вектора
            throw 1;

        add_vector(v, el, pos); //вызов функции для добавления
        std::cout << "add_vector: " << std::endl;
        print_vector(v); //печать вектора

        //

        int n_max = max(v); //поиск номера максимального элемента
        del_vector(v, n_max); //удалить элемент с этим номером
        std::cout << "del_vector: " << std::endl;
        print_vector(v);

        //

        division(v); //каждый элемент разделить на мин. значение вектора
        std::cout << "division: " << std::endl;
        print_vector(v);
    }
    catch (int)
    {
        std::cout << "Error!" << std::endl;
    }

    return 0;
}
