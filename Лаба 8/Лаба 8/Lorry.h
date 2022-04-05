#pragma once
#include"Car.h"
class Lorry :public Car
{
protected:
	int m_gruz;
public:
	Lorry(void);
	~Lorry(void);

	void Show() override;
	void Input() override;

	Lorry(const std::string, const int, const int, const int);
	Lorry(const Lorry&);

	int Get_gruz();
	void Set_gruz(const int);

	Lorry& operator=(const Lorry&);
};

