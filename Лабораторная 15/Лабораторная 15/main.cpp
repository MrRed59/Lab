#include "Graph.h"
#include <iostream>
#include<conio.h>

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");

	Graph graph; // C������� �����, ����������� ������� � �������� ������ ����
	//int amountVerts{}, amountEdges{}, vertex{}, sourceVertex{}, targetVertex{}, weight{};;
	//std::cout << "������� ���������� ������ �����: ";
	//std::cin >> amountVerts; std::cout << std::endl; // ���� ���������� ����� ����� � ���������� amountVerts
	//std::cout << "������� ���������� ����� �����: ";
	//std::cin >> amountEdges; std::cout << std::endl;	// ���� ���������� ����� ����� � ���������� amountEdges
	//std::cout << "///////////////////////////////////////////////////////////////" << std::endl;
	//std::cout << "///////////////////////////////////////////////////////////////" << std::endl;

	//for (int i = 0; i < amountVerts; ++i)
	//{
	//	std::cout << "�������: "; 
	//	std::cin >> vertex; // ���� �������
	//	int* vertPtr = &vertex; // ���������� ����� ������� � ������� ���������
	//	graph.InsertVertex(*vertPtr);
	//	// �������� ������ �� ������� � ������� InsertVertex ���������� ������� ������� � ������ ������
	//	std::cout << std::endl;
	//	std::cout << "///////////////////////////////////////////////////////////////" << std::endl;

	//}
	//for (int i = 0; i < amountEdges; ++i)
	//{
	//	std::cout << "�������� �������: ";
	//	std::cin >> sourceVertex;
	//	std::cout << std::endl; // ���� �������� �������
	//	int* sourceVertPtr = &sourceVertex;	// ���������� ����� �������� �������
	//	std::cout << "�������� �������: "; 
	//	std::cin >> targetVertex; // ���� �������, �� ������� ����� ���� ����� �� �������� �������
	//	std::cout << std::endl;		
	//	std::cout << "��� �����: ";
	//	std::cin >> weight;
	//	std::cout << "///////////////////////////////////////////////////////////////" << std::endl; 
	//	int* targetVertPtr = &targetVertex; // ���������� ����� �������� ������� (�� ������� ����� ���� ����� �� �������� �������)			
	//	graph.InsertEdge(*sourceVertPtr, *targetVertPtr, weight); 
	//	// ������� ����� ����� �������� � �������� ���������, � ������� ���������� ������ �� �������� � �������� �������
	//}
	//std::cout << "///////////////////////////////////////////////////////////////" << std::endl;
	//std::cout << std::endl;
	//graph.Print(); // ������ ������� ��������� �����
	//std::cout << "������� �������, � ������� ������ �����: ";
	//std::cin >> vertex;
	//std::cout << std::endl; // ���� ��������� �������, � ������� �������� ����� ����� � ������� (� ����� ������ ��� 0)
	//bool* visitedVerts = new bool[20]{};
	//int* vertPtr = &vertex; // ���������� �����	��������� �������
	//// �������� ������� ������ ����� � �������, � ������� ���������� ������ �� ��������� ������� � ������ ���������� ������
	//graph.DFS(*vertPtr, visitedVerts);
	//delete[] visitedVerts;

	graph.initWindow(argc, argv);

	return 0;
}

