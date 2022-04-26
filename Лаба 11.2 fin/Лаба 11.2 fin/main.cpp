#include<iostream>
#include<vector>
#include<cstdlib>
#include"Money.h"

typedef std::vector<Money>Vec;
Vec make_vector(const int n)
{
	Vec v;
	Money money;

	for (int i = 0; i < n; i++)
	{
		money.Set_rubles(rand() % 100 - 50);
		money.Set_kopeck(rand() % 100 - 50);
		v.push_back(money);
		money.clear();
	}
	return v;
}

void print_vector(const Vec& v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		if (i)
			std::cout << ";  " << v[i];
		else
			std::cout << v[i];
	}
	std::cout << "." << std::endl;
}

Money arithmetic_mean(const Vec& v)
{
	Money time;

	for (size_t i = 0; i < v.size(); i++) 
	{
		time += v[i];
	}
	int n = v.size(); 
	return (time / n);
}

void add_vector(Vec& v, Money el, int pos)
{
	v.insert(v.begin() + pos, el); 
}

int max(const Vec& v)
{
	Money time = v[0];
	int n = 0;

	for (size_t i = 0; i < v.size(); i++)
	{
		if (time < v[i])
		{
			time = v[i];
			n = i;
		}
	}

	return n;
}

void remove_element_by_index(Vec& v, int pos)
{
	v.erase(v.begin() + pos);
}

int min(const Vec& v)
{
	Money time = v[0];
	int n = 0;

	for (size_t i = 0; i < v.size(); i++)
	{
		if (time > v[i])
		{
			time = v[i];
			n = i;
		}
	}

	return n;
}

void subtract_min_element(Vec& v)
{
	int m = min(v);
	Money min_element = v[m];
	for (size_t i = 0; i < v.size(); i++)
	{
		v[i] -= min_element;
	}
}




int main()
{
	try
	{
		std::vector<Money> v;
		std::vector<Money>::iterator vi = v.begin();
		int n;

		std::cout << "N? ";
		std::cin >> n;

		v = make_vector(n);
		print_vector(v);

		//

		Money el = arithmetic_mean(v);

		int pos;
		std::cout << "Position: ";
		std::cin >> pos;

		if (pos > v.size())
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

}