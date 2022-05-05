#pragma once
#include<iostream>
#include<queue>
#include<vector>


template <class T>
class Vector
{
	std::queue <T> q;
	size_t len;
public:
	//---------constructor-----------
	Vector() :len(0) {};
	Vector(int);
	Vector(const Vector<T>&);
	~Vector();
	//-------overloaded-functions----
	void Print();

};

template<class T>
Vector<T> copy_queue_to_vector(std::queue <T> q)
{
	std::vector<T> v;
	while (!s.empty()) //ïîêà ñòåê íå ïóñòîé
	{
		v.push_back(s.top()); //äîáàâèòü â âåêòîð ýëåìåíò èç âåðøèíû ñòåêà
		q.pop();
	}
	return v; //âåðíóòü âåêòîð êàê ðåçóëüòàò ôóíêöèè
};

template<class T>
std::queue<T> copy_vector_to_queue(std::vector<T> v) //êîïèðóåì âåêòîð â ñòåê
{
	std::queue<T> q;
	for (size_t i = 0; i < v.size(); i++)
	{
		q.push(v[i]);
	}
	return s;
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
	len = s.size();
}

template<class T>
inline Vector<T>::Vector(const Vector<T>& Vec)
{
	len = Vec.len;
	std::vector<T> v = copy_queue_to_vector(Vec.q);
	s = copy_vector_to_queue(v);
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