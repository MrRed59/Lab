#include<iostream>
#include<set>

typedef std::multiset<float> TMSet;
typedef TMSet::iterator it;

TMSet make_multiset(size_t n)
{
	TMSet m;
	for (size_t i = 0; i < n; i++) //создать элемент и добавить его в множество
	{
		m.insert(rand() % 10);
	}
	return m;
}

void print_multiset(const TMSet& m)
{
	for (auto& item : m)
		std::cout << item << ": ";
}

float arithmetic_mean(const TMSet& m)
{
	it i = m.begin();
	float s{};
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
	float min = *Min(m);

	if (!min)
	{
		std::cout << "Error! Minimum value = 0.\nDivision failed." << std::endl;
		return;
	}

	it iter = m.begin();

	float* arr = new float[m.size()];

	size_t size = m.size();

	for (size_t i = 0; i < m.size(); i++, iter++)
	{
		arr[i] = *iter / min;
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
	it i = m.begin();
	for (size_t j = 0; j < pos; i++, j++);
	m.erase(i);
}

void add_sum_max_min(TMSet& m)
{
	float sum = *Min(m) + *Max(m);

	it iter = m.begin();

	float* arr = new float[m.size()];

	size_t size = m.size();

	for (size_t i = 0; i < m.size(); i++, iter++)
	{
		arr[i] = *iter + sum;
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

	float el = arithmetic_mean(m); //вычислить среднее значение
	std::cout << "\nArithmetic mean: " << el << std::endl;
	m.insert(el); //добавить в конец
	print_multiset(m);

	float max = *Max(m);
	std::cout << "\nMax: " << max << std::endl;
	m.erase(max);
	print_multiset(m);

	float min = *Min(m);
	std::cout << "\nMin: " << min << std::endl;
	division(m);
	print_multiset(m);

	add_min_el(m);
	std::cout << "\nAdd minimal element: " << std::endl;
	print_multiset(m);

	std::cout << "\nWhich element should i delete? " << std::endl;
	float value;
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