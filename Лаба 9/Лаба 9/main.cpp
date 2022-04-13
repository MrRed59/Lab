#include"Set.h"
#include "Error.h"
#include<iostream>

int main()
{
	try
	{
		std::cout << "Realization 1 or 2? " << std:: endl;
		short choise;
		std::cin >> choise;

		Set x(5); //вектор на 5 элементов
		Set y; //пуской вектор

		x.Set_realization(choise - 1); //выбор реализации для множеств
		y.Set_realization(choise - 1);

		std::cout << "x: ";
		std::cin >> x;

		std::cout << x; 
		std::cout << "Vector number? ";

		int i;
		std::cin >> i;

		std::cout << "x[" << i << "] : " << x[i] << std::endl;

		std::cout << "y = x + 3;" << std::endl;
		y = x + 3;
		std::cout << "y = " << y;

		std::cout << "Intersection of many: " << x * y << std::endl;

		std::cout << "--x;" << std::endl;
		--x;
		std::cout << "x = " << x;
		std::cout << "--x;" << std::endl;
		--x;
		std::cout << "x = " << x;
		std::cout << "--x;" << std::endl;
		--x;
		std::cout << "x = " << x;
		std::cout << "--x;" << std::endl;
		--x;
		std::cout << "x = " << x;
		std::cout << "--x;" << std::endl;
		--x;
		std::cout << "x = " << x;
		std::cout << "--x;" << std::endl;
		--x;
		std::cout << "x = " << x;

	}

	catch (const int value)
	{
		switch (value)
		{
		case 1:
			std::cout << "Error! The vector size specified is too large" << std::endl;
			break;
		case 2:
			std::cout << "Error! The vector size specified is too large" << std::endl;
			break;
		case 3:
			std::cout << "Error! The entered number cannot be less than zero" << std::endl;
			break;
		case 4:
			std::cout << "Vector Length more than max size" << std::endl;
			break;
		case 5:
			std::cout << "Error! Unable to add element" << std::endl;
			break;
		case 6:
			std::cout << "Error! Element cannot be removed" << std::endl;
			break;
		}
	}
	catch (const Error& e)
	{
		std::cout<< e.what() << std::endl;
	}
}