#include "Set.h"
#include"Error.h"
#include<iostream>

//---------constructor-----------

Set::Set()
{
	m_size = 0;
	m_beg = nullptr;
}

Set::Set(int size)
{
	//если текущий размер больше максимального, то генерируются исключения
	if (size > MAX_SIZE)
		if(!m_realization)
			throw 1;
		else
			throw Error("Error! The vector size specified is too large");
	m_size = size;
	m_beg = new int[size] {};
}

Set::Set(int size, int* arr)
{
	//если текущий размер больше максимального, то генерируются исключения
	if (size > MAX_SIZE)
		if (!m_realization)
			throw 2;
		else
			throw Error("Error! The vector size specified is too large");
	m_size = size;
	m_beg = new int[size];
	for (int i = 0; i < m_size; i++)
		m_beg[i] = arr[i];
}

Set::Set(const Set& temp, int size)
{
	if (!size)
		m_size = temp.m_size;
	else
		m_size = size;
	m_beg = new int[m_size];
	for (int i = 0; i < m_size; i++)
		m_beg[i] = temp.m_beg[i];
}

Set::~Set()
{
	if (m_beg)
		delete[] m_beg;
}

//-------overloaded-functions----

int Set::operator()()
{
	return 0;
}

const Set& Set::operator=(const Set& temp)
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

int Set::operator[](int i)
{
	if (i < 0)
		if (!m_realization)
			throw 3;
		else
			throw Error("Error! The entered number cannot be less than zero");
	if (i >= m_size)
		if (!m_realization)
			throw 4;
		else
			throw Error("Vector Length more than max size");
	return m_beg[i];
}

Set Set::operator+(int a)
{
	/*если при добавлении элемента размер вектора
	станет больше макимального, то генерируется исключение*/
	if (m_size + 1 == MAX_SIZE)
		if (!m_realization)
			throw 5;
		else
			throw Error("Error! Unable to add element");
	Set temp(m_size + 1, m_beg);
	temp.m_beg[m_size] = a;
	return temp;
}

Set Set::operator--()
{
	/*если вектор пустой, то удалить элемент нельзя
	и генерируется исключение*/
	if (!m_size)
		if (!m_realization)
			throw 6;
		else
			throw Error("Error! Element cannot be removed");

	if (m_size == 1) //если в векторе один элемент
	{
		m_size = 0;
		delete[] m_beg;
		m_beg = nullptr;
		return *this;
	}

	Set temp(m_size, m_beg);
	delete[] m_beg;
	m_size--;
	m_beg = new int[m_size];
	for (int i = 0; i < m_size; i++)
		m_beg[i] = temp.m_beg[i];

	return *this;
}

Set Set::operator*(const Set& second)
{
	Set temp(m_size);

	unsigned int n = 0;

	//поиск пересечения множества и запись в промежуточный класс
	for (int i = 0; i < m_size; i++)
	{
		for (int j = 0; j < second.m_size; j++)
		{
			if (m_beg[i] == second.m_beg[j])
			{
				temp.m_beg[n] = m_beg[i];
				n++;
				break;
			}
		}
	}

	//если нет пересечений
	if (!n)
	{
		Set null(0);
		std::cout << "No intersections found" << std::endl;
		return null;
	}

	//сортировка по возрастанию
	int value = 0;
	for (unsigned int i = 0; (i < (n - 1)) && (i < (m_size - 1)); i++)
	{
		for (unsigned int j = i + 1; (j < n) && (j < m_size); j++)
		{
			if (temp.m_beg[i] >= temp.m_beg[j])
			{
				value = temp.m_beg[i];
				temp.m_beg[i] = temp.m_beg[j];
				temp.m_beg[j] = value;
			}
		}
	}

	Set temp_short(temp, n);

	unsigned int counter = 1;

	//запись в класс temp_short чисел без повторения
	for (unsigned int i = 0; (i < (n - 1)) && n && (i < m_size); i++)
	{
		if (temp.m_beg[i] != temp.m_beg[i + 1])
		{
			temp_short.m_beg[i] = temp.m_beg[i];
			counter++;
		}
	}

	if (temp.m_size == counter)
		return temp;
	else
	{
		Set temp_fin(temp, counter);
		return temp_fin;
	}
}

//-------friend-functions---------

std::ostream& operator<<(std::ostream& out, const Set& temp)
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

std::istream& operator>>(std::istream& in, Set& temp)
{

	for (int i = 0; i < temp.m_size; i++)
	{
		std::cout << i << ':';
		in >> temp.m_beg[i];
	}
	return in;
}


struct TEvent
{
	int what;//тип события
	union
	{
		int command;//код команды
		struct
		{
			int message;
			int a;//параметр команды
		};
	};
};

