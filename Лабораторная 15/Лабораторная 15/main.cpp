#include "Graph.h"
#include <iostream>
#include<conio.h>

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");

	Graph graph; // Cоздание графа, содержащего вершины с номерами целого типа
	int amountVerts{}, amountEdges{}, vertex{}, sourceVertex{}, targetVertex{}, weight{};;
	std::cout << "Введите количество вершин графа: ";
	std::cin >> amountVerts; std::cout << std::endl; // Ввод количества ребер графа в переменную amountVerts
	std::cout << "Введите количество ребер графа: ";
	std::cin >> amountEdges; std::cout << std::endl;	// Ввод количества ребер графа в переменную amountEdges
	std::cout << "///////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "///////////////////////////////////////////////////////////////" << std::endl;

	for (int i = 0; i < amountVerts; ++i)
	{
		std::cout << "Вершина: "; 
		std::cin >> vertex; // Ввод вершины
		int* vertPtr = &vertex; // Запоминаем адрес вершины с помощью указателя
		graph.InsertVertex(*vertPtr);
		// Передаем ссылку на вершину в функцию InsertVertex происходит вставка вершины в вектор вершин
		std::cout << std::endl;
		std::cout << "///////////////////////////////////////////////////////////////" << std::endl;

	}
	for (int i = 0; i < amountEdges; ++i)
	{
		std::cout << "Исходная вершина: ";
		std::cin >> sourceVertex;
		std::cout << std::endl; // ввод исходной вершины
		int* sourceVertPtr = &sourceVertex;	// Запоминаем адрес исходной вершины
		std::cout << "Конечная вершина: "; 
		std::cin >> targetVertex; // Ввод вершины, до которой будет идти ребро от исходной вершины
		std::cout << std::endl;		
		std::cout << "Вес ребра: ";
		std::cin >> weight;
		std::cout << "///////////////////////////////////////////////////////////////" << std::endl; 
		int* targetVertPtr = &targetVertex; // Запоминаем адрес конечной вершины (до которой будет идти ребро от исходной вершины)			
		graph.InsertEdge(*sourceVertPtr, *targetVertPtr, weight); 
		// Вставка ребра между исходной и конечной вершинами, в функцию передаются ссылки на исходную и конечную вершины
	}
	std::cout << "///////////////////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl;
	graph.Print(); // Печать матрицы смежности графа
	std::cout << "Введите вершину, с которой начать обход: ";
	std::cin >> vertex;
	std::cout << std::endl; // Ввод начальной вершины, с которой начнется обход графа в глубину (в нашем случае это 0)
	bool* visitedVerts = new bool[20]{};
	int* vertPtr = &vertex; // Запоминаем адрес	введенной вершины
	// Вызываем функцию обхода графа в глубину, в функцию передаются ссылка на введенную вершину и вектор посещенных вершин
	graph.DFS(*vertPtr, visitedVerts);
	delete[] visitedVerts;

	graph.initWindow(argc, argv);

	return 0;
}

