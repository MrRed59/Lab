#include<iostream>
#include"Time.h"
#include<queue>
#include<vector>


typedef std::queue<Time> Qu;
typedef std::vector<Time> Vec;

Qu make_queue(int n)
{
	Qu s;
	Time t;
	for (int i = 0; i < n; i++)
	{
		std::cin >> t;
		s.push(t);
	}
	return s;
}

//Vec copy_stack_to_vector(Qu s) //�������� ���� � ������
//{
//	Vec v;
//	while (!s.empty()) //���� ���� �� ������
//	{
//		v.push_back(s.top()); //�������� � ������ ������� �� ������� �����
//		s.pop();
//	}
//	return v; //������� ������ ��� ��������� �������
//}

//Qu copy_vector_to_stack(Vec v) //�������� ������ � ����
//{
//	Qu s;
//	for (size_t i = 0; i < v.size(); i++)
//	{
//		s.push(v[i]);
//	}
//	return s;
//}

void print_stack(Qu s)
{
	while (!s.empty())
	{
		std::cout << s.top() << "  ";
		s.pop();
	}
	std::cout << std::endl;
}

//

Time arithmetic_mean(Qu s) //���������� �������� ��������
{
	Vec v = copy_stack_to_vector(s); //�������� �������� ��� �����
	int n = 1;
	Time sum = s.top(); //��������� �������� ��� �����

	s.pop(); //������� ������ ������� �� �������

	while (!s.empty()) //���� ���� �� ������
	{
		sum += s.top(); //�������� � ����� ������� �� ������� �����
		s.pop(); //������� �������
		n++;
	}

	s = copy_vector_to_stack(v); //����������� ������ � ����

	return (sum / n);
}

void Add_to_stack(Qu& s, Time el, int pos) //���������� �������� � ����
{
	Vec v;
	Time t;
	int i = s.size(); //����� �������� � �����
	while (!s.empty()) //���� ���� �� ������
	{
		t = s.top(); //�������� ������� �� �������

		if (i == pos) //���� ����� ����� ������ �������, �� ������� �������� �������
			v.push_back(el); //�������� ����� ������� �� ����� � ������

		v.push_back(t); //�������� ������� �� ����� � ������
		s.pop(); //������� ������� �� �����

		if (!pos && i == 1)
			v.push_back(el); //���� ����� ������� 0, �� �������� ��� � �����

		i--;
	}
	s = copy_vector_to_stack(v); //����������� ������ � ����
}

Time Max(Qu s) // ����� ������������� �������� � �����
{
	Time m = s.top(); //���������� m ������������� �������� �� ������� �����
	Vec v = copy_stack_to_vector(s); //�������� ���� � ������
	 
	while (!s.empty()) //���� ���� �� ������
	{
		if (s.top() > m) //�������� m � ������� � ������� �����
			m = s.top(); // ������� ������� �� �����

		s.pop();
	}

	s = copy_vector_to_stack(v); //����������� ������ � ����

	return m;
}

void Delete_from_stack(Qu& s)//������� ������������ ������� �� �����
{
	Time m = Max(s); //������� ������������ �������
	Vec v;
	Time t;
	while (!s.empty()) //���� ���� ������
	{
		t = s.top(); //�������� ������� �� ������� �����

		if (t != m) //���� �� �� ����� �������������, ������� ������� � ������
			v.push_back(t);

		s.pop(); //������� ������� �� �����
	}

	s = copy_vector_to_stack(v); //����������� ������ � ����

}

Time Min(Qu s)
{
	Time m = s.top();
	Vec v = copy_stack_to_vector(s);
	while (!s.empty()) //���� ���� �� ������
	{
		if (s.top() < m) //�������� m � ������� � ������� �����
			m = s.top(); // ������� ������� �� �����

		s.pop();
	}

	s = copy_vector_to_stack(v); //����������� ������ � ����

	return m;
}

void Division(Qu& s)
{
	Time m = Min(s);
	Vec v;
	Time t;

	while (!s.empty()) //���� ���� �� ������
	{
		t = s.top(); //�������� ������� �� �������
		v.push_back(t / m); //������ t �� ����������� ������� � �������� � ������
		s.pop(); //������� ������� �� �������
	}

	s = copy_vector_to_stack(v); //����������� ������ � ����
}


int main()
{
	Time t;
	Qu s;
	int n;

	std::cout << "n? ";
	std::cin >> n;

	s = make_stack(n);
	print_stack(s);

	t = arithmetic_mean(s);

	std::cout << "Arithmetic mean = " << arithmetic_mean(s) << std::endl;
	std::cout << "Add arithmetic mean: " << std::endl;
	std::cout << "Position? ";

	int pos;

	std::cin >> pos;

	Add_to_stack(s, t, pos);
	print_stack(s);

	std::cout << "Delete Max = " << std::endl;

	Delete_from_stack(s);
	print_stack(s);

	std::cout << "Division = " << std::endl;

	Division(s);
	print_stack(s);

}