#include<iostream>
#include"Search.h"
#include<vector>
#include"Tree.h"
#include<conio.h>
#include"functions.h"

short Checking_For_Valid_Input()											//проверка ввода для типа данных short
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

char Checking_For_Valid_Input_Char()											//проверка ввода для типа данных char
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

Tree<char>* create_tree()														//создать дерево
{
	Tree<char>* tree = new Tree<char>('A');

	tree->insertLeft('B');														//добавить Элемент слева
	tree->getLeft()->insertLeft('D');											//перейти к Элементу слева, добавляется Элемент слева
	tree->getLeft()->getLeft()->insertLeft('G');								//перейти к Элементу слева, переход к Элементу слева, добавляется Элемент слева
	tree->getLeft()->insertRight('E');											//перейти к Элементу слева,добавляется Элемент справа
	tree->getLeft()->getLeft()->insertRight('H');								//перейти к Элементу слева, переход к элементу слева, добавляется Элемент справа
	tree->insertRight('C');														//добавить Элемент справа
	tree->getRight()->insertRight('F');											//перейти к Элементу справа и добавляется Элемент справа
	tree->getRight()->getRight()->insertLeft('I');								//перейти к Элементу справа, переход к Элементу справа, добавляется Элемент слева
	tree->getRight()->getRight()->insertRight('J');								//перейти к Элементу справа, переход к Элементу справа, добавляется Элемент справа

	return tree;
}

Tree<char>* create_ideal_tree()													//создать идеально сбалансированное дерево
{
	int n;

	std::cout << "Введите количество Элементов:  ";
	std::cin >> n;
	std::cout << std::endl;

	Tree<char>* tree = Tree<char>::balancedTree(n);

	std::cout << std::endl;

	return tree;
}

Tree<char>* create_array_tree()														//создать бинарное дерево из массива
{
	std::vector<char> arr = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };	//создать контейнер значений элементов дерева

	Tree<char>* tree = new Tree<char>(arr.at(0));									//создать первый элемент дерева

	for (int i = 0; i < arr.size(); i++)
	{
		int left = 2 * i + 1;														//задать номер элемента слева от текущего равным 2n+1
		int right = left + 1;														//задать номер элемента справа от текущего равным 2n+2

		if (left < arr.size())														//проверить не выходит ли элемент с номером left за границы контейнера
		{
			tree->findElement_insertLeft(tree, arr.at(i), arr.at(left));			//добавить элемент с номером left слева от текущего
		}

		if (right < arr.size())														//проверить не выходит элемент с номером right за границы контейнера
		{
			tree->findElement_insertRight(tree, arr.at(i), arr.at(right));			//добавить элемент с номером right справа от текущего
		}
	}

	return tree;
}

SearchTree<char>* create_array_search_tree()										//Создать дерево поиска из массива
{
	std::vector<char> arr = { 'A', 'B', 'D', 'G', 'E', 'H', 'C', 'F', 'I', 'J' };	//Создать контейнер значений элементов дерева

	SearchTree<char>* tree = new SearchTree<char>(arr.at(0));						//Создать первый элемент дерева

	for (int i = 1; i < arr.size(); i++)
	{
		tree->insertNode(arr.at(i));												//Добавить элемент с текущим номером в дерево
	}

	return tree;																
}

void show_tree(Tree<char>* tree)												//печать дерева
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

	std::cout << "Горизонтальная печать дерева: " << std::endl;
	tree->printTree(12);														//Вывод значений элементов (слева направо)
	std::cout << std::endl;

	std::cout << "Вертикальная печать дерева: " << std::endl;
	tree->printVTree(3);														//Вывод значений элементов (слева направо)
	std::cout << std::endl;

	std::cout << "Поперечный обход:     ";
	tree->levelScan();
	std::cout << std::endl;
}

void show_tree(SearchTree<char>* tree)											//печать дерева поиска
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

	std::cout << "Горизонтальная печать дерева: " << std::endl;
	tree->printTree(12);														//Вывод значений элементов (слева направо)
	std::cout << std::endl;

	std::cout << "Вертикальная печать дерева: " << std::endl;
	tree->printVTree(1);														//Вывод значений элементов (слева направо)
	std::cout << std::endl;
}

void add(Tree<char>* tree) //добавить элемент
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

void eject_left(Tree<char>* tree)								//извлечь поддерево слева
{
	tree->ejectLeft();
}

void eject_right(Tree<char>* tree)								//извлечь поддерево справа
{
	tree->ejectRight();
}

void delete_left(Tree<char>* tree)								//удалить поддерево слева
{
	tree->deleteLeft();														
}

void delete_right(Tree<char>* tree)								//удалить поддерево справа
{
	tree->deleteRight();
}

void number_of_elements(Tree<char>* tree)
{
	std::cout << "Количество элементов в дереве:  " << tree->getAmountOfNodes() << std::endl << std::endl;
}

void height(Tree<char>* tree)
{
	std::cout << "Высота дерева:  " << tree->getHeight() << std::endl << std::endl;
}

void number_by_symbol(Tree<char>* tree)				//найти количество элементов дерева, начинающихся с заданного символа
{
	char symbol{};
	std::cout << "Введите символ:\t";
	std::cin >> symbol;
	std::cout << "Кол-во элементов, начинающихся с \'" << symbol << "\': " << tree->number_by_symbol(symbol) << std::endl;
}

void number_by_symbol(SearchTree<char>* tree)				//найти количество элементов дерева, начинающихся с заданного символа
{
	char symbol{};
	std::cout << "Введите символ:\t";
	std::cin >> symbol;
	std::cout << "Кол-во элементов, начинающихся с \'" << symbol << "\': " << tree->number_by_symbol(symbol) << std::endl;
}

//------main-menu------
void Selection()
{
	Tree<char>* tree = new Tree<char>('X');	
	SearchTree<char>* seartch_tree = new SearchTree<char>('X');	

	bool boolean = true;

	while (boolean)
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
		std::cout << "14. Найти количество элементов дерева, начинающихся с заданного символа." << std::endl;
		std::cout << "15. Найти количество элементов дерева поиска, начинающихся с заданного символа." << std::endl;
		std::cout << "0. Закрыть программу." << std::endl;
		std::cout << "//////////////////////////////////////////////////////" << std::endl;

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
			eject_left(tree);
			break;
		case 7:
			eject_right(tree);
			break;
		case 8:
			delete_left(tree);
			break;
		case 9:
			delete_right(tree);
			break;
		case 10:
			number_of_elements(tree);
			break;
		case 11:
			height(tree);
			break;
		case 12:
			show_tree(tree);
			break;
		case 13:
			show_tree(seartch_tree);
			break;
		case 14:
			number_by_symbol(tree);
			break;
		case 15:
			number_by_symbol(seartch_tree);
			break;
		case 0:
			boolean = false;
			break;
		default:
			std::cout << "Ошибка. Неверный пункт меню." << std::endl;
			break;
		}
		system("pause");
		system("cls");
	}
}