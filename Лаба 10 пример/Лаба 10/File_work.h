#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"Person.h"


int add_file(const char* f_name, int k, Person& p)
{
	std::fstream temp("temp", std::ios::out); //������� ��� ������
	std::fstream stream(f_name, std::ios::in); // ������� ��� ������

	if (!stream) //������ �������� �����
		return -1;

	int i{};
	Person m_p;

	while (stream >> m_p)
	{
		if (stream.eof())
			break;

		i++;

		if (i == k)
			temp << p;
		temp << m_p;
	}

	stream.close();
	temp.close();
	std::remove(f_name); // ������� ������ ����
	if (!std::rename("temp", f_name))
		std::cout << "The file was successfully renamed"; //������������� � temp
	return i; //���-�� �����������
}

int add_end(const char* f_name, Person& p)
{
	std::fstream stream(f_name, std::ios::in); // ������� ��� ������
	
	if (!stream) //������ �������� �����
		return -1;

	stream << p;
	return 1;
}

int del_file(const char* f_name, int k)
{
	std::fstream temp("temp", std::ios::out); //������� ��� ������
	std::fstream stream(f_name, std::ios::in); // ������� ��� ������

	if (!stream) //������ �������� �����
		return -1;

	int i{};
	Person p;

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
	std::remove(f_name); // ������� ������ ����
	if(!std::rename("temp", f_name))
		std::cout << "The file was successfully renamed"; //������������� � temp
	return i; //���-�� �����������
}

int print_file(const char* f_name)
{
	std::fstream stream(f_name, std::ios::in); //������� ��� ������
	
	if (!stream) //������ �������� �����
		return -1;

	int n{};
	Person p;

	while (stream >> p)
	{
		std::cout << p << std::endl;
		n++;
	}

	stream.close();

	return n;
}

int change_file(const char* f_name, int k, Person& p)
{
	std::fstream temp("temp", std::ios::out); //������� ��� ������
	std::fstream stream(f_name, std::ios::in); // ������� ��� ������

	if (!stream) //������ �������� �����
		return -1;

	int i{}, n{};
	char x{};
	Person m_p;

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
	std::remove(f_name); // ������� ������ ����
	if (!std::rename("temp", f_name))
		std::cout << "The file was successfully renamed"; //������������� � temp
	return i; //���-�� �����������
}

int make_file(const char* f_name)
{
	std::fstream stream(f_name, std::ios::out | std::ios::trunc); //������� ��� ������
	
	if (!stream) //������ �������� �����
		return -1;

	int n;
	Person p;

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

