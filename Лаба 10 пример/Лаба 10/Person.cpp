#include "Person.h"


Person::Person()
{
	m_name = "";
	m_age = 0;
}

Person::Person(std::string name, int age)
{
	m_name = name;
	m_age = age;
}

Person::Person(const Person& temp)
{
	m_name = temp.m_name;
	m_age = temp.m_age;
}

Person::~Person()
{
}

Person Person::operator=(const Person& temp)
{
	if (&temp == this)
		return *this;
	m_name = temp.m_name;
	m_age = temp.m_age;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Person& temp)
{
	out << "Name: " << temp.m_name << "; Age : " << temp.m_age << '.';
	return out;
}

std::istream& operator>>(std::istream& in, Person& temp)
{
	std::cout << "Name: ";
	in >> temp.m_name;
	std::cout << "Age : ";
	in >> temp.m_age;
	return in;
}

std::fstream& operator<<(std::fstream& fout, const Person& temp)
{
	fout << temp.m_name << std::endl << temp.m_age;
	return fout;
}

std::fstream& operator>>(std::fstream& fin, Person& temp)
{
	std::cout << "Name: ";
	fin >> temp.m_name;
	std::cout << "Age : ";
	fin >> temp.m_age;
	return fin;
}
