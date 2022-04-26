#pragma once
#include<iostream>


class Money
{
	long m_rubles;
	short m_kopeck;
public:
	//---------constructor-----------
	Money();
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
	Money& operator+=(const Money&);
	Money operator/(const Money&);
	Money& operator/=(const Money&);
	Money operator/(int);
	Money& operator-=(const int);
	Money& operator-=(const Money&);
	bool operator>(const Money&);
	bool operator<(const Money&);
	void clear();
	//-------friend-functions---------
	friend std::ostream& operator<<(std::ostream&, const Money&);
	friend std::istream& operator>>(std::istream&, Money&);
};

