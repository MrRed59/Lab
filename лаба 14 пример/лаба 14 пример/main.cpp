#include "tree.h"
#include "search.h"
#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

Tree<char>* create_test_tree()													//реализация функции СОЗДАТЬ БИНАРНОЕ ДЕРЕВО
{
	Tree<char>* tree = new Tree<char>('A');										//создаётся первый Элемент дерева

	tree->insertLeft('B');														//добавляется Элемент слева
	tree->getLeft()->insertLeft('D');											//переход к Элементу слева, добавляется Элемент слева
	tree->getLeft()->getLeft()->insertLeft('G');								//переход к Элементу слева, переход к Элементу слева, добавляется Элемент слева
	tree->getLeft()->insertRight('E');											//переход к Элементу слева,добавляется Элемент справа
	tree->getLeft()->getLeft()->insertRight('H');								//переход к Элементу слева, переход к элементу слева, добавляется Элемент справа
	tree->insertRight('C');														//добавляется Элемент справа
	tree->getRight()->insertRight('F');											//переход к Элементу справа и добавляется Элемент справа
	tree->getRight()->getRight()->insertLeft('I');								//переход к Элементу справа, переход к Элементу справа, добавляется Элемент слева
	tree->getRight()->getRight()->insertRight('J');								//переход к Элементу справа, переход к Элементу справа, добавляется Элемент справа

	return tree;																//возвращается полученное дерево
}

Tree<char>* create_ideal_tree()													//реализация функции СОЗДАТЬ ИДЕАЛЬНО СБАЛАНСИРОВАННОЕ ДЕРЕВО
{
	int n;																		//объявляется переменная Количество элементов

	cout << "Введите количество Элементов:  ";
	cin >> n;																	//вводится значение Количество элементов
	cout << endl;

	Tree<char>* tree = Tree<char>::balancedTree(n);								//создаётся идеально сбалансированное дерево

	cout << endl;

	return tree;																//возвращается полученное дерево
}

Tree<char>* create_array_tree()													//описание функции СОЗДАТЬ БИНАРНОЕ ДЕРЕВО ИЗ МАССИВА
{
	vector<char> arr = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };	//создаётся контейнер значений элементов дерева

	Tree<char>* tree = new Tree<char>(arr.at(0));								//создаётся первый элемент дерева

	for (int i = 0; i < arr.size(); i++)										//перебираются элементы контейнера
	{
		int left = 2 * i + 1;													//задаётся номер элемента слева от текущего равным 2n+1
		int right = left + 1;													//задаётся номер элемента справа от текущего равным 2n+2

		if (left < arr.size())													//проверяется не выходит ли элемент с номером left за границы контейнера
		{
			tree->findElement_insertLeft(tree, arr.at(i), arr.at(left));		//добавляется элемент с номером left слева от текущего
		}

		if (right < arr.size())													//проверяется не выходит элемент с номером right за границы контейнера
		{
			tree->findElement_insertRight(tree, arr.at(i), arr.at(right));		//добавляется элемент с номером right справа от текущего
		}
	}

	return tree;																//возвращается полученное дерево
}

SearchTree<char>* create_array_search_tree()									//реализация функции СОЗДАТЬ ДЕРЕВО ПОИСКА ИЗ МАССИВА
{
	vector<char> arr = { 'A', 'B', 'D', 'G', 'E', 'H', 'C', 'F', 'I', 'J' };	//создаётся контейнер значений элементов дерева

	SearchTree<char>* tree = new SearchTree<char>(arr.at(0));					//создаётся первый элемент дерева

	for (int i = 1; i < arr.size(); i++)										//перебираются элементы контейнера
	{
		tree->insertNode(arr.at(i));											//добавляется элемент с текущим номером в дерево
	}

	return tree;																//возвращается полученное дерево
}

