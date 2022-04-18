#include "Money.h"


Money::Money()
{
	m_rubles = m_kopecks = 0;
}

Money::Money(long rubles, int kopecks)
{
	m_rubles = rubles;
	m_kopecks = kopecks;
}

Money::Money(const Money& temp)
{
	m_rubles = temp.m_rubles;
	m_kopecks = temp.m_kopecks;
}

Money::~Money()
{
}

Money Money::operator=(const Money& temp)
{
	if (&temp == this)
		return *this;
	m_rubles = temp.m_rubles;
	m_kopecks = temp.m_kopecks;
	return *this;
}

Money Money::operator+(const Money& t)
{
	long long money_first = m_rubles;
	money_first *= 100;
	money_first += m_kopecks;
	long long money_second = t.m_rubles;
	money_second *= 100;
	money_second += t.m_kopecks;
	Money p;
	p.m_rubles = (money_first + money_second) / 100;
	p.m_kopecks = (money_first + money_second) % 100;
	return p;
}

Money Money::operator/(const Money& p)
{
	Money money;
	if (&p == this)
	{
		money.m_rubles = 0;
		money.m_kopecks = 1;
		return money;
	}
	long long money_first = m_rubles;
	money_first *= 100;
	money_first += m_kopecks;
	long long money_second = p.m_rubles;
	money_second *= 100;
	money_second += p.m_kopecks;
	money.m_rubles = (money_first / money_second) / 100;
	money.m_kopecks = (money_first / money_second) % 100;
	return money;
}

Money Money::operator/(const int value)
{
	Money money;

	long long long_money = m_rubles;
	long_money *= 100;
	long_money += m_kopecks;

	long_money /= 2;

	money.m_rubles = long_money / 100;
	money.m_kopecks = long_money % 100;

	return money;
}

Money Money::operator*(const double value)
{
	Money multiplication;
	long long money = m_rubles;
	money *= 100;
	money += m_kopecks;
	money *= value;
	multiplication.m_rubles = money / 100;
	multiplication.m_kopecks = money % 100;

	return multiplication;
}

bool Money::operator==(const Money& money)
{
	return (money.m_kopecks == m_kopecks && money.m_rubles == m_rubles);
}

bool Money::operator!=(const Money& money)
{
	return !(money.m_kopecks == m_kopecks && money.m_rubles == m_rubles);
}

std::ostream& operator<<(std::ostream& out, const Money& temp)
{
	out << "Rubles: " << temp.m_rubles << "; Kopecks : " << temp.m_kopecks << '.';
	return out;
}

std::istream& operator>>(std::istream& in, Money& temp)
{
	std::cout << "Rubles: ";
	in >> temp.m_rubles;
	std::cout << "Kopecks : ";
	in >> temp.m_kopecks;
	return in;
}

std::fstream& operator<<(std::fstream& fout, const Money& temp)
{
	fout << temp.m_rubles << std::endl << temp.m_kopecks << std::endl;
	return fout;
}

std::fstream& operator>>(std::fstream& fin, Money& temp)
{
	//std::cout << "Rubles: ";
	fin >> temp.m_rubles;
	//std::cout << "Kopecks : ";
	fin >> temp.m_kopecks;
	return fin;
}
