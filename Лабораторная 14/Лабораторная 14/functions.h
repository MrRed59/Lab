#pragma once
#include<iostream>
#include"Search.h"
#include<vector>
#include"Tree.h"
#include<conio.h>

short Checking_For_Valid_Input();				//�������� ����� ��� ���� ������ short
char Checking_For_Valid_Input_Char();			//�������� ����� ��� ���� ������ char
//------functions-for-tree------
Tree<char>* create_tree();						//������� ������
Tree<char>* create_ideal_tree();				//������� ��������� ������
Tree<char>* create_array_tree();				//������� ������ �� �������
SearchTree<char>* create_array_search_tree();	//������� ������ ������ �� �������
void show_tree(Tree<char>*);					//������ ������
void show_tree(SearchTree<char>*);				//������ ������ ������
void add(Tree<char>*);							//�������� �������
void eject_left(Tree<char>*);					//������� ��������� �����
void eject_right(Tree<char>*);					//������� ��������� ������
void delete_left(Tree<char>*);					//������� ��������� �����
void delete_right(Tree<char>*);					//������� ��������� ������
void number_of_elements(Tree<char>*);			//���-�� ��������� ������
void height(Tree<char>*);						//������ ������
void number_by_symbol(Tree<char>*);				//����� ���������� ��������� ������, ������������ � ��������� �������

//------main-menu------

void Selection();

