﻿#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"Money.h"

int Add_entries_at_the_beginning(const char* f_name, int k)
{
	std::fstream temp("temp", std::ios::out); //открыть для записи
	std::fstream stream(f_name, std::ios::in); // открыть для чтения

	if (!stream) //ошибка открытия файла
		return -1;

	int i{};
	Money m_p;
	Money temp_money;

	for (int j = 0; j < k; j++)
	{
		std::cin >> temp_money;
		temp << temp_money;
		i++;
	}

	while (stream >> m_p)
	{
		if (stream.eof())
			break;

		i++;

		temp << m_p;
	}

	stream.close();
	temp.close();
	std::remove(f_name); // удалить старый файл
	if (std::rename("temp", f_name))
		std::cout << "Renaming error."; //переименовать в temp
	return 1; //кол-во прочитанных
}

int halve(const char* f_name, Money& p)
{
	std::fstream temp("temp", std::ios::out); //открыть для записи
	std::fstream stream(f_name, std::ios::in); // открыть для чтения

	if (!stream) //ошибка открытия файла
		return -1;

	int i{};
	Money m_p;

	while (stream >> m_p)
	{
		if (stream.eof())
			break;

		i++;

		if (m_p != p)
			temp << m_p;
		else
			temp << (m_p / 2);
	}

	stream.close();
	temp.close();
	std::remove(f_name); // удалить старый файл
	if (std::rename("temp", f_name)) //переименовать в temp
		std::cout << "Renaming error.";
	return 1; //кол-во прочитанных
}

int delete_does_not_equal(const char* f_name, Money & p)
{
	std::fstream temp("temp", std::ios::out); //открыть для записи
	std::fstream stream(f_name, std::ios::in); // открыть для чтения

	if (!stream) //ошибка открытия файла
		return -1;

	int i{};
	Money m_p;

	while (stream >> m_p)
	{
		if (stream.eof())
			break;

		i++;

		if (m_p != p)
			//temp << p;
			temp << m_p;
	}

	stream.close();
	temp.close();
	std::remove(f_name); // удалить старый файл
	if (std::rename("temp", f_name)) //переименовать в temp
		std::cout << "Renaming error.";
	return i; //кол-во прочитанных
}

int add_file(const char* f_name, int k, Money& p)
{
	std::fstream temp("temp", std::ios::out); //открыть для записи
	std::fstream stream(f_name, std::ios::in); // открыть для чтения

	if (!stream) //ошибка открытия файла
		return -1;

	int i{};
	Money m_p;

	while (stream >> m_p)
	{
		if (stream.eof())
			break;

		i++;

		if (i == k)
			temp << p;
		temp << m_p;
	}

	if (i == (k - 1))
		temp << p;

	stream.close();
	temp.close();
	std::remove(f_name); // удалить старый файл
	if (std::rename("temp", f_name)) //переименовать в temp
		std::cout << "Renaming error.";
	return i; //кол-во прочитанных
}

int del_file(const char* f_name, int k)
{
	std::fstream temp("temp", std::ios::out); //открыть для записи
	std::fstream stream(f_name, std::ios::in); // открыть для чтения

	if (!stream) //ошибка открытия файла
		return -1;

	int i{};
	Money p;

	while (stream >> p)
	{
		if (stream.eof())
			break;

		i++;

		if (i!=k)
			temp << p;
	}

	stream.close();
	temp.close();
	std::remove(f_name); // удалить старый файл
	if(!std::rename("temp", f_name))
		std::cout << "The file was successfully renamed"; //переименовать в temp
	return i; //кол-во прочитанных
}

int print_file(const char* f_name)
{
	std::fstream stream(f_name, std::ios::in); //открыть для чтения
	
	if (!stream) //ошибка открытия файла
		return -1;

	int n{};
	Money p;

	while (stream >> p)
	{
		std::cout << (n + 1) << ": " << p << std::endl;
		n++;
	}

	stream.close();

	return n;
}

int change_file(const char* f_name, int k, Money& p)
{
	std::fstream temp("temp", std::ios::out); //открыть для записи
	std::fstream stream(f_name, std::ios::in); // открыть для чтения

	if (!stream) //ошибка открытия файла
		return -1;

	int i{}, n{};
	char x{};
	Money m_p;

	while (stream >> m_p)
	{
		if (stream.eof())
			break;

		i++;

		if (i == k)
		{
			std::cout << p << " - is changing... Continue[y/n]?" << std::endl;
			std::cin >> x;

			if (x=='n' || x=='N')
				break;
			temp << p;
			i++;
		}
		else
			temp << m_p;
	}

	stream.close();
	temp.close();
	std::remove(f_name); // удалить старый файл
	if (std::rename("temp", f_name)) //переименовать в temp
		std::cout << "Renaming error."; 
	return i; //кол-во прочитанных
}

int make_file(const char* f_name)
{
	std::fstream stream(f_name, std::ios::out | std::ios::trunc); //открыть для записи
	
	if (!stream) //ошибка открытия файла
		return -1;

	int n;
	Money p;

	std::cout << "N? ";
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		std::cin >> p;
		stream << p << std::endl;
	}

	stream.close();

	return n;
};

