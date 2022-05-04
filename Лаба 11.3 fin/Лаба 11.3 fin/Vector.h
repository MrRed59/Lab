#pragma once
#include<iostream>
#include<vector>
#include<ctime>


template <class T>
class Vector
{
	std::vector <T> v;
public:
	//---------constructor-----------
	Vector(int);
	~Vector();
	//-------overloaded-functions----
	void Add();
	void Print();
	size_t Size();
	Vector& operator=(const Vector <T>&);
	Vector operator+(const T&);
	Vector operator*(const Vector <T>&);
	T& operator[](int);
};


template<class T>
inline Vector<T>::Vector(int n)
{
	T a{};
	for (int i = 0; i < n; i++)
		v.push_back(a);
}

template<class T>
inline Vector<T>::~Vector()
{
}

template<class T>
inline void Vector<T>::Add()
{
	T a{};
	for (size_t i = 0; i < v.size(); i++)
	{
		std::cin >> a;
		v[i] = a;
	}
}

template<class T>
inline void Vector<T>::Print()
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

template<class T>
inline size_t Vector<T>::Size()
{
	return v.size();
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& temp)
{
	if (this == &temp)
		return *this;
	v.clear();

	for (size_t i = 0; i < temp.v.size(); i++)
	{
		v.push_back(temp.v[i]);
	}
	return *this;
}

template <class T>
Vector<T> Vector<T>::operator+(const T& k)
{
	Vector<T> temp(v.size());
	for (size_t i = 0; i < v.size(); i++)
		temp.v[i] = v[i] + k;
	return temp;
}

template <class T>
Vector<T> Vector<T>::operator*(const Vector<T>& second)
{
	Vector<T> temp(v.size());

	size_t n = 0;

	//ïîèñê ïåðåñå÷åíèÿ ìíîæåñòâà è çàïèñü â ïðîìåæóòî÷íûé êëàññ
	for (size_t i = 0; i < v.size(); i++)
	{
		for (size_t j = 0; j < second.v.size(); j++)
		{
			if (v[i] == second.v[j])
			{
				temp.v[n] = v[i];
				n++;
				break;
			}
		}
	}

	//åñëè íåò ïåðåñå÷åíèé
	if (!n)
	{
		Vector<T> null(0);
		std::cout << "No intersections found" << std::endl;
		return null;
	}

	//ñîðòèðîâêà ïî âîçðàñòàíèþ
	T value = 0;
	for (size_t i = 0; (i < (n - 1)) && (i < (v.size() - 1)); i++)
	{
		for (size_t j = i + 1; (j < n) && (j < v.size()); j++)
		{
			if (temp.v[i] >= temp.v[j])
			{
				value = temp.v[i];
				temp.v[i] = temp.v[j];
				temp.v[j] = value;
			}
		}
	}

	Vector<T> temp_short(temp, n);

	size_t counter = 1;

	//çàïèñü â êëàññ temp_short ÷èñåë áåç ïîâòîðåíèÿ
	for (size_t i = 0; (i < (n - 1)) && n && (i < v.size()); i++)
	{
		//if (temp.v[i] != temp.v[i + 1])
		//{
		//	temp_short.v[i] = temp.v[i];
		//	counter++;
		//}
		if (temp.v[i] == temp.v[i + 1])
			v.erase(i + 1);
	}

	return temp;

	//if (temp.v.size() == counter)
	//	return temp;
	//else
	//{
	//	Vector<T> temp_fin(temp, counter);
	//	return temp_fin;
	//}
}

template <class T>
T& Vector<T>::operator[](int index)
{
	if (index < v.size())
		return v[index];
	else
		std::cout << "Error. Index > Size" << std::endl;
	exit(1);
}
