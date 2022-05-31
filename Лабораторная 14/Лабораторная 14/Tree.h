#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include<queue>
#include"draw.h"
//#pragma clang diagnostic push
//#pragma ide diagnostic ignored "InfiniteRecursion"
//#pragma ide diagnostic ignored "misc-no-recursion"
//#include"stdafx.h"
//using namespace std;
template <class T>

class Tree
{
		T data; // ������ ���� �
		Tree* left; // ��������� �� ���� �����
		Tree* right; // ��������� �� ���� ������
		Tree* parent; // ��������� �� ������
public:

		//-------------Constructors-------------//

		Tree(T); // �����������
		~Tree(); // ����������

		//-------------Getters-------------//

		T getData() { return data; }; // �������� ������ � ����	
		int getAmountOfNodes(); // �������� ���������� ��������� ������
		int getHeight(); //�������� ������ ������ (������� � �������� ���� �� ����������� � �������)
		Tree<T>* getLeft() { return left; } // �������� ����� ����
		Tree<T>* getRight() { return right; } // �������� ������ ����
		Tree<T>* getParent() { return parent; } // �������� ��������
		int getLevel(Tree* tree);

		//-------------Setters-------------//

		void setData(T& dt) { data = dt; } // ���������� ������ ��� ����

		//-------------Delete-------------//

		void deleteLeft(); // ������� ��������� �����
		void deleteRight(); // ������� ��������� ������
		void deleteTree() { delete this; } // ������� ������

		//-------------Overloaded functions-------------//

		void insertLeft(T); // �������� ���� �����
		void insertRight(T); // �������� ���� ������		
		void addLeftTree(Tree<T>* tree) { left = tree; } // �������� ��������� �����		
		void addRightTree(Tree<T>* tree) { right = tree; } // �������� ��������� ������
		Tree<T>* ejectLeft(); // ������� ��������� �����
		Tree<T>* ejectRight(); // ������� ��������� ������
		static void preOrder(Tree<T>*); //������ ������ � ������� ���������	� ������ �������(������ ����)
		static void inOrder(Tree<T>*); //������ ������ � ������� ��������� � ������������ �������(����� �������)
		static void postOrder(Tree<T>*); //������ ������ � ������� ��������� � �������� �������(����� �����)
		Tree<T>* copyTree(); // ����������� ������
		void obh(Tree<T>* node); //����������� �� ������ � ������ � ����
		void levelScan(); //��������� �� ������� ������ ������ ������� � ����� � ������� ��������
		Tree<T>* replaceNULLforEmpty(); //���� ������ ��������, ������� ��� ������ (����������� ���� ���������� ������ NULL)
		Tree<T>* replace_help(Tree* node, int h);
		void findElement_insertLeft(Tree<T>*, T, T); //����� ������� � �������� � ���� ����� ����
		void findElement_insertRight(Tree<T>*, T, T); //����� ������� � �������� � ���� ������ ����
		static Tree<T>* balancedTree(int n); //��������� �������� ���������������� ������ �� ������� ���������� ���������

		//-------------Print-------------//

		void printTree(int); // ������ ������ �������������
		void printVTree(int); // ������ ������ �����������
		void printVTree2(); // ������ ������ ����������� (2)

};

//template <class T>
//int getLevel(Tree<T>* tree);

template<class T>
Tree<T>::Tree(T dt)/* :data(dt), left(nullptr), right(nullptr), parent(nullptr)*/ // ����������� ����
{
	data = dt; // �������� ������ �� ���������
	left = NULL; // ������� ��� ���������
	right = NULL;
	parent = NULL;
}

template<class T>
Tree<T>::~Tree() // ���������� ������
{
	delete this->left;
	delete this->right;
}

template <class T>
void Tree<T>::insertLeft(T dt) //������� ���� �����
{
	Tree<T>* node = new Tree(dt);
	if (this->left != nullptr)
		this->left->parent = node;// ������� ���, ����� ��� ������� ��� ����� ����
	node->left = this->left; //������ � ������ ���� ����� ������� � ��� ����� ������� ����������� ����
	this->left = node; //� ���������� ���� ������ �����	������ ������� � ��� ����� ����
	node->parent = this; //���������, ��� � ������ ���� ������ ������� �������� ������� ����
}

