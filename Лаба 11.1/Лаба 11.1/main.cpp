#include <iostream>
#include<vector>
#include<cstdlib>

typedef std::vector<int>Vec; //���������� ��� ��� ������ � ��������
Vec make_vector(int n) //������� ��� ������������ �������
{
    Vec v; //������ ������
    for (int i = 0; i < n; i++)
    {
        int a = rand() % 100 - 50;
        v.push_back(a); //��������� � � ����� �������
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

    for (size_t i = 0; i < v.size(); i ++) //������� �������
    {
        s += v[i];
    }
    int n = v.size(); //���������� �������� �������
    return s / n;
}

void add_vector(Vec& v, int el, int pos)
{
    v.insert(v.begin() + pos, el); //��������� �� ����� pos ������� el
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
        v = make_vector(n); //������������ �������
        print_vector(v); //������ �������

        int el = arithmetic_mean(v); //���������� �������� - ��������������� ��������
        std::cout << "Position? ";
        int pos;
        std::cin >> pos;

        if (pos > v.size()) //���� ������� ������� ������ ������� �������
            throw 1;

        add_vector(v, el, pos); //����� ������� ��� ����������
        std::cout << "add_vector: " << std::endl;
        print_vector(v); //������ �������

        //

        int n_max = max(v); //����� ����� �������������
        del_vector(v, n_max); //������� ������� � ����� �������
        std::cout << "del_vector: " << std::endl;
        print_vector(v);

        //

        division(v); //������ ������� ��������� �� ����������� �������� �������
        std::cout << "division: " << std::endl;
        print_vector(v);
    }
    catch (int)
    {
        std::cout << "Error!" << std::endl;
    }

    return 0;
}