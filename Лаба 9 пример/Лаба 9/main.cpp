#include"Vector.h"
#include<iostream>

int main()
{
	try
	{
		Vector x(2); //������ �� 2 ��������
		Vector y; //������ ������

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
	catch (const char* exeption)
	{
		std::cerr << exeption << std::endl;
	}
}