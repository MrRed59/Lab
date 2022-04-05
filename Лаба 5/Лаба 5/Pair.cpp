#include "Pair.h"
#include<iostream>


int Pair::Checking_For_Valid_Input()
{
	int value;
	do
	{
		if (!cin)
		{
			cout << "Syntax error" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
		cin >> value;
	} while (!cin);
	return value;
}

Pair::Pair(void)
{
	first = 0;
	second = 0;
}

Pair::~Pair(void){}

Pair::Pair(const int first, const int second)
{
	this->first = first;
	this->second = second;
}

Pair::Pair(const Pair& p)
{
	first = p.first;
	second = p.second;
}

int Pair::Get_First()
{
	return first;
}

int Pair::Get_Second()
{
	return second;
}

void Pair::Set_First(const int first)
{
	this->first = first;
}

void Pair::Set_Second(const int second)
{
	this->second = second;
}

void Pair::Scan_First()
{
	this->first = Checking_For_Valid_Input();
}

void Pair::Scan_Second()
{
	this->second = Checking_For_Valid_Input();
}

long long Pair::Multiplication_Of_Class_Fields()
{
	return (long long)first * second;
}


Pair& Pair::operator=(const Pair&p)
{
	if (&p == this)
		return *this;
	first = p.first;
	second = p.second;
	return *this;
}

Pair Pair::operator*(const Pair& p)
{
	Pair result;
	result.first = first * p.first;
	result.second = second * p.second;
	return result;
}

Pair& Pair::operator*=(const Pair& p)
{
	first *= p.first;
	second *= p.second;
	return *this;
}

Pair Pair::operator-(const Pair& p)
{
	Pair temp;
	first -= second;
	second = p.first - p.second;
	return temp;
}


bool Pair::operator==(const Pair& p)
{
	return (first == p.first && second == p.second);
}

istream& operator>>(istream& in, Pair& p)
{
	cout << "First = "; in >> p.first;
	cout << "Second = "; in >> p.second;
	return in;
}

ostream& operator<<(ostream& out, const Pair& p)
{
	out << "First = " << p.first;
	out << ";  Second = " << p.second << endl;
	return out;
}

void Pair::Show()
{
	cout << "First = " << first;
	cout << ";\tSecond = " << second << endl;
}