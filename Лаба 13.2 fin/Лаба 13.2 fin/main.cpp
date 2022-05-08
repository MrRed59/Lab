#include <iostream>
#include<vector>
#include<queue>
#include"Money.h"

typedef std::queue<Money> Qu;
typedef std::vector<Money> Vec;

Qu make_queue(int n) //функция для формирования очереди
{
    Qu v; //пустой вектор
    Money money;
    for (int i = 0; i < n; i++)
    {
        std::cin >> money;

        v.push(money); //добавить money в конец вектора
    }
    return v;
}

Vec copy_queue_to_vector(Qu s) //копируем стек в вектор
{
    Vec v;
    while (!s.empty()) //пока очередь не пустая
    {
        v.push_back(s.front()); //добавить в вектор элемент из вершины очереди
        s.pop();
    }
    return v; //вернуть вектор как результат функции
}

Qu copy_vector_to_queue(Vec v) //копируем вектор в очередь
{
    Qu s;
    for (size_t i = 0; i < v.size(); i++)
    {
        s.push(v[i]); //добавить в очередь элемент вектора
    }
    return s; //вернуть очередь как результат функции
}

void print_queue(Qu s)
{
	while (!s.empty())
	{
		std::cout << s.front() << "  ";
		s.pop();
	}
	std::cout << std::endl;
}

Money arithmetic_mean(Qu s) //вычисление среднего значения
{
	Vec v = copy_queue_to_vector(s); //копируем значение для суммы
	int n = 1;
	Money sum = s.front(); //начальное значение для суммы

	s.pop(); //удалить первый элемент из вектора

	while (!s.empty()) //пока стек не пустой
	{
		sum += s.front(); //добавить в сумму элемент из вершины стека
		s.pop(); //удалить элемент
		n++;
	}

	s = copy_vector_to_queue(v); //скопировать вектор в очередь

	return (sum / n);
}

void Add_to_queue(Qu& s, const Money& el, int pos) //добавление элемента в очередь
{
	Vec v;
	Money t;
	int i = s.size(); //размер очереди

	if (!pos)
		v.push_back(el); //если номер позиции 0, то добавить его в конец

	while (!s.empty()) //пока стек не пустой
	{
		t = s.front(); //получить элемент из вершины

		if (i == pos) //если номер равен номеру позиции, на которую добавлен элемент
			v.push_back(el); //добавить новый элемент из очeреди в вектор

		v.push_back(t); //добавить элемент из очереди в вектор
		s.pop(); //удалить элемент из очереди

		i--;
	}

	s = copy_vector_to_queue(v); //скопировать вектор в очередь
}

Money Max(Qu s) // поиск максимального элемента в очереди
{
	Money m = s.front(); //переменной m присваивается значение из вершины очереди
	Vec v = copy_queue_to_vector(s); //копируем очередь в вектор

	while (!s.empty()) //пока стек не пустой
	{
		if (s.front() > m) //сравнить m и элемент в вершине очереди
			m = s.front(); // удалить элемент из очереди

		s.pop();
	}

	s = copy_vector_to_queue(v); //скопировать вектор в очередь

	return m;
}

void Delete_from_queue(Qu& s)//удалить максимальный элемент из очереди
{
	Money m = Max(s); //находим максимальный элемент
	Vec v;
	Money t;
	while (!s.empty()) //пока очередь пустая
	{
		t = s.front(); //получаем элемент из вершины очереди

		if (t != m) //если он не равен максимальному, занести элемент в вектор
			v.push_back(t);

		s.pop(); //удалить элемент из очереди
	}

	s = copy_vector_to_queue(v); //скопировать вектор в очередь
}

Money Min(Qu s)
{
	Money m = s.front();
	Vec v = copy_queue_to_vector(s);
	while (!s.empty()) //пока очередь не пустая
	{
		if (s.front() < m) //сравнить m и элемент в вершине очереди
			m = s.front(); // удалить элемент из стека

		s.pop();
	}

	s = copy_vector_to_queue(v); //скопировать вектор в очередь

	return m;
}

void Division(Qu& s)
{
	Money m = Min(s);
	Vec v;
	Money t;

	while (!s.empty()) //пока стек не пустой
	{
		t = s.front(); //получить элемент из вершины
		v.push_back(t / m); //делить t на минимальный элемент и добавить в вектор
		s.pop(); //удалить элемент из вершины
	}

	s = copy_vector_to_queue(v); //скопировать вектор в стек
}

void add_min_element(Qu& s)
{
	Vec v;
	Money min = Min(s);
	Money t;
	size_t i = 0;
	while (!s.empty()) //пока очередь пустая
	{
		t = s.front(); //получаем элемент из вершины очереди
		v.push_back(t);
		s.pop(); //удалить элемент из стека
		i++;
	}

	v.push_back(min);

	s = copy_vector_to_queue(v); //скопировать вектор в очередь
}


void remove_element_by_index(Qu& s, int pos)
{
	Vec v;
	Money t;
	size_t i = 0;
	while (!s.empty()) //пока очередь пустая
	{
		t = s.front(); //получаем элемент из вершины очереди

		if (pos != i) //если он не равен максимальному, занести элемент в вектор
			v.push_back(t);

		s.pop(); //удалить элемент из стека

		i++;
	}

	s = copy_vector_to_queue(v); //скопировать вектор в очередь
}

void add_sum_max_min(Qu& s)
{
	Vec v;
	Money sum_min_max = Max(s) + Min(s);
	Money t;
	size_t i = 0;
	while (!s.empty()) //пока очередь пустая
	{
		t = s.front(); //получаем элемент из вершины очереди
		v.push_back(t + sum_min_max);
		s.pop(); //удалить элемент из стека
		i++;
	}


	s = copy_vector_to_queue(v); //скопировать вектор в очередь
}


int main()
{
	Money t;
	Qu q;
	int n;

	std::cout << "n? ";
	std::cin >> n;

	q = make_queue(n);
	print_queue(q);

	t = arithmetic_mean(q);

	std::cout << "Arithmetic mean = " << arithmetic_mean(q) << std::endl;
	std::cout << "Add arithmetic mean: " << std::endl;
	std::cout << "Position? ";

	int pos;

	std::cin >> pos;

	Add_to_queue(q, t, pos);
	print_queue(q);

	add_min_element(q);
	std::cout << "Add a minimal element: " << std::endl;
	print_queue(q);

	std::cout << "\nPosition to delete an element? ";
	std::cin >> pos;
	remove_element_by_index(q, pos); //удалить элемент с этим номером
	std::cout << "Remove element by index: " << std::endl;
	print_queue(q);

	add_sum_max_min(q);
	std::cout << "Add the sum of the maximum and minimum: " << std::endl;
	print_queue(q);

	std::cout << "Delete Max = " << std::endl;

	Delete_from_queue(q);
	print_queue(q);

	std::cout << "Division = " << std::endl;

	Division(q);
	print_queue(q);

}