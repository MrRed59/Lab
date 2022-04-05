#include "Vector.h"
#include<iostream>

using namespace std;

Vector::Vector(int size)
{
	this->size = size;
	data = new int[size] {};
	beg.elem = &data[0];
	end.elem = &data[size];
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
	data = 0;
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
}

Vector Vector::operator+(const int k)
{
	Vector temp(size);
	for (int i = 0; i < size; i++)
		temp.data[i] = data[i] + k;
	return temp;
}

int Vector::operator()()
{
	return size;
}

ostream& operator<<(ostream& out, const Vector& temp)
{
	for (int i = 0; i < temp.size; i++)
		out << temp.data[i] << " ";
	return out;
}

istream& operator>>(istream& in, Vector& temp)
{
	for (int i = 0; i < temp.size; i++)
		in >> temp.data[i];
	return in;
}