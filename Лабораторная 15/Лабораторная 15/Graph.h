#pragma once

template<class T>
class Graph
{

public:
	Graph();
	~Graph();
};

template<class T>
Graph<T>::Graph() //Объявление шаблона с формальным параметром класс Т
{
	// Конструктор, который инициализирует значения объектов класса Graph
	// Перебор строк и столбцов матрицы смежности и заполнение ее нулями
	for (int i = 0; i < maxSize; ++i)
	{
		for (int j = 0; j < maxSize; ++j)
		{
			this->adjMatrix[i][j] = 0;
		}
	}
}

template<class T>
Graph<T>::~Graph()
{
}

