#pragma once
#include<iostream>
#include<string>
using namespace std;

class Computer
{
	string CPU;
	int amount_of_RAM;
	int HDD_memory_capacity;
public:
	Computer();
	Computer(const string , const int, const int);
	Computer(const Computer&);
	~Computer();
	string Get_CPU();
	void Set_CPU(string);
	int Get_amount_of_RAM();
	void Set_amount_of_RAM(int);
	int Get_HDD_memory_capacity();
	void Set_HDD_memory_capacity(int);
	void Show();
};

