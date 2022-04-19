#include<iostream>
#include<vector>
#include<cstdlib>
#include"Time.h"

typedef std::vector<Time>Vec;
Vec make_vector(const int n)
{
	Vec v;
	Time time;
	for (int i = 0; i < n; i++)
	{
		time.set_min(rand() % 100 - 50);
		time.set_sec(rand() % 100 - 50);
		v.push_back(time);
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

Time arithmetic_mean(const Vec& v)
{
	Time time;

	for (size_t i = 0; i < v.size(); i++) 
	{
		time += v[i];
	}
	int n = v.size(); 
	return (time / n);
}

void add_vector(Vec& v, Time el, int pos)
{
	v.insert(v.begin() + pos, el); 
}

int max(const Vec& v)
{
	Time time = v[0];
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

void del_vector(Vec& v, int pos)
{
	v.erase(v.begin() + pos);
}

int min(const Vec& v)
{
	Time time = v[0];
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
		std::vector<Time> v;
		std::vector<Time>::iterator vi = v.begin();
		int n;

		std::cout << "N? ";
		std::cin >> n;

		v = make_vector(n);
		print_vector(v);

		//

		Time el = arithmetic_mean(v);

		int pos;
		std::cout << "Position: ";
		std::cin >> pos;

		if (pos > v.size())
			throw 1;

		std::cout << "add_vector: " << std::endl;
		add_vector(v, el, pos);
		print_vector(v);

		//

		int n_max = max(v);
		std::cout << "del_vector: " << std::endl;
		del_vector(v, n_max);
		print_vector(v);

		//

		std::cout << "division: " << std::endl;
		division(v);
		print_vector(v);
	}
	catch (int)
	{
		std::cout << "Error!" << std::endl;
	}

}