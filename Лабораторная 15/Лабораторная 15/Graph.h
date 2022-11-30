#pragma once
#include<vector>
#include<iostream>


const int maxSize = 20;
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

class Graph
{
	std::vector<int> vertList;
	int adjMatrix[maxSize][maxSize];
public:


	Graph();
	~Graph();
	int GetVertPos(const int&);
	bool IsEmpty();
	bool IsFull();
	int GetAmountVerts();
	int GetAmountEdges();
	int GetWeight(const int&, const int&);
	std::vector<int> GetNbrs(const int&);
	void InsertVertex(const int&);
	void InsertEdge(const int& vertex1, const int& vertex2, int weight = 0);
	void Print();
	void DFS(int, bool*);
	static void initWindow(int argc, char** argv);
};