template<class T>
void Tree<T>::insertRight(T dt) //������� ���� ������
{
	Tree<T>* node = new Tree(dt);
	if (this->right != nullptr)
		this->right->parent = node;
	node->right = this->right;
	this->right = node;
	node->parent = this;
}

template<class T>
void Tree<T>::preOrder(Tree<T>* node) // ������ ����� (������ ����)
{
	if (node != NULL)
	{
		std::cout << node->getData() << "";
		reorder(node->left);
		reorder(node->right);
	}
}

template<class T>
void Tree<T>::inOrder(Tree<T>* node) // ������������ ����� (����� �������)
{
	if (node != NULL)
	{
		inOrder(node->left);
		std::cout << node->getData() << "";
		inOrder(node->right);
	}
}

template<class T>
void Tree<T>::postOrder(Tree<T>* node) // �������� ����� (����� �����)
{
	if (node != NULL)
	{
		postOrder(node->left);
		postOrder(node->right);
		std::cout << node->getData() << "";
	}
}


//------Deleting

template<class T>
Tree<T>* Tree<T>::ejectLeft() // ����������
{
	if (this->left != nullptr)
	{
		Tree<T>* temp = this->left;
		this->left = nullptr;
		return temp;
	}
	return nullptr;
}

template<class T>
void Tree<T>::deleteLeft() // ��������
{
	Tree<T>* temp = this->ejectLeft();
	delete temp;
}

template<class T>
Tree<T>* Tree<T>::ejectRight()
{
	if (this->right != nullptr)
	{
		Tree<T>* temp = this->right;
		this->right = nullptr;
		return temp;
	}
	return nullptr;
}

template<class T>
void Tree<T>::deleteRight()
{
	Tree<T>* temp = this->ejectRight();
	delete temp;
}

//

template<class T>
void Tree<T>::printTree(int level)
{
	if (this != NULL)
	{
		this->left->printTree(level + 1);
		for (int i = 1; i < level; i++)
			std::cout << " ";
		std::cout << this->getData() << std::endl;
		this->right->printTree(level + 1);
	}
}

template<class T>
Tree<T>* Tree<T>::copyTree()
{
	Tree<T>* tree = new Tree<T>(this->data);
	if (this->parent != nullptr)
		tree->parent = this->parent;
	if (this->left != nullptr)
		tree->left = this->left->copyTree();
	if (this->right != nullptr)
		tree->right = this->right->copyTree();
	return tree;
}

template <class T>
Tree<T>* Tree<T>::balancedTree(int n)
{
	if (n == 0) return NULL;
	std::cout << "data=";
	T dt;
	std::cin >> dt;
	int nLeft = n / 2;
	int nRight = n - n / 2 - 1;
	Tree<T>* tree = new Tree<T>(dt);
	tree->addLeftTree(balancedTree(nLeft));
	tree->addRightTree(balancedTree(nRight));
	return tree;
}

template <class T>
void Tree<T>::findElement_insertLeft(Tree<T>* node, T dt1, T dt2)
{
	if (node != nullptr)
	{
		findElement_insertLeft(node->getLeft(), dt1, dt2);
		if (dt1 == node->getData()) node->insertLeft(dt2);
		findElement_insertLeft(node->getRight(), dt1, dt2);
	}
}

template <class T>
void Tree<T>::findElement_insertRight(Tree<T>* node, T dt1, T dt2)
{
	if (node != nullptr)
	{
		findElement_insertRight(node->getLeft(), dt1, dt2);
		if (dt1 == node->getData()) node->insertRight(dt2);
		findElement_insertRight(node->getRight(), dt1, dt2);
	}
}

template<class T>
void Tree<T>::levelScan()
{
	std::vector<Tree<T>*> V;
	Tree<T>* p = this;
	V.push_back(p);
	for (int i = 0; i < this->getAmountOfNodes(); i++)
	{
		if (V.at(i)->left != nullptr)
			V.push_back(V.at(i)->left);
		if (V.at(i)->right != nullptr)
			V.push_back(V.at(i)->right);
	}
	for (int i = 0; i < V.size(); i++)
		std::cout << V.at(i)->getData() << " ";
	std::cout << std::endl;
}

