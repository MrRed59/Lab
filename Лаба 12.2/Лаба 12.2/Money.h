#pragma once
#include<iostream>


class Money
{
	int m_rubles;
	int m_kopeck;
public:
	//---------constructor-----------
	Money() :m_rubles(0), m_kopeck(0) {};
	Money(long, short);
	Money(const Money&);
	~Money();
	//-------Getters and Setters----
	long Get_rubles();
	short Get_kopeck();
	void Set_rubles(long);
	void Set_kopeck(short);
	//-------overloaded-functions----
	Money& operator=(const Money&);
	Money operator+(const Money&);
	Money operator+(int);
	Money& operator+=(const Money&);
	Money operator/(const Money&);
	Money& operator/=(const Money&);
	Money operator/(int);
	bool operator>(const Money&);
	bool operator<(const Money&);
	void clear();
	//-------friend-functions---------
	friend std::ostream& operator<<(std::ostream&, const Money&);
	friend std::istream& operator>>(std::istream&, Money&);
};

