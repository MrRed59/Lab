#include "Lorry.h"
#include<string>
#include<iostream>

Lorry::Lorry(void)
{
	m_gruz = 0;
}


Lorry::~Lorry(void)
{
}

void Lorry::Show()
{
	Car::Show();
	std::cout << "Gruz: " << m_gruz << std::endl;
}

void Lorry::Input()
{
	Car::Input();
	std::cout << "Gruz: ";
	m_gruz = Checking_For_Valid_Input();
}


Lorry::Lorry(const std::string mark, const int cyl, const int power, const int gruz) : Car(mark, cyl, power)
{
	m_gruz = gruz;
}

Lorry::Lorry(const Lorry& temp):Car(temp.m_mark, temp.m_cyl, temp.m_power)
{
	m_gruz = temp.m_gruz;
}


int Lorry::Get_gruz()
{
	return m_gruz;
}

void Lorry::Set_gruz(const int gruz)
{
	m_gruz = gruz;
}


Lorry& Lorry::operator=(const Lorry& temp)
{
	if (&temp == this)
		return *this;
	m_mark = temp.m_mark;
	m_cyl = temp.m_cyl;
	m_power = temp.m_power;
	m_gruz = temp.m_gruz;
	return *this;
}
