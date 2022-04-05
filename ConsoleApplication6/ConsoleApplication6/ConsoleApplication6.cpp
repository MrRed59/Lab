#include<iostream>
#include<stdio.h>
using namespace std;

int Min(int size, ...) //функция с переменным числом параметров
{
	int* parr = &size + 1, min = *parr; /*объявляем переменные : указатель * parr - указатель на следующий элемент после size,
	min - переменная для хранения минимального значения (если циклы не найдут минимальное число, 
	значит минимальное число - нулевой элемент массива, по этому используем указатель на его нулевой элемент)*/	
	for (; size != 0; size--) //цикл для элемента, с которым сравнивается следующий цикл для нахождения минимального числа
	{
		if (min > *parr)
			min = *parr;
		parr++; // инкремент указателя "parr" (проверяющее число) для перехода на следующий элемент массива
	}
	return min; 
}

double Min(double size, ...) // перегруженная функция, которая находит минимальное значение, но с действительным типом данных
{
	double* parr = &size + 1, min = *parr;
	for (; size != 0; size--)
	{
		if (min > *parr)
			min = *parr;
		parr++;
	}
	return min;
}

void main()
{
	setlocale(LC_ALL, "Rus");

	bool choise; // переменная для выбора типа данных для нахождения минимального числа
	choise = 0;
	cout << "Найти минимальное число для типа int/double? 0/1" << endl;
	cin >> choise;

	int size_int5 = 5, size_int10 = 10, size_int12 = 12, arr_int[12]; // объявляем переменные: size - количество операций функции Min, arr_int [] - массив для записи в него целых чисел
	double size_double5 = size_int5, size_double10 = size_int10, size_double12 = size_int12, arr_double[12]; // объявляем переменные: size - количество операций функции Min, arr_int [] - массив для записи в него чисел с плавающей точкой

	cout << "Введите числа, из которых требуется найти минимальное: ";
	for (int i = 0; i < size_int12; i++) // цикл для записи в массивы чисел целых или с плавающей точкой в зависимости от выбора типа данных
	{
		if (choise == true)
			cin >> arr_double[i];
		else
			cin >> arr_int[i];
	}

	if (choise == true) // условие для целочисленного массива или действительного массива
	{
		cout << "Минимальное число из первых пяти введенных = " << Min(size_double5, arr_double[0], arr_double[1], arr_double[2], arr_double[3], arr_double[4]) << endl; 
		cout << "Минимальное число из первых десяти введенных = " << Min(size_double10, arr_double[0], arr_double[1], arr_double[2], arr_double[3], arr_double[4], arr_double[5], arr_double[6], arr_double[7], arr_double[8], arr_double[9]) << endl; 
		cout << "Минимальное число из первых двенадцати введенных = " << Min(size_double12, arr_double[0], arr_double[1], arr_double[2], arr_double[3], arr_double[4], arr_double[5], arr_double[6], arr_double[7], arr_double[8], arr_double[9], arr_double[10], arr_double[11]) << endl; 
	}

	else
	{

		cout << "Минимальное число из первых пяти введенных = " << Min(size_int5, arr_int[0], arr_int[1], arr_int[2], arr_int[3], arr_int[4]) << endl; 
		cout << "Минимальное число из первых десяти введенных = " << Min(size_int10, arr_int[0], arr_int[1], arr_int[2], arr_int[3], arr_int[4], arr_int[5], arr_int[6], arr_int[7], arr_int[8], arr_int[9]) << endl; 
		cout << "Минимальное число из первых двенадцати введенных = " << Min(size_int12, arr_int[0], arr_int[1], arr_int[2], arr_int[3], arr_int[4], arr_int[5], arr_int[6], arr_int[7], arr_int[8], arr_int[9], arr_int[10], arr_int[11]) << endl; 
	}
}