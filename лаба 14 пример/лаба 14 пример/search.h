#pragma once
#include <iostream>

using namespace std;

template <class S>														//�������� ���������� ������ ������� ������ ������
class SearchTree
{
public:

	S data;																//����������� ���������� �������� ��������
	SearchTree* left;													//����������� ��������� ������� �����
	SearchTree* right;													//����������� ��������� ������� ������
	SearchTree* parent;													//����������� ��������� ������� ������

	SearchTree(S);														//����������� ����������� � �����������
	~SearchTree();														//����������� ����������

	SearchTree<S>* findElement(S);										//����������� ����� ����� �������
	SearchTree<S>* findMax();											//����������� ����� ����� ���������� �������
	SearchTree<S>* findMin();											//����������� ����� ����� ���������� �������
	SearchTree<S>* next();												//����������� ����� ����� ��������� �������
	SearchTree<S>* prev();												//����������� ����� ����� ���������� �������
	void preOrder(SearchTree<S>*);										//����������� ����� ������� �������� ��������� (������ ����)
	void inOrder(SearchTree<S>*);										//����������� ����� ������� �������� ��������� (����� �������)
	void postOrder(SearchTree<S>*);										//����������� ����� ������� �������� ��������� (c��� �����)
	void printTree(int);												//����������� ����� ������� �������� ��������� (�������������)
	//void inOrder(SerachTree<S>*);										//����������� ����� ������� �������� ��������� (����� �������)
	//void printSearchTree(int);											//����������� ����� ������� �������� ��������� (�������������)
	void insertNode(S);													//����������� ����� �������� �������
	void deleteNode(S);													//����������� ����� ������� �������

	void setData(S dt)													//���������� ������ �������� �������� ��������
	{
		data = dt;														//������� �������� ��������
	}

	void deleteSearchTree()												//���������� ������ ������� ������
	{
		delete this;													//��������� �������
	}
};

template <class S>														//���������� ������������ � �����������
SearchTree<S>::SearchTree(S dt)
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

template <class S>														//���������� ������ ����� �������
SearchTree<S>* SearchTree<S>::findElement(S dt)
{
	if ((this != NULL) || (dt == this->data))							//����������� ������������� �������� � ������������ � ������� ���������
	{
		return this;													//������������ �������� ��������
	}
	else
	{
		if (dt < this->data)											//����������� �������� ��������
		{
			return this->left->findElement(dt);							//������� � �������� �����
		}
		else
		{
			return this->right->findElement(dt);						//������� � �������� ������
		}
	}	
}

template <class S>														//���������� ������ ����� ���������� �������
SearchTree<S>* SearchTree<S>::findMax()
{
	if (this->right == NULL)											//����������� ������������� �������� ������
	{
		return this;													//������������ �������� ��������
	}
	else
	{
		return this->right->findMax();									//������� � �������� ������
	}
}

template <class S>														//���������� ������ ����� ���������� �������
SearchTree<S>* SearchTree<S>::findMin()
{
	if (this->left == NULL)												//����������� ������������� �������� �����
	{
		return this;													//������������ �������� ��������
	}
	else
	{
		return this->left->findMin();									//������� � �������� �����
	}
}

template <class S>														//���������� ������ ����� ��������� �������
SearchTree<S>* SearchTree<S>::next()
{
	SearchTree<S>* tree = this;											//�������� ������� ������ ��������

	if (tree->right != NULL)											//����������� ������������� �������� ������
	{
		return tree->right->findMin();									//������������ �������� ���������� �������� ������
	}
	else
	{
		SearchTree<S>* temp = tree->parent;								//�������� ��������� ������� ������ �������� ������

		while ((temp != NULL) && (tree == temp->right))					//����������� ������������� �������� ������ � ������� ������� ������������ � ��������� ������ �� ������
		{
			tree = temp;												//������� � �������� ������
			temp = temp->parent;										//������� � �������� ������
		}

		return temp;													//������������ �������� ���������� ��������
	}
}

