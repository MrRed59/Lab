#include "Fraction.h"
#include "iostream"
#include "conio.h"
using namespace std;

Fraction make_fraction(const double A, const double B, const double x)
{
	Fraction t;
	t.Init(A, B, x);
	return t;
}

int main()
{
	setlocale(LC_ALL, "ru");
	Fraction A;
	Fraction B;
	A.Init(3, 2, 5); //инициализация переменной А
	B.Read(); //инициализация переменной В
	cout << "A:" << endl;
	A.Show(); //Вывод значений полей переменной А
	cout << "B:" << endl;
	B.Show(); //Вывод значений полей переменной В
	//вывод значения степени, вычесленного с помощью функции function
	cout << "Вывод значения степени, вычесленного с помощью функции function" << endl;
	cout << "A:" << endl;
	cout << "y = " << A.function() << endl;
	cout << "B:" << endl;
	B.SetX();
	cout << "y = " << B.function() << endl;
	//указатели
	cout << "Указатели:" << endl;
	Fraction* p_fraction = new Fraction;
	p_fraction->Init(2, 5, 3);
	p_fraction->Show();
	cout << "y = " << p_fraction->function() << endl;
	//массивы
	cout << "Mассивы:" << endl;
	Fraction arr[3];
	for (size_t i = 0; i < 3; i++)
		arr[i].Read();
	for (size_t i = 0; i < 3; i++)
		arr[i].Show();
	for (size_t i = 0; i < 3; i++)
	{
		arr[i].SetX();
		arr[i].function();
		cout << "y[" << i << "] = " << arr[i].function() << endl;
	}
	//динамические массивы
	cout << "Динамические массивы:" << endl;
	Fraction* p_arr = new Fraction[3];
	for (size_t i = 0; i < 3; i++)
		p_arr[i].Read();
	for (size_t i = 0; i < 3; i++)
		p_arr[i].Show();
	for (size_t i = 0; i < 3; i++)
	{
		p_arr[i].SetX();
		p_arr[i].function();
		cout << "y[" << i << "] = " << p_arr[i].function() << endl;
	}
	delete[] p_arr;
	//вызов функции make_fraction()
	cout << "Bызов функции make_fraction() " << endl;
	double a, b, x;
	cout << "A= ";
	cin >> a;
	cout << "B= ";
	cin >> b;
	cout << "x= ";
	cin >> x;
	Fraction F = make_fraction(a, b, x);
	F.Show();
	cout << F.function();
	return 0;
}