#include<iostream>
#include<fstream>
#include<string>
#include"Person.h"
#include"File_work.h"

int main()
{
	//Person a;
	//std::cin >> a;
	//std::cout << a << std::endl;
	//Person b;
	//b = a;
	//std::cout << a;

	Person p;
	int k, c;
	char file_name[30]{};
	do
	{
		std::cout << std::endl << "1. Make file";
		std::cout << std::endl << "2. Print file";
		std::cout << std::endl << "3. Delete record from file";
		std::cout << std::endl << "4. Add record to file";
		std::cout << std::endl << "5. Change record in file";
		std::cout << std::endl << "0. Exit" << std::endl;
		std::cin >> c;
		switch (c)
		{
		case 1:
		{
			std::cout << "File name? ";
			std::cin >> file_name; //������ ��� �����

			k = make_file(file_name); //����� ������� ��� ������ � ����

			if (k < 0) //����� ��������� �� ������
				std::cout << "Can't make file" << std::endl;

			break;
		}
		case 2:
		{
			std::cout << "File name? ";
			std::cin >> file_name; //������ ��� �����

			k = print_file(file_name); //����� ������� ��� ������ �� �����

			if (!k) //����� ��������� �� ������
				std::cout << "Empty file" << std::endl;

			if (k < 0) //����� ��������� �� ������
				std::cout << "Can't read file" << std::endl;

			break;
		}
		case 3:
		{
			std::cout << "File name? ";
			std::cin >> file_name; //������ ��� �����

			int num;

			std::cout << "num? ";
			std::cin >> num;

			k = del_file(file_name, num); //����� ������� ��� ������ �� �����

			if (k < 0) //����� ��������� �� ������
				std::cout << "Can't read file" << std::endl;

			break;
		}
		case 4:
		{
			std::cout << "File name? ";
			std::cin >> file_name; //������ ��� �����

			int num;

			std::cout << "num? ";
			std::cin >> num;

			Person p1;

			std::cout << "New person? ";
			std::cin >> p1;

			k = add_file(file_name, num, p1); //����� ������� ��� ������ �� �����

			if (k < 0) //����� ��������� �� ������
				std::cout << "Can't read file" << std::endl;

			if (!k)
				k = add_end(file_name, p1);
			break;
		}
		case 5:
		{
			std::cout << "File name? ";
			std::cin >> file_name; //������ ��� �����

			int num;

			std::cout << "num? ";
			std::cin >> num;

			Person p2;

			std::cout << "New person? ";
			std::cin >> p2;

			k = change_file(file_name, num, p2); //����� ������� ��� ������ �� �����

			if (k < 0) //����� ��������� �� ������
				std::cout << std::endl << "Can't read file" << std::endl;

			if (!k)
				std::cout << std::endl << "Not such record" << std::endl;
			break;
		}
		}
	} while (c);
}