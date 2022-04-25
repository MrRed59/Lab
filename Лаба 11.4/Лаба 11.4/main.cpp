#include<iostream>
#include"Time.h"
#include<stack>
#include<vector>


typedef std::stack<Time> St;
typedef std::vector<Time> Vec;

St make_stack(int n)
{
	St s;
	Time t;
	for (int i = 0; i < n; i++)
	{
		std::cin >> t;
		s.push(t);
	}
	return s;
}

Vec copy_stack_to_vector(St s) //копируем стек в вектор
{
	Vec v;
	while (!s.empty()) //пока стек не пустой
	{
		v.push_back(s.top()); //добавить в вектор элемент из вершины стека
		s.pop();
	}
	return v; //вернуть вектор как результат функции
}

St copy_vector_to_stack(Vec v) //копируем вектор в стек
{
	St s;
	for (size_t i = 0; i < v.size(); i++)
	{
		s.push(v[i]);
	}
	return s;
}

void print_stack(St s)
{
	while (!s.empty())
	{
		std::cout << s.top() << "  ";
		s.pop();
	}
	std::cout << std::endl;
}

//

Time arithmetic_mean(St s) //вычисление среднего значения
{
	Vec v = copy_stack_to_vector(s); //копируем значение для суммы
	int n = 1;
	Time sum = s.top(); //начальное значение для суммы

	s.pop(); //удалить первый элемент из вектора

	while (!s.empty()) //пока стек не пустой
	{
		sum += s.top(); //добавить в сумму элемент из вершины стека
		s.pop(); //удалить элемент
		n++;
	}

	s = copy_vector_to_stack(v); //скопировать вектор в стек

	return (sum / n);
}

void Add_to_stack(St& s, Time el, int pos) //добавление элемента в стек
{
	Vec v;
	Time t;
	int i = s.size(); //номер элемента в стеке
	while (!s.empty()) //пока стек не пустой
	{
		t = s.top(); //получить элемент из вершины

		if (i == pos) //если номер равен номеру позиции, на которую добавлен элемент
			v.push_back(el); //добавить новый элемент из стека в вектор

		v.push_back(t); //добавить элемент из стека в вектор
		s.pop(); //удалить элемент из стека

		if (!pos && i == 1)
			v.push_back(el); //если номер позиции 0, то добавить его в конец

		i--;
	}
	s = copy_vector_to_stack(v); //скопировать вектор в стек
}

Time Max(St s) // поиск максимального элемента в стеке
{
	Time m = s.top(); //переменной m присваивается значение из вершины стека
	Vec v = copy_stack_to_vector(s); //копируем стек в вектор
	 
	while (!s.empty()) //пока стек не пустой
	{
		if (s.top() > m) //сравнить m и элемент в вершине стека
			m = s.top(); // удалить элемент из стека

		s.pop();
	}

	s = copy_vector_to_stack(v); //скопировать вектор в стек

	return m;
}

void Delete_from_stack(St& s)//удалить максимальный элемент из стека
{
	Time m = Max(s); //находим максимальный элемент
	Vec v;
	Time t;
	while (!s.empty()) //пока стек пустой
	{
		t = s.top(); //получаем элемент из вершины стека

		if (t != m) //если он не равен максимальному, занести элемент в вектор
			v.push_back(t);

		s.pop(); //удалить элемент из стека
	}

	s = copy_vector_to_stack(v); //скопировать вектор в стек

}

Time Min(St s)
{
	Time m = s.top();
	Vec v = copy_stack_to_vector(s);
	while (!s.empty()) //пока стек не пустой
	{
		if (s.top() < m) //сравнить m и элемент в вершине стека
			m = s.top(); // удалить элемент из стека

		s.pop();
	}

	s = copy_vector_to_stack(v); //скопировать вектор в стек

	return m;
}

void Division(St& s)
{
	Time m = Min(s);
	Vec v;
	Time t;

	while (!s.empty()) //пока стек не пустой
	{
		t = s.top(); //получить элемент из вершины
		v.push_back(t / m); //делить t на минимальный элемент и добавить в вектор
		s.pop(); //удалить элемент из вершины
	}

	s = copy_vector_to_stack(v); //скопировать вектор в стек
}


int main()
{
	Time t;
	St s;
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