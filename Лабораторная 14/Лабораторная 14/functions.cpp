#include<iostream>
#include"Search.h"
#include<vector>
#include<conio.h>
#include"functions.h"
#include<algorithm>

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

SearchTree<char>* create_ideal_tree()													//создать идеально сбалансированное дерево
{
	int n;

	std::cout << "Введите количество Элементов:  ";
	std::cin >> n;
	std::cout << std::endl;

	SearchTree<char>* tree = SearchTree<char>::balancedTree(n);

	std::cout << std::endl;

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

void add(SearchTree<char>* tree)									//добавить элемент
{
	char new_elem{};	
	std::cout << std::endl << "Введите значение нового элемента:  ";
	std::cin >> new_elem;
	tree->add(new_elem);
}

void delete_left(SearchTree<char>* tree)							//удалить поддерево слева
{
	tree->deleteLeft();														
}

void delete_right(SearchTree<char>* tree)							//удалить поддерево справа
{
	tree->deleteRight();
}

void number_of_elements(SearchTree<char>* tree)
{
	std::cout << "Количество элементов в дереве:  " << tree->getAmountOfNodes() << std::endl << std::endl;
}

void height(SearchTree<char>* tree)
{
	std::cout << "Высота дерева:  " << tree->getHeight() << std::endl << std::endl;
}

void number_by_symbol(SearchTree<char>* tree)				//найти количество элементов дерева поиска, начинающихся с заданного символа
{
	char symbol{};
	std::cout << "Введите символ:\t";
	std::cin >> symbol;
	std::cout << "Кол-во элементов, начинающихся с \'" << symbol << "\': " << tree->number_by_symbol(symbol) << std::endl;
}

SearchTree<char>* create_ideal_search(SearchTree<char>* tree)
{
	std::vector<char> v = tree->copy_to_vector();
	std::sort(v.begin(), v.end());
	SearchTree<char>* temp;
	temp = tree->ideal_to_search(v, 0, v.size() - 1);
	return temp;
}

//------main-menu------
void Selection()
{
	SearchTree<char>* tree = new SearchTree<char>('X');
	SearchTree<char>* seartch_tree = new SearchTree<char>('X');	

	bool boolean = true;

	while (boolean)
	{
		std::cout <<	"Выберите нужный пункт меню:"														<< std::endl;
		std::cout <<	"1. Создать идеально сбалансированное дерево."										<< std::endl;
		std::cout <<	"2. Преобразовать сбалансированное дерево в дерево поиска."							<< std::endl;
		std::cout <<	"3. Добавить новый элемент."														<< std::endl;
		std::cout <<	"4. Удалить поддерево слева."														<< std::endl;
		std::cout <<	"5. Удалить поддерево справа."														<< std::endl;
		std::cout <<	"6. Показать кол-во элементов в дереве."											<< std::endl;
		std::cout <<	"7. Показать высоту дерева."														<< std::endl;
		std::cout <<	"8. Печать дерева поиска."															<< std::endl;
		std::cout <<	"9. Найти количество элементов дерева поиска, начинающихся с заданного символа."	<< std::endl;
		std::cout <<	"0. Закрыть программу."																<< std::endl;
		std::cout <<	"///////////////////////////////////////////////////////////////////////////////"	<< std::endl;

		switch (Checking_For_Valid_Input())
		{
		case 1:
			tree = create_ideal_tree();
			break;
		case 2:
			seartch_tree = create_ideal_search(tree);
			break;
		case 3:
			add(seartch_tree);
			break;
		case 4:
			delete_left(seartch_tree);
			break;
		case 5:
			delete_right(seartch_tree);
			break;
		case 6:
			number_of_elements(seartch_tree);
			break;
		case 7:
			height(seartch_tree);
			break;
		case 8:
			show_tree(seartch_tree);
			break;
		case 9:
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