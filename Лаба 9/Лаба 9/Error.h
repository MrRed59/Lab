#pragma once
#include<iostream>
#include<string>

class Error
{
	std::string m_str;
public:
	Error(std::string str)
	{
		m_str = str;
	}

	std::string what()
	const{
		//std::cout << m_str << std::endl;
		return m_str;
	}

	friend std::ostream& operator<<(std::ostream& out, const Error& temp)
	{
		out << temp.m_str;
		return out;
	}
};

