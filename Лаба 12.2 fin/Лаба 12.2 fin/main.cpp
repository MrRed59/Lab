#include<iostream>
#include<set>
#include"Money.h"

typedef std::multiset<Money> TMSet;
typedef TMSet::iterator it;

TMSet make_multiset(size_t n)
{
	TMSet m;
	Money money;
	for (size_t i = 0; i < n; i++) //создать элемент и добавить его в множество
	{
		std::cin >> money;
		m.insert(money);
	}
	return m;
}

void print_multiset(const TMSet& m)
{
	for (auto& item : m)
		std::cout << item << ": ";
}

Money arithmetic_mean(const TMSet& m)
{
	it i = m.begin();
	Money s{};
	for (size_t j = 0; j < m.size(); j++, i++)
		s += *i;
	return s / m.size(); 
}

it Max(const TMSet& m)
{
	auto iter = m.end();
	return (--iter);
}

it Min(const TMSet& m)
{
	auto iter = m.begin();
	return iter;
}

void division(TMSet& m)
{
	Money min = *Min(m);

	if (min == 0)
	{
		std::cout << "Error! Minimum value = 0.\nDivision failed." << std::endl;
		return;
	}

	it iter = m.begin();

	Money* arr = new Money[m.size()];

	size_t size = m.size();

	for (size_t i = 0; i < m.size(); i++, iter++)
	{
		arr[i] = *iter;
		arr[i] /= min;
	}

	m.clear();

	for (size_t i = 0; i < size; i++)
	{
		m.insert(arr[i]);
	}
	delete[] arr;
}

void add_min_el(TMSet& m)
{
	m.insert(*Min(m));
}

void remove_element_by_index(TMSet& m, size_t pos)
{
	if (pos > m.size())
	{
		std::cout << "Error. Position > size" << std::endl;
		return;
	}
	it i = m.begin();
	for (size_t j = 0; j < pos; i++, j++);
	m.erase(i);
}

void add_sum_max_min(TMSet& m)
{
	Money sum = *Min(m);
	sum += *Max(m);

	it iter = m.begin();

	Money* arr = new Money[m.size()];

	size_t size = m.size();

	for (size_t i = 0; i < m.size(); i++, iter++)
	{
		arr[i] = *iter;
		arr[i] += sum;
	}

	m.clear();

	for (size_t i = 0; i < size; i++)
	{
		m.insert(arr[i]);
	}
	delete[] arr;
}


int main()
{
	size_t n{};
	std::cout << "N? ";
	std::cin >> n;

	TMSet m = make_multiset(n); //создать словарь
	print_multiset(m);

	Money el = arithmetic_mean(m); //вычислить среднее значение
	std::cout << "\nArithmetic mean: " << el << std::endl;
	m.insert(el); //добавить в конец
	print_multiset(m);

	Money max = *Max(m);
	std::cout << "\nMax: " << max << std::endl;
	m.erase(max);
	print_multiset(m);

	Money min = *Min(m);
	std::cout << "\nMin: " << min << std::endl;
	std::cout << "\Division: " << std::endl;
	division(m);
	print_multiset(m);

	add_min_el(m);
	std::cout << "\nAdd minimal element: " << std::endl;
	print_multiset(m);

	std::cout << "\nWhich element should i delete? " << std::endl;
	Money value;
	std::cin >> value;
	m.erase(value);
	print_multiset(m);

	std::cout << "\nWhich position should i delete? " << std::endl;
	size_t pos;
	std::cin >> pos;
	remove_element_by_index(m, pos);
	print_multiset(m);

	std::cout << "\nAdd the sum of the minimum and maximum elements to each element: " << std::endl;
	add_sum_max_min(m);
	print_multiset(m);

	return 0;
}
