#include "Vector.h"
#include<iostream>

using namespace std;

int main()
{
	Vector a(5);

	cout << a << endl;
	cin >> a;
	cout << a << endl;

	a[2] = 100;

	cout << "a: " << a << endl;

	Vector b(10);

	cout << "b: " << b << endl;

	b = a;

	cout << "b: " << b << endl;

	Vector c(10);

	c = b + 100;

	cout << "c: " << c << endl;

	cout << "The lenght of a = " << a() << endl << "/////////////////////////////////////////////////////////////////" << endl;

	/////////////////////////////////

	cout << "*(a.first()): " << *(a.first()) << endl;

	Iterator i = a.first();

	++i;

	cout << "*i[1]: " << *i << endl;

	int n = 0;
	for (i = a.first(); i != a.last(); ++i, n++)
		cout << "i" << n << ": " << * i << endl;

	return 0;
}