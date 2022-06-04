#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include<queue>
#include"draw.h"

template <class S>
class SearchTree
{
	S data; // Данные типа Т
	SearchTree* left;							// Указатель на узел слева
	SearchTree* right;							// Указатель на узел справа
	SearchTree* parent;							// Указатель на предка
public:
	//-------------Constructors-------------//

	SearchTree(S);								// Конструктор
	~SearchTree();								// Деструктор

	//

	int getHeight(); //Получить высоту дерева (считает с текущего узла по направлению к листьям)
	S getData() { return data; }; // Получить данные с узла	
	int getAmountOfNodes(); // Получить количество элементов дерева
	SearchTree<S>* getLeft() { return left; } // Получить левый узел
	SearchTree<S>* getRight() { return right; } // Получить правый узел
	SearchTree<S>* getParent() { return parent; } // Получить родителя
	int getLevel(SearchTree* tree);

	SearchTree<S>* copyTree(); // Скопировать дерево
	SearchTree<S>* replaceNULLforEmpty(); //Если дерево неполное, сделать его полным (недостающие узлы приобретут данные NULL)
	SearchTree<S>* replace_help(SearchTree* node, int h);

	void insertLeft(S); // Вставить узел слева
	void insertRight(S); // Вставить узел справа		
	void addLeftTree(SearchTree<S>* tree) { left = tree; } // Добавить поддерево слева		
	void addRightTree(SearchTree<S>* tree) { right = tree; } // Добавить поддерево справа


	void deleteSearchTree() { delete this; }	// Удалить дерево	
	void printSearchTree(int);					// Горизонтальная печать дерева	
	void inOrder(SearchTree<S>*);				// Симметричный обход дерева	
	void preOrder(SearchTree<S>*);				//Вывести значения элементов (сверху вниз)
	void postOrder(SearchTree<S>*);				//Вывести значения элементов (cниз вверх)
	void printTree(int);						//Вывести значения элементов (горизонтально)
	void printVTree(int);						// Печать дерева вертикально
	void setData(S dt) { data = dt; }			// Установить данные для узла	
	SearchTree<S>* next();						// Найти следующий элемент
	SearchTree<S>* prev();						// Найти предыдущий элемент
	void insertNode(S);							// Вставить узел
	void deleteNode(S);							// Удалить узел
	SearchTree<S>* findElement(S);				// Найти элемент
	SearchTree<S>* findMax();					// Найти максимум
	SearchTree<S>* findMin();					// Найти минимум
	size_t number_by_symbol(const S&);
};

template <class S>
void SearchTree<S>::insertLeft(S dt) //вставка узла слева
{
	SearchTree<S>* node = new SearchTree(dt);
	if (this->left != nullptr)
		this->left->parent = node;// Сделать так, чтобы его предком был новый узел
	node->left = this->left; //Теперь у нового узла левый потомок – это левый потомок вызывающего узла
	this->left = node; //А вызывающий узел теперь имеет	левого потомка – это новый узел
	node->parent = this; //Указываем, что у нового узла теперь предком является текущий узел
}

template<class S>
void SearchTree<S>::insertRight(S dt) //вставка узла справа
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
		std::cout << temp->data << "   ";									//выводится значение элемента
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
		std::cout << temp->data << "   ";									//выводится значение элемента
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
			std::cout << "  ";
		}

		std::cout << this->data << std::endl;										//выводится значение элемента
		this->left->printTree(level + 1);								//переход к элементу слева
	}
}

template <class S>
void SearchTree<S>::printVTree(int k)
{
	int height = this->getHeight(); //Максимальное число листов на нижнем уровне(нумерация с нуля)
	int maxLeafs = pow(2, height - 1); //Минимальная ширина дерева для печати	(не конечная, но необходимая)
	int width = 2 * maxLeafs - 1;
	int curLevel = 0; // Номер строки (на выводе)
	int index = 0; // Номер элемента в строке (нумерация с нуля)
	int factSpaces = getPos(index, width, curLevel, height - 1); //Позиция корня (число пробелов перед ним)
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
	/* Редактируем позиции в строчках (теперь они обозначают количество пробелов перед данным символом начиная с предыдущего символа):
 до этого эти значения представляли собой координаты (как х) */
	for (int i = V.size() - 1; i >= 0; i--)
	{
		if (i != 0)
		{
			if (Vi.at(i - 1).str == Vi.at(i).str) Vi.at(i).col = Vi.at(i).col - Vi.at(i - 1).col - 1;
		}
	}
	int flag = 0; // Следит за тем, что y меняется
	for (int i = 0; i < V.size(); i++)
	{
		node = Vi.at(i);
		curLevel = node.str; //Переход на новую строчку будет, когда y1	станет меньше y (слежка за изменением y)
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