#include "Fraction.h"
#include "iostream"
using namespace std;

void Fraction::Read()
{
	setlocale(LC_ALL, "ru");
	cout << "Введите коэф. А: ";
	cin >> A;
	cout << "Введите коэф. В: ";
	cin >> B;
}

void Fraction::Show()
{
	setlocale(LC_ALL, "ru");
	cout << "y = " << A << " * x + " << B << endl;
}

void Fraction::SetX()
{
	cout << "Введите значение \'x\' для вычисления \'y\': ";
	cin >> x;
}

double Fraction::function()
{
	return (A*x+B);
}