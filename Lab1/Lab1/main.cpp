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
	A.Init(3, 2, 5); //������������� ���������� �
	B.Read(); //������������� ���������� �
	cout << "A:" << endl;
	A.Show(); //����� �������� ����� ���������� �
	cout << "B:" << endl;
	B.Show(); //����� �������� ����� ���������� �
	//����� �������� �������, ������������ � ������� ������� function
	cout << "����� �������� �������, ������������ � ������� ������� function" << endl;
	cout << "A:" << endl;
	cout << "y = " << A.function() << endl;
	cout << "B:" << endl;
	B.SetX();
	cout << "y = " << B.function() << endl;
	//���������
	cout << "���������:" << endl;
	Fraction* p_fraction = new Fraction;
	p_fraction->Init(2, 5, 3);
	p_fraction->Show();
	cout << "y = " << p_fraction->function() << endl;
	//�������
	cout << "M������:" << endl;
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
	//������������ �������
	cout << "������������ �������:" << endl;
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
	//����� ������� make_fraction()
	cout << "B���� ������� make_fraction() " << endl;
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