#include "Time.h"

Time::Time()
{
	m_min = m_sec = 0;
}

Time::Time(const int min, const int sec)
{
	m_min = min;
	m_sec = sec;
}

Time::Time(const Time& time)
{
	m_min = time.m_min;
	m_sec = time.m_sec;
}

Time::~Time()
{
}

int Time::get_min()
{
	return m_min;
}

int Time::get_sec()
{
	return m_sec;
}

void Time::set_min(const int min)
{
	m_min = min;
}

void Time::set_sec(const int sec)
{
	m_sec = sec;
}

Time& Time::operator=(const Time& time)
{
	if (&time == this)
		return *this;
	m_min = time.m_min;
	m_sec = time.m_sec;
	return *this;
}

Time Time::operator+(const Time& time)
{
	int temp1 = m_min * 60 + m_sec;
	int temp2 = time.m_min * 60 + time.m_sec;
	Time temp_time;
	temp_time.m_min = (temp1 + temp2) / 60;
	temp_time.m_sec = (temp1 + temp2) % 60;
	return temp_time;
}

Time& Time::operator+=(const Time& time)
{
	int temp1 = m_min * 60 + m_sec;
	int temp2 = time.m_min * 60 + time.m_sec;
	Time temp_time;
	m_min = (temp1 + temp2) / 60;
	m_sec = (temp1 + temp2) % 60;
	return *this;
}

Time Time::operator/(const Time& time)
{
	int temp1 = m_min * 60 + m_sec;
	int temp2 = time.m_min * 60 + time.m_sec;
	Time temp_time;
	temp_time.m_min = (temp1 / temp2) / 60;
	temp_time.m_sec = (temp1 / temp2) % 60;
	return temp_time;
}

Time& Time::operator/=(const Time& time)
{
	int temp1 = m_min * 60 + m_sec;
	int temp2 = time.m_min * 60 + time.m_sec;
	m_min = (temp1 / temp2) / 60;
	m_sec = (temp1 / temp2) % 60;
	return *this;
}

Time Time::operator/(const int value)
{
	int temp1 = m_min * 60 + m_sec;
	Time temp_time;
	temp_time.m_min = (temp1 / value) / 60;
	temp_time.m_sec = (temp1 / value) % 60;
	return temp_time;
}

bool Time::operator>(const Time& time)
{
	return (m_min > time.m_min || m_min == time.m_min && m_sec > time.m_sec);
}

bool Time::operator<(const Time& time)
{
	return (m_min < time.m_min || m_min == time.m_min && m_sec < time.m_sec);
}

bool Time::operator==(const Time& time)
{
	return (time.m_min == m_min && time.m_sec == m_sec);
}

bool Time::operator!=(const Time& time)
{
	return !(time.m_min == m_min && time.m_sec == m_sec);
}

std::ostream& operator<<(std::ostream& out, const Time& time)
{
	return (out << time.m_min << ":" << time.m_sec);
}

std::istream& operator>>(std::istream& in, Time& time)
{
	std::cout << "Minutes: ";
	in >> time.m_min;
	std::cout << "Seconds:";
	in >> time.m_sec;
	return in;
}
