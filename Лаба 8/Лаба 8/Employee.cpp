#include "Employee.h"
//#include "Human.h"
#include<string>
#include<iostream>

Employee::Employee(void)
{
	m_wages = 0;
	m_position = "";
}


Employee::~Employee(void)
{
}

void Employee::Show()
{
	//std::cout << "==================================================================" << std::endl;
	//std::cout << "==================================================================" << std::endl;
	//std::cout << "Number: " << m_counter << std::endl;
	//std::cout << "==================================================================" << std::endl;
	//std::cout << "Name: " << m_name << std::endl;
	//std::cout << "==================================================================" << std::endl;
	//std::cout << "Age: " << m_age << std::endl;
	//std::cout << "==================================================================" << std::endl;
	Human::Show();
	std::cout << "Wages: " << m_wages << std::endl;
	std::cout << "==================================================================" << std::endl;
	std::cout << "Position: " << m_position << std::endl;
	std::cout << "==================================================================" << std::endl;
}

void Employee::Input(const int counter)
{
	//m_counter = counter;
	//std::cout << "==================================================================" << std::endl;
	//std::cout << "==================================================================" << std::endl;
	//std::cout << "Number: " << m_counter << std::endl;
	//std::cout << "==================================================================" << std::endl;
	//std::cout << "Name: ";
	//std::cin.clear();
	//std::cin.ignore(1024, '\n');
	//getline(std::cin, m_name);
	//std::cout << "==================================================================" << std::endl;
	//std::cout << "Age: ";
	//Checking_For_Valid_Input(m_age);
	//std::cout << "==================================================================" << std::endl;
	Human::Input(counter);
	std::cout << "Wages: ";
	Checking_For_Valid_Input(m_wages);
	std::cout << "==================================================================" << std::endl;
	std::cout << "Position: ";
	std::cin.clear();
	std::cin.ignore(1024, '\n');
	getline(std::cin, m_position);
	std::cout << "==================================================================" << std::endl;
}


Employee::Employee(const std::string name, const int age, const float wages, const std::string position):Human(name, age)
{
	m_wages = wages;
	m_position = position;
}

Employee::Employee(const Employee& temp):Human(temp.m_name, temp.m_age)
{
	m_wages = temp.m_wages;
	m_position = temp.m_position;
}


float Employee::Get_wages()
{
	return m_wages;
}

std::string Employee::Get_position()
{
	return m_position;
}

void Employee::Set_wages(const float wages)
{
	m_wages = wages;
}

void Employee::Set_position(const std::string position)
{
	m_position = position;
}


Employee& Employee::operator=(const Employee& temp)
{
	if (&temp == this)
		return *this;
	m_name = temp.m_name;
	m_age = temp.m_age;
	m_wages = temp.m_wages;
	m_position = temp.m_position;
	return *this;
}