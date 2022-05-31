#include<iostream>
#include"Search.h"
#include<vector>
#include"Tree.h"
#include<conio.h>

short Checking_For_Valid_Input()
{
	short value;
	do
	{
		if (!std::cin)
		{
			std::cout << "Syntax error" << std::endl;
			std::cin.clear();
			std::cin.ignore(1024, '\n');
		}
		std::cin >> value;
	} while (!std::cin);
	return value;
}

char Checking_For_Valid_Input_Char()
{
	char symbol;
	do
	{
		if (!std::cin)
		{
			std::cout << "Syntax error" << std::endl;
			std::cin.clear();
			std::cin.ignore(1024, '\n');
		}
		std::cin >> symbol;
	} while (!std::cin);
	return symbol;
}

//------functions-for-tree------

Tree<char>* create_tree()
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

	return tree;
}

Tree<char>* create_ideal_tree()													//реализация функции СОЗДАТЬ ИДЕАЛЬНО СБАЛАНСИРОВАННОЕ ДЕРЕВО
{
	int n;																		//объявляется переменная Количество элементов

	std::cout << "Введите количество Элементов:  ";
	std::cin >> n;																	//вводится значение Количество элементов
	std::cout << std::endl;

	Tree<char>* tree = Tree<char>::balancedTree(n);								//создаётся идеально сбалансированное дерево

	std::cout << std::endl;

	return tree;
}

Tree<char>* create_array_tree()													//описание функции СОЗДАТЬ БИНАРНОЕ ДЕРЕВО ИЗ МАССИВА
{
	std::vector<char> arr = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };	//создаётся контейнер значений элементов дерева

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

SearchTree<char>* create_array_search_tree()									//СОЗДАТЬ ДЕРЕВО ПОИСКА ИЗ МАССИВА
{
	std::vector<char> arr = { 'A', 'B', 'D', 'G', 'E', 'H', 'C', 'F', 'I', 'J' };	//создаётся контейнер значений элементов дерева

	SearchTree<char>* tree = new SearchTree<char>(arr.at(0));					//создаётся первый элемент дерева

	for (int i = 1; i < arr.size(); i++)										//перебираются элементы контейнера
	{
		tree->insertNode(arr.at(i));											//добавляется элемент с текущим номером в дерево
	}

	return tree;																
}

void show_tree(Tree<char>* tree)												//ПОКАЗАТЬ БИНАРНОЕ ДЕРЕВО
{
	std::cout << "Прямой обход:         ";
	tree->preOrder(tree);														//Вывод значений элементов (сверху вниз)
	std::cout << std::endl << std::endl;

	std::cout << "Симметричный обход:   ";
	tree->inOrder(tree);														//Вывод значений элементов (слева направо)
	std::cout << std::endl << std::endl;

	std::cout << "Обратный обход:       ";
	tree->postOrder(tree);														//Вывод значений элементов (cниз вверх)
	std::cout << std::endl << std::endl;

	std::cout << "Симметричный обход 2: " << std::endl;
	tree->printTree(12);														//Вывод значений элементов (слева направо)
	std::cout << std::endl;

	std::cout << "Поперечный обход:     ";
	tree->levelScan();
	std::cout << std::endl;
}

void show_tree(SearchTree<char>* tree)											//ПОКАЗАТЬ ДЕРЕВО ПОИСКА
{
	std::cout << "Прямой обход:         ";
	tree->preOrder(tree);														//Вывод значений элементов (сверху вниз)
	std::cout << std::endl << std::endl;

	std::cout << "Симметричный обход:   ";
	tree->inOrder(tree);														//Вывод значений элементов (слева направо)
	std::cout << std::endl << std::endl;

	std::cout << "Обратный обход:       ";
	tree->postOrder(tree);														//Вывод значений элементов (cниз вверх)
	std::cout << std::endl << std::endl;

	std::cout << "Симметричный обход 2: " << std::endl;
	tree->printTree(12);														//Вывод значений элементов (слева направо)
	std::cout << std::endl;
}

void add(Tree<char>* tree)
{
	char post_elem{};
	char new_elem{};
	char choise{};

	std::cout << "Введите значение элемента, после которого нужно добавить новый элемент:  ";
	std::cin >> post_elem;
	std::cout << std::endl << "Введите значение нового элемента:  ";
	std::cin >> new_elem;
	std::cout << std::endl << "Добавить элемент слева [L] или справа [R]?  ";
	std::cin >> choise;
	std::cout << std::endl;

	switch (choise)
	{
	case 'L':
	case 'l':
		tree->findElement_insertLeft(tree, post_elem, new_elem);
		break;
	case 'R':
	case 'r':
		tree->findElement_insertRight(tree, post_elem, new_elem);
		break;
	default:
		std::cout << "Ошибка ввода." << std::endl << std::endl;
		break;
	}

	//return tree;
}


//------main-menu------
void Selection()
{
	Tree<char>* tree = new Tree<char>('X');								//объявляется объект Элемент
	SearchTree<char>* seartch_tree = new SearchTree<char>('X');					//объявляется объект Элемент

	while (true)
	{
		std::cout << "Выберите нужный пункт меню:" << std::endl;
		std::cout << "1. Создать бинарное дерево (символы)." << std::endl;
		std::cout << "2. Создать идеально сбалансированное дерево." << std::endl;
		std::cout << "3. Создать бинарное дерево(массив)." << std::endl;
		std::cout << "4. Создать бинарное дерево поиска." << std::endl;
		std::cout << "5. Добавить новый элемент." << std::endl;
		std::cout << "6. Извлечь поддерево слева." << std::endl;
		std::cout << "7. Извлечь поддерево справа." << std::endl;
		std::cout << "8. Удалить поддерево слева." << std::endl;
		std::cout << "9. Удалить поддерево справа." << std::endl;
		std::cout << "10. Показать кол-во элементов в дереве." << std::endl;
		std::cout << "11. Показать высоту дерева." << std::endl;
		std::cout << "12. Печать дерева" << std::endl;
		std::cout << "13. Печать дерева поиска." << std::endl;
		std::cout << "0. Закрыть программу." << std::endl;

		switch (Checking_For_Valid_Input())
		{
		case 1:
			tree = create_tree();
			break;
		case 2:
			tree = create_ideal_tree();
			break;
		case 3:
			tree = create_array_tree();
			break;
		case 4:
			seartch_tree = create_array_search_tree();
			break;
		case 5:
			add(tree);
			break;
		case 6:

			break;
		case 7:

			break;
		case 8:

			break;
		case 9:

			break;
		case 10:

			break;
		case 11:

			break;
		case 12:
			show_tree(tree);
			break;
		case 13:
			show_tree(seartch_tree);
			break;
		case 0:

			break;

		default:
			std::cout << "Ошибка. Неверный пункт меню." << std::endl;
			break;
		}
	}
}