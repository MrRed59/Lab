#pragma once

template<class T>
class Graph
{

public:
	Graph();
	~Graph();
};

template<class T>
Graph<T>::Graph() //���������� ������� � ���������� ���������� ����� �
{
	// �����������, ������� �������������� �������� �������� ������ Graph
	// ������� ����� � �������� ������� ��������� � ���������� �� ������
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

