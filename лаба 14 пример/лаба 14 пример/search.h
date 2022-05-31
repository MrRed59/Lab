#pragma once
#include <iostream>

using namespace std;

template <class S>														//описание шаблонного класса Элемент дерева поиска
class SearchTree
{
public:

	S data;																//объявляется переменная Значение элемента
	SearchTree* left;													//объявляется указатель Элемент слева
	SearchTree* right;													//объявляется указатель Элемент справа
	SearchTree* parent;													//объявляется указатель Элемент предок

	SearchTree(S);														//объявляется Конструктор с параметрами
	~SearchTree();														//объявляется Деструктор

	SearchTree<S>* findElement(S);										//объявляется метод Найти элемент
	SearchTree<S>* findMax();											//объявляется метод Найти наибольший элемент
	SearchTree<S>* findMin();											//объявляется метод Найти наименьший элемент
	SearchTree<S>* next();												//объявляется метод Найти следующий элемент
	SearchTree<S>* prev();												//объявляется метод Найти предыдущий элемент
	void preOrder(SearchTree<S>*);										//объявляется метод Вывести значения элементов (сверху вниз)
	void inOrder(SearchTree<S>*);										//объявляется метод Вывести значения элементов (слева направо)
	void postOrder(SearchTree<S>*);										//объявляется метод Вывести значения элементов (cниз вверх)
	void printTree(int);												//объявляется метод Вывести значения элементов (горизонтально)
	//void inOrder(SerachTree<S>*);										//объявляется метод Вывести значения элементов (слева направо)
	//void printSearchTree(int);											//объявляется метод Вывести значения элементов (горизонтально)
	void insertNode(S);													//объявляется метод Вставить элемент
	void deleteNode(S);													//объявляется метод Удалить элемент

	void setData(S dt)													//реализация метода Изменить значение элемента
	{
		data = dt;														//задаётся значение элемента
	}

	void deleteSearchTree()												//реализация метода Удалить дерево
	{
		delete this;													//удаляется элемент
	}
};

template <class S>														//реализация Конструктора с параметрами
SearchTree<S>::SearchTree(S dt)
{
	data = dt;															//задаётся значение элемента
	left = NULL;														//задаётся значение элемента слева
	right = NULL;														//задаётся значение элемента справа
	parent = NULL;														//задаётся значение элемента предка
}

template <class S>														//реализация Деструктора
SearchTree<S>::~SearchTree()
{
	delete this->left;													//удаляется элемент слева
	delete this->right;													//удаляется элемент справа
}

template <class S>														//реализация метода Найти элемент
SearchTree<S>* SearchTree<S>::findElement(S dt)
{
	if ((this != NULL) || (dt == this->data))							//проверяется существование элемента и сравнивается с искомым элементом
	{
		return this;													//возвращается значение элемента
	}
	else
	{
		if (dt < this->data)											//проверяется значение элемента
		{
			return this->left->findElement(dt);							//переход к элементу слева
		}
		else
		{
			return this->right->findElement(dt);						//переход к элементу справа
		}
	}	
}

template <class S>														//реализация метода Найти наибольший элемент
SearchTree<S>* SearchTree<S>::findMax()
{
	if (this->right == NULL)											//проверяется существование элемента справа
	{
		return this;													//возвращается значение элемента
	}
	else
	{
		return this->right->findMax();									//переход к элементу справа
	}
}

template <class S>														//реализация метода Найти наименьший элемент
SearchTree<S>* SearchTree<S>::findMin()
{
	if (this->left == NULL)												//проверяется существование элемента слева
	{
		return this;													//возвращается значение элемента
	}
	else
	{
		return this->left->findMin();									//переход к элементу слева
	}
}

template <class S>														//реализация метода Найти следующий элемент
SearchTree<S>* SearchTree<S>::next()
{
	SearchTree<S>* tree = this;											//создаётся элемент равный текущему

	if (tree->right != NULL)											//проверяется существование элемента справа
	{
		return tree->right->findMin();									//возвращается значение наименшего элемента справа
	}
	else
	{
		SearchTree<S>* temp = tree->parent;								//создаётся временный элемент равный элементу предку

		while ((temp != NULL) && (tree == temp->right))					//проверяется существование элемента предка и текущий элемент сравнивается с элементом справа от предка
		{
			tree = temp;												//переход к элементу предку
			temp = temp->parent;										//переход к элементу предку
		}

		return temp;													//возвращается значение временного элемента
	}
}

template <class S>														//реализация метода Найти предыдущий элемент
SearchTree<S>* SearchTree<S>::prev()
{
	SearchTree<S>* tree = this;											//создаётся элемент равный текущему

	if (tree->left != NULL)												//проверяется существование элемента слева
	{
		return tree->left->findMax();									//возвращается значение наибольшего элемента слева
	}
	else
	{
		SearchTree<S>* temp = tree->parent;								//создаётся временный элемент равный элементу предку

		while ((temp != NULL) && (tree == temp->left))					//проверяется существование элемента предка и текущий элемент сравнивается с элементом справа от предка
		{
			tree = temp;												//переход к элементу предку
			temp = temp->parent;										//переход к элементу предку
		}

		return temp;													//возвращается значение временного элемента
	}
}

template <class S>														//реализация метода Вывести значения элементов (сверху вниз)
void SearchTree<S>::preOrder(SearchTree<S>* temp)
{
	if (temp != NULL)													//проверяется существование элемента
	{
		cout << temp->data << "   ";									//выводится значение элемента
		preOrder(temp->left);											//переход к элементу слева
		preOrder(temp->right);											//переход к элементу справа
	}
}

