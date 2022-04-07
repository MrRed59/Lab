#pragma once
#include "Object.h"
class List
{
protected:
	Object** m_beg;
	int m_size;
	int m_cur;
	int Checking_For_Valid_Input();
private:
	unsigned static int counter;
public:
	List();
	List(int);
	~List();

	void Add();
	void Add(Object*);
	void Del();
	void Show(int = 0);

	int operator()();
	void HandleEvent(const TEvent&);
};

