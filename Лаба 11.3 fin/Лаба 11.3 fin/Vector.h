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
	int min();
	int max();
	void remove_element_by_index(int);
	void add_min_max();
	void add_min_el();
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

template<class T>
inline int Vector<T>::min()
{
	T time = v[0];
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

template<class T>
inline int Vector<T>::max()
{
	T time = v[0];
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

template<class T>
inline void Vector<T>::remove_element_by_index(int pos)
{
	v.erase(v.begin() + pos);
}

template<class T>
inline void Vector<T>::add_min_max()
{
	T m = v[min()] + v[max()];
	for (size_t i = 0; i < v.size(); i++)
	{
		v[i] += m;
	}
}

template<class T>
inline void Vector<T>::add_min_el()
{
	v.push_back(v[min()]);
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

	if (!n)
	{
		Vector<T> null(0);
		std::cout << "No intersections found" << std::endl;
		return null;
	}

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

	for (size_t i = 0; (i < (n - 1)) && n && (i < v.size()); i++)
	{
		if (temp.v[i] == temp.v[i + 1])
			v.erase(i + 1);
	}

	return temp;
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
