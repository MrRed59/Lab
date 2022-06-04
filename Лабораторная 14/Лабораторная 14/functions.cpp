#include<iostream>
#include"Search.h"
#include<vector>
#include"Tree.h"
#include<conio.h>
#include"functions.h"

short Checking_For_Valid_Input()											//�������� ����� ��� ���� ������ short
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

char Checking_For_Valid_Input_Char()											//�������� ����� ��� ���� ������ char
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

Tree<char>* create_tree()														//������� ������
{
	Tree<char>* tree = new Tree<char>('A');

	tree->insertLeft('B');														//�������� ������� �����
	tree->getLeft()->insertLeft('D');											//������� � �������� �����, ����������� ������� �����
	tree->getLeft()->getLeft()->insertLeft('G');								//������� � �������� �����, ������� � �������� �����, ����������� ������� �����
	tree->getLeft()->insertRight('E');											//������� � �������� �����,����������� ������� ������
	tree->getLeft()->getLeft()->insertRight('H');								//������� � �������� �����, ������� � �������� �����, ����������� ������� ������
	tree->insertRight('C');														//�������� ������� ������
	tree->getRight()->insertRight('F');											//������� � �������� ������ � ����������� ������� ������
	tree->getRight()->getRight()->insertLeft('I');								//������� � �������� ������, ������� � �������� ������, ����������� ������� �����
	tree->getRight()->getRight()->insertRight('J');								//������� � �������� ������, ������� � �������� ������, ����������� ������� ������

	return tree;
}

Tree<char>* create_ideal_tree()													//������� �������� ���������������� ������
{
	int n;

	std::cout << "������� ���������� ���������:  ";
	std::cin >> n;
	std::cout << std::endl;

	Tree<char>* tree = Tree<char>::balancedTree(n);

	std::cout << std::endl;

	return tree;
}

Tree<char>* create_array_tree()														//������� �������� ������ �� �������
{
	std::vector<char> arr = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };	//������� ��������� �������� ��������� ������

	Tree<char>* tree = new Tree<char>(arr.at(0));									//������� ������ ������� ������

	for (int i = 0; i < arr.size(); i++)
	{
		int left = 2 * i + 1;														//������ ����� �������� ����� �� �������� ������ 2n+1
		int right = left + 1;														//������ ����� �������� ������ �� �������� ������ 2n+2

		if (left < arr.size())														//��������� �� ������� �� ������� � ������� left �� ������� ����������
		{
			tree->findElement_insertLeft(tree, arr.at(i), arr.at(left));			//�������� ������� � ������� left ����� �� ��������
		}

		if (right < arr.size())														//��������� �� ������� ������� � ������� right �� ������� ����������
		{
			tree->findElement_insertRight(tree, arr.at(i), arr.at(right));			//�������� ������� � ������� right ������ �� ��������
		}
	}

	return tree;
}

SearchTree<char>* create_array_search_tree()										//������� ������ ������ �� �������
{
	std::vector<char> arr = { 'A', 'B', 'D', 'G', 'E', 'H', 'C', 'F', 'I', 'J' };	//������� ��������� �������� ��������� ������

	SearchTree<char>* tree = new SearchTree<char>(arr.at(0));						//������� ������ ������� ������

	for (int i = 1; i < arr.size(); i++)
	{
		tree->insertNode(arr.at(i));												//�������� ������� � ������� ������� � ������
	}

	return tree;																
}

void show_tree(Tree<char>* tree)												//������ ������
{
	std::cout << "������ �����:         ";
	tree->preOrder(tree);														//����� �������� ��������� (������ ����)
	std::cout << std::endl << std::endl;

	std::cout << "������������ �����:   ";
	tree->inOrder(tree);														//����� �������� ��������� (����� �������)
	std::cout << std::endl << std::endl;

	std::cout << "�������� �����:       ";
	tree->postOrder(tree);														//����� �������� ��������� (c��� �����)
	std::cout << std::endl << std::endl;

	std::cout << "�������������� ������ ������: " << std::endl;
	tree->printTree(12);														//����� �������� ��������� (����� �������)
	std::cout << std::endl;

	std::cout << "������������ ������ ������: " << std::endl;
	tree->printVTree(3);														//����� �������� ��������� (����� �������)
	std::cout << std::endl;

	std::cout << "���������� �����:     ";
	tree->levelScan();
	std::cout << std::endl;
}

