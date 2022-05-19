#include<iostream>
#include"Vector.h"
#include"Money.h"


int main()
{
	int n;
	std::cout << "N? ";
	std::cin >> n;
	Vector <Money> money(n);
	money.Add();

	money.Print();

	//

	std::cout << "\nAdd minimal element: ";
	money.add_min_el();
	money.Print();

	int pos;

	std::cout << "\nPosition to delete an element? ";
	std::cin >> pos;

	std::cout << "\nRemove element by index: " << std::endl;
	money.remove_element_by_index(pos);
	money.Print();

	//

	std::cout << "\nAdd the sum of the minimum and maximum elements: " << std::endl;
	money.add_min_max();
	money.Print();

}