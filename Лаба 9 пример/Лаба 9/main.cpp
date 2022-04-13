#include"Vector.h"
#include <exception>
#include<iostream>

int main()
{
	try
	{
		Vector x(2); //вектор на 2 элемента
		Vector y; //пуской вектор

		std::cout << x; 
		std::cout << "Vector number? ";

		int i;
		std::cin >> i;

		std::cout << "x[" << i << "] : " << x[i] << std::endl;

		std::cout << "y = x + 3;" << std::endl;
		y = x + 3;
		std::cout << "y = " << y;

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
	catch (const char* exception)
	{
		std::cerr << exception << std::endl;
	}

	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}