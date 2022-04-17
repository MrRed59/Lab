#pragma once
#include<iostream>
#include<fstream>
#include<string>

class Person
{
	std::string m_name;
	int m_age;
public:
	//---------constructor-----------	
	Person();
	Person(std::string, int);
	Person(const Person&);
	~Person();
	//-------overloaded-functions----
	Person operator =(const Person&);
	//-------friend-functions---------
	friend std::ostream& operator<<(std::ostream&, const Person&);
	friend std::istream& operator>>(std::istream&, Person&);
	friend std::fstream& operator<<(std::fstream&, const Person&);
	friend std::fstream& operator>>(std::fstream&, Person&);

};

