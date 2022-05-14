#include "Fraction.h"
#include "iostream"
using namespace std;

void Fraction::Init(double A, double B, double x)
{
	m_A = A;
	m_B = B;
	m_x = x;
}

void Fraction::Read()
{
	setlocale(LC_ALL, "ru");
	cout << "������� ����. �: ";
	cin >> m_A;
	cout << "������� ����. �: ";
	cin >> m_B;
}

void Fraction::Show()
{
	cout << "y = " << m_A << " * x + " << m_B << endl;
}

void Fraction::SetX()
{
	cout << "������� �������� \'x\' ��� ���������� \'y\': ";
	cin >> m_x;
}

double Fraction::function()
{
	return (m_A*m_x+m_B);
}