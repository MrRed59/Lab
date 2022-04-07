#pragma once
#include"TEvent.h"
#include<iostream>

class Object
{
public:
	Object();
	virtual void Show() = 0;
	virtual void Input(int) = 0;
	virtual ~Object(void);

	template<class T>
	void Checking_For_Valid_Input(T&);

	virtual void HandleEvent(const TEvent&) = 0;
};


template<class T>
void Object::Checking_For_Valid_Input(T& value)
{
	do
	{
		if (!std::cin)
		{
			std::cout << "Syntax error" << std::endl;
			std::cin.clear();
			std::cin.ignore(1024, '\n');
		}
		std::cin >> value;
	} while (!std::cin);
}

