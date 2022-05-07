#include "Money.h"

//Money::Money()
//{
//	m_rubles = m_kopeck = 0;
//}

Money::Money(const long rubles, const short kopeck)
{
	if (rubles < 0 || kopeck < 0)
	{
		m_rubles = -abs(m_rubles);
		m_kopeck = -abs(m_kopeck);
	}
	long long money = (long long)m_rubles * 100 + m_kopeck;
	m_rubles = money / 100;
	m_kopeck = money % 100;
}

Money::Money(const Money& money)
{
	m_rubles = money.m_rubles;
	m_kopeck = money.m_kopeck;
}

Money::~Money()
{
}

long Money::Get_rubles()
{
	return m_rubles;
}

short Money::Get_kopeck()
{
	return m_kopeck;
}

void Money::Set_rubles(const long rubles)
{
	if (m_kopeck >= 0)
		m_rubles = rubles;
	else
		m_rubles = -abs(rubles);
	//m_rubles = rubles;
}

void Money::Set_kopeck(const short kopeck)
{
	m_kopeck = kopeck;

	if (m_rubles < 0)
		m_kopeck = -abs(m_kopeck);

	if (m_kopeck < 0)
		m_rubles = -abs(m_rubles);
}

Money& Money::operator=(const Money& money)
{
	if (&money == this)
		return *this;
	m_rubles = money.m_rubles;
	m_kopeck = money.m_kopeck;
	return *this;
}

Money Money::operator+(const Money& money)
{
	long long money_first = (long long)m_rubles * 100 + m_kopeck;
	long long money_second = (long long)money.m_rubles * 100 + money.m_kopeck;

	Money p;

	p.m_rubles = (money_first + money_second) / 100;
	p.m_kopeck = (money_first + money_second) % 100;
	return p;
}

Money Money::operator+(int value)
{
	long long money = (long long)m_rubles * 100 + m_kopeck;
	money += value;

	Money temp;

	temp.m_rubles = (money) / 100;
	temp.m_kopeck = (money) % 100;

	return temp;
}

Money& Money::operator+=(const Money& money)
{
	long long temp1 = (long long)m_rubles * 100 + m_kopeck;
	long long temp2 = (long long)money.m_rubles * 100 + money.m_kopeck;
	m_rubles = (temp1 + temp2) / 100;
	m_kopeck = (temp1 + temp2) % 100;
	return *this;
}


Money Money::operator/(const Money& money)
{
	Money division;
	if (&money == this)
	{
		division.m_rubles = 0;
		division.m_kopeck = 1;
		return division;
	}
	long long money_first = m_rubles;
	money_first *= 100;
	money_first += m_kopeck;
	long long money_second = money.m_rubles;
	money_second *= 100;
	money_second += money.m_kopeck;
	division.m_rubles = (money_first / money_second) / 100;
	division.m_kopeck = (money_first / money_second) % 100;
	return division;
}

Money& Money::operator/=(const Money& money)
{
	if (&money == this)
	{
		m_rubles = 0;
		m_kopeck = 1;
		return *this;
	}

	long long money_first = (long long)m_rubles * 100 + m_kopeck;
	long long money_second = (long long)money.m_rubles * 100 + money.m_kopeck;
	m_rubles = (money_first / money_second) / 100;
	m_kopeck = (money_first / money_second) % 100;
	return *this;
}

Money Money::operator/(const int value)
{
	int temp1 = m_rubles * 100 + m_kopeck;
	Money temp_money;
	temp_money.m_rubles = (temp1 / value) / 100;
	temp_money.m_kopeck = (temp1 / value) % 100;
	return temp_money;
}





bool Money::operator>(const Money& money)
{
	return (m_rubles > money.m_rubles || m_rubles == money.m_rubles && m_kopeck > money.m_kopeck);
}

bool Money::operator<(const Money& money)
{
	return (m_rubles < money.m_rubles || m_rubles == money.m_rubles && m_kopeck < money.m_kopeck);
}

bool Money::operator!=(const Money& money)
{
	return !(m_rubles == money.m_rubles && m_kopeck == money.m_kopeck);
}

bool Money::operator!=(int value)
{
	return !(m_rubles == value && m_kopeck == value);
}

bool Money::operator==(int value)
{
	return (m_rubles == value && m_kopeck == value);
}


bool Money::operator==(const Money& money)
{
	return (m_rubles == money.m_rubles && m_kopeck == money.m_kopeck);
}



void Money::clear()
{
	m_kopeck = 0;
	m_rubles = 0;
}


bool operator<(const Money& _Left, const Money& _Right)
{
	return (_Left.m_rubles < _Right.m_rubles || _Left.m_rubles == _Right.m_rubles && _Left.m_kopeck < _Right.m_kopeck);
}

std::ostream& operator<<(std::ostream& out, const Money& time)
{
	return (out << time.m_rubles << ":" << time.m_kopeck);
}

std::istream& operator>>(std::istream& in, Money& money)
{
	int kopeck_sup;
	std::cout << "Rubles? "; in >> money.m_rubles;
	do
	{
		std::cout << "Kopeck? "; in >> kopeck_sup;
		if (abs(kopeck_sup) > 99)
			std::cout << "Error!. Please enter a number from -99 to 99" << std::endl;
	} while (abs(kopeck_sup) > 99);
	money.m_kopeck = kopeck_sup;
	if (money.m_rubles < 0 || money.m_kopeck < 0)
	{
		money.m_rubles = -abs(money.m_rubles);
		money.m_kopeck = -abs(money.m_kopeck);
	}
	return in;
}
