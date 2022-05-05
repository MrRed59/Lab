#include<iostream>
#include<map>

typedef std::map<int, int> TMap;
typedef TMap::iterator it;

TMap make_map(size_t n)
{
	TMap m;
	int a;
	for (size_t i = 0; i < n; i++) //создать пару и добавить её в словарь
	{
		std::cout << "value: ";
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

int arithmetic_mean(TMap v)
{
	int s{};
	for (size_t i = 0; i < v.size(); i++)
		s += v[i];
	//int n = v.size();
	return s / v.size(); 
}

int Max(TMap v)
{
	it i = v.begin();
	int num_max{}, k{}; //номер максимального и счетчик элементов
	int m = i->second; //значение первого элемента
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
	int m = i->second; //значение первого элемента
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
	int m = v[Min(v)];
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

	int el = arithmetic_mean(m); //вычислить среднее значение
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