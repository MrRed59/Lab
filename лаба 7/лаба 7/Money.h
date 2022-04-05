#pragma once
#include<iostream>

using namespace std;

class Money
{
	long rubles;
	short kopeck;
public:

	Money();
	Money(long, short);
	Money(const Money&);

	int Get_rubles();
	int Get_kopeck();
	void Set_rubles(const long);
	void Set_kopeck(short);

	Money& operator=(const Money&);
	Money& operator++();
	Money operator ++ (int);
	Money operator+(const Money&);

	template <class T>
	Money operator+(const T);

	Money& operator/(const Money&);
	Money operator*(double);

	friend istream& operator>>(istream&, Money&);
	friend ostream& operator<<(ostream&, const Money&);
};

template <class T>
Money Money::operator+(const T value)
{
	long long money_first = rubles;
	money_first *= 100;
	money_first += kopeck;
	Money p;
	p.rubles = (money_first + value) / 100;
	p.kopeck = (money_first + value) % 100;
	return p;
}

