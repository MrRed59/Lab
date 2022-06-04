#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include<queue>
#include"draw.h"

template <class S>
class SearchTree
{
	S data; // ������ ���� �
	SearchTree* left;							// ��������� �� ���� �����
	SearchTree* right;							// ��������� �� ���� ������
	SearchTree* parent;							// ��������� �� ������
public:
	//-------------Constructors-------------//

	SearchTree(S);								// �����������
	~SearchTree();								// ����������

	//

	int getHeight(); //�������� ������ ������ (������� � �������� ���� �� ����������� � �������)
	S getData() { return data; }; // �������� ������ � ����	
	int getAmountOfNodes(); // �������� ���������� ��������� ������
	SearchTree<S>* getLeft() { return left; } // �������� ����� ����
	SearchTree<S>* getRight() { return right; } // �������� ������ ����
	SearchTree<S>* getParent() { return parent; } // �������� ��������
	int getLevel(SearchTree* tree);

	SearchTree<S>* copyTree(); // ����������� ������
	SearchTree<S>* replaceNULLforEmpty(); //���� ������ ��������, ������� ��� ������ (����������� ���� ���������� ������ NULL)
	SearchTree<S>* replace_help(SearchTree* node, int h);

	void insertLeft(S); // �������� ���� �����
	void insertRight(S); // �������� ���� ������		
	void addLeftTree(SearchTree<S>* tree) { left = tree; } // �������� ��������� �����		
	void addRightTree(SearchTree<S>* tree) { right = tree; } // �������� ��������� ������


	void deleteSearchTree() { delete this; }	// ������� ������	
	void printSearchTree(int);					// �������������� ������ ������	
	void inOrder(SearchTree<S>*);				// ������������ ����� ������	
	void preOrder(SearchTree<S>*);				//������� �������� ��������� (������ ����)
	void postOrder(SearchTree<S>*);				//������� �������� ��������� (c��� �����)
	void printTree(int);						//������� �������� ��������� (�������������)
	void printVTree(int);						// ������ ������ �����������
	void setData(S dt) { data = dt; }			// ���������� ������ ��� ����	
	SearchTree<S>* next();						// ����� ��������� �������
	SearchTree<S>* prev();						// ����� ���������� �������
	void insertNode(S);							// �������� ����
	void deleteNode(S);							// ������� ����
	SearchTree<S>* findElement(S);				// ����� �������
	SearchTree<S>* findMax();					// ����� ��������
	SearchTree<S>* findMin();					// ����� �������
	size_t number_by_symbol(const S&);
};

template <class S>
void SearchTree<S>::insertLeft(S dt) //������� ���� �����
{
	SearchTree<S>* node = new SearchTree(dt);
	if (this->left != nullptr)
		this->left->parent = node;// ������� ���, ����� ��� ������� ��� ����� ����
	node->left = this->left; //������ � ������ ���� ����� ������� � ��� ����� ������� ����������� ����
	this->left = node; //� ���������� ���� ������ �����	������ ������� � ��� ����� ����
	node->parent = this; //���������, ��� � ������ ���� ������ ������� �������� ������� ����
}

template<class S>
void SearchTree<S>::insertRight(S dt) //������� ���� ������
{
	SearchTree<S>* node = new SearchTree(dt);
	if (this->right != nullptr)
		this->right->parent = node;
	node->right = this->right;
	this->right = node;
	node->parent = this;
}


template <class	S>
int SearchTree<S>::getHeight()
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

template<class S>
int SearchTree<S>::getAmountOfNodes()
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

template <class S>
int SearchTree<S>::getLevel(SearchTree<S>* tree)
{
	return tree->getParent() == nullptr ? 0 : getLevel(tree->getParent()) + 1;
}

template <class S>
SearchTree<S>* SearchTree<S>::replaceNULLforEmpty()
{
	SearchTree<S>* node = this->copyTree();
	int h = node->getHeight();
	node = replace_help(node, h);
	return node;
}

