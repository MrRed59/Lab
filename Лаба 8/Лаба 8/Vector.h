#pragma once
#include "Object.h"
class Vector/*: public Object*/
{
protected:
	Object** m_beg;
	int m_size;
	int m_cur;
	int Checking_For_Valid_Input();
public:
	Vector();
	Vector(int);
	~Vector();

	void Add();
	void Add(Object*);
	void Del();
	void Show();

	int operator()();
	void HandleEvent(const TEvent&);
};

