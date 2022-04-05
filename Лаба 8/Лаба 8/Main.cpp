#include "Car.h"
#include "Lorry.h"
#include "Vector.h"
#include "Dialog.h"
#include <iostream>

int main()
{
	//Car* a = new Car;
	//std::cout << "Car: " << std::endl;
	//a->Input();
	//std::cout << "==============================================================" << std::endl;
	//a->Show();
	//std::cout << "==============================================================" << std::endl;

	//Lorry* b = new Lorry;
	//std::cout << "Lorry: " << std::endl;
	//b->Input();
	//std::cout << "==============================================================" << std::endl;
	//b->Show();
	//std::cout << "==============================================================" << std::endl;

	/////////////////////////////////////////////////

	//std::cout << "==============================================================" << std::endl;
	//std::cout << "Vector: " << std::endl;
	//std::cout << "==============================================================" << std::endl;

	//Vector v(10);
	//Object* p = a;
	//v.Add(p);
	//p = b;
	//v.Show();
	//v.Del();
	//std::cout << "\nVector size = " << v();

	Dialog D;
	D.Execute();

	return 0;
}