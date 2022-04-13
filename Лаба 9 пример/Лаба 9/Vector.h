#pragma once
#include<iostream>
const int MAX_SIZE = 30;

class Vector
{
	int m_size;
	int* m_beg;
public:
	//---------constructor-----------
	Vector();
	Vector(int);
	Vector(int, int*);
	Vector(const Vector&);
	~Vector();
	//-------overloaded-functions----
	const Vector& operator=(const Vector&);
	int operator[](int);
	Vector operator+(int);
	Vector operator--();
	//-------friend-functions---------
	friend std::ostream& operator<<(std::ostream&, const Vector&);
	friend std::istream& operator>>(std::istream&, Vector&);
};

