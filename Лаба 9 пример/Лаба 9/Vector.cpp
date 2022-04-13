#include "Vector.h"
#include<iostream>

Vector::Vector()
{
	m_size = 0;
	m_beg = nullptr;
}

Vector::Vector(int size)
{
	//если текущий размер больше максимального, то генерируются исключения
	if (size > MAX_SIZE)
		throw "Error! The vector size specified is too large";
	m_size = size;
	m_beg = new int[size] {};
}

Vector::Vector(int size, int* arr)
{
	//если текущий размер больше максимального, то генерируются исключения
	if (size > MAX_SIZE)
		throw "Error! The vector size specified is too large";
	m_size = size;
	m_beg = new int[size];
	for (int i = 0; i < m_size; i++)
		m_beg[i] = arr[i];
}

Vector::Vector(const Vector& temp)
{
	m_size = temp.m_size;
	m_beg = new int[m_size];
	for (int i = 0; i < m_size; i++)
		m_beg[i] = temp.m_beg[i];
}

Vector::~Vector()
{
	if (m_beg)
		delete[] m_beg;
}

const Vector& Vector::operator=(const Vector& temp)
{
	if (this ==&temp)
		return *this;
	if (m_beg)
		delete[] m_beg;
	m_size = temp.m_size;
	m_beg = new int[m_size];
	for (int i = 0; i < m_size; i++)
		m_beg[i] = temp.m_beg[i];
	return *this;
}

int Vector::operator[](int i)
{
	if (i < 0)
		throw "Error! The entered number cannot be less than zero";
	if (i >= m_size)
		throw ("Vector Length more than max size\n");
	return m_beg[i];
}

Vector Vector::operator+(int a)
{
	/*если при добавлении элемента размер вектора
	станет больше макимального, то генерируется исключение*/
	if (m_size + 1 == MAX_SIZE)
		throw "Error! Unable to add element";
	Vector temp(m_size + 1, m_beg);
	temp.m_beg[m_size] = a;
	return temp;
}

Vector Vector::operator--()
{
	/*если вектор пустой, то удалить элемент нельзя
	и генерируется исключение*/
	if (!m_size)
		throw "Error! Element cannot be removed";

	if (m_size == 1) //если в векторе один элемент
	{
		m_size = 0;
		delete[] m_beg;
		m_beg = nullptr;
		return *this;
	}

	Vector temp(m_size, m_beg);
	delete[] m_beg;
	m_size--;
	m_beg = new int[m_size];
	for (int i = 0; i < m_size; i++)
		m_beg[i] = temp.m_beg[i];

	return *this;
}

std::ostream& operator<<(std::ostream& out, const Vector& temp)
{
	if (!temp.m_size)
		out << "Empty" << std::endl;
	else
	{
		for (int i = 0; i < temp.m_size; i++)
			out << temp.m_beg[i] << "; ";
		out << std::endl;
	}
	return out;
}

std::istream& operator>>(std::istream& in, Vector& temp)
{

	for (int i = 0; i < temp.m_size; i++)
	{
		std::cout << i << ':';
		in >> temp.m_beg[i];
	}
	return in;
}
