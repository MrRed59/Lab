#include "Vector.h"
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
	//Vector a(5);

	//cout << a << endl;
	//cin >> a;
	//cout << a << endl;

	//a[2] = 100;

	//cout << "a: " << a << endl;

	//Vector b(10);

	//cout << "b: " << b << endl;

	//b = a;

	//cout << "b: " << b << endl;

	//Vector c(10);

	//c = b + 100;

	//cout << "c: " << c << endl;

	//cout << "The lenght of a = " << a() << endl << "/////////////////////////////////////////////////////////////////" << endl;

	////////////////////////////////////

	//cout << "*(a.first()): " << *(a.first()) << endl;

	Vector a(5);

	a[0] = 0;
	a[1] = 1;
	a[2] = 2;
	a[3] = 3;
	a[4] = 4;



	Iterator i = a.first();



	//++i;

	//cout << "*i[1]: " << *i << endl;

	//int n = 0;
	//for (i = a.first(); i != a.last(); ++i, n++)
	//	cout << "i" << n << ": " << * i << endl;

	//cout << "\nSets of numbers" << endl << "Enter the length of the vector \'d\'" << endl;
	//
	//int value;

	//Vector d(Checking_For_Valid_Input());

	//cout << "Enter the length of the vector \'e\'" << endl;

	//Vector e(Checking_For_Valid_Input());

	//cout << "\nEnter elements into vector \'d\'" << endl;

	//cin >> d;

	//cout << "Enter elements into vector \'e\'" << endl;

	//cin >> e;


	//cout << "Intersection of many: " << d * e << endl;

	//Iterator j = d.first();

	//cout << "Array \'b\':" << endl;
	//cout << "*j[0]: " << *j << endl;

	//n = d.GetSize() - 1;
	//for (j = d.last(); j != d.first(); --j, n--)
	//	cout << "*j" << n << ": " << *j << endl;
	//cout << "*j" << n << ": " << *d.first() << endl;

	return 0;
}