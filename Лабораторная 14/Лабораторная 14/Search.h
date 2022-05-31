#pragma once

template <class S>
class SearchTree
{
	S data; // Данные типа Т
	SearchTree* left; // Указатель на узел слева
	SearchTree* right; // Указатель на узел справа
	SearchTree* parent; // Указатель на предка
public:
	//-------------Constructors-------------//

	SearchTree(S); // Конструктор
	~SearchTree(); // Деструктор

	//

	void deleteSearchTree() { delete this; } // Удалить дерево	
	void printSearchTree(int); // Горизонтальная печать дерева	
	void inOrder(SearchTree<S>*); // Симметричный обход дерева	
	void preOrder(SearchTree<S>*);										//Вывести значения элементов (сверху вниз)
	void postOrder(SearchTree<S>*);										//Вывести значения элементов (cниз вверх)
	void printTree(int);												//Вывести значения элементов (горизонтально)
	void setData(S dt) { data = dt; } // Установить данные для узла	
	SearchTree<S>* next(); // Найти следующий элемент
	SearchTree<S>* prev(); // Найти предыдущий элемент
	void insertNode(S); // Вставить узел
	void deleteNode(S); // Удалить узел
	SearchTree<S>* findElement(S); // Найти элемент
	SearchTree<S>* findMax(); // Найти максимум
	SearchTree<S>* findMin(); // Найти минимум
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

template<class S>
void SearchTree<S>::deleteNode(S dt)
{
	SearchTree<S>* e = this->findElement(dt);
	SearchTree<S>* p = e->parent; //предок удаляемого элемента

	if ((e->left == nullptr) && (e->right == nullptr)) // Первый случай: удаляемый элемент не имеет потомков
	{
		if (p->left == e) p->left = nullptr;
		if (p->right == e) p->right = nullptr;
	}

	else if ((e->left == NULL) || (e->right == NULL)) // Второй случай: удаляемый элемент имеет одного потомка
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

	// Третий случай: удаляемый элемент имеет двух потомков
	else
	{
		SearchTree<S>* s = e->next();
		// Следующий элемент за удаляемым
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

template <class S>														//реализация метода Вывести значения элементов (горизонтально)
void SearchTree<S>::printSearchTree(int level)
{
	if (this != NULL)													//проверяется существование элемента
	{
		this->right->printSearchTree(level + 1);						//переход к элементу справа

		for (int i = 1; i < level; i++)									//выводятся пробелы
		{
			std::cout << "  ";
		}

		std::cout << this->data << std::endl;										//выводится значение элемента
		this->left->printSearchTree(level + 1);								//переход к элементу слева
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
		std::cout << temp->data << "   ";									//выводится значение элемента
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