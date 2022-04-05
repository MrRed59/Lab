#include "Fraction.h"
#include "iostream"
#include "conio.h"
using namespace std;

short Selection()
{
	bool boolean_Selection = 1;
	short choise;
	while (boolean_Selection)
	{
		cout << "Выберите нужный пункт: " << endl;
		cout << "1 - Ввести значения коэффициентов для линейного уравнения \'y=Ax+B\'" << endl;
		cout << "2 - Ввести значение \'x\' и вывести на экран значение \'y\'" << endl;
		cout << "0 - Закрыть программу" << endl;

		choise = _getche();
		cout << endl;
		if (choise > 51 || choise < 48)
			cout << "Ошибка синтаксиса!" << endl;
		else
		{
			boolean_Selection = false;
			choise -= 48;
		}
	}
	return choise;
}


int main()
{
	setlocale(LC_ALL, "ru");
	Fraction linear_equation;
	bool boolean_main = 1;
	while (boolean_main)
	{
		switch (Selection())
		{
		case 1:
			linear_equation.Read();
			cout << endl;
			break;
		case 2:
			linear_equation.SetX();
			cout << "y = " << linear_equation.function() << endl;
			cout << endl;
			break;
		case 0:
			boolean_main = 0;
			break;
		}
	}
}