#include "Car.h"
#include<string>

Car::Car(void) 
{
	m_mark = "";
	m_cyl = 0;
	m_power = 0;
}

Car::~Car(void)
{
}


Car::Car(std::string mark, int cyl, int power)
{
	m_mark = mark;
	m_cyl = cyl;
	m_power = power;
}

Car::Car(const Car& temp)
{
	m_mark = temp.m_mark;
	m_cyl = temp.m_cyl;
	m_power = temp.m_power;
}


std::string Car::Get_mark()
{
	return m_mark;
}

int Car::Get_power()
{
	return m_power;
}

int Car::Get_cyl()
{
	return m_cyl;
}


void Car::Set_mark(const std::string mark)
{
	m_mark = mark;
}

void Car::Set_cyl(const int cyl)
{
	m_cyl = cyl;
}

void Car::Set_power(const int power)
{
	m_power = power;
}

Car& Car::operator=(const Car& temp)
{
	if (&temp == this)
		return *this;
	m_mark = temp.m_mark;
	m_cyl = temp.m_cyl;
	m_power = temp.m_power;
	return *this;
}

void Car::HandleEvent(const TEvent&e)
{
	if(e.what == evMessage)
		switch (e.command)
		{
		case cmGet:std::cout << "mark = " << Get_mark() << std::endl;
			break;
		}
}

void Car::Show()
{
	std::cout << "Mark: " << m_mark << std::endl;
	std::cout << "Cyl: " << m_cyl << std::endl;
	std::cout << "Power: " << m_power << std::endl;
}

void Car::Input()
{
	std::cout << "Mark: ";
	std::cin.clear();
	std::cin.ignore(1024, '\n');
	getline(std::cin, m_mark);
	std::cout << "Cyl: ";
	m_cyl = Checking_For_Valid_Input();
	std::cout << "Power: ";
	m_power = Checking_For_Valid_Input();
}


