#include "Pair.h"
#include "Rational.h"
#include<iostream>
#include<conio.h>
#include"object.h"
#include"Vector.h"

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

int Checking_For_Valid_Input_Above_Zero()
{
	int value;
	do 
	{
		cin >> value;

		if (value <= 0 && cin)
		{
			cout << "Enter a number greater than zero" << endl;
			cin.ignore(1024, '\n');
		}

		if (!cin)
		{
			cout << "Syntax error" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
	} while (value <= 0);
	return value;
}

int Checking_For_Valid_Input()
{
	int value;
	do
	{
		cin >> value;
		if (!cin)
		{
			cout << "Syntax error" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
	} while (!cin);
	return value;
}


void Mathemical_Operations(Pair& one, Pair& two)
{
	bool boolean = 1;
	while (boolean)
	{
		cout << "================================================================================================" << endl;
		cout << "================================================================================================" << endl;
		cout << "\t\tSelect action: " << endl;
		cout << "\t\t1 - Multiplication of class fields" << endl;
		cout << "\t\t2 - Class multiplication" << endl;
		cout << "\t\t0 - Exit to menu" << endl;

		switch (Checking_For_Valid_Input(0, 2))
		{
		case 1:
		{
			cout << "================================================================================================" << endl;
			cout << "================================================================================================" << endl;
			cout << "\t\t\tResult for class \'a\' : " << one.Multiplication_Of_Class_Fields() << endl;
			cout << "\t\t\tResult for class \'b\' : " << two.Multiplication_Of_Class_Fields() << endl;
			break;
		}
		case 2:
		{
			cout << "================================================================================================" << endl;
			cout << "================================================================================================" << endl;
			cout << "\t\t\tResult: " << (one * two);
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
		cout << "================================================================================================" << endl;
		cout << "================================================================================================" << endl;
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
			cout << "================================================================================================" << endl;
			cout << "================================================================================================" << endl;
			cout << "\t\t\tResult for class \'a\' : " << one.Multiplication_Of_Class_Fields() << endl;
			cout << "\t\t\tResult for class \'b\' : " << two.Multiplication_Of_Class_Fields() << endl;
			break;
		}
		case 2:
		{
			cout << "================================================================================================" << endl;
			cout << "================================================================================================" << endl;
			cout << "\t\t\tResult: " << (one - two) << endl;
			break;
		}
		case 3:
		{
			cout << "================================================================================================" << endl;
			cout << "================================================================================================" << endl;
			cout << "\t\t\tResult: " << (one * two) << endl;
			break;
		}
		case 4:
		{
			cout << "================================================================================================" << endl;
			cout << "================================================================================================" << endl;
			cout << "\t\t\tResult: " << (one + two) << endl;
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
	Object* p;
	while (boolean)
	{
		short choise_Pair_menu = 0;
		cout << "================================================================================================" << endl;
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
				p = &one;
				cout << "================================================================================================" << endl;
				cout << "================================================================================================" << endl;
				cout << "\t\ta:"; p->Show();				
				p = &two;
				cout << "================================================================================================" << endl;
				cout << "\t\tb:"; p->Show();
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
				p = &first_fraction;
				cout << "================================================================================================" << endl;
				cout << "================================================================================================" << endl;
				cout << "\t\tfirst_fraction: "; p->Show();
				p = &second_fraction;
				cout << "================================================================================================" << endl;
				cout << "\t\tfirst_fraction: "; p->Show();
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

void Selection_Vector_Menu__Add_Element(Pair& one, Pair& two, Rational& first_fraction, Rational& second_fraction, Vector& vec)
{
	Object* p;
	bool boolean = 1, last_input = 0;
	while (boolean)
	{
		if (vec.GetSize() == vec.GetNumberOfOccupiedCells())
		{
			cout << "\t\tVector filled" << endl;
			break;
		}

		p = &one;
		cout << "================================================================================================" << endl;
		cout << "================================================================================================" << endl;
		cout << "\t\t1 - Pair (first):\t\t";
		p->Show();
		p = &two;
		cout << "\t\t2 - Pair (second):\t\t";
		p->Show();
		p = &first_fraction;
		cout << "\t\t3 - Rational (first fraction):\t\t";
		p->Show();
		p = &second_fraction;
		cout << "\t\t4 - Rational (second fraction):\t\t";
		p->Show();
		cout << "\t\t0 - Back to main menu" << endl;

		switch (Checking_For_Valid_Input(0, 4))
		{
		case 1:
		{
			p = &one;
			vec.Add(p);
			break;
		}
		case 2:
		{
			p = &two;
			vec.Add(p);
			break;
		}
		case 3:
		{
			p = &first_fraction;
			vec.Add(p);
			break;
		}
		case 4:
		{
			p = &second_fraction;
			vec.Add(p);
			break;
		}
		case 0:
		{
			boolean = 0;
		}
		}

		if (boolean)
		{
			cout << "Entered: "; 
			vec.PrintLastElement();
		}
	}
}

void Selection_Vector_Menu(Pair& one, Pair& two, Rational& first_fraction, Rational& second_fraction, Vector &vec)
{
	bool boolean = 1;
	while (boolean)
	{
		cout << "================================================================================================" << endl;
		cout << "================================================================================================" << endl;
		cout << "\t1 - Show" << endl;
		cout << "\t2 - Add element" << endl;
		cout << "\t3 - Remove the last element" << endl;
		cout << "\t4 - Clear" << endl;
		cout << "\t0 - Back to main menu" << endl;

		switch (Checking_For_Valid_Input(0, 4))
		{
		case 1:
		{
			cout << "================================================================================================" << endl;
			cout << "================================================================================================" << endl;
			cout << vec << endl;
			break;
		}
		case 2:
		{
			Selection_Vector_Menu__Add_Element(one, two, first_fraction, second_fraction, vec);
			break;
		}
		case 3:
		{
			vec.PopBack();
			break;
		}
		case 4:
		{
			vec.Clear();
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

void Selection_New_Vector(Pair& one, Pair& two, Rational& first_fraction, Rational& second_fraction, Vector &vec)
{
	cout << "================================================================================================" << endl;
	cout << "================================================================================================" << endl;
	cout << "\tCreate a new vector? " << endl;
	cout << "\t 1 - Yes" << endl;
	cout << "\t 2 - No" << endl;

	if (Checking_For_Valid_Input(1, 2) == 1)
	{
		cout << "Choice of vector length: " << endl;
		Vector vec2(Checking_For_Valid_Input_Above_Zero());
		vec = vec2;
	}
		Selection_Vector_Menu(one, two, first_fraction, second_fraction, vec);
}

void Selection_Main_Menu(Pair& one, Pair& two, Rational &first_fraction, Rational &second_fraction, Vector& vec)
{
	short choise_main_menu = 0, choise_Rational_menu = 0;
	bool boolean = 1, choise_class = 0;
	while (boolean)
	{
		cout << "================================================================================================" << endl;
		cout << "1 - class \"Pair\"" << endl;
		cout << "2 - class \"Rational\"" << endl;
		cout << "3 - class \"Vector\"" << endl;
		cout << "0 - close the programm" << endl;

		switch (Checking_For_Valid_Input(0, 3))
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
		case 3:
		{
			Selection_New_Vector(one, two, first_fraction, second_fraction, vec);
			break;
		}
		case 0:
			boolean = 0;
			cout << "================================================================================================" << endl;
		}
	}
}


int main()
{
	Pair one;
	Pair two(4, 90);
	Rational first_fraction;
	Rational second_fraction(1, 10);
	cout << "Choice of vector length: " << endl;
	Vector vec(Checking_For_Valid_Input_Above_Zero());

	Selection_Main_Menu(one, two, first_fraction, second_fraction, vec);
}