void show_tree(SearchTree<char>* tree)											//������ ������ ������
{
	std::cout << "������ �����:         ";
	tree->preOrder(tree);														//����� �������� ��������� (������ ����)
	std::cout << std::endl << std::endl;

	std::cout << "������������ �����:   ";
	tree->inOrder(tree);														//����� �������� ��������� (����� �������)
	std::cout << std::endl << std::endl;

	std::cout << "�������� �����:       ";
	tree->postOrder(tree);														//����� �������� ��������� (c��� �����)
	std::cout << std::endl << std::endl;

	std::cout << "�������������� ������ ������: " << std::endl;
	tree->printTree(12);														//����� �������� ��������� (����� �������)
	std::cout << std::endl;

	std::cout << "������������ ������ ������: " << std::endl;
	tree->printVTree(1);														//����� �������� ��������� (����� �������)
	std::cout << std::endl;
}

void add(Tree<char>* tree) //�������� �������
{
	char post_elem{};
	char new_elem{};
	char choise{};

	std::cout << "������� �������� ��������, ����� �������� ����� �������� ����� �������:  ";
	std::cin >> post_elem;
	std::cout << std::endl << "������� �������� ������ ��������:  ";
	std::cin >> new_elem;
	std::cout << std::endl << "�������� ������� ����� [L] ��� ������ [R]?  ";
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
		std::cout << "������ �����." << std::endl << std::endl;
		break;
	}

	//return tree;
}

void eject_left(Tree<char>* tree)								//������� ��������� �����
{
	tree->ejectLeft();
}

void eject_right(Tree<char>* tree)								//������� ��������� ������
{
	tree->ejectRight();
}

void delete_left(Tree<char>* tree)								//������� ��������� �����
{
	tree->deleteLeft();														
}

void delete_right(Tree<char>* tree)								//������� ��������� ������
{
	tree->deleteRight();
}

void number_of_elements(Tree<char>* tree)
{
	std::cout << "���������� ��������� � ������:  " << tree->getAmountOfNodes() << std::endl << std::endl;
}

void height(Tree<char>* tree)
{
	std::cout << "������ ������:  " << tree->getHeight() << std::endl << std::endl;
}

void number_by_symbol(Tree<char>* tree)				//����� ���������� ��������� ������, ������������ � ��������� �������
{
	char symbol{};
	std::cout << "������� ������:\t";
	std::cin >> symbol;
	std::cout << "���-�� ���������, ������������ � \'" << symbol << "\': " << tree->number_by_symbol(symbol) << std::endl;
}

void number_by_symbol(SearchTree<char>* tree)				//����� ���������� ��������� ������, ������������ � ��������� �������
{
	char symbol{};
	std::cout << "������� ������:\t";
	std::cin >> symbol;
	std::cout << "���-�� ���������, ������������ � \'" << symbol << "\': " << tree->number_by_symbol(symbol) << std::endl;
}

//------main-menu------
void Selection()
{
	Tree<char>* tree = new Tree<char>('X');	
	SearchTree<char>* seartch_tree = new SearchTree<char>('X');	

	bool boolean = true;

	while (boolean)
	{
		std::cout << "�������� ������ ����� ����:" << std::endl;
		std::cout << "1. ������� �������� ������ (�������)." << std::endl;
		std::cout << "2. ������� �������� ���������������� ������." << std::endl;
		std::cout << "3. ������� �������� ������(������)." << std::endl;
		std::cout << "4. ������� �������� ������ ������." << std::endl;
		std::cout << "5. �������� ����� �������." << std::endl;
		std::cout << "6. ������� ��������� �����." << std::endl;
		std::cout << "7. ������� ��������� ������." << std::endl;
		std::cout << "8. ������� ��������� �����." << std::endl;
		std::cout << "9. ������� ��������� ������." << std::endl;
		std::cout << "10. �������� ���-�� ��������� � ������." << std::endl;
		std::cout << "11. �������� ������ ������." << std::endl;
		std::cout << "12. ������ ������" << std::endl;
		std::cout << "13. ������ ������ ������." << std::endl;
		std::cout << "14. ����� ���������� ��������� ������, ������������ � ��������� �������." << std::endl;
		std::cout << "15. ����� ���������� ��������� ������ ������, ������������ � ��������� �������." << std::endl;
		std::cout << "0. ������� ���������." << std::endl;
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
			std::cout << "������. �������� ����� ����." << std::endl;
			break;
		}
		system("pause");
		system("cls");
	}
}