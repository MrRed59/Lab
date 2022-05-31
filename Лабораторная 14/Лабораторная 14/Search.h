#pragma once

template <class S>
class SearchTree
{
	S data; // ������ ���� �
	SearchTree* left; // ��������� �� ���� �����
	SearchTree* right; // ��������� �� ���� ������
	SearchTree* parent; // ��������� �� ������
public:
	//-------------Constructors-------------//

	SearchTree(S); // �����������
	~SearchTree(); // ����������

	//

	void deleteSearchTree() { delete this; } // ������� ������	
	void printSearchTree(int); // �������������� ������ ������	
	void inOrder(SearchTree<S>*); // ������������ ����� ������	
	void preOrder(SearchTree<S>*);										//������� �������� ��������� (������ ����)
	void postOrder(SearchTree<S>*);										//������� �������� ��������� (c��� �����)
	void printTree(int);												//������� �������� ��������� (�������������)
	void setData(S dt) { data = dt; } // ���������� ������ ��� ����	
	SearchTree<S>* next(); // ����� ��������� �������
	SearchTree<S>* prev(); // ����� ���������� �������
	void insertNode(S); // �������� ����
	void deleteNode(S); // ������� ����
	SearchTree<S>* findElement(S); // ����� �������
	SearchTree<S>* findMax(); // ����� ��������
	SearchTree<S>* findMin(); // ����� �������
};

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
		cout << temp->data << "   ";									//��������� �������� ��������
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
		cout << temp->data << "   ";									//��������� �������� ��������
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
			cout << "  ";
		}

		cout << this->data << endl;										//��������� �������� ��������
		this->left->printTree(level + 1);								//������� � �������� �����
	}
}