void show_tree(Tree<char>* tree)												//реализация функции ПОКАЗАТЬ БИНАРНОЕ ДЕРЕВО
{
	cout << "Прямой обход:         ";
	tree->preOrder(tree);														//выполняется метод Вывод значений элементов (сверху вниз)
	cout << endl << endl;

	cout << "Симметричный обход:   ";
	tree->inOrder(tree);														//выполняется метод Вывод значений элементов (слева направо)
	cout << endl << endl;

	cout << "Обратный обход:       ";
	tree->postOrder(tree);														//выполняется метод Вывод значений элементов (cниз вверх)
	cout << endl << endl;

	cout << "Симметричный обход 2: " << endl;
	tree->printTree(12);														//выполняется метод Вывод значений элементов (слева направо)
	cout << endl;

	cout << "Поперечный обход:     ";
	tree->levelscan();
	cout << endl;
}

void show_search_tree(SearchTree<char>* tree)									//реализация функции ПОКАЗАТЬ ДЕРЕВО ПОИСКА
{
	cout << "Прямой обход:         ";
	tree->preOrder(tree);														//выполняется метод Вывод значений элементов (сверху вниз)
	cout << endl << endl;

	cout << "Симметричный обход:   ";
	tree->inOrder(tree);														//выполняется метод Вывод значений элементов (слева направо)
	cout << endl << endl;

	cout << "Обратный обход:       ";
	tree->postOrder(tree);														//выполняется метод Вывод значений элементов (cниз вверх)
	cout << endl << endl;

	cout << "Симметричный обход 2: " << endl;
	tree->printTree(12);														//выполняется метод Вывод значений элементов (слева направо)
	cout << endl;
}

Tree<char>* eject_left_tree(Tree<char>* tree)								//ОПИСАНИЕ ФУНКЦИИ "ИЗВЛЕЧЬ ПОДДЕРЕВО СЛЕВА"
{
	Tree<char>* temp = tree->ejectLeft();
	return temp;
}

Tree<char>* eject_right_tree(Tree<char>* tree)								//ОПИСАНИЕ ФУНКЦИИ "ИЗВЛЕЧЬ ПОДДЕРЕВО СПРАВА"
{
	Tree<char>* temp = tree->ejectRight();
	return temp;
}

Tree<char>* delete_left_tree(Tree<char>* tree)								//ОПИСАНИЕ ФУНКЦИИ "удалить ПОДДЕРЕВО слева"
{
	tree->deleteLeft();														//выполняется метод
	return tree;
}

Tree<char>* delete_right_tree(Tree<char>* tree)								//ОПИСАНИЕ ФУНКЦИИ "удалить ПОДДЕРЕВО СПРАВА"
{
	tree->deleteRight();
	return tree;
}

