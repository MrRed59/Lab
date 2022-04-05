#pragma once
#include"Object.h"
#include<iostream>

class Vector
{
public:
	Vector(void);
	Vector(const int);
	~Vector(void);
	Vector(const Vector&);
	void Add(Object*);

	int GetSize(void);
	int GetNumberOfOccupiedCells(void);
	void PrintLastElement();
	void PopBack();
	void Clear();

	Vector &operator=(const Vector&);

	friend std::ostream & operator<<(std::ostream & out, const Vector&);

private:
	Object** beg;
	int size;
	int cur;
};

