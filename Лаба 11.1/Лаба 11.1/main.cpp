#include <iostream>
#include<vector>
#include<cstdlib>

typedef std::vector<int>Vec; //îïðåäåëÿåì òèï äëÿ ðàáîòû ñ âåêòîðîì
Vec make_vector(int n) //ôóíêöèÿ äëÿ ôîðìèðîâàíèÿ âåêòîðà
{
    Vec v; //ïóñòîé âåêòîð
    for (int i = 0; i < n; i++)
    {
        int a = rand() % 100 - 50;
        v.push_back(a); //äîáàâëÿåì à â êîíåö âåêòîðà
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
    int s = 0;

    for (size_t i = 0; i < v.size(); i ++) //ïåðåáîð âåêòîðà
    {
        s += v[i];
    }
    int n = v.size(); //êîëè÷åñòâî ýëìåíòîâ âåêòîðà
    return s / n;
}

void add_vector(Vec& v, int el, int pos)
{
    v.insert(v.begin() + pos, el); //äîáàâëÿåì íà ìåñòî pos ýëåìåíò el
}

int max(const Vec& v)
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
        v = make_vector(n); //ôîðìèðîâàíèå âåêòîðà
        print_vector(v); //ïå÷àòü âåêòîðà

        int el = arithmetic_mean(v); //âû÷èñëåíèå ñðåäíåãî - àðèôìåòè÷åñêîãî çíà÷åíèÿ
        std::cout << "Position? ";
        int pos;
        std::cin >> pos;

        if (pos > v.size()) //åñëè ïîçèöèÿ âñòàâêè áîëüøå ðàçìåðà âåêòîðà
            throw 1;

        add_vector(v, el, pos); //âûçîâ ôóíêöèè äëÿ äîáàâëåíèÿ
        std::cout << "add_vector: " << std::endl;
        print_vector(v); //ïå÷àòü âåêòîðà

        //

        int n_max = max(v); //íàéòè íîìåð ìàêñèìàëüíîãî
        del_vector(v, n_max); //óäàëèòü ýëåìåíò ñ òàêèì íîìåðîì
        std::cout << "del_vector: " << std::endl;
        print_vector(v);

        //

        division(v); //êàæäûé ýëåìåíò ðàçäåëèòü íà ìèíèìàëüíîå çíà÷åíèå âåêòîðà
        std::cout << "division: " << std::endl;
        print_vector(v);
    }
    catch (int)
    {
        std::cout << "Error!" << std::endl;
    }

    return 0;
}
