#include "Rational.h"
#include<iostream>

Rational::Rational(void){}

Rational::~Rational(void){}

Rational::Rational(const int first, const int second):Pair(first, second){}

int Rational::Get_Numerator()
{
	return first;
}

int Rational::Get_Denominator()
{
	return second;
}

void Rational::Set_Numerator(const int numerator)
{
	this->first = numerator;
}

void Rational::Set_Denominator(const int denominator)
{
	this->second = denominator;
}

void Rational::Scan_First()
{
	cin >> first;
}

void Rational::Scan_Second()
{
	do {
		cin >> second;
		if (second == 0 && cin)
			cout << "Error. The denominator cannot be zero" << endl;
		if (!cin)
		{
			cout << "Syntax error" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
	} while (second == 0);
}


Rational Rational::operator+(const Rational&r)
{
	Rational result;
	if (second == r.second)
	{
		result.first = first + r.first;
		result.second = second;
	}
	else
	{
		result.second = second * r.second;
		result.first = first * r.second + r.first * second;
	}
	short reduce_the_numerator, cut_the_denominator;
		do {
			for (short i = 2; i < 10; i++)
			{
				reduce_the_numerator = result.first % i;
				cut_the_denominator = result.second % i;
				if (!reduce_the_numerator && !cut_the_denominator)
				{
					result.first /= i;
					result.second /= i;
					i = 1;
				}
			}
		} while (!reduce_the_numerator && !cut_the_denominator);
	return result;
}

Rational& Rational::operator+=(const Rational& r)
{
	if (second == r.second)
		first += r.first;
	else
	{
		second *= r.second;
		first = first * r.second + r.first * second;
	}
	short reduce_the_numerator, cut_the_denominator;
	do {
		for (short i = 2; i < 10; i++)
		{
			reduce_the_numerator = first % i;
			cut_the_denominator = second % i;
			if (!reduce_the_numerator && !cut_the_denominator)
			{
				first /= i;
				second /= i;
				i = 1;
			}
		}
	} while (!reduce_the_numerator && !cut_the_denominator);
	return *this;
}

Rational Rational::operator-(const Rational& r)
{
	Rational result;
	if (second == r.second)
	{
		result.first = first - r.first;
		result.second = second;
	}
	else
	{
		result.second = second * r.second;
		result.first = first * r.second - r.first * second;
	}
	short reduce_the_numerator, cut_the_denominator;
	do {
		for (short i = 2; i < 10; i++)
		{
			reduce_the_numerator = result.first % i;
			cut_the_denominator = result.second % i;
			if (!reduce_the_numerator && !cut_the_denominator)
			{
				result.first /= i;
				result.second /= i;
				i = 1;
			}
		}
	} while (!reduce_the_numerator && !cut_the_denominator);
	return result;
}

Rational& Rational::operator-=(const Rational& r)
{
	if (second == r.second)
		first -= r.first;
	else
	{
		second *= r.second;
		first = first * r.second - r.first * second;
	}
	short reduce_the_numerator, cut_the_denominator;
	do {
		for (short i = 2; i < 10; i++)
		{
			reduce_the_numerator = first % i;
			cut_the_denominator = second % i;
			if (!reduce_the_numerator && !cut_the_denominator)
			{
				first /= i;
				second /= i;
				i = 1;
			}
		}
	} while (!reduce_the_numerator && !cut_the_denominator);
	return *this;
}

Rational Rational::operator*(const Rational& r)
{
	Rational result;
	result.first = first * r.first;
	result.second = second * r.second;
	short reduce_the_numerator, cut_the_denominator;
	do {
		for (short i = 2; i < 10; i++)
		{
			reduce_the_numerator = result.first % i;
			cut_the_denominator = result.second % i;
			if (!reduce_the_numerator && !cut_the_denominator)
			{
				result.first /= i;
				result.second /= i;
				i = 1;
			}
		}
	} while (!reduce_the_numerator && !cut_the_denominator);
	return result;
}

Rational& Rational::operator*=(const Rational& r)
{
	first *= r.first;
	second *= r.second;
	short reduce_the_numerator, cut_the_denominator;
	do {
		for (short i = 2; i < 10; i++)
		{
			reduce_the_numerator = first % i;
			cut_the_denominator = second % i;
			if (!reduce_the_numerator && !cut_the_denominator)
			{
				first /= i;
				second /= i;
				i = 1;
			}
		}
	} while (!reduce_the_numerator && !cut_the_denominator);
	return *this;
}


istream& operator>>(istream& in, Rational&r)
{

	cout << "Numerator: "; cin >> r.first;
	while (true)
	{
		cout << "/ Denominator: "; cin >> r.second;
		if (r.second == 0)
			cout << "Error. You cannot enter \'0\'" << endl;
		else
			break;
	}
	return in;
}

ostream& operator<<(ostream& out, const Rational& r)
{
	out << r.first;

	out << "/" << r.second;
	return out;
}