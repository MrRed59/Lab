#include<iostream>
#include"Vector.h"
#include"Money.h"


int main()
{
	Vector<Money>vec(2);

	std::cout << "Money \'1\': ";
	std::cin >> vec[0];

	int k;

	std::cout << "k: ";
	std::cin >> k;

	std::cout << "Money \'2\': ";
	std::cin >> vec[1];

	vec[1] = vec[1] + k;
	std::cout << "Money \'2\'+ k : " << vec[1] << std::endl;

	std::cout << "Enter the elements in Money A: ";
	Vector <Money> V_money_1(5);
	V_money_1.Add();
	std::cout << "Money A: ";
	V_money_1.Print();
	std::cout << std::endl;

	std::cout << "Money B: " << std::endl;
	Vector <Money> V_money_2(10);
	V_money_2.Add();
	std::cout << "Money B: " << std::endl;
	V_money_2.Print();
	std::cout << std::endl;

	V_money_2 = V_money_1;

	std::cout << "B = A: \t";
	V_money_2.Print();
	std::cout << std::endl;


	std::cout << "A[2]: \t" << V_money_1[2] << std::endl;
	std::cout << "Size \'A\': \t" << V_money_2.Size() << std::endl;

	V_money_2 = V_money_1 + vec[0];

	std::cout << "B = A + Money 1: \t";
	V_money_2.Print();
	std::cout << std::endl;
}