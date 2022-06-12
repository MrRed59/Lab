#include "Graph.h"
#include "GL/glut.h"
#include <iostream>
#include "draw.h"


Graph::Graph()
{
	// Перебор строк и столбцов матрицы смежности и заполнение ее нулями
	for (int i = 0; i < maxSize; ++i)
	{
		for (int j = 0; j < maxSize; ++j)
		{
			this->adjMatrix[i][j] = 0;
		}
	}
}

Graph::~Graph()
{
}

int Graph::GetVertPos(const int& vertex)
{
	for (int i = 0; i < this->vertList.size(); ++i)
	{
		if (this->vertList[i] == vertex)
			return i;
	}
	return -1;
}

bool Graph::IsEmpty()
{
	return !(this->vertList.size());
}

bool Graph::IsFull()
{
	return (vertList.size() == maxSize);
}

int Graph::GetAmountVerts()
{
	return this->vertList.size();
}

int Graph::GetAmountEdges()
{
	int amount = 0; // Обнуляем счетчик
	if (!this->IsEmpty()) // Проверяем, что граф не пуст
	{
		for (int i = 0, vertListSize = this->vertList.size(); i < vertListSize; ++i)
		{
			for (int j = 0; j < vertListSize; ++j)
			{
				if (this->adjMatrix[i][j] == 1) // Находим ребра
					++amount; // Считаем количество ребер
			}
		}
		return amount; // Возвращаем количество ребер
	}
	else
		return 0; // Если граф пуст, возвращаем 0
}

int Graph::GetWeight(const int& vertex1, const int& vertex2)
{
	if (!this->IsEmpty())
	{
		int vertPos1 = GetVertPos(vertex1);
		int vertPos2 = GetVertPos(vertex2);
		return adjMatrix[vertPos1][vertPos2];
	}
	return 0;
}

std::vector<int> Graph::GetNbrs(const int& vertex)
{
	std::vector<int> nbrsList; // Создание списка соседей
	int pos = this->GetVertPos(vertex); // Вычисление позиции vertex в матрице смежности	
	if (pos != (-1)) // Проверка, что vertex есть в матрице смежности
	{
		for (int i = 0, vertListSize = this->vertList.size(); i < vertListSize; ++i)
		{
			if (this->adjMatrix[pos][i] != 0) // Вычисление соседей
				nbrsList.push_back(this->vertList[i]); // Запись соседей в вектор			
		}
	}
	return nbrsList; // Возврат списка соседей
}

void Graph::InsertVertex(const int& vertex)
{
	if (!this->IsFull())
	{
		this->vertList.push_back(vertex);
	}
	else
	{
		std::cout << "Граф уже заполнен. Невозможно добавить новую вершину " << std::endl;
		return;
	}
}

void Graph::InsertEdge(const int& vertex1, const int& vertex2, int weight)
{
	if (this->GetVertPos(vertex1) != (-1) && this->GetVertPos(vertex2) != (-1))
	{
		int vertPos1 = GetVertPos(vertex1);
		int vertPos2 = GetVertPos(vertex2);
		if (this->adjMatrix[vertPos1][vertPos2] != 0)
		{
			std::cout << "Ребро между этими вершинами уже существует" << std::endl;
			return;
		}
		else
			this->adjMatrix[vertPos1][vertPos2] = weight;
	}
	else
		std::cout << "Обеих вершин (или одной из них) нет в графе " << std::endl;
}

void Graph::Print()
{
	if (!this->IsEmpty())
	{
		std::cout << "Матрица смежности графа: " << std::endl;
		for (int i = 0, vertListSize = this->vertList.size(); i < vertListSize; ++i)
		{
			std::cout << this->vertList[i] << "|\t";
			for (int j = 0; j < vertListSize; ++j)
			{
				std::cout /*<< "\t"*/ << this->adjMatrix[i][j] << "\t";
			}
			std::cout << std::endl;
		}
	}
	else
		std::cout << "Граф пуст " << std::endl;
}

void Graph::DFS(int startVertex, bool* visitedVerts)
{
    // Выводим сообщение о том, что вершина посещена
    std::cout << "Вершина " << startVertex << " посещена" << std::endl;
    // Отмечаем в массиве посещенных вершин, что вершина посещена
    visitedVerts[this->GetVertPos(startVertex)] = true;
    std::vector<int> neighbors = this -> GetNbrs(startVertex);
    // Создаем вектор соседей
    for (int i = 0, size = this -> GetNbrs(startVertex).size();
        i < size; ++i)
    {
        if (visitedVerts[this -> GetVertPos(neighbors[i])] != true)
            // В цикле проверяем, что соседи текущей вершины еще не посещены и вызываем функцию обхода графа в глубину
            this->DFS(neighbors[i], visitedVerts);
    }
}

void Graph::initWindow(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutCreateWindow("My Graph");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
}