template <class T>
int Tree<T>::getHeight()
{
	int h1 = 0, h2 = 0, hadd = 0;
	if (this == nullptr)
		return 0;
	if (this->left != nullptr)
		h1 = this->left->getHeight();
	if (this->right != nullptr)
		h2 = this->right->getHeight();
	if (h1 >= h2)
		return h1 + 1;
	else
		return h2 + 1;
}

template<class T>
int Tree<T>::getAmountOfNodes()
{
	if (this == nullptr)
		return 0;
	if ((this->left == nullptr) && (this->right == nullptr))
		return 1;
	int l = 0;
	int r = 0;
	if (this->left != nullptr)
		l = this->left->getAmountOfNodes();
	if (this->right != nullptr)
		r = this->right->getAmountOfNodes();
	return (l + r + 1);
}

template <class T>
int Tree<T>::getLevel(Tree<T>* tree)
{
	return tree->getParent() == nullptr ? 0 : getLevel(tree->getParent()) + 1;
}

template <class T>
Tree<T>* Tree<T>::replaceNULLforEmpty()
{
	Tree<T>* node = this->copyTree();
	int h = node->getHeight();
	node = replace_help(node, h);
	return node;
}

template <class T>
Tree<T>* Tree<T>::replace_help(Tree<T>* node, int h)
{
	int curLevel = getLevel(node);
	if ((node->getLeft() == nullptr) && (curLevel != (h - 1)))
		node->insertLeft(NULL);
	if ((node->getRight() == nullptr) && (curLevel != h - 1))
		node->insertRight(NULL);
	if (node->getLeft() != nullptr)
		node->addLeftTree(replace_help(node->getLeft(), h));
	if (node->getRight() != nullptr)
		node->addRightTree(replace_help(node->getRight(), h));
	return node;
}

template <class T>
void Tree<T>::printVTree(int k)
{
	int height = this->getHeight(); //������������ ����� ������ �� ������ ������(��������� � ����)
	int maxLeafs = pow(2, height - 1); //����������� ������ ������ ��� ������	(�� ��������, �� �����������)
	int width = 2 * maxLeafs - 1;
	int curLevel = 0; // ����� ������ (�� ������)
	int index = 0; // ����� �������� � ������ (��������� � ����)
	int factSpaces = getPos(index, width, curLevel, height - 1); //������� ����� (����� �������� ����� ���)
	pos node;
	std::vector<Tree<T>*> V;
	std::vector<pos> Vi;
	Tree<T>* t = this->copyTree();
	t = t->replaceNULLforEmpty();
	Tree<T>* p = t;
	V.push_back(p);
	node.col = factSpaces;
	node.str = curLevel;
	Vi.push_back(node);
	for (int i = 0; i < t->getAmountOfNodes(); i++)
	{
		if (pow(2, curLevel) <= index + 1)
		{
			index = 0;
			curLevel++;
		}
		if (V.at(i)->left != nullptr)
		{
			V.push_back(V.at(i)->left);
			factSpaces = getPos(index, width, curLevel, height - 1);
			node.col = factSpaces;
			node.str = curLevel;
			Vi.push_back(node);
			index++;
		}
		if (V.at(i)->right != nullptr)
		{
			V.push_back(V.at(i)->right);
			factSpaces = getPos(index, width, curLevel, height - 1);
			node.col = factSpaces;
			node.str = curLevel;
			Vi.push_back(node);
			index++;
		}
	}
	/* ����������� ������� � �������� (������ ��� ���������� ���������� �������� ����� ������ �������� ������� � ����������� �������):
 �� ����� ��� �������� ������������ ����� ���������� (��� �) */
	for (int i = V.size() - 1; i >= 0; i--)
	{
		if (i != 0)
		{
			if (Vi.at(i - 1).str == Vi.at(i).str) Vi.at(i).col = Vi.at(i).col - Vi.at(i - 1).col - 1;
		}
	}
	int flag = 0; // ������ �� ���, ��� y ��������
	for (int i = 0; i < V.size(); i++)
	{
		node = Vi.at(i);
		curLevel = node.str; //������� �� ����� ������� �����, ����� y1	������ ������ y (������ �� ���������� y)
		if (flag < curLevel)
		{
			flag = curLevel;
			std::cout << std::endl;
		}
		factSpaces = node.col;
		int realSpaces = k * factSpaces;
		for (int j = 0; j < realSpaces; j++)
			std::cout << " ";
		if (V.at(i)->getData() != NULL)
			std::cout << V.at(i)->getData();
		else for (int j = 0; j < k; j++)
			std::cout << " ";
	}
	std::cout << std::endl;
}

