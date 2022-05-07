#pragma once
#include<iostream>
#include<set>


template <class T>
class Container
{
	std::multiset<T> m;
public:
	//---------constructor-----------
	Container() {};
	Container(size_t);
	~Container();
	//-------other-functions----
	void Print();
	T arithmetic_mean();
	void Add(const T&);
	typename std::multiset<T>::iterator Max();
	typename std::multiset<T>::iterator Min();
	void delete_el(const T&);	
	void division();
	void remove_element_by_index(int);
	void add_min_el();
	void add_sum_max_min();
};

template<class T>
inline Container<T>::Container(size_t n)
{
	T money;
	for (size_t i = 0; i < n; i++) //создать элемент и добавить его в множество
	{
		std::cin >> money;
		m.insert(money);
	}
}

template<class T>
inline Container<T>::~Container()
{
}

template<class T>
inline void Container<T>::Print()
{
	for (auto& item : m)
		std::cout << item << ": ";
}


template<class T>
T Container<T>::arithmetic_mean()
{
	if (!m.size())
		throw 0;
	class std::multiset<T>::iterator i = m.begin();
	T s{};
	for (size_t j = 0; j < m.size(); j++, i++)
		s += *i;
	return s / m.size();
}

template<class T>
void Container<T>::Add(const T& el)
{
	m.insert(el);
}



template<class T>
typename std::multiset<T>::iterator Container<T>::Max()
{
	if (!m.size())
		throw 1;
	auto iter = m.end();
	return (--iter);
}

template<class T>
typename std::multiset<T>::iterator Container<T>::Min()
{
	if (!m.size())
		throw 2;
	auto iter = m.begin();
	return iter;
}


template<class T>
void Container<T>::delete_el(const T& temp)
{
	if (!m.size())
		throw 3;
	m.erase(temp);
}


template<class T>
void Container<T>::division()
{
	T min								  = *Min();

	if (min == 0)
	{
		std::cout << "Error! Minimum value = 0.\nDivision failed." << std::endl;
		return;
	}

	class std::multiset<T>::iterator iter = m.begin();
	T* arr								  = new T[m.size()];
	size_t size							  = m.size();

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

template<class T>
inline void Container<T>::remove_element_by_index(int pos)
{
	if (pos >= m.size())
	{
		std::cout << "Error. Position > size" << std::endl;
		return;
	}

	class std::multiset<T>::iterator i = m.begin();
	for (size_t j = 0; j < pos; i++, j++);
	m.erase(i);
}

template<class T>
inline void Container<T>::add_min_el()
{
	m.insert(*Min());
}

template<class T>
inline void Container<T>::add_sum_max_min()
{
	T sum								  = *Min();
	sum									 += *Max();

	class std::multiset<T>::iterator iter = m.begin();
	T* arr								  = new T[m.size()];
	size_t size							  = m.size();

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

