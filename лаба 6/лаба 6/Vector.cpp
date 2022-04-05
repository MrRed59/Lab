#include "Vector.h"
#include<iostream>

using namespace std;

Vector::Vector(int size)
{
	this->size = size;
	data = new int[size] {};
	beg.size = size;
	beg.elem = data;
	end.elem = &data[size - 1];
}

Vector::Vector(const Vector& temp, int size)
{
	this->size = size;
	data = new int[size] {};
	for (int i = 0; i < size; i++)
	{
		data[i] = temp.data[i];
	}
	beg.elem = data;
	end.elem = &data[size - 1];
}


Vector::Vector(const Vector& temp)
{
	size = temp.size;
	data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = temp.data[i];
	}

	beg = temp.beg;
	end = temp.end;
}

Vector::~Vector()
{
	delete[] data;
	data = nullptr;
}

Vector& Vector::operator=(const Vector&temp)
{
	if(this == &temp)
		return *this;
	size = temp.size;
	delete[] data;
	data = new int[size];

	for (int i = 0; i < size; i++)
	{
		data[i] = temp.data[i];
	}
	beg = temp.beg;
	end = temp.end;
	return *this;
}

int& Vector::operator[](int index)
{
	if (index < size)
		return data[index];
	else
		cout << "Error. Index > Size" << endl;
	exit(1);
}

Vector Vector::operator+(const int k)
{
	Vector temp(size);
	for (int i = 0; i < size; i++)
		temp.data[i] = data[i] + k;
	return temp;
}

Vector Vector::operator*(const Vector& second)
{
	Vector temp(size);

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
		Vector null(0);
		cout << "No intersections found" << endl;
		return null;
	}

	//сортировка по возрастанию
	int value = 0;
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

	Vector temp_short(temp, n);

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
		Vector temp_fin(temp, counter);
		return temp_fin;
	}
}

int Vector::operator()()
{
	return size;
}

ostream& operator<<(ostream& out, const Vector& temp)
{
	for (int i = 0; i < temp.size; i++)
		out << temp.data[i] << "; ";
	return out;
}

istream& operator>>(istream& in, Vector& temp)
{
	for (int i = 0; i < temp.size; i++)
	{
		//in >> temp.data[i];
		do
		{
			if (!cin)
			{
				cout << "Syntax error" << endl;
				cin.clear();
				cin.ignore(1024, '\n');
			}

			in >> temp.data[i];
		} while (!cin);
	}
	return in;
}