template<class S>
SearchTree<S>* SearchTree<S>::copyTree()
{
	SearchTree<S>* tree = new SearchTree<S>(this->data);
	if (this->parent != nullptr)
		tree->parent = this->parent;
	if (this->left != nullptr)
		tree->left = this->left->copyTree();
	if (this->right != nullptr)
		tree->right = this->right->copyTree();
	return tree;
}

template <class S>
SearchTree<S>* SearchTree<S>::replace_help(SearchTree<S>* node, int h)
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



template <class S>
SearchTree<S>* SearchTree<S>::findElement(S dt)
{
	if ((this == nullptr) || (dt == this->data))
		return this;
	if (dt < this->data)
		return this->left->findElement(dt);
	else
		return this->right->findElement(dt);
}

template <class S>
SearchTree<S>* SearchTree<S>::findMin()
{
	if (this->left == nullptr)
		return this;
	return this->left->findMin();
}
template <class S>
SearchTree<S>* SearchTree<S>::findMax()
{
	if (this->right == nullptr)
		return this;
	return this->right->findMax();
}

template <class S>
SearchTree<S>* SearchTree<S>::next()
{
	SearchTree* tree = this;
	if (tree->right != nullptr)
		return tree->right->findMin();
	SearchTree<S>* t = tree->parent;
	while ((t != nullptr) && (tree == t->right))
	{
		tree = t;
		t = t->parent;
	}
	return t;
}

template <class S>
SearchTree<S>* SearchTree<S>::prev()
{
	SearchTree* tree = this;
	if (tree->left != nullptr)
		return tree->left->findMax();
	SearchTree<S>* t = tree->parent;
	while ((t != nullptr) && (tree == t->left))
	{
		tree = t;
		t = t->parent;
	}
	return t;
}

template <class S>														//���������� ������ �������� �������
void SearchTree<S>::insertNode(S dt)
{
	SearchTree<S>* tree = this;											//�������� ������� ������ ��������

	while (tree != NULL)												//����������� ������������� ��������
	{
		if (dt >= tree->data)											//����������� �������� ��������
		{
			if (tree->right != NULL)									//����������� ������������� �������� ������
			{
				tree = tree->right;										//������� � �������� ������
			}
			else
			{
				SearchTree<S>* temp = new SearchTree<S>(dt);			//�������� ����� �������

				temp->parent = tree;									//������� ������ �������� �������� �������� ������
				tree->right = temp;										//������� �������� �������� �������� ������
				break;
			}
		}
		else if (dt < tree->data)										//����������� �������� ��������
		{
			if (tree->left != NULL)										//����������� ������������� �������� �����
			{
				tree = tree->left;										//������� � �������� �����
			}
			else
			{
				SearchTree<S>* temp = new SearchTree<S>(dt);			//�������� ����� �������

				temp->parent = tree;									//������� ������ �������� �������� �������� ������
				tree->left = temp;										//������� �������� �������� �������� �����
				break;
			}
		}
	}
}

template<class S>
void SearchTree<S>::deleteNode(S dt)
{
	SearchTree<S>* e = this->findElement(dt);
	SearchTree<S>* p = e->parent; //������ ���������� ��������

	if ((e->left == nullptr) && (e->right == nullptr)) // ������ ������: ��������� ������� �� ����� ��������
	{
		if (p->left == e) p->left = nullptr;
		if (p->right == e) p->right = nullptr;
	}

	else if ((e->left == NULL) || (e->right == NULL)) // ������ ������: ��������� ������� ����� ������ �������
	{
		if (e->left == NULL)
		{
			if (p->left == e) p->left = e->right;
			else p->right = e->right;
			e->right->parent = p;
		}
		else
		{
			if (p->left == e) p->left = e->left;
			else p->right = e->left;
			e->left->parent = p;
		}
	}

	// ������ ������: ��������� ������� ����� ���� ��������
	else
	{
		SearchTree<S>* s = e->next();
		// ��������� ������� �� ���������
		e->data = s->data;
		if (s->parent->left == s)
		{
			s->parent->left = s->right;
			if (s->right != NULL)
				s->right->parent = s->parent;
		}
		else
		{
			s->parent->right = s->right;
			if (s->right != NULL)
				s->right->parent = s->parent;
		}
	}
}

