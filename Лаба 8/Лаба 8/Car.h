#pragma once
#include "Object.h"
#include<iostream>

class Car :public Object
{
protected:
	std::string m_mark;
	int m_cyl;
	int m_power;
public:
	Car(void);
	virtual ~Car(void);
	void Show() override;
	void Input() override;
	Car(std::string, int, int);
	Car(const Car&);

	std::string Get_mark();
	int Get_power();
	int Get_cyl();

	void Set_mark(const std::string);
	void Set_cyl(const int);
	void Set_power(const int);
	Car& operator=(const Car&);

	void HandleEvent(const TEvent&) override;
};

