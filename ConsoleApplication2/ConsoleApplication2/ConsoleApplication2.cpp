#include <iostream>
using namespace std;

int Sum(int a, int b)
{
	return a / b;
}

double Sum(double A, double B)
{
	return A / B;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int a, b;
	double A, B;
	cout << "Введите а и b для решения целых чисел"<< endl;
	cin >> a;
	cin >> b;
	cout << "Введите а и b для решения комплексных чисел"<< endl;
	cin >> A;
	cin >> B;
	cout << "Сумма целых числел = " << Sum(a, b) << "\nСумма комплексных числе = " << Sum(A, B);
	return 0;
}