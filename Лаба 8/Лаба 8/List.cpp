#include "List.h"
#include "TEvent.h"
#include "Object.h"
#include "Human.h"
#include "Employee.h"
#include <iostream>

unsigned int List::counter = 1;

List::List()
{
	m_beg = nullptr;
	m_size = NULL;
	m_cur = NULL;
}

List::List(int n)
{
	m_beg = new Object * [n];
	m_cur = NULL;
	m_size = n;
}

List::~List()
{
	if (m_beg)
		delete[] m_beg;
	m_beg = nullptr;
}

void List::Add()
{
	if (m_cur > m_size)
	{
		std::cout << "Error. The storage is full" << std::endl;
		return;
	}

	Object* p;

	std::cout << "1. Human" << std::endl;
	std::cout << "2. Employee" << std::endl;

	switch (Checking_For_Valid_Input())
	{
	case 1:
	{
		Human* human = new (Human);
		human->Input(counter);
		p = human;

		if (m_cur <= m_size)
		{
			m_beg[m_cur] = p;
			m_cur++;
			counter++;
		}
		break;
	}
	case 2:
	{
		Employee* employee = new Employee;
		employee->Input(counter);
		p = employee;

		if (m_cur < m_size)
		{
			m_beg[m_cur] = p;
			m_cur++;
			counter++;
		}
		break;
	}
	default:
		return;
	}
}

void List::Add(Object* temp)
{
	if (m_cur < m_size)
	{
		m_beg[m_cur] = temp;
		m_cur++;
	}
	else
		return;
}

void List::Del()
{
	if (!m_cur)
		return;
	m_cur--;
}

void List::Show(const int n)
{
	if (!m_beg)
		return;
	if (!m_cur)
		std::cout << "Empty" << std::endl;
	Object** p = m_beg;
	if (!n)
		for (int i = 0; i < m_cur; i++)
		{
			std::cout << "//////////////////////////////////////////////////////////////////" << std::endl;
			(*p)->Show();
			p++;
			std::cout << "//////////////////////////////////////////////////////////////////" << std::endl;
		}
	else
		if (n > m_cur || n < 1)
			std::cout << "Error. incorrect item number" << std::endl;
		else
		{
			p += n - 1;
			(*p)->Show();
		}
}

int List::operator()()
{
	return m_cur;
}

void List::HandleEvent(const TEvent& e)
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

int List::Checking_For_Valid_Input()
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