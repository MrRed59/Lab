#include "Vector.h"
#include<iostream>

Vector::Vector(void)
{
	beg = 0;
	size = 0;
	cur = 0;
}

Vector::~Vector(void)
{
	cur;
	if (beg != 0)
		delete[] beg;
	beg = 0;
}

Vector::Vector(const int i)
{
	beg = new Object * [i] {};
	cur = 0;
	size = i;
}

Vector::Vector(const Vector& temp)
{
	cur = temp.cur;
	size = temp.size;
	delete[]beg;
	beg = 0;
	beg = new Object * [temp.size];
	for (int i = 0; i < temp.size; i++)
	{
		beg[i] = temp.beg[i];
	}
}

void Vector::Add(Object* p)
{
	if (cur < size)
	{
		beg[cur] = p;
		cur++;
	}
}

Vector& Vector::operator=(const Vector& temp)
{
	cur = temp.cur;
	size = temp.size;
	delete[]beg;
	beg = 0;
	beg = new Object * [temp.size];
	for (int i = 0; i < temp.size; i++)
	{
		beg[i] = temp.beg[i];
	}
	return *this;
}

int Vector::GetSize(void)
{
	return size;
}

int Vector::GetNumberOfOccupiedCells(void)
{
	return cur;
}

void Vector::PrintLastElement()
{
	Object** p = beg;

	(*(p + cur - 1))->Show();
}

void Vector::PopBack()
{

	if (cur - 1)
	{
		beg[cur - 1] = 0;
		cur--;
	}
	else Clear();
}

void Vector::Clear()
{
	cur = 0;
}



std::ostream& operator<<(std::ostream& out, const Vector& temp)
{
	if (!temp.size || !temp.cur)
		out << "Empty" << std::endl;
	Object** p = temp.beg;
	for (int i = 0; i < temp.cur; i++)
	{
		(*p)->Show();
		p++;
	}
	return out;
}