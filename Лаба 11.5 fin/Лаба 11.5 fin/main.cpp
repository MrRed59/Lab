#include <iostream>
#include<vector>
#include"Money.h"
#include"Vector.h"

int main()
{
	size_t n{};
	std::cout << "n? ";
	std::cin >> n;

	Vector<Money> v(n);
	v.Print();

	Money money = v.arithmetic_mean();

	std::cout << "Arithmetic mean = " << money << std::endl;
	std::cout << "Add arithmetic mean: " << std::endl;
	std::cout << "Position? ";

	int pos;

	std::cin >> pos;

	v.Add_to_queue(money, pos);
	v.Print();

	v.add_min_element();
	std::cout << "Add a minimal element: " << std::endl;
	v.Print();

	std::cout << "\nPosition to delete an element? ";
	std::cin >> pos;
	v.remove_element_by_index(pos); //удалить элемент с этим номером
	std::cout << "Remove element by index: " << std::endl;
	v.Print();

	v.add_sum_max_min();
	std::cout << "Add the sum of the maximum and minimum: " << std::endl;
	v.Print();

	std::cout << "Delete Max = " << std::endl;
	
	v.Delete_from_queue();
	v.Print();

	std::cout << "Division = " << std::endl;

	v.Division();
	v.Print();
}