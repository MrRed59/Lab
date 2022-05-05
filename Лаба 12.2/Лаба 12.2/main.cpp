#include<iostream>
#include"Money.h"
#include<map>

typedef std::map<int, Money> TMap;
typedef TMap::iterator it;

TMap make_map(size_t n)
{
	TMap m;
	Money a;
	for (size_t i = 0; i < n; i++) //создать пару и добавить её в словарь
	{
		std::cin >> a;
		m.insert(std::make_pair(i, a));
	}
	return m;
}

void print_map(TMap m)
{
	for (size_t i = 0; i < m.size(); i++)
		std::cout << i << " : " << m[i] << " " << std::endl;
}

Money arithmetic_mean(TMap v)
{
	Money s{};
	for (size_t i = 0; i < v.size(); i++)
		s += v[i];
	return s / v.size();
}

int Max(TMap v)
{
	it i = v.begin();
	int num_max{}, k{}; //номер максимального и счетчик элементов
	Money m = i->second; //значение первого элемента
	while (i != v.end())
	{
		if (m < (*i).second)
		{
			m = (*i).second;
			num_max = k;
		}
		i++;
		k++;
	}
	return num_max;
}

int Min(TMap v)
{
	it i = v.begin();
	int num_min{}, k{}; //номер максимального и счетчик элементов
	Money m = i->second; //значение первого элемента
	while (i != v.end())
	{
		if (m > (*i).second)
		{
			m = (*i).second;
			num_min = k;
		}
		i++;
		k++;
	}
	return num_min;
}

void division(TMap& v)
{
	Money m = v[Min(v)];
	for (size_t i = 0; i < v.size(); i++)
		v[i] = v[i] / m;
}


int main()
{
	size_t n{};
	std::cout << "N? ";
	std::cin >> n;

	TMap m = make_map(n); //создать словарь
	print_map(m);

	Money el = arithmetic_mean(m); //вычислить среднее значение
	std::cout << "Arithmetic mean: " << el << std::endl;
	m.insert(std::make_pair(n, el)); //добавить в конец
	print_map(m);

	int max = Max(m);
	std::cout << "Max: " << m[max] << "; num:" << max << std::endl;
	m.erase(max);
	print_map(m);

	int min = Min(m);
	std::cout << "Min: " << m[min] << "; num:" << min << std::endl;
	division(m);
	print_map(m);

	return 0;
}