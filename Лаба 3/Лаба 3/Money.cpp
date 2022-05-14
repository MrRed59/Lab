#include "Money.h"
#include<iostream>

using namespace std;

Money::Money()
{
	rubles = 0;
	kopeck = 0;
}

Money::Money(long rubles, short kopeck)
{
	if (rubles < 0 || kopeck < 0)
	{
		rubles = -abs(rubles);
		kopeck = -abs(kopeck);
	}
	long long money = rubles;
	money *= 100;
	money += kopeck;
	this->rubles = money / 100;
	this->kopeck = money % 100;
}

Money::Money(const Money& t)
{
	rubles = t.rubles;
	kopeck = t.kopeck;
}

int Money::Get_rubles()
{
	return rubles;
}

int Money::Get_kopeck()
{
	return abs(kopeck);
}

void Money::Set_rubles(const long rubles)
{
	this->rubles = rubles;
}

void Money::Set_kopeck(short kopeck)
{
	while (abs(kopeck) > 99)
	{
		cout << "Error!. Please enter a number from -99 to 99 ";
		cin >> kopeck;
	}
	this->kopeck = kopeck;
}

//перегруженные операции
Money& Money::operator=(const Money& t)
{
	if (&t == this)
		return *this;
	rubles = t.rubles;
	kopeck = t.kopeck;
	return *this;
}

Money& Money::operator++()
{
	long long money = rubles;
	money *= 100;
	money += kopeck;
	money++;
	rubles = money / 100;
	kopeck = money % 100;
	return *this;
}

Money Money::operator++(int)
{
	long long money = rubles;
	money *= 100;
	money += kopeck;
	money++;
	Money t(rubles, kopeck);
	rubles = money / 100;
	kopeck = money % 100;
	return t;
}

Money Money::operator+(const Money& t)
{
	long long money_first = rubles;
	money_first *= 100;
	money_first += kopeck;
	long long money_second = t.rubles;
	money_second *= 100;
	money_second += t.kopeck;
	Money p;
	p.rubles = (money_first + money_second) / 100;
	p.kopeck = (money_first + money_second) % 100;
	return p;
}

Money Money::operator/(const Money&p)
{
	Money division;
	if (&p == this)
	{
		division.rubles = 0;
		division.kopeck = 1;
		return division;
	}
	long long money_first = rubles;
	money_first *= 100;
	money_first += kopeck;
	long long money_second = p.rubles;
	money_second *= 100;
	money_second += p.kopeck;
	division.rubles = (money_first / money_second) / 100;
	division.kopeck = (money_first / money_second) % 100;
	return division;
}

Money& Money::operator*=(const double value)
{
	long long money = rubles;
	money *= 100;
	money += kopeck;
	money *= value;
	rubles = money / 100;
	kopeck = money % 100;
	return *this;
}

//перегрузки функции ввода-вывода
istream& operator>>(istream& in, Money& t)
{
	int value;
	cout << "Rubles? "; in >> t.rubles;
	do
	{
		cout << "Kopeck? "; in >> value;
		if (abs(value) > 99)
			cout << "Error!. Please enter a number from -99 to 99" << endl;
	} while (abs(value) > 99);
	t.kopeck = value;
	if (t.rubles < 0 || t.kopeck < 0)
	{
		t.rubles = -abs(t.rubles);
		t.kopeck = -abs(t.kopeck);
	}
	return in;
}

ostream& operator<<(ostream& out, const Money& t)
{
	return (out << t.rubles << "rub : " << abs(t.kopeck) << "kop");
}