#pragma once
#include "Object.h"
#include<iostream>

class Human :public Object
{
protected:
	std::string m_name;
	int m_age;
	unsigned int m_counter;
public:
	Human(void);
	virtual ~Human(void);

	void Show() override;
	void Input(int) override;

	Human(std::string, int);
	Human(const Human&);

	std::string Get_name();
	int Get_age();

	void Set_name(const std::string);
	void Set_age(const int);
	Human& operator=(const Human&);

	void HandleEvent(const TEvent&) override;
};

