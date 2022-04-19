#pragma once
#include<iostream>
#include<vector>


template <class T>
class Vector
{
	std::vector <T> v;
	int len;
public:
	//---------constructor-----------
	Vector();
	Vector(int);
	~Vector();
	//-------overloaded-functions----
	void Print();

};

template<class T>
inline Vector<T>::Vector()
{
	len = 0;
}

template<class T>
inline Vector<T>::Vector(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		std::cin >> a;
		v.push_back(a);
	}
	len = v.size();
}

template<class T>
inline Vector<T>::~Vector()
{
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
