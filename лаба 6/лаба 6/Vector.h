#pragma once
#include<iostream>

class Iterator
{
	friend class Vector;
	int* elem;
	int size;
public:
	Iterator()
	{
		elem = 0;
		size = 0;
	}

	Iterator(const Iterator& temp)
	{
		elem = temp.elem;
		size = 0;
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
	Vector(const Vector&, int);
	Vector(const Vector&);
	~Vector();

	int GetSize()
	{
		return size;
	}

	Vector& operator=(const Vector&);
	Vector operator+(const int);	
	Vector operator*(const Vector&);
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