template <class S>														//реализация метода Вывести значения элементов (слева направо)
void SearchTree<S>::inOrder(SearchTree<S>* temp)
{
	if (temp != NULL)													//проверяется существование элемента
	{
		inOrder(temp->left);											//переход к элементу слева
		cout << temp->data << "   ";									//выводится значение элемента
		inOrder(temp->right);											//переход к элементу справа
	}
}

template <class S>														//реализация метода Вывести значения элементов (cниз вверх)
void SearchTree<S>::postOrder(SearchTree<S>* temp)
{
	if (temp != NULL)													//проверяется существование элемента
	{
		postOrder(temp->left);											//переход к элементу слева
		postOrder(temp->right);											//переход к элементу справа
		cout << temp->data << "   ";									//выводится значение элемента
	}
}

template <class S>														//реализация метода Вывести значения элементов (горизонтально)
void SearchTree<S>::printTree(int level)
{
	if (this != NULL)													//проверяется существование элемента
	{
		this->right->printTree(level + 1);								//переход к элементу справа

		for (int i = 1; i < level; i++)									//выводятся пробелы
		{
			cout << "  ";
		}

		cout << this->data << endl;										//выводится значение элемента
		this->left->printTree(level + 1);								//переход к элементу слева
	}
}

template <class S>														//реализация метода Вставить элемент
void SearchTree<S>::insertNode(S dt)
{
	SearchTree<S>* tree = this;											//создаётся элемент равный текущему

	while (tree != NULL)												//проверяется существование элемента
	{
		if (dt >= tree->data)											//проверяется значение элемента
		{
			if (tree->right != NULL)									//проверяется существование элемента справа
			{
				tree = tree->right;										//переход к элементу справа
			}
			else
			{
				SearchTree<S>* temp = new SearchTree<S>(dt);			//создаётся новый элемент

				temp->parent = tree;									//задаётся новому элементу значение элемента предка
				tree->right = temp;										//задаётся элементу значение элемента справа
				break;
			}
		}
		else if (dt < tree->data)										//проверяется значение элемента
		{
			if (tree->left != NULL)										//проверяется существование элемента слева
			{
				tree = tree->left;										//переход к элементу слева
			}
			else
			{
				SearchTree<S>* temp = new SearchTree<S>(dt);			//создаётся новый элемент

				temp->parent = tree;									//задаётся новому элементу значение элемента предка
				tree->left = temp;										//задаётся элементу значение элемента слева
				break;
			}
		}
	}
}

template <class S>														//реализация метода Удалить элемент
void SearchTree<S>::deleteNode(S dt)
{
	SearchTree<S>* temp1 = this->findElement(dt);						//создаётся новый элемент равный удаляемому элементу
	SearchTree<S>* temp2 = temp1->parent;								//создаётся новый элемент равный предку удаляемого элемента

	//ЕСЛИ У УДАЛЯЕМОГО ЭЛЕМЕНТА НЕТ ПОТОМКОВ

	if ((temp1->left == NULL) && (temp1->right == NULL))				//проверяется существование элементов слева и справа от удаляемого
	{
		if (temp2->left == temp1)										//проверяется какой из элементов удаляется у предка
		{
			temp2->left = NULL;											//задаётся нулевое значение элемента слева у предка
		}

		if (temp2->right == temp1)										//проверяется какой из элементов удаляется у предка
		{
			temp2->right = NULL;										//задаётся нулевое значение элемента справа у предка
		}
	}

	//ЕСЛИ У УДАЛЯЕМОГО ЭЛЕМЕНТА ОДИН ПОТОМОК

	else if ((temp1->left == NULL) || (temp1->right == NULL))			//проверяется существование элементов слева или справа от удаляемого
	{
		if (temp1->left == NULL)										//проверяется существование элемента слева от удаляемого
		{
			if (temp2->right == temp1)									//проверяется какой из элементов удаляется у предка
			{
				temp2->left = temp1->right;								//задаётся значение элемента слева у предка удаляемого элемента
			}
			else
			{
				temp2->right = temp1->right;							//задаётся значение элемента справа у предка удаляемого элемента
			}

			temp1->right->parent = temp2;								//задаётся значение элемента предка у элемента справа от удаляемого
		}
		else
		{
			if (temp2->left == temp1)									//проверяется какой из элементов удаляется у предка
			{
				temp2->left = temp1->left;								//задаётся значение элемента слева у предка удаляемого элемента
			}
			else
			{
				temp2->right = temp1->left;								//задаётся значение элемента справа у предка удаляемого элемента
			}

			temp1->left->parent = temp2;
		}
	}

	//ЕСЛИ У УДАЛЯЕМОГО ЭЛЕМЕНТА ДВА ПОТОМКА

	else
	{
		SearchTree<S>* temp3 = temp1->next();							//создаётся новый элемент равный следующему элементу после удаляемого

		temp1->data = temp3->data;										//задаётся значение эдаляемого элемента равное следующему элементу
		
		if (temp3->parent->left == temp3)								//проверяется какой из элементов удаляется у предка
		{
			temp3->parent->left = temp3->right;							//задаётся значение элемента слева у предка удаляемого элемента

			if (temp3->right != NULL)									//проверяется существование элемента справа от удаляемого
			{
				temp3->right->parent = temp3->parent;					//задаётся значение предка у элемента справа от удаляемого
			}
		}
		else
		{
			temp3->parent->right = temp3->right;						//задаётся значение элемента справа у предка удаляемого элемента

			if (temp3->right != NULL)									//проверяется существование элемента справа от удаляемого
			{
				temp3->right->parent = temp3->parent;					//задаётся значение предка у элемента справа от удаляемого
			}
		}
	}
}