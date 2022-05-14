#include "Computer.h"
#include<iostream>
#include<string>
#include<Windows.h>

using namespace std;

Computer Make_Computer()
{
	SetConsoleCP(1251);
	string CPU;
	int amount_of_RAM;
	int HDD_memory_capacity;
	cout << "Âגוהטעו ÖÏ: " << endl;
	cin >> CPU;
	cout << "Âגוהטעו מבתול ÎÏ(Ìב): " << endl;
	cin >> amount_of_RAM;
	cout << "Âגוהטעו מבתול ÆÄ(Ìב): " << endl;
	cin >> HDD_memory_capacity;
	Computer Comp(CPU, amount_of_RAM, HDD_memory_capacity);
	SetConsoleCP(866);
	return Comp;
}

void Print_Computer(Computer &Comp)
{
	Comp.Show();
}

int main()
{
	Computer Comp1;
	cout << "1: " << endl;
	Comp1.Show();
	Computer Comp2("AMD FX6350", 1024, 2048);
	cout << "2: " << endl;
	Comp2.Show();
	Computer Comp3 = Comp2;
	Comp3.Set_CPU("Intel Core I3");
	Comp3.Set_amount_of_RAM(256);
	Comp3.Set_HDD_memory_capacity(512);
	cout << "3: " << endl;
	Print_Computer(Comp3);
	Comp1 = Make_Computer();
	Comp1.Show();
}