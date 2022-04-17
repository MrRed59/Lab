#include<iostream>
#include<fstream>
#include<string>
#include"Money.h"
#include"File_work.h"

int main()
{
	Money p;
	int k, c;
	char file_name[30]{};
	do
	{
		std::cout << "\n============================================" << std::endl;
		std::cout << "1. Make file";
		std::cout << std::endl << "2. Print file";
		std::cout << std::endl << "3. Delete record from file";
		std::cout << std::endl << "4. Add record to file";
		std::cout << std::endl << "5. Change record in file";
		std::cout << std::endl << "6. Delete all entries not equal";
		std::cout << std::endl << "7. Reduce all entries by half with the value";
		std::cout << std::endl << "8. Add the number of entries to the beginning of the file";
		std::cout << std::endl << "0. Exit" << std::endl;
		std::cout << "============================================" << std::endl;
		std::cin >> c;
		switch (c)
		{
		case 1:
		{
			std::cout << "File name? ";
			std::cin >> file_name; //задаем имя файла

			k = make_file(file_name); //вызов функции для записи в файл

			if (k < 0) //вывод сообщения об ошибке
				std::cout << "Can't make file" << std::endl;

			break;
		}
		case 2:
		{
			std::cout << "File name? ";
			std::cin >> file_name; //задаем имя файла

			k = print_file(file_name); //вызов функции для чтения из файла

			if (!k) //вывод сообщения об ошибке
				std::cout << "Empty file" << std::endl;

			if (k < 0) //вывод сообщения об ошибке
				std::cout << "Can't read file" << std::endl;

			break;
		}
		case 3:
		{
			std::cout << "File name? ";
			std::cin >> file_name; //задаем имя файла

			int num;

			std::cout << "num? ";
			std::cin >> num;

			k = del_file(file_name, num); //вызов функции для чтения из файла

			if (k < 0) //вывод сообщения об ошибке
				std::cout << "Can't read file" << std::endl;

			break;
		}
		case 4:
		{
			std::cout << "File name? ";
			std::cin >> file_name; //задаем имя файла

			int num;

			std::cout << "num? ";
			std::cin >> num;

			Money p1;

			std::cout << "New money? ";
			std::cin >> p1;

			k = add_file(file_name, num, p1); //вызов функции для чтения из файла

			if (k < 0) //вывод сообщения об ошибке
				std::cout << "Can't read file" << std::endl;

			break;
		}
		case 5:
		{
			std::cout << "File name? ";
			std::cin >> file_name; //задаем имя файла

			int num;

			std::cout << "num? ";
			std::cin >> num;

			Money p2;

			std::cout << "New person? ";
			std::cin >> p2;

			k = change_file(file_name, num, p2); //вызов функции для чтения из файла

			if (k < 0) //вывод сообщения об ошибке
				std::cout << std::endl << "Can't read file" << std::endl;

			if (!k)
				std::cout << std::endl << "Not such record" << std::endl;
			break;
		}
		}
	} while (c);
}