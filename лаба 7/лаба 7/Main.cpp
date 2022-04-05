#include "Vector.h"
#include "Money.h"
#include<iostream>

using namespace std;

int Checking_For_Valid_Input()
{
	int temp;
	do
	{
		cin >> temp;

		if (temp <= 0 && cin)
		{
			cout << "Enter a number greater than zero" << endl;
			cin.ignore(1024, '\n');
		}

		if (!cin)
		{
			cout << "Syntax error" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
	} while (temp <= 0);
	return temp;
}


int main()
{
	Vector<int> a(5, 0);

	cout << "Enter the elements in Vector \'A\': \t\t" << endl;
	cin >> a;

	cout << "===========================================================================" << endl;

	cout << "A: \t\t" << a << endl;

	Vector<int> b(10, 1);

	cout << "B: \t\t" << b << endl;

	b.SetRand();

	cout << "===========================================================================" << endl;

	cout << "B filled with random numbers: \t" << b << endl;

	cout << "===========================================================================" << endl;

	cout << "Intersection of many: \t\t" << a * b << endl;

	cout << "===========================================================================" << endl;

	b = a;

	cout << "B = A: \t\t" << b << endl;
	cout << "A[2]: \t\t" << a[2] << endl;
	cout << "size = \t\t" << a() << endl;

	b = a + 10;

	cout << "B = A + 10: \t" << b << endl;

	cout << "===========================================================================" << endl;

	//class Money

	cout << "===========================================================================" << endl;
	cout << "class Money" << endl;

	//Money money;

	//cin >> money;
	//cout << "Money \'1\': " << money << endl;

	//int k;

	//cout << "k: ";
	//cin >> k;

	//Money m;
	//m = money + k;
	//cout << "Money \'2\'+ k : " << m << endl;

	//Vector <Money> test_Vector_Time_first(5, money);
	//cout << "Enter the elements in Money A: ";
	//cin >> test_Vector_Time_first;
	//cout << "Money A: " << test_Vector_Time_first << endl;

	//Vector <Money> test_Vector_Time_second(10, money);
	//cout << "Money B: " << test_Vector_Time_second << endl;

	//test_Vector_Time_second = test_Vector_Time_first;

	//cout << "B = A: \t\t" << test_Vector_Time_second << endl;
	//cout << "A[2]: \t\t" << test_Vector_Time_first[2] << endl;
	//cout << "Size \'A\': \t" << test_Vector_Time_first() << endl;

	//test_Vector_Time_second = test_Vector_Time_first + money;

	//cout << "B = A + Money 1: \t" << test_Vector_Time_second << endl;

	return 0;
}