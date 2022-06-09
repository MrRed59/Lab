#pragma once
#include<vector>


class SearchTree
{
	char		data;											// Данные типа Т
	SearchTree* left;											// Указатель на узел слева
	SearchTree* right;											// Указатель на узел справа
	SearchTree* parent;											// Указатель на предка

public:

	int node_x;
	int node_y;
	int text_x;
	int text_y;

	// Установить координаты для данного узла при рисовании

	void drawTree(int, char**, int, int, int, int); //рисовать дерево

	//-------------Constructors-------------//

	SearchTree(char);												// Конструктор
	~SearchTree();												// Деструктор
	SearchTree(const SearchTree&);							// Конструктор копирования

	//

	int				getHeight();								// Получить высоту дерева (считает с текущего узла по направлению к листьям)
	char			getData()				{ return data; };	// Получить данные с узла	
	int				getAmountOfNodes();							// Получить количество элементов дерева
	SearchTree*		getLeft()				{ return left; }	// Получить левый узел
	SearchTree*		getRight()				{ return right; }	// Получить правый узел
	SearchTree*		getParent()				{ return parent; }	// Получить родителя
	int				getLevel				(SearchTree* tree);
	SearchTree*		getNodeByCoords			(int x, int y, int R);

	void			setCoordsForNode(	int window_width, int window_height, 
										int shift, int tree_width, int tree_height, 
										int x, int y, int R);
	void			setCoordsForText(int k, int shift);			// Установить координаты для текста текущего узла при рисовании


	SearchTree* copyTree();									// Скопировать дерево
	SearchTree* replaceNULLforEmpty();						// Если дерево неполное, сделать его полным (недостающие узлы приобретут данные NULL)
	SearchTree* replace_help(SearchTree* node, int h);

	void insertLeft(char);											// Вставить узел слева
	void insertRight(char);										// Вставить узел справа		
	void addLeftTree(SearchTree* tree) { left = tree; }		// Добавить поддерево слева		
	void addRightTree(SearchTree* tree) { right = tree; }	// Добавить поддерево справа

	void deleteSearchTree() { delete this; }					// Удалить дерево	
	void deleteNode(char);											// Удалить узел
	void deleteLeft();											// Удалить поддерево слева
	void deleteRight();											// Удалить поддерево справа
	SearchTree* ejectLeft();									// Извлечь поддерево слева
	SearchTree* ejectRight();								// Извлечь поддерево справа

	void printSearchTree(int);									// Горизонтальная печать дерева	
	void inOrder(SearchTree*);								// Симметричный обход дерева	
	void preOrder(SearchTree*);								// Вывести значения элементов (сверху вниз)
	void postOrder(SearchTree*);								// Вывести значения элементов (cниз вверх)
	void printTree(int);										// Вывести значения элементов (горизонтально)
	void printVTree(int);										// Печать дерева вертикально
	void setData(char dt) { data = dt; }							// Установить данные для узла	
	SearchTree* next();										// Найти следующий элемент
	SearchTree* prev();										// Найти предыдущий элемент
	void insertNode(char);											// Вставить узел
	SearchTree* findElement(char);								// Найти элемент
	SearchTree* findMax();									// Найти максимум
	SearchTree* findMin();									// Найти минимум
	size_t number_by_symbol(const char&);
	static SearchTree* balancedTree(int n);					// Построить идеально сбалансированное дерево поиска по данному количеству элементов
	void findElement_insertLeft(SearchTree*, char, char);			// Найти элемент и добавить к нему слева узел
	void findElement_insertRight(SearchTree*, char, char);			// Найти элемент и добавить к нему справа узел
	void add(char dt);												// Добавить элемент в дерево
	std::vector<char> copy_to_vector();							// Копировать дерево в вектор
	SearchTree* ideal_to_search( std::vector<char>, int, int);		// Преобразовать идельно сбалансированное дерево в дерево поиска
};