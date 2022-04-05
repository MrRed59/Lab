#pragma once
#include<iostream>
#include"object.h"
using namespace std;
class Pair:public Object
{
protected:
	int first;
	int second;
	int Checking_For_Valid_Input(void);
public:
	Pair(void);
	virtual ~Pair(void);
	Pair(const int, const int);
	Pair(const Pair&);

	void Show() override;

	int Get_First();
	int Get_Second();
	void Set_First(const int);
	void Set_Second(const int);
	void Scan_First();
	void Scan_Second();
	long long Multiplication_Of_Class_Fields();


	Pair& operator=(const Pair&);
	Pair operator*(const Pair&);
	Pair operator-(const Pair&);
	Pair& operator*=(const Pair&);
	bool operator==(const Pair&);

	friend istream& operator>>(istream& in, Pair&);
	friend ostream& operator<<(ostream& out, const Pair&);
};

