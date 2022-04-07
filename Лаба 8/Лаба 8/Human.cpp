#include "Human.h"
#include<string>

Human::Human(void)
{
	m_name = "";
	m_age = 0;
	m_counter = 0;
}

Human::~Human(void)
{
}


Human::Human(std::string name, int age)
{
	m_name = name;
	m_age = age;
}

Human::Human(const Human& temp)
{
	m_name = temp.m_name;
	m_age = temp.m_age;
}


std::string Human::Get_name()
{
	return m_name;
}

int Human::Get_age()
{
	return m_age;
}


void Human::Set_name(const std::string name)
{
	m_name = name;
}

void Human::Set_age(const int age)
{
	m_age = age;
}


Human& Human::operator=(const Human& temp)
{
	if (&temp == this)
		return *this;
	m_name = temp.m_name;
	m_age = temp.m_age;
	return *this;
}

void Human::HandleEvent(const TEvent&e)
{
	if(e.what == evMessage)
		switch (e.command)
		{
		case cmGet:
			std::cout << "Name = " << Get_name() << std::endl;
			break;
		}
}

void Human::Show()
{
	std::cout << "==================================================================" << std::endl;
	std::cout << "==================================================================" << std::endl;
	std::cout << "Number: " << m_counter << std::endl;
	std::cout << "==================================================================" << std::endl;
	std::cout << "Name: " << m_name << std::endl;
	std::cout << "==================================================================" << std::endl;
	std::cout << "Age: " << m_age << std::endl;
	std::cout << "==================================================================" << std::endl;
}

void Human::Input(const int counter)
{
	m_counter = counter;
	std::cout << "==================================================================" << std::endl;
	std::cout << "==================================================================" << std::endl;
	std::cout << "Number: " << m_counter << std::endl;
	std::cout << "==================================================================" << std::endl;
	std::cout << "Name: ";
	std::cin.clear();
	std::cin.ignore(1024, '\n');
	getline(std::cin, m_name);
	std::cout << "==================================================================" << std::endl;
	std::cout << "Age: ";
	Checking_For_Valid_Input(m_age);
	std::cout << "==================================================================" << std::endl;
}


