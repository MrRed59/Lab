﻿#pragma once
#include<iostream>
#include<queue>
#include<vector>
#include"Money.h"


template <class T>
class Vector
{
	std::queue <T> q;
	size_t len;
public:
	//---------constructor-----------
	//Vector() :len(0) {};
	Vector() {};
	Vector(int);
	Vector(const Vector<T>&);
	~Vector();
	//-------overloaded-functions----
	void Print();
	T arithmetic_mean();
	void Add_to_queue(const T&, int);
	T Max();
	void Delete_from_queue();
	T Min();
	void Division();
	void add_min_element();
	void remove_element_by_index(int);
	void add_sum_max_min();
};

template<class T>
std::vector<T> copy_queue_to_vector(std::queue <T> q)
{
	std::vector<T> v;
	while (!q.empty()) //пока очередь не пустая
	{
		v.push_back(q.front()); //добавить в вектор элемент из вершины очереди
		q.pop();
	}
	return v; //вернуть вектор как результат функции
};

template<class T>
std::queue<T> copy_vector_to_queue(std::vector<T> v) //êîïèðóåì âåêòîð â ñòåê
{
	std::queue<T> q;
	for (size_t i = 0; i < v.size(); i++)
	{
		q.push(v[i]); //добавить в очередь элемент вектора
	}
	return q; //вернуть очередь как результат функции
};


template<class T>
Vector<T>::Vector(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		std::cin >> a;
		q.push(a);
	}
	len = q.size();
}

template<class T>
inline Vector<T>::Vector(const Vector<T>& Vec)
{
	len = Vec.len;
	std::vector<T> v = copy_queue_to_vector(Vec.q);
	q = copy_vector_to_queue(v);
}

template<class T>
inline Vector<T>::~Vector()
{
}

template<class T>
void Vector<T>::Print()
{
	std::vector<T> v = copy_queue_to_vector(q);
	while (!q.empty())
	{
		std::cout << q.front() << "  ";
		q.pop();
	}
	std::cout << std::endl;
	q = copy_vector_to_queue(v);
}

template<class T>
T Vector<T>::arithmetic_mean() //вычисление среднего значения
{
	std::vector<T> v = copy_queue_to_vector(q); //копируем значение для суммы
	int n = 1;
	Money sum = q.front(); //начальное значение для суммы

	q.pop(); //удалить первый элемент из вектора

	while (!q.empty()) //пока стек не пустой
	{
		sum += q.front(); //добавить в сумму элемент из вершины стека
		q.pop(); //удалить элемент
		n++;
	}

	q = copy_vector_to_queue(v); //скопировать вектор в очередь

	return (sum / n);
}

template<class T>
void Vector<T>::Add_to_queue(const T& el, int pos) //добавление элемента в очередь
{
	std::vector<T> v;
	T t;
	int i = q.size(); //размер очереди

	if (!pos)
		v.push_back(el); //если номер позиции 0, то добавить его в конец

	while (!q.empty()) //пока стек не пустой
	{
		t = q.front(); //получить элемент из вершины

		if (i == pos) //если номер равен номеру позиции, на которую добавлен элемент
			v.push_back(el); //добавить новый элемент из очeреди в вектор

		v.push_back(t); //добавить элемент из очереди в вектор
		q.pop(); //удалить элемент из очереди

		i--;
	}
	q = copy_vector_to_queue(v); //скопировать вектор в очередь
}

template<class T>
T Vector<T>::Max() // поиск максимального элемента в очереди
{
	T m = q.front(); //переменной m присваивается значение из вершины очереди
	std::vector<T> v = copy_queue_to_vector(q); //копируем очередь в вектор

	while (!q.empty()) //пока стек не пустой
	{
		if (q.front() > m) //сравнить m и элемент в вершине очереди
			m = q.front(); // удалить элемент из очереди

		q.pop();
	}

	q = copy_vector_to_queue(v); //скопировать вектор в очередь

	return m;
}

template<class T>
void Vector<T>::Delete_from_queue()//удалить максимальный элемент из очереди
{
	T m = Max(); //находим максимальный элемент
	std::vector<T> v;
	T t;
	while (!q.empty()) //пока очередь пустая
	{
		t = q.front(); //получаем элемент из вершины очереди

		if (t != m) //если он не равен максимальному, занести элемент в вектор
			v.push_back(t);

		q.pop(); //удалить элемент из очереди
	}

	q = copy_vector_to_queue(v); //скопировать вектор в очередь
}

template<class T>
T Vector<T>::Min()
{
	T m = q.front();
	std::vector<T> v = copy_queue_to_vector(q);
	while (!q.empty()) //пока очередь не пустая
	{
		if (q.front() < m) //сравнить m и элемент в вершине очереди
			m = q.front(); // удалить элемент из стека

		q.pop();
	}

	q = copy_vector_to_queue(v); //скопировать вектор в очередь

	return m;
}

template<class T>
void Vector<T>::Division()
{
	T m = Min();
	std::vector<T> v;
	Money t;

	while (!q.empty()) //пока стек не пустой
	{
		t = q.front(); //получить элемент из вершины
		v.push_back(t / m); //делить t на минимальный элемент и добавить в вектор
		q.pop(); //удалить элемент из вершины
	}

	q = copy_vector_to_queue(v); //скопировать вектор в стек
}

template<class T>
void Vector<T>::add_min_element()
{
	std::vector<T> v;
	Money min = Min();
	Money t;
	size_t i = 0;
	while (!q.empty()) //пока очередь пустая
	{
		t = q.front(); //получаем элемент из вершины очереди
		v.push_back(t);
		q.pop(); //удалить элемент из стека
		i++;
	}

	v.push_back(min);

	q = copy_vector_to_queue(v); //скопировать вектор в очередь
}


template<class T>
void Vector<T>::remove_element_by_index(int pos)
{
	std::vector<T> v;
	T t;
	size_t i = 0;
	while (!q.empty()) //пока очередь пустая
	{
		t = q.front(); //получаем элемент из вершины очереди

		if (pos != i) //если он не равен максимальному, занести элемент в вектор
			v.push_back(t);

		q.pop(); //удалить элемент из стека

		i++;
	}
	q = copy_vector_to_queue(v); //скопировать вектор в очередь
}

template<class T>
void Vector<T>::add_sum_max_min()
{
	std::vector<T> v;
	T sum_min_max = Max() + Min();
	T t;
	size_t i = 0;
	while (!q.empty()) //пока очередь пустая
	{
		t = q.front(); //получаем элемент из вершины очереди
		v.push_back(t + sum_min_max);
		q.pop(); //удалить элемент из стека
		i++;
	}
	q = copy_vector_to_queue(v); //скопировать вектор в очередь
}

