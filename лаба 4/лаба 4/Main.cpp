#include "Pair.h"
#include "Rational.h"
#include<iostream>
#include<conio.h>

using namespace std;

short Checking_For_Valid_Input(const short low, const short high)
{
	short choise;
	do
	{
		choise = _getche();
		cout << endl;
		if (choise > (high + 48) || choise < (low + 48))
			cout << "Error. Enter a number from " << low << " to " << high << endl;
	} while (choise > (high + 48) || choise < (low + 48));
	return (choise - 48);
}

void Mathemical_Operations(Pair& one, Pair& two)
{
	bool boolean = 1;
	while (boolean)
	{
		cout << "================================================================" << endl;
		cout << "\t\tSelect action: " << endl;
		cout << "\t\t1 - Multiplication of class fields" << endl;
		cout << "\t\t2 - Class multiplication" << endl;
		cout << "\t\t0 - Exit to menu" << endl;

		switch (Checking_For_Valid_Input(0, 2))
		{
		case 1:
		{
			cout << "================================================================" << endl;
			cout << "================================================================" << endl;
			cout << "\t\t\tResult for class \'a\' : " << one.Multiplication_Of_Class_Fields() << endl;
			cout << "\t\t\tResult for class \'b\' : " << two.Multiplication_Of_Class_Fields() << endl;
			cout << "================================================================" << endl;
			break;
		}
		case 2:
		{
			cout << "================================================================" << endl;
			cout << "================================================================" << endl;
			cout << "\t\t\tResult: " << (one * two);
			cout << "================================================================" << endl;
			break;
		}
		case 0:
			boolean = 0;
		}
	}
}

void Mathemical_Operations(Rational& one, Rational& two)
{
	bool boolean = 1;
	while (boolean)
	{
		cout << "================================================================" << endl;
		cout << "\t\tSelect action: " << endl;
		cout << "\t\t1 - Multiplication of class fields" << endl;
		cout << "\t\t2 - Class subtraction" << endl;
		cout << "\t\t3 - Class multiplication" << endl;
		cout << "\t\t4 - Addition of classes" << endl;
		cout << "\t\t0 - Exit to menu" << endl;

		switch (Checking_For_Valid_Input(0, 4))
		{
		case 1:
		{
			cout << "================================================================" << endl;
			cout << "================================================================" << endl;
			cout << "\t\t\tResult for class \'a\' : " << one.Multiplication_Of_Class_Fields() << endl;
			cout << "\t\t\tResult for class \'b\' : " << two.Multiplication_Of_Class_Fields() << endl;
			cout << "================================================================" << endl;
			break;
		}
		case 2:
		{
			cout << "================================================================" << endl;
			cout << "================================================================" << endl;
			cout << "\t\t\tResult: " << (one - two) << endl;
			cout << "================================================================" << endl;
			break;
		}
		case 3:
		{
			cout << "================================================================" << endl;
			cout << "================================================================" << endl;
			cout << "\t\t\tResult: " << (one * two) << endl;
			cout << "================================================================" << endl;
			break;
		}
		case 4:
		{
			cout << "================================================================" << endl;
			cout << "================================================================" << endl;
			cout << "\t\t\tResult: " << (one + two) << endl;
			cout << "================================================================" << endl;
			break;
		}
		case 0:
			boolean = 0;
		}
	}
}

void Selection_Second_Menu(Pair& one, Pair& two, Rational& first_fraction, Rational& second_fraction, const bool &choise_class)
{
	bool boolean = 1;
	while (boolean)
	{
		short choise_Pair_menu = 0;
		cout << "================================================================================================" << endl;
		if(choise_class)
			cout << "\tclass Pair: " << endl;
		else
			cout << "\tclass Rational: " << endl;
		cout << "\t1 - Show" << endl;
		cout << "\t2 - Enter data" << endl;
		cout << "\t3 - Mathemical operations" << endl;
		cout << "\t0 - back to main menu" << endl;

		if (choise_class)
			switch (Checking_For_Valid_Input(0, 3))
			{
			case 1:
			{
				cout << "================================================================================================" << endl;
				cout << "================================================================================================" << endl;
				cout << "\t\ta: first = " << one.Get_First() << "\t;\tsecond = " << one.Get_Second() << endl;
				cout << "================================================================================================" << endl;
				cout << "\t\tb: first = " << two.Get_First() << "\t;\tsecond = " << two.Get_Second() << endl;
				cout << "================================================================================================" << endl;
				break;
			}
			case 2:
			{
				cout << "================================================================================================" << endl;
				cout << "================================================================================================" << endl;
				cout << "\t\tPlease, enter two numbers into variable \'a\': first = ";
				one.Scan_First();
				cout << "\t\tsecond = ";
				one.Scan_Second();
				cout << "================================================================================================" << endl;
				cout << "\t\t\'b\' : first = ";
				two.Scan_First();
				cout << "\t\t second = ";
				two.Scan_Second();
				cout << "================================================================================================" << endl;
				break;
			}
			case 3:
			{
				Mathemical_Operations(one, two);
				break;
			}
			case 0:
			{
				boolean = 0;
				system("cls");
			}
			}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		else
			switch (Checking_For_Valid_Input(0, 3))
			{
			case 1:
			{
				cout << "================================================================================================" << endl;
				cout << "================================================================================================" << endl;
				cout << "\t\tfirst_fraction: " << first_fraction << endl;
				cout << "================================================================================================" << endl;
				cout << "\t\tfirst_fraction: " << second_fraction << endl;
				cout << "================================================================================================" << endl;
				break;
			}
			case 2:
			{
				cout << "================================================================================================" << endl;
				cout << "================================================================================================" << endl;
				cout << "\t\tPlease, enter numbers into fractions \'first_fraction\': ";
				first_fraction.Scan_First();
				cout << "\t\t / ";
				first_fraction.Scan_Second();
				cout << "================================================================================================" << endl;
				cout << "\t\t\'second_fraction\':  ";
				second_fraction.Scan_First();
				cout << "\t\t / ";
				second_fraction.Scan_Second();
				cout << "================================================================================================" << endl;
				break;
			}
			case 3:
			{
				Mathemical_Operations(first_fraction, second_fraction);
				break;
			}
			case 0:
			{
				boolean = 0;
				system("cls");
			}
			}
	}
}

void Selection_Main_Menu(Pair& one, Pair& two, Rational &first_fraction, Rational &second_fraction)
{
	short choise_main_menu = 0, choise_Rational_menu = 0;
	bool boolean = 1, choise_class = 0;
	while (boolean)
	{
		cout << "================================================================================================" << endl;
		cout << "1 - class \"Pair\"" << endl;
		cout << "2 - class \"Rational\"" << endl;
		cout << "0 - close the programm" << endl;		

		switch (Checking_For_Valid_Input(0, 2))
		{
		case 1:
		{
			choise_class = 1;
			Selection_Second_Menu(one, two, first_fraction, second_fraction, choise_class);
			break;
		}
		case 2:
		{
			choise_class = 0;
			Selection_Second_Menu(one, two, first_fraction, second_fraction, choise_class);
			break;
		}
		case 0:
			boolean = 0;
		}
	}
}

int main()
{
	Pair one;
	Pair two(4, 90);
	Rational first_fraction;
	Rational second_fraction(1, 10);

	Selection_Main_Menu(one, two, first_fraction, second_fraction);
}
