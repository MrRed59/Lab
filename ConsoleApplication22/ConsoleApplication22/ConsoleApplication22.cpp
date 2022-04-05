#include <iostream>
#include <cmath>
using namespace std;

// cos(2/𝑥)−2sin(1/𝑥)+3/𝑥 = 0

double F(const double& X)
{
	return cos(2 / X) - 2 * sin(1 / X) + 3 / X;
}

void Change(double& a, double& b) // функция, проверяющая в правильном стоят порядке числа на прямой или нет. Если нет, то меняет их местами
{
	if (a > b)
	{
		double value;
		value = a;
		a = b;
		b = value;
	}

	if (b > 0)
	{
		b = -0.000000000000001;
		cout << "Выбранный интервал не подходит, конечное значение интервала было заменено на \'-0.0000000000000001\'" << endl;
	}
}


int main()
{
	setlocale(LC_ALL, "ru");
	double a, b, value, eps(0.0001), x;
	cout << "Введите начало и конец интервала от a до b (корень лежит в интервале [-2.5;-1.5]):\n";
	cin >> a >> b;

	Change(a, b);


	while ((F(a) * F(b)) > 0) //проверка на сходимость
	{
		cout << "На интервале от " << a << " до " << b << " корней нет" << endl;
		cout << "Введите начало и конец интервала от a до b (корень лежит в интервале [-2.5;-1.5])" << endl;
		cin >> a >> b;
		Change(a, b);
	}

	int num = 0;

	cout << endl;

	//Половинное деление
	do
	{
		num++;
		x = (a + b) / 2;

		if ((F(a) * F(x)) < 0) // Проверка дял перехода на следующую итерацию
			b = x;
		else
			a = x;

		cout << "x(" << num << ")\t=  " << x << endl;
	} while (abs(F(x)) > eps);

	cout << endl << endl << "=================================================" << endl;
	cout << "Результат вычислений методом половинного деления:" << endl;
	cout << "Заданная точность: " << eps << endl;
	cout << "x = " << x << endl;
	cout << "Количество итераций: " << num << endl;

	return 0;
}
