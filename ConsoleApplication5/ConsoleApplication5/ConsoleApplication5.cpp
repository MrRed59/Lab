﻿#include<iostream>
#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;

void main()
{
	setlocale(LC_ALL, "ru");
	cout << "Введите символы: ";
	char arr[255]; //создаем символьный массив
	gets_s(arr); //вводим туда значение через консоль
	int num = strlen(arr), x=0; //объявляем переменные: num - позиция следующего за последним введенным символом, х - промежуточная переменная для хранения значения
	cout << "Символы, отсортированные по возрастанию: ";
	for (int i = 0; i < num; i++) //цикл для проверки числа (с данным элементом массива сравнивается следующий цикл)
	{
		for (int j = i+1; j < num && i < num; j++) //цикл для проверки (больше ли следующие числа массива)
			{
				if (arr[i] > arr[j] && (arr[j] >= 97 && arr[j] <= 122 || arr[j] >= 65 && arr[j] <= 90)) //условие, при котором не будут сортироваться символы
				{
					x = arr[j];
					arr[j] = arr[i];
					arr[i] = x;
				}
			}
		cout << arr[i] << "\t";
	}
}