template <class T>
void Tree<T>::obh(Tree<T>* node) //���������� ����� ������ � ������ ��������� � ����
{
	std::ofstream f("print.txt");
	int amount = node->getAmountOfNodes(); //���-�� ��������� � ������
	std::queue<Tree<T>*> q; // ������� ����������
	q.push(node);
	while (!q.empty()) // ��� ������ �������� � ������� ������
	{
		Tree<T>* temp = q.front();
		q.pop();
		f << temp->data << std::endl;
		if (temp->left) //���� ���� ����� ���������, �� �������� ��� � ������� ��� ���������� ���������
			q.push(temp->left);
		if (temp->right) //���� ���� ������ ���������, �� �������� ��� � ������� ��� ���������� ���������
			q.push(temp->right);
	}
	f.close();
}

template <class T>
void Tree<T>::printVTree2()
{
	obh(this); // ����� ������ � ���������� �����
	std::ifstream f("print.txt");
	int amount = 0; // ���-�� ��������� � ������
	while (!f.eof())
	{
		char str[255];
		f.getline(str, 255);
		amount++;
	}
	f.close();
	amount--; // ���-�� ��������� � ������
	std::ifstream f1("print.txt");
	int* mas = new int[amount];
	for (int i = 0; i < amount; i++)
	{
		char str[255];// ���������� ��������� � ������
		f1.getline(str, 255);
		mas[i] = atoi(str);
	}
	f1.close();
	int height = this->getHeight();
	int count = 0; // ������� ��� ������
	int* spaces = new int[height]; // ������ ������ ��������	
	spaces[0] = 0; // ��� ������� 1 ����� 0 ��������
	for (int i = 1; i < height; i++)
		spaces[i] = spaces[i - 1] * 2 + 1; // ���������� ��������
	int amount_p = 0; // ���-�� ������������ ���������
	if (height == 1)
	{
		std::cout << mas[0] << std::endl;
	}
	else
	{
		/* l � ������ ��� ������ �������� |	����� ���� �����, ����� ��������� */
		for (int i = 0, l = height - 1; i < height - 1; i++,
			l--)
		{
			for (int j = 0, k = 0; j < pow(2, i); j++, k++)
			{
				if (k == 0) // ����� ������� ����� � ������
					for (int u = 0; u < spaces[l]; u++) // �������� �������
						std::cout << " ";
				else
				{
					for (int u = 0; u < spaces[l + 1]; u++)
						std::cout << " ";
				}
				std::cout << mas[count++];
				amount_p++;
			}
			std::cout << std::endl;
		}
		int* last_str = new int[pow(2, height - 1)]; // ����� ��������� ��������� ������
		for (int i = 0; i < pow(2, height - 1); i++)
			last_str[i] = 2000000000; // amount � ��� amount_p (���-�� ���������� ���������)
		int sch1 = 0;  // ������� ��� ���������� �������
		int sch2 = spaces[height - 2] + 1; //������ ������� ��� ���������� �������
		for (int i = amount_p; i < amount; i += 2) // ������ ������ ���, ��� ������ �������� � ������
		{
			if (i <= amount - 1) //���� ��� ���� ��������
			{
				last_str[sch1] = mas[i];
				sch1 += 2;
			}
			if (i + 1 <= amount - 1)
			{
				last_str[sch2] = mas[i + 1];
				sch2 += 2;
			}
			if (sch1 >= pow(2, height - 1) || sch2 >= pow(2,
				height - 1))
			{ //��������� ������ �������� �������
				sch1 = 1;
				sch2 = spaces[height - 2] + 2;
			}
		}
		for (int i = 0; i < pow(2, height - 1); i++) // ���������� ������������ ���������� �������
			if (last_str[i] != 2000000000)
				last_str[i] = mas[amount_p++];
		for (int i = 0; i < pow(2, height - 1); i++) //�������� ��������� ������
			if (last_str[i] != 2000000000)
				std::cout << last_str[i] << " ";
			else std::cout << " ";
		delete[] last_str;
		std::cout << std::endl;
	}
	delete[] mas;
	delete[] spaces;
}




//#include "Tree.cpp"
