#include "Computer.h"
#include<iostream>
#include<string>

using namespace std;

Computer::Computer()
{
	CPU = "";
	HDD_memory_capacity = 0;
	amount_of_RAM = 0;
	setlocale(LC_ALL, "ru");
	cout << "Конструктор без параметров для объекта " << this << endl;
}

Computer::Computer(const string CPU, const int amount_of_RAM, const int HDD_memory_capacity)
{
	this->CPU = CPU;
	this->amount_of_RAM = amount_of_RAM;
	this->HDD_memory_capacity = HDD_memory_capacity;
	setlocale(LC_ALL, "ru");
	cout << "Конструктор с параметрами для объекта " << this << endl;
}

Computer::Computer(const Computer& t)
{
	CPU = t.CPU;
	amount_of_RAM = t.amount_of_RAM;
	HDD_memory_capacity = t.HDD_memory_capacity;
	setlocale(LC_ALL, "ru");
	cout << "Конструктор копирования для объекта " << this << endl;
}

Computer::~Computer()
{
	setlocale(LC_ALL, "ru");
	cout << "Деструктор для объекта " << this << endl;
}

string Computer::Get_CPU()
{
	return CPU;
}

int Computer::Get_amount_of_RAM()
{
	return amount_of_RAM;
}

int Computer::Get_HDD_memory_capacity()
{
	return HDD_memory_capacity;
}

void Computer::Set_CPU(const string CPU)
{
	this->CPU = CPU;
}

void Computer::Set_amount_of_RAM(const int amount_of_RAM)
{
	this->amount_of_RAM = amount_of_RAM;
}

void Computer::Set_HDD_memory_capacity(const int HDD_memory_capacity)
{
	this->HDD_memory_capacity = HDD_memory_capacity;
}

void Computer::Show()
{
	setlocale(LC_ALL, "ru");
	cout << "ЦП: " << CPU << endl;
	cout << "Объем ОП(Мб): " << amount_of_RAM << endl;
	cout << "Объем памяти ЖД(Мб): " << HDD_memory_capacity << endl;
}
