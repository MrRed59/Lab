#pragma once
#include<iostream>
#include<fstream>

class Money
{
	long m_rubles;
	int m_kopecks;
public:
	//---------constructor-----------	
	Money();
	Money(long, int);
	Money(const Money&);
	~Money();
	//-------overloaded-functions----
	Money operator+(const Money&);
	Money operator =(const Money&);
	Money operator/(const Money&);
	Money operator/(int);
	Money operator*(double);
	bool operator==(const Money&);
	bool operator!=(const Money&);
	//-------friend-functions---------
	friend std::ostream& operator<<(std::ostream&, const Money&);
	friend std::istream& operator>>(std::istream&, Money&);
	friend std::fstream& operator<<(std::fstream&, const Money&);
	friend std::fstream& operator>>(std::fstream&, Money&);
};