template<class S>
inline SearchTree<S>::SearchTree(S dt)
{
	data = dt;															//������� �������� ��������
	left = NULL;														//������� �������� �������� �����
	right = NULL;														//������� �������� �������� ������
	parent = NULL;														//������� �������� �������� ������
}

template <class S>														//���������� �����������
SearchTree<S>::~SearchTree()
{
	delete this->left;													//��������� ������� �����
	delete this->right;													//��������� ������� ������
}

template <class S>														//���������� ������ ������� �������� ��������� (�������������)
void SearchTree<S>::printSearchTree(int level)
{
	if (this != NULL)													//����������� ������������� ��������
	{
		this->right->printSearchTree(level + 1);						//������� � �������� ������

		for (int i = 1; i < level; i++)									//��������� �������
		{
			std::cout << "  ";
		}

		std::cout << this->data << std::endl;										//��������� �������� ��������
		this->left->printSearchTree(level + 1);								//������� � �������� �����
	}
}

template <class S>														//���������� ������ ������� �������� ��������� (������ ����)
void SearchTree<S>::preOrder(SearchTree<S>* temp)
{
	if (temp != NULL)													//����������� ������������� ��������
	{
		std::cout << temp->data << "   ";									//��������� �������� ��������
		preOrder(temp->left);											//������� � �������� �����
		preOrder(temp->right);											//������� � �������� ������
	}
}

template <class S>														//���������� ������ ������� �������� ��������� (����� �������)
void SearchTree<S>::inOrder(SearchTree<S>* temp)
{
	if (temp != NULL)													//����������� ������������� ��������
	{
		inOrder(temp->left);											//������� � �������� �����
		std::cout << temp->data << "   ";									//��������� �������� ��������
		inOrder(temp->right);											//������� � �������� ������
	}
}

template <class S>														//���������� ������ ������� �������� ��������� (c��� �����)
void SearchTree<S>::postOrder(SearchTree<S>* temp)
{
	if (temp != NULL)													//����������� ������������� ��������
	{
		postOrder(temp->left);											//������� � �������� �����
		postOrder(temp->right);											//������� � �������� ������
		std::cout << temp->data << "   ";									//��������� �������� ��������
	}
}

template <class S>														//���������� ������ ������� �������� ��������� (�������������)
void SearchTree<S>::printTree(int level)
{
	if (this != NULL)													//����������� ������������� ��������
	{
		this->right->printTree(level + 1);								//������� � �������� ������

		for (int i = 1; i < level; i++)									//��������� �������
		{
			std::cout << "  ";
		}

		std::cout << this->data << std::endl;										//��������� �������� ��������
		this->left->printTree(level + 1);								//������� � �������� �����
	}
}

template <class S>
void SearchTree<S>::printVTree(int k)
{
	int height = this->getHeight(); //������������ ����� ������ �� ������ ������(��������� � ����)
	int maxLeafs = pow(2, height - 1); //����������� ������ ������ ��� ������	(�� ��������, �� �����������)
	int width = 2 * maxLeafs - 1;
	int curLevel = 0; // ����� ������ (�� ������)
	int index = 0; // ����� �������� � ������ (��������� � ����)
	int factSpaces = getPos(index, width, curLevel, height - 1); //������� ����� (����� �������� ����� ���)
	pos node;
	std::vector<SearchTree<S>*> V;
	std::vector<pos> Vi;
	SearchTree<S>* t = this->copyTree();
	t = t->replaceNULLforEmpty();
	SearchTree<S>* p = t;
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

template <class S>
size_t SearchTree<S>::number_by_symbol(const S& value)
{
	size_t n_l{}, n_r{};

	if (this == nullptr)
	{
		return 0;
	}

	if (this->left != nullptr)
	{
		n_l = this->left->number_by_symbol(value);
	}
	if (this->right != nullptr)
	{
		n_r = this->right->number_by_symbol(value);
	}
	if (this->data == value)
	{
		return (n_l + n_r + 1);
	}
	return (n_l + n_r);
}