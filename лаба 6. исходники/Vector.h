#pragma once
#include<iostream>

class Iterator
{
	friend class Vector;
	int* elem;
public:
	Iterator()
	{
		elem = 0;
	}

	Iterator(const Iterator& temp)
	{
		elem = temp.elem;
	}

	bool operator==(const Iterator& temp)
	{
		return (elem == temp.elem);
	}

	bool operator!=(const Iterator& temp)
	{
		return (elem != temp.elem);
	}

	void operator++()
	{
		++elem;
	}

	void operator--()
	{
		--elem;
	}

	int& operator*()
		const {
		return *elem;
	}

};

class Vector
{
	int size;
	int* data;
	Iterator beg;
	Iterator end;
public:
	Vector(int);
	Vector(const Vector&);
	~Vector();
	Vector& operator=(const Vector&);
	Vector operator+(const int);
	int& operator[](int);
	int operator()();

	friend std::ostream & operator<<(std::ostream &, const Vector &);
	friend std::istream& operator>>(std::istream&, Vector&);

	Iterator first()
	{
		return beg;
	}

	Iterator last()
	{
		return end;
	}
};

