#pragma once
#include<iostream>
#include<map>
#include"Money.h"

//template <class T>
//typename std::map<int, T>::iterator it;

template <class T>
class Container
{
	std::map<int, T> v;
	size_t len;
public:
	//---------constructor-----------
	Container() :len(0) {};
	Container(size_t);
	~Container();
	//-------other-functions----
	void Print();
	T arithmetic_mean();
	void Add(int, const T&);
	int Max();
	void Del();
	int Min();
	void division();
};

template<class T>
inline Container<T>::Container(size_t n)
{
	T a;
	for (size_t i = 0; i < n; i++)
	{
		std::cin >> a;
		v[i] = a;
	}
	len = v.size();
}

template<class T>
inline Container<T>::~Container()
{
}

template<class T>
inline void Container<T>::Print()
{
	for (size_t i = 0; i < v.size(); i++)
		std::cout << i << " - " << v[i] << " " << std::endl;
}


template<class T>
T Container<T>::arithmetic_mean()
{
	Money s = v[0];
	for (size_t i = 1; i < v.size(); i++)
		s += v[i];
	return s / v.size();
}

template<class T>
void Container<T>::Add(int n, const T& el)
{
	v.insert(std::make_pair(n, el));
}



template<class T>
int Container<T>::Max()
{
	class std::map<int, T>::iterator i = v.begin();
	int num_max{}, k{}; //номер максимального и счетчик элементов
	T m = i->second; //значение первого элемента
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

template<class T>
void Container<T>::Del()
{
	int max = Max();
	std::cout << "max: " << v[max] << " num:" << max << std::endl;
	v.erase(max);
}


template<class T>
int Container<T>::Min()
{
	class std::map<int, T>::iterator i = v.begin();
	int num_min{}, k{}; //номер максимального и счетчик элементов
	T m = i->second; //значение первого элемента
	
	while (i != v.end())
	{
		if ((*i).second.Get_rubles() && (*i).second.Get_kopeck())
		{
			m = (*i).second;
			num_min = k;
		}
		i++;
		k++;
	}
	return num_min;
}

template<class T>
void Container<T>::division()
{
	T m = v[Min()];
	for (size_t i = 0; i < v.size(); i++)
		v[i] = v[i] / m;
}
