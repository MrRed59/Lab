#include <iostream>
#include<conio.h>
#include "Money.h"

using namespace std;

Money Choice_of_equation(const short &change, const Money &money_first, const Money& money_second, const Money& money_third, const Money& money_fourth)
{
	Money t;
	switch (change)
	{
	case 1:
	{		
		t = money_first;
		return t;
	}
	case 2:
	{
		t = money_second;
		return t;
	}
	case 3:
	{
		t = money_third;
		return t;
	}
	case 4:
	{
		t = money_fourth;
		return t;
	}
	}
}

void Selection(short &change_fin)
{
	cout << "What class objects to add? ";
	short* change = new short[2];
	do
	{
		change[0] = _getche();
		if (change[0] > 52 || change[0] < 49)
			cout << endl << "Error! Choose a number from 1 to 4" << endl;
	} while (change[0] > 52 || change[0] < 49);
	cout << " And ";
	do
	{
		change[1] = _getche();
		if (change[1] > 52 || change[1] < 49)
			cout << endl << "Error! Choose a number from 1 to 4" << endl;
	} while (change[1] > 52 || change[1] < 49);
	cout << endl;
	for (short i = 0; i < 2; i++)
	{
		change[i] -= 48;
	}
	change_fin = change[0] * 10 + change[1];
	delete[] change;
}



int main()
{
	double value;
	short change;
	Money money_first;
	Money money_second;
	Money money_third;
	Money money_fourth;
	Money sum;
	Money multiplication;

	cout << "a: " << endl;
	cin >> money_first;
	cout << "b: " << endl;
	cin >> money_second;
	cout << "c: " << endl;
	cin >> money_third;
	cout << "d: " << endl;
	cin >> money_fourth;

	sum = (money_first + money_second) / (money_third + money_fourth);

	cout << "Division of sums: " << sum << endl;

	Selection(change);
	cout << "Enter the number to multiply" << endl;
	cin >> value;
	multiplication = (Choice_of_equation((change/10), money_first, money_second, money_third, money_fourth) + Choice_of_equation((change%10), money_first, money_second, money_third, money_fourth)) * value;

	cout << "Division of multiplication: " << multiplication << endl;


	cout << "a = " << money_first << endl;
	cout << "b = " << money_second << endl;
	cout << "c = " << money_third << endl;
	cout << "d = " << money_fourth << endl;
}