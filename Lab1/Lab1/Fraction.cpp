#include "Fraction.h"
#include "iostream"
using namespace std;

void Fraction::Read()
{
	setlocale(LC_ALL, "ru");
	cout << "������� ����. �: ";
	cin >> A;
	cout << "������� ����. �: ";
	cin >> B;
}

void Fraction::Show()
{
	setlocale(LC_ALL, "ru");
	cout << "y = " << A << " * x + " << B << endl;
}

void Fraction::SetX()
{
	cout << "������� �������� \'x\' ��� ���������� \'y\': ";
	cin >> x;
}

double Fraction::function()
{
	return (A*x+B);
}