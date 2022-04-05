#include "Vector.h"
#include<iostream>
using namespace std;

template <class T>
Vector<T>::Vector(int size)
{
	this->size = size;
	data = new T[size]{};
}

template <class T>
Vector<T>::Vector(int size, T k)
{
	this->size = size;
	data = new T[size] {};
	for (int i = 0; i < size; i++)
	{
		data[i] = k;
	}
}

template <class T>
Vector<T>::Vector(const Vector <T>& temp, int size)
{
	this->size = size;
	data = new T[size] {};
	for (int i = 0; i < size; i++)
	{
		data[i] = temp.data[i];
	}
}


template <class T>
Vector<T>::Vector(const Vector<T>& temp)
{
	size = temp.size;
	data = new T[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = temp.data[i];
	}
}


template <class T>
Vector<T>::~Vector()
{
	delete[] data;
	data = nullptr;
}


template <class T>
int Vector<T>::GetSize()
{
	return size;
}


template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>&temp)
{
	if(this == &temp)
		return *this;
	size = temp.size;
	delete[] data;
	data = new T[size];

	for (int i = 0; i < size; i++)
	{
		data[i] = temp.data[i];
	}
	return *this;
}


template <class T>
T& Vector<T>::operator[](int index)
{
	if (index < size)
		return data[index];
	else
		cout << "Error. Index > Size" << endl;
	exit(1);
}


template <class T>
Vector<T> Vector<T>::operator+(const T k)
{
	Vector<T> temp(size);
	for (int i = 0; i < size; i++)
		temp.data[i] = data[i] + k;
	return temp;
}


template <class T>
Vector<T> Vector<T>::operator*(const Vector<T>& second)
{
	Vector<T> temp(size);

	unsigned int n = 0;

	//поиск пересечения множества и запись в промежуточный класс
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < second.size; j++)
		{
			if (data[i] == second.data[j])
			{
				temp.data[n] = data[i];
				n++;
				break;
			}
		}
	}

	//если нет пересечений
	if (!n)
	{
		Vector<T> null(0);
		cout << "No intersections found" << endl;
		return null;
	}

	//сортировка по возрастанию
	T value = 0;
	for (unsigned int i = 0; (i < (n - 1)) && (i < (size - 1)); i++)
	{
		for (unsigned int j = i + 1; (j < n) && (j < size); j++)
		{
			if (temp.data[i] >= temp.data[j])
			{
				value = temp.data[i];
				temp.data[i] = temp.data[j];
				temp.data[j] = value;
			}
		}
	}

	Vector<T> temp_short(temp, n);

	unsigned int counter = 1;

	//запись в класс temp_short чисел без повторения
	for (unsigned int i = 0; (i < (n - 1)) && n && (i < size); i++)
	{
		if (temp.data[i] != temp.data[i + 1])
		{
			temp_short.data[i] = temp.data[i];
			counter++;
		}
	}

	if (temp.size == counter)
		return temp;
	else
	{
		Vector<T> temp_fin(temp, counter);
		return temp_fin;
	}
}


template <class T>
int Vector<T>::operator()()
{
	return size;
}


//template <class T>
//ostream& operator<<(ostream& out, const Vector<T>& temp)
//{
//	for (int i = 0; i < temp.size; i++)
//		out << temp.data[i] << "; ";
//	return out;
//}
//
//
//template <class T>
//istream& operator>>(istream& in, Vector<T>& temp)
//{
//	for (int i = 0; i < temp.size; i++)
//	{
//		do
//		{
//			if (!cin)
//			{
//				cout << "Syntax error" << endl;
//				cin.clear();
//				cin.ignore(1024, '\n');
//			}
//
//			in >> temp.data[i];
//		} while (!cin);
//	}
//	return in;
//}


//template <class U>
//ostream& operator<< (ostream& out, const Vector<U>& temp)
//{
//	for (int i = 0; i < temp.size; i++)
//	{
//		out << temp.data[i] << " ";
//	}
//	return out;
//}

//template <class T>
//istream& operator>>(istream& in, Vector<T>& temp)
//{
//	for (int i = 0; i < temp.size; i++)
//	{
//		in >> temp.data[i];
//	}
//	return in;
//}


//template <class V>
//int Foo(Vector<V>& temp)
//{
//	cout << "It's a live!" << endl;
//}