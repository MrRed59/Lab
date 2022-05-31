#include "tree.h"
#include "search.h"
#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

Tree<char>* create_test_tree()													//���������� ������� ������� �������� ������
{
	Tree<char>* tree = new Tree<char>('A');										//�������� ������ ������� ������

	tree->insertLeft('B');														//����������� ������� �����
	tree->getLeft()->insertLeft('D');											//������� � �������� �����, ����������� ������� �����
	tree->getLeft()->getLeft()->insertLeft('G');								//������� � �������� �����, ������� � �������� �����, ����������� ������� �����
	tree->getLeft()->insertRight('E');											//������� � �������� �����,����������� ������� ������
	tree->getLeft()->getLeft()->insertRight('H');								//������� � �������� �����, ������� � �������� �����, ����������� ������� ������
	tree->insertRight('C');														//����������� ������� ������
	tree->getRight()->insertRight('F');											//������� � �������� ������ � ����������� ������� ������
	tree->getRight()->getRight()->insertLeft('I');								//������� � �������� ������, ������� � �������� ������, ����������� ������� �����
	tree->getRight()->getRight()->insertRight('J');								//������� � �������� ������, ������� � �������� ������, ����������� ������� ������

	return tree;																//������������ ���������� ������
}

Tree<char>* create_ideal_tree()													//���������� ������� ������� �������� ���������������� ������
{
	int n;																		//����������� ���������� ���������� ���������

	cout << "������� ���������� ���������:  ";
	cin >> n;																	//�������� �������� ���������� ���������
	cout << endl;

	Tree<char>* tree = Tree<char>::balancedTree(n);								//�������� �������� ���������������� ������

	cout << endl;

	return tree;																//������������ ���������� ������
}

Tree<char>* create_array_tree()													//�������� ������� ������� �������� ������ �� �������
{
	vector<char> arr = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };	//�������� ��������� �������� ��������� ������

	Tree<char>* tree = new Tree<char>(arr.at(0));								//�������� ������ ������� ������

	for (int i = 0; i < arr.size(); i++)										//������������ �������� ����������
	{
		int left = 2 * i + 1;													//������� ����� �������� ����� �� �������� ������ 2n+1
		int right = left + 1;													//������� ����� �������� ������ �� �������� ������ 2n+2

		if (left < arr.size())													//����������� �� ������� �� ������� � ������� left �� ������� ����������
		{
			tree->findElement_insertLeft(tree, arr.at(i), arr.at(left));		//����������� ������� � ������� left ����� �� ��������
		}

		if (right < arr.size())													//����������� �� ������� ������� � ������� right �� ������� ����������
		{
			tree->findElement_insertRight(tree, arr.at(i), arr.at(right));		//����������� ������� � ������� right ������ �� ��������
		}
	}

	return tree;																//������������ ���������� ������
}

SearchTree<char>* create_array_search_tree()									//���������� ������� ������� ������ ������ �� �������
{
	vector<char> arr = { 'A', 'B', 'D', 'G', 'E', 'H', 'C', 'F', 'I', 'J' };	//�������� ��������� �������� ��������� ������

	SearchTree<char>* tree = new SearchTree<char>(arr.at(0));					//�������� ������ ������� ������

	for (int i = 1; i < arr.size(); i++)										//������������ �������� ����������
	{
		tree->insertNode(arr.at(i));											//����������� ������� � ������� ������� � ������
	}

	return tree;																//������������ ���������� ������
}

void show_tree(Tree<char>* tree)												//���������� ������� �������� �������� ������
{
	cout << "������ �����:         ";
	tree->preOrder(tree);														//����������� ����� ����� �������� ��������� (������ ����)
	cout << endl << endl;

	cout << "������������ �����:   ";
	tree->inOrder(tree);														//����������� ����� ����� �������� ��������� (����� �������)
	cout << endl << endl;

	cout << "�������� �����:       ";
	tree->postOrder(tree);														//����������� ����� ����� �������� ��������� (c��� �����)
	cout << endl << endl;

	cout << "������������ ����� 2: " << endl;
	tree->printTree(12);														//����������� ����� ����� �������� ��������� (����� �������)
	cout << endl;

	cout << "���������� �����:     ";
	tree->levelscan();
	cout << endl;
}

void show_search_tree(SearchTree<char>* tree)									//���������� ������� �������� ������ ������
{
	cout << "������ �����:         ";
	tree->preOrder(tree);														//����������� ����� ����� �������� ��������� (������ ����)
	cout << endl << endl;

	cout << "������������ �����:   ";
	tree->inOrder(tree);														//����������� ����� ����� �������� ��������� (����� �������)
	cout << endl << endl;

	cout << "�������� �����:       ";
	tree->postOrder(tree);														//����������� ����� ����� �������� ��������� (c��� �����)
	cout << endl << endl;

	cout << "������������ ����� 2: " << endl;
	tree->printTree(12);														//����������� ����� ����� �������� ��������� (����� �������)
	cout << endl;
}

