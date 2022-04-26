#pragma once
#include<iostream>
#include<stack>
#include<vector>


template <class T>
class Vector
{
	std::stack <T> s;
	int len;
public:
	//---------constructor-----------
	Vector();
	Vector(int);
	Vector(const Vector<T>&);
	~Vector();
	//-------overloaded-functions----
	void Print();

};

template<class T>
Vector<T> copy_stack_to_vector(std::stack <T> s)
{
	std::vector<T> v;
	while (!s.empty()) //���� ���� �� ������
	{
		v.push_back(s.top()); //�������� � ������ ������� �� ������� �����
		s.pop();
	}
	return v; //������� ������ ��� ��������� �������
};

template<class T>
std::stack<T> copy_vector_to_stack(std::vector<T> v) //�������� ������ � ����
{
	std::stack<T> s;
	for (size_t i = 0; i < v.size(); i++)
	{
		s.push(v[i]);
	}
	return s;
};



template<class T>
Vector<T>::Vector()
{
	len = 0;
}

template<class T>
Vector<T>::Vector(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		std::cin >> a;
		s.push(a);
	}
	len = s.size();
}

template<class T>
inline Vector<T>::Vector(const Vector<T>&)
{
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
