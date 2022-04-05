#pragma once
#include<iostream>
#include "Pair.h"

class Rational :
	public Pair
{
protected:
public:
	Rational(void);
	~Rational(void);
	Rational(const int, const int);

	int Get_Numerator();
	int Get_Denominator();
	void Set_Numerator(const int numerator);
	void Set_Denominator(const int denominator);
	void Scan_First();
	void Scan_Second();


	Rational operator+(const Rational&);
	Rational& operator+=(const Rational&);
	Rational operator-(const Rational&);
	Rational& operator-=(const Rational&);
	Rational operator*(const Rational&);
	Rational& operator*=(const Rational&);

	friend istream &operator>>(istream& in, Rational&);
	friend ostream &operator<<(ostream& out, const Rational&);
};