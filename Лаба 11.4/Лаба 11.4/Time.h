#pragma once
#include<iostream>


class Time
{
	int m_min;
	int m_sec;
public:
	//---------constructor-----------
	Time();
	Time(int, int);
	Time(const Time&);
	~Time();	
	//-------Getters and Setters----
	int get_min();
	int get_sec();
	void set_min(int);
	void set_sec(int);
	//-------overloaded-functions----
	Time& operator=(const Time&);
	Time operator+(const Time&);
	Time& operator+=(const Time&);
	Time operator/(const Time&);
	Time& operator/=(const Time&);
	Time operator/(int);
	bool operator>(const Time&);
	bool operator<(const Time&);
	bool operator==(const Time&);
	bool operator!=(const Time&);
	//-------friend-functions---------
	friend std::ostream& operator<<(std::ostream&, const Time&);
	friend std::istream& operator>>(std::istream&, Time&);
};

