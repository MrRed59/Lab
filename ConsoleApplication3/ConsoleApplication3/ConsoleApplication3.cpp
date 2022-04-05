#include<iostream>
#include<stdio.h>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Rus");
	char arr[255];
	gets_s(arr);
	cout << arr;
}