template <class S>														//���������� ������ ����� ���������� �������
SearchTree<S>* SearchTree<S>::prev()
{
	SearchTree<S>* tree = this;											//�������� ������� ������ ��������

	if (tree->left != NULL)												//����������� ������������� �������� �����
	{
		return tree->left->findMax();									//������������ �������� ����������� �������� �����
	}
	else
	{
		SearchTree<S>* temp = tree->parent;								//�������� ��������� ������� ������ �������� ������

		while ((temp != NULL) && (tree == temp->left))					//����������� ������������� �������� ������ � ������� ������� ������������ � ��������� ������ �� ������
		{
			tree = temp;												//������� � �������� ������
			temp = temp->parent;										//������� � �������� ������
		}

		return temp;													//������������ �������� ���������� ��������
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
		cout << temp->data << "   ";									//��������� �������� ��������
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

template <class S>														//���������� ������ ������� �������
void SearchTree<S>::deleteNode(S dt)
{
	SearchTree<S>* temp1 = this->findElement(dt);						//�������� ����� ������� ������ ���������� ��������
	SearchTree<S>* temp2 = temp1->parent;								//�������� ����� ������� ������ ������ ���������� ��������

	//���� � ���������� �������� ��� ��������

	if ((temp1->left == NULL) && (temp1->right == NULL))				//����������� ������������� ��������� ����� � ������ �� ����������
	{
		if (temp2->left == temp1)										//����������� ����� �� ��������� ��������� � ������
		{
			temp2->left = NULL;											//������� ������� �������� �������� ����� � ������
		}

		if (temp2->right == temp1)										//����������� ����� �� ��������� ��������� � ������
		{
			temp2->right = NULL;										//������� ������� �������� �������� ������ � ������
		}
	}

	//���� � ���������� �������� ���� �������

	else if ((temp1->left == NULL) || (temp1->right == NULL))			//����������� ������������� ��������� ����� ��� ������ �� ����������
	{
		if (temp1->left == NULL)										//����������� ������������� �������� ����� �� ����������
		{
			if (temp2->right == temp1)									//����������� ����� �� ��������� ��������� � ������
			{
				temp2->left = temp1->right;								//������� �������� �������� ����� � ������ ���������� ��������
			}
			else
			{
				temp2->right = temp1->right;							//������� �������� �������� ������ � ������ ���������� ��������
			}

			temp1->right->parent = temp2;								//������� �������� �������� ������ � �������� ������ �� ����������
		}
		else
		{
			if (temp2->left == temp1)									//����������� ����� �� ��������� ��������� � ������
			{
				temp2->left = temp1->left;								//������� �������� �������� ����� � ������ ���������� ��������
			}
			else
			{
				temp2->right = temp1->left;								//������� �������� �������� ������ � ������ ���������� ��������
			}

			temp1->left->parent = temp2;
		}
	}

	//���� � ���������� �������� ��� �������

	else
	{
		SearchTree<S>* temp3 = temp1->next();							//�������� ����� ������� ������ ���������� �������� ����� ����������

		temp1->data = temp3->data;										//������� �������� ���������� �������� ������ ���������� ��������
		
		if (temp3->parent->left == temp3)								//����������� ����� �� ��������� ��������� � ������
		{
			temp3->parent->left = temp3->right;							//������� �������� �������� ����� � ������ ���������� ��������

			if (temp3->right != NULL)									//����������� ������������� �������� ������ �� ����������
			{
				temp3->right->parent = temp3->parent;					//������� �������� ������ � �������� ������ �� ����������
			}
		}
		else
		{
			temp3->parent->right = temp3->right;						//������� �������� �������� ������ � ������ ���������� ��������

			if (temp3->right != NULL)									//����������� ������������� �������� ������ �� ����������
			{
				temp3->right->parent = temp3->parent;					//������� �������� ������ � �������� ������ �� ����������
			}
		}
	}
}