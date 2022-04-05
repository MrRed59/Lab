#include "Object.h"
#include<iostream>

Object::Object()
{
}

Object::~Object(void)
{
}

int Object::Checking_For_Valid_Input()
{
	int value;
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
	return value;
}

