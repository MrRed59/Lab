#include<iostream>
#include"Container.h"
#include"Money.h"

//TMSet make_multiset(size_t n)
//{
//	TMSet m;
//	Money money;
//	for (size_t i = 0; i < n; i++) //создать элемент и добавить его в множество
//	{
//		std::cin >> money;
//		m.insert(money);
//	}
//	return m;
//}

//void print_multiset(const TMSet& m)
//{
//	for (auto& item : m)
//		std::cout << item << ": ";
//}

//Money arithmetic_mean(const TMSet& m)
//{
//	it i = m.begin();
//	Money s{};
//	for (size_t j = 0; j < m.size(); j++, i++)
//		s += *i;
//	return s / m.size(); 
//}

//it Max(const TMSet& m)
//{
//	auto iter = m.end();
//	return (--iter);
//}
//
//it Min(const TMSet& m)
//{
//	auto iter = m.begin();
//	return iter;
//}

//void division(TMSet& m)
//{
//	Money min = *Min(m);
//
//	if (min == 0)
//	{
//		std::cout << "Error! Minimum value = 0.\nDivision failed." << std::endl;
//		return;
//	}
//
//	it iter = m.begin();
//
//	Money* arr = new Money[m.size()];
//
//	size_t size = m.size();
//
//	for (size_t i = 0; i < m.size(); i++, iter++)
//	{
//		arr[i] = *iter;
//		arr[i] /= min;
//	}
//
//	m.clear();
//
//	for (size_t i = 0; i < size; i++)
//	{
//		m.insert(arr[i]);
//	}
//	delete[] arr;
//}

//void add_min_el(TMSet& m)
//{
//	m.insert(*Min(m));
//}

//void remove_element_by_index(TMSet& m, size_t pos)
//{
//	size_t value = m.size();
//
//	if (pos > value)
//	{
//		std::cout << "Error. Position > size" << std::endl;
//	}
//
//
//	if (pos > m.size())
//	{
//		std::cout << "Error. Position > size" << std::endl;
//		return;
//	}
//
//
//
//	it i = m.begin();
//	for (size_t j = 0; j < pos; i++, j++);
//	m.erase(i);
//}
//
//void add_sum_max_min(TMSet& m)
//{
//	Money sum = *Min(m);
//	sum += *Max(m);
//
//	it iter = m.begin();
//
//	Money* arr = new Money[m.size()];
//
//	size_t size = m.size();
//
//	for (size_t i = 0; i < m.size(); i++, iter++)
//	{
//		arr[i] = *iter;
//		arr[i] += sum;
//	}
//
//	m.clear();
//
//	for (size_t i = 0; i < size; i++)
//	{
//		m.insert(arr[i]);
//	}
//	delete[] arr;
//}


int main()
{
	try
	{
		size_t n{};
		std::cout << "N? ";
		std::cin >> n;

		Container<Money> m(n); //создать словарь
		m.Print();

		Money el = m.arithmetic_mean(); //вычислить среднее значение
		std::cout << "\nArithmetic mean: " << el << std::endl;
		m.Add(el); //добавить в конец
		m.Print();

		Money max = *m.Max();
		std::cout << "\nMax: " << max << std::endl;
		m.delete_el(max);
		m.Print();

		Money min = *m.Min();
		std::cout << "\nMin: " << min << std::endl;
		std::cout << "\Division: " << std::endl;
		m.division();
		m.Print();

		m.add_min_el();
		std::cout << "\nAdd minimal element: " << std::endl;
		m.Print();

		std::cout << "\nWhich element should i delete? " << std::endl;
		Money value;
		std::cin >> value;
		m.delete_el(value);
		m.Print();

		std::cout << "\nWhich position should i delete? " << std::endl;
		size_t pos;
		std::cin >> pos;
		m.remove_element_by_index(pos);
		m.Print();

		std::cout << "\nAdd the sum of the minimum and maximum elements to each element: " << std::endl;
		m.add_sum_max_min();
		m.Print();
	}
	catch (const int num_error)
	{
		switch (num_error)
		{
		case 0:
			std::cout << "Error in calculating the arithmetic mean. The container is empty." << std::endl;
			break;
		case 1:
			std::cout << "Error getting the maximum element. The container is empty." << std::endl;
			break;
		case 2:
			std::cout << "Error getting the minimum element. The container is empty." << std::endl;
			break;
		case 3:
			std::cout << "Error deleting an element. The container is empty." << std::endl;
			break;
		default:
			std::cout << "Error!" << std::endl;
			break;
		}
	}

	return 0;
}