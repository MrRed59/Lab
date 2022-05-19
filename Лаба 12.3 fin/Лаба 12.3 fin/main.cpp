#include<iostream>
#include"Container.h"
#include"Money.h"


int main()
{
	try
	{
		size_t n{};
		std::cout << "N? ";
		std::cin >> n;

		Container<Money> m(n); //создать словарь
		m.Print();

		Money el = m.arithmetic_mean(); //вычислить среднее значение
		std::cout << "\nArithmetic mean: " << el << std::endl;
		m.Add(el); //добавить в конец
		m.Print();

		Money max = *m.Max();
		std::cout << "\nMax: " << max << std::endl;
		m.delete_el(max);
		m.Print();

		Money min = *m.Min();
		std::cout << "\nMin: " << min << std::endl;

		m.add_min_el();
		std::cout << "\nAdd minimal element: " << std::endl;
		m.Print();

		std::cout << "\nWhich element should i delete? " << std::endl;
		Money value;
		std::cin >> value;
		m.delete_el(value);
		m.Print();

		std::cout << "\nWhich position should i delete? " << std::endl;
		size_t pos;
		std::cin >> pos;
		m.remove_element_by_index(pos);
		m.Print();

		std::cout << "\nAdd the sum of the minimum and maximum elements to each element: " << std::endl;
		m.add_sum_max_min();
		m.Print();
	}
	catch (const int num_error)
	{
		switch (num_error)
		{
		case 0:
			std::cout << "Error in calculating the arithmetic mean. The container is empty." << std::endl;
			break;
		case 1:
			std::cout << "Error getting the maximum element. The container is empty." << std::endl;
			break;
		case 2:
			std::cout << "Error getting the minimum element. The container is empty." << std::endl;
			break;
		case 3:
			std::cout << "Error deleting an element. The container is empty." << std::endl;
			break;
		default:
			std::cout << "Error!" << std::endl;
			break;
		}
	}

	return 0;
}