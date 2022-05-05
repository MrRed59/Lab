#include<iostream>
#include"Container.h"
#include"Money.h"


int main()
{
	size_t n{};
	std::cout << "N? ";
	std::cin >> n;
	Container <Money> v(n);
	v.Print();

	Money el = v.arithmetic_mean(); //вычислить среднее значение
	int pos;
	std::cout << "Arithmetic mean: " << el << std::endl;
	std::cout << "Add arithmetic mean on position: " << std::endl;
	std::cin >> pos;
	v.Add(pos, el);
	v.Print();

	std::cout << "Delete max: " << std::endl;
	v.Del();
	v.Print();

	std::cout << "Division by the minimum element: " << std::endl;
	v.division();
	v.Print();
}
