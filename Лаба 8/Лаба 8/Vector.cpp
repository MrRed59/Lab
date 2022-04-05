#include "Vector.h"
#include "TEvent.h"
#include "Object.h"
#include "Car.h"
#include "Lorry.h"
#include <iostream>

Vector::Vector()
{
	m_beg = nullptr;
	m_size = NULL;
	m_cur = NULL;
}

Vector::Vector(int n)
{
	m_beg = new Object * [n];
	m_cur = NULL;
	m_size = n;
}

Vector::~Vector()
{
	if (m_beg)
		delete[] m_beg;
	m_beg = nullptr;
}

void Vector::Add()
{
	Object* p;

	std::cout << "1. Car" << std::endl;
	std::cout << "2. Lorry" << std::endl;

	switch (Checking_For_Valid_Input())
	{
	case 1:
	{
		Car* car = new (Car);
		car->Input();
		p = car;

		if (m_cur < m_size)
		{
			m_beg[m_cur] = p;
			m_cur++;
		}
		break;
	}
	case 2:
	{
		Lorry* lorry = new Lorry;
		lorry->Input();
		p = lorry;

		if (m_cur < m_size)
		{
			m_beg[m_cur] = p;
			m_cur++;
		}
		break;
	}
	default:
		return;
	}
}

void Vector::Add(Object* temp)
{
	if (m_cur < m_size)
	{
		m_beg[m_cur] = temp;
		m_cur++;
	}
	else
		return;
}

void Vector::Del()
{
	if (!m_cur)
		return;
	m_cur--;
}

void Vector::Show()
{
	if (!m_cur)
		std::cout << "Empty" << std::endl;
	Object** p = m_beg;
	for (int i = 0; i < m_cur; i++)
	{
		(*p)->Show();
		p++;
	}
}

int Vector::operator()()
{
	return m_cur;
}

void Vector::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		Object** p = m_beg;
		for (int i = 0; i < m_cur; i++)
		{
			(*p)->HandleEvent(e);
			p++;
		}
	}
}

int Vector::Checking_For_Valid_Input()
{
	int value;
	do
	{
		if (!std::cin)
		{
			std::cout << "Syntax error" << std::endl;
			std::cin.clear();
			std::cin.ignore(1024, '\n');
		}
		std::cin >> value;
	} while (!std::cin);
	return value;
}