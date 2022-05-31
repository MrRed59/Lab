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
		T data; // Данные типа Т
		Tree* left; // Указатель на узел слева
		Tree* right; // Указатель на узел справа
		Tree* parent; // Указатель на предка
public:

		//-------------Constructors-------------//

		Tree(T); // Конструктор
		~Tree(); // Деструктор

		//-------------Getters-------------//

		T getData() { return data; }; // Получить данные с узла	
		int getAmountOfNodes(); // Получить количество элементов дерева
		int getHeight(); //Получить высоту дерева (считает с текущего узла по направлению к листьям)
		Tree<T>* getLeft() { return left; } // Получить левый узел
		Tree<T>* getRight() { return right; } // Получить правый узел
		Tree<T>* getParent() { return parent; } // Получить родителя
		int getLevel(Tree* tree);

		//-------------Setters-------------//

		void setData(T& dt) { data = dt; } // Установить данные для узла

		//-------------Delete-------------//

		void deleteLeft(); // Удалить поддерево слева
		void deleteRight(); // Удалить поддерево справа
		void deleteTree() { delete this; } // Удалить дерево

		//-------------Overloaded functions-------------//

		void insertLeft(T); // Вставить узел слева
		void insertRight(T); // Вставить узел справа		
		void addLeftTree(Tree<T>* tree) { left = tree; } // Добавить поддерево слева		
		void addRightTree(Tree<T>* tree) { right = tree; } // Добавить поддерево справа
		Tree<T>* ejectLeft(); // Извлечь поддерево слева
		Tree<T>* ejectRight(); // Извлечь поддерево справа
		static void preOrder(Tree<T>*); //Пройти дерево с печатью элементов	в прямом порядке(сверху вниз)
		static void inOrder(Tree<T>*); //Пройти дерево с печатью элементов в симметричном порядке(слева направо)
		static void postOrder(Tree<T>*); //Пройти дерево с печатью элементов в обратном порядке(снизу вверх)
		Tree<T>* copyTree(); // Скопировать дерево
		void obh(Tree<T>* node); //Прохождение по дереву и запись в файл
		void levelScan(); //Проходить по каждому уровню дерева начиная с корня и вывести элементы
		Tree<T>* replaceNULLforEmpty(); //Если дерево неполное, сделать его полным (недостающие узлы приобретут данные NULL)
		Tree<T>* replace_help(Tree* node, int h);
		void findElement_insertLeft(Tree<T>*, T, T); //Найти элемент и добавить к нему слева узел
		void findElement_insertRight(Tree<T>*, T, T); //Найти элемент и добавить к нему справа узел
		static Tree<T>* balancedTree(int n); //Построить идеально сбалансированное дерево по данному количеству элементов

		//-------------Print-------------//

		void printTree(int); // Печать дерева горизонтально
		void printVTree(int); // Печать дерева вертикально
		void printVTree2(); // Печать дерева вертикально (2)

};

//template <class T>
//int getLevel(Tree<T>* tree);

template<class T>
Tree<T>::Tree(T dt)/* :data(dt), left(nullptr), right(nullptr), parent(nullptr)*/ // Конструктор узла
{
	data = dt; // Присвоим данные по аргументу
	left = NULL; // Обнулим все указатели
	right = NULL;
	parent = NULL;
}

template<class T>
Tree<T>::~Tree() // Деструктор дерева
{
	delete this->left;
	delete this->right;
}

template <class T>
void Tree<T>::insertLeft(T dt) //вставка узла слева
{
	Tree<T>* node = new Tree(dt);
	if (this->left != nullptr)
		this->left->parent = node;// Сделать так, чтобы его предком был новый узел
	node->left = this->left; //Теперь у нового узла левый потомок – это левый потомок вызывающего узла
	this->left = node; //А вызывающий узел теперь имеет	левого потомка – это новый узел
	node->parent = this; //Указываем, что у нового узла теперь предком является текущий узел
}

template<class T>
void Tree<T>::insertRight(T dt) //вставка узла справа
{
	Tree<T>* node = new Tree(dt);
	if (this->right != nullptr)
		this->right->parent = node;
	node->right = this->right;
	this->right = node;
	node->parent = this;
}

template<class T>
void Tree<T>::preOrder(Tree<T>* node) // ПРЯМОЙ ОБХОД (СВЕРХУ ВНИЗ)
{
	if (node != NULL)
	{
		std::cout << node->getData() << "";
		reorder(node->left);
		reorder(node->right);
	}
}

