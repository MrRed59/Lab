#pragma once
#include<iostream>
const int MAX_SIZE = 30;

class Set
{
	int m_size;
	int* m_beg;
	bool m_realization = 0;
public:
	//---------constructor-----------
	Set();
	Set(int);
	Set(int, int*);
	Set(const Set&, int size = 0);
	~Set();
	//-------Set---------------------
	void Set_realization(bool realization){m_realization = realization;}
	//-------overloaded-functions----
	int operator()();
	const Set& operator=(const Set&);
	int operator[](int);
	Set operator+(int);
	Set operator--();
	Set operator*(const Set&);
	//-------friend-functions---------
	friend std::ostream& operator<<(std::ostream&, const Set&);
	friend std::istream& operator>>(std::istream&, Set&);
};

