#pragma once
#include"Human.h"
class Employee :public Human
{
protected:
	float m_wages;
	std::string m_position;
public:
	Employee(void);
	~Employee(void);

	void Show() override;
	void Input(int) override;

	Employee(const std::string, const int, const float, const std::string);
	Employee(const Employee&);

	float Get_wages();
	std::string Get_position();

	void Set_wages(const float);
	void Set_position(const std::string);

	Employee& operator=(const Employee&);
};