template<class T>
void Tree<T>::inOrder(Tree<T>* node) // СИММЕТРИЧНЫЙ ОБХОД (СЛЕВА НАПРАВО)
{
	if (node != NULL)
	{
		inOrder(node->left);
		std::cout << node->getData() << "";
		inOrder(node->right);
	}
}

template<class T>
void Tree<T>::postOrder(Tree<T>* node) // ОБРАТНЫЙ ОБХОД (СНИЗУ ВВЕРХ)
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
Tree<T>* Tree<T>::ejectLeft() // Извлечение
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
void Tree<T>::deleteLeft() // Удаление
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
	int height = this->getHeight(); //Максимальное число листов на нижнем уровне(нумерация с нуля)
	int maxLeafs = pow(2, height - 1); //Минимальная ширина дерева для печати	(не конечная, но необходимая)
	int width = 2 * maxLeafs - 1;
	int curLevel = 0; // Номер строки (на выводе)
	int index = 0; // Номер элемента в строке (нумерация с нуля)
	int factSpaces = getPos(index, width, curLevel, height - 1); //Позиция корня (число пробелов перед ним)
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

template <class T>
void Tree<T>::obh(Tree<T>* node) //Построчный обход дерева и запись элементов в файл
{
	std::ofstream f("print.txt");
	int amount = node->getAmountOfNodes(); //Кол-во элементов в дереве
	std::queue<Tree<T>*> q; // Очередь указателей
	q.push(node);
	while (!q.empty()) // Для начала поместим в очередь корень
	{
		Tree<T>* temp = q.front();
		q.pop();
		f << temp->data << std::endl;
		if (temp->left) //Если есть левый наследник, то помещаем его в очередь для дальнейшей обработки
			q.push(temp->left);
		if (temp->right) //Если есть правый наследник, то помещаем его в очередь для дальнейшей обработки
			q.push(temp->right);
	}
	f.close();
}

template <class T>
void Tree<T>::printVTree2()
{
	obh(this); // Обход дерева и заполнение файла
	std::ifstream f("print.txt");
	int amount = 0; // Кол-во элементов в дереве
	while (!f.eof())
	{
		char str[255];
		f.getline(str, 255);
		amount++;
	}
	f.close();
	amount--; // Кол-во элементов в дереве
	std::ifstream f1("print.txt");
	int* mas = new int[amount];
	for (int i = 0; i < amount; i++)
	{
		char str[255];// Считывание элементов в массив
		f1.getline(str, 255);
		mas[i] = atoi(str);
	}
	f1.close();
	int height = this->getHeight();
	int count = 0; // Счетчик для вывода
	int* spaces = new int[height]; // Массив нужных пробелов	
	spaces[0] = 0; // При глубине 1 будет 0 пробелов
	for (int i = 1; i < height; i++)
		spaces[i] = spaces[i - 1] * 2 + 1; // Вычисление пробелов
	int amount_p = 0; // Кол-во напечатанных элементов
	if (height == 1)
	{
		std::cout << mas[0] << std::endl;
	}
	else
	{
		/* l – индекс для вывода пробелов |	вывод всех строк, кроме последней */
		for (int i = 0, l = height - 1; i < height - 1; i++,
			l--)
		{
			for (int j = 0, k = 0; j < pow(2, i); j++, k++)
			{
				if (k == 0) // Вывод первого числа в строке
					for (int u = 0; u < spaces[l]; u++) // Печатаем пробелы
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
		int* last_str = new int[pow(2, height - 1)]; // Будет храниться последняя строка
		for (int i = 0; i < pow(2, height - 1); i++)
			last_str[i] = 2000000000; // amount – это amount_p (кол-во оставшихся элементов)
		int sch1 = 0;  // счетчик для последнего массива
		int sch2 = spaces[height - 2] + 1; //Второй счетчик для последнего массива
		for (int i = amount_p; i < amount; i += 2) // Строим массив так, как встают элементы в дереве
		{
			if (i <= amount - 1) //если еще есть элементы
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
			{ //Заполняем вторую половину массива
				sch1 = 1;
				sch2 = spaces[height - 2] + 2;
			}
		}
		for (int i = 0; i < pow(2, height - 1); i++) // Исправляем неправильное построение массива
			if (last_str[i] != 2000000000)
				last_str[i] = mas[amount_p++];
		for (int i = 0; i < pow(2, height - 1); i++) //Печатаем последнюю строку
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