Tree<char>* add_elem(Tree<char>* tree)
{
	char dt1, dt2;
	char lr;

	cout << "Введите значение элемента, после которого нужно добавить новый элемент:  ";
	cin >> dt1;
	cout << endl << "Введите значение нового элемента:  ";
	cin >> dt2;
	cout << endl << "Добавить элемент слева [L] или справа [R]?  ";
	cin >> lr;
	cout << endl;

	switch (lr)
	{
	case 'L':
		tree->findElement_insertLeft(tree, dt1, dt2);
		break;
	case 'l':
		tree->findElement_insertLeft(tree, dt1, dt2);
		break;
	case 'R':
		tree->findElement_insertRight(tree, dt1, dt2);
		break;
	case 'r':
		tree->findElement_insertRight(tree, dt1, dt2);
		break;
	default:
		cout << "Ошибка ввода." << endl << endl;
		break;
	}

	return tree;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int num = 99;															//объявляется переменная номер меню
	Tree<char>* tree = new Tree<char> ('X');								//объявляется объект Элемент
	SearchTree<char>* s_tree = new SearchTree<char> ('X');					//объявляется объект Элемент

	while (num != 0)
	{
		cout << "Программа работает." << endl << endl << endl;

		cout << "МЕНЮ ПРОГРАММЫ:" << endl << endl;							//меню программы
		cout << "1.  Создать бинарное дерево (тестовое)." << endl;
		cout << "2.  Создать идеально сбалансированное дерево." << endl;
		cout << "3.  Создать бинарное дерево (из массива)." << endl;
		cout << "4.  Создать дерево поиска (из массива)." << endl;
		cout << "5.  Добавить новый элемент." << endl;
		cout << "6.  Извлечь поддерево слева." << endl;
		cout << "7.  Извлечь поддерево справа." << endl;
		cout << "8.  Удалить поддерево слева." << endl;
		cout << "9.  Удалить поддерево справа." << endl;
		cout << "10. Показать количество элементов в дереве." << endl;
		cout << "11. Показать высоту дерева." << endl;
		cout << "12. Показать бинарное дерево." << endl;
		cout << "13. Показать дерево поиска." << endl;

		cout << "0.  Завершение работы." << endl << endl;

		cout << "Выберите пункт меню:  ";
		cin >> num;															//вводится номер операции
		cout << endl;

		switch (num)
		{
		case 1:																//выполняется алгоритм 1
			tree = create_test_tree();										//выполняется функция СОЗДАТЬ БИНАРНОЕ ДЕРЕВО
			break;
		case 2:																//выполняется алгоритм 2
			tree = create_ideal_tree();										//выполняется функция СОЗДАТЬ ИДЕАЛЬНО СБАЛАНСИРОВАННОЕ ДЕРЕВО
			break;
		case 3:																//выполняется алгоритм 3
			tree = create_array_tree();										//выполняется функция СОЗДАТЬ БИНАРНОЕ ДЕРЕВО ИЗ МАССИВА
			break;
		case 4:																//выполняется аогоритм 4
			s_tree = create_array_search_tree();							//выполняется функция СОЗДАТЬ ДЕРЕВО ПОИСКА ИЗ МАССИВА
			break;
		case 5:
			tree = add_elem(tree);
			break;
		case 6:																//выполняется алгоритм "ИЗВЛЕЧЬ ПОДДЕРЕВО СЛЕВА"
			tree = eject_left_tree(tree);									//выполняется функция "ИЗВЛЕЧЬ ПОДДЕРЕВО СЛЕВА"
			break;
		case 7:																//выполняется алгоритм "ИЗВЛЕЧЬ ПОДДЕРЕВО СПРАВА"
			tree = eject_right_tree(tree);									//выполняется функция "ИЗВЛЕЧЬ ПОДДЕРЕВО СПРАВА"
			break;
		case 8:																//выполняется алгоритм "УДАЛИТЬ ПОДДЕРЕВО СЛЕВА"
			tree = delete_left_tree(tree);									//выполняется функция "УДАЛИТЬ ПОДДЕРЕВО СЛЕВА"
			break;
		case 9:																//выполняется алгоритм "УДАЛИТЬ ПОДДЕРЕВО СПРАВА"
			tree = delete_right_tree(tree);									//выполняется функция "УДАЛИТЬ ПОДДЕРЕВО СПРАВА"
			break;
		case 10:															//выполняется алгоритм 10
			cout << "Количество элементов в дереве:  " << tree->getAmountOfNodes() << endl << endl;
			break;
		case 11:															//выполняется алгоритм 11
			cout << "Количество элементов в дереве:  " << tree->getHeight() << endl << endl;
			break;
		case 12:															//выполняется алгоритм 12
			show_tree(tree);												//выполняется функция ПОКАЗАТЬ БИНАРНОЕ ДЕРЕВО
			break;
		case 13:															//выполняется алгоритм 13
			show_search_tree(s_tree);										//выполняется функция ПОКАЗАТЬ ДЕРЕВО ПОИСКА
			break;
		}

		system("pause");
		system("cls");
	}
}