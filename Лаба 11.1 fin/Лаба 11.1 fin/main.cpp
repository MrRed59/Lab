#include <iostream>
#include<vector>
#include<cstdlib>

typedef std::vector<float>Vec; //определить тип для работы с вектором
Vec make_vector(int n) //функция для формирования вектора
{
    Vec v; //пустой вектор
    for (int i = 0; i < n; i++)
    {
        //srand(unsigned(time(0)));

        float a = ((float)rand() / RAND_MAX) + rand() % 100 - 50;

        v.push_back(a); //добавить а в конец вектора
    }
    return v;
}

void print_vector(const Vec& v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        if (i)
            std::cout << "; \t" << v[i];
        else
            std::cout << v[i];
    }
    std::cout << "." << std::endl;
}

float arithmetic_mean(const Vec& v)
{
    float s = 0;

    for (size_t i = 0; i < v.size(); i ++) //перебор вектора
    {
        s += v[i];
    }
    float n = v.size(); //кол-во элементов в векторе
    return s / n;
}

void add_vector(Vec& v, float el, int pos)
{
    v.insert(v.begin() + pos, el); //добавить на место pos элемент el
}

//int max(const Vec& v)
//{
//    int m = v[0]; //мин. элемент
//    int n = 0; //номер мин. элемента
//    for (size_t i = 0; i < v.size(); i++)
//    {
//        if (m < v[i])
//        {
//            m = v[i]; //макс. элемент
//            n = i; //номер макс. элемента
//        }
//    }
//    return n;
//}

void remove_element_by_index(Vec& v, int pos) //удалить элемент из позиции pos
{
    v.erase(v.begin() + pos);
}

int min(const Vec& v) //поиск минимального элемента
{
    float m = v[0]; //мин. элемент
    int n = 0; //номер мин. элемента
    for (size_t i = 0; i < v.size(); i++)
    {
        if (m > v[i])
        {
            m = v[i]; //мин. элемент
            n = i; //номер мин. элемента
        }
    }
    return n;
}

void subtract_min_element(Vec& v)
{
    int m = min(v);
    float min_element = v[m];
    for (size_t i = 0; i < v.size(); i++)
    {
        v[i] -= min_element;
    }
}

void add_to_the_end_of_the_vector(Vec& v)
{
    int m = min(v);
    v.push_back(v[m]);
}




int main()
{
    srand(unsigned(time(0)));

    try
    {
        std::vector<float> v;
        std::vector<float>::iterator vi = v.begin();
        int n;
        std::cout << "N? ";
        std::cin >> n;
        v = make_vector(n); //формирование вектора
        print_vector(v); //печать вектора

        float el = arithmetic_mean(v); //вычисление средне - арифметического значения
        std::cout << "\nPosition for adding an element? ";
        int pos;
        std::cin >> pos;

        if (pos > v.size()) //генерируется ошибка, если позиция для вставки больше размера вектора
            throw 1;

        add_vector(v, el, pos); //вызов функции для добавления
        std::cout << "\nadd_vector: " << std::endl;
        print_vector(v); //печать вектора

        //

        std::cout << "\nPosition to delete an element? ";
        std::cin >> pos;

        remove_element_by_index(v, pos); //удалить элемент с этим номером
        std::cout << "\nRemove element by index: " << std::endl;
        print_vector(v);

        //

        subtract_min_element(v); //каждый элемент разделить на мин. значение вектора
        std::cout << "\nSubtract min element: " << std::endl;
        print_vector(v);
    }
    catch (int)
    {
        std::cout << "Error!" << std::endl;
    }

    return 0;
}