Tree<char>* eject_left_tree(Tree<char>* tree)								//�������� ������� "������� ��������� �����"
{
	Tree<char>* temp = tree->ejectLeft();
	return temp;
}

Tree<char>* eject_right_tree(Tree<char>* tree)								//�������� ������� "������� ��������� ������"
{
	Tree<char>* temp = tree->ejectRight();
	return temp;
}

Tree<char>* delete_left_tree(Tree<char>* tree)								//�������� ������� "������� ��������� �����"
{
	tree->deleteLeft();														//����������� �����
	return tree;
}

Tree<char>* delete_right_tree(Tree<char>* tree)								//�������� ������� "������� ��������� ������"
{
	tree->deleteRight();
	return tree;
}

Tree<char>* add_elem(Tree<char>* tree)
{
	char dt1, dt2;
	char lr;

	cout << "������� �������� ��������, ����� �������� ����� �������� ����� �������:  ";
	cin >> dt1;
	cout << endl << "������� �������� ������ ��������:  ";
	cin >> dt2;
	cout << endl << "�������� ������� ����� [L] ��� ������ [R]?  ";
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
		cout << "������ �����." << endl << endl;
		break;
	}

	return tree;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int num = 99;															//����������� ���������� ����� ����
	Tree<char>* tree = new Tree<char> ('X');								//����������� ������ �������
	SearchTree<char>* s_tree = new SearchTree<char> ('X');					//����������� ������ �������

	while (num != 0)
	{
		cout << "��������� ��������." << endl << endl << endl;

		cout << "���� ���������:" << endl << endl;							//���� ���������
		cout << "1.  ������� �������� ������ (��������)." << endl;
		cout << "2.  ������� �������� ���������������� ������." << endl;
		cout << "3.  ������� �������� ������ (�� �������)." << endl;
		cout << "4.  ������� ������ ������ (�� �������)." << endl;
		cout << "5.  �������� ����� �������." << endl;
		cout << "6.  ������� ��������� �����." << endl;
		cout << "7.  ������� ��������� ������." << endl;
		cout << "8.  ������� ��������� �����." << endl;
		cout << "9.  ������� ��������� ������." << endl;
		cout << "10. �������� ���������� ��������� � ������." << endl;
		cout << "11. �������� ������ ������." << endl;
		cout << "12. �������� �������� ������." << endl;
		cout << "13. �������� ������ ������." << endl;

		cout << "0.  ���������� ������." << endl << endl;

		cout << "�������� ����� ����:  ";
		cin >> num;															//�������� ����� ��������
		cout << endl;

		switch (num)
		{
		case 1:																//����������� �������� 1
			tree = create_test_tree();										//����������� ������� ������� �������� ������
			break;
		case 2:																//����������� �������� 2
			tree = create_ideal_tree();										//����������� ������� ������� �������� ���������������� ������
			break;
		case 3:																//����������� �������� 3
			tree = create_array_tree();										//����������� ������� ������� �������� ������ �� �������
			break;
		case 4:																//����������� �������� 4
			s_tree = create_array_search_tree();							//����������� ������� ������� ������ ������ �� �������
			break;
		case 5:
			tree = add_elem(tree);
			break;
		case 6:																//����������� �������� "������� ��������� �����"
			tree = eject_left_tree(tree);									//����������� ������� "������� ��������� �����"
			break;
		case 7:																//����������� �������� "������� ��������� ������"
			tree = eject_right_tree(tree);									//����������� ������� "������� ��������� ������"
			break;
		case 8:																//����������� �������� "������� ��������� �����"
			tree = delete_left_tree(tree);									//����������� ������� "������� ��������� �����"
			break;
		case 9:																//����������� �������� "������� ��������� ������"
			tree = delete_right_tree(tree);									//����������� ������� "������� ��������� ������"
			break;
		case 10:															//����������� �������� 10
			cout << "���������� ��������� � ������:  " << tree->getAmountOfNodes() << endl << endl;
			break;
		case 11:															//����������� �������� 11
			cout << "���������� ��������� � ������:  " << tree->getHeight() << endl << endl;
			break;
		case 12:															//����������� �������� 12
			show_tree(tree);												//����������� ������� �������� �������� ������
			break;
		case 13:															//����������� �������� 13
			show_search_tree(s_tree);										//����������� ������� �������� ������ ������
			break;
		}

		system("pause");
		system("cls");
	}
}