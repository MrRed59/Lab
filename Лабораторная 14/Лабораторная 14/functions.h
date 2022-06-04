#pragma once
#include<iostream>
#include"Search.h"
#include<vector>
#include"Tree.h"
#include<conio.h>

short Checking_For_Valid_Input();				//проверка ввода для типа данных short
char Checking_For_Valid_Input_Char();			//проверка ввода для типа данных char
//------functions-for-tree------
Tree<char>* create_tree();						//создать дерево
Tree<char>* create_ideal_tree();				//создать идеальное дерево
Tree<char>* create_array_tree();				//создать дерево из массива
SearchTree<char>* create_array_search_tree();	//создать дерево поиска из массива
void show_tree(Tree<char>*);					//печать дерева
void show_tree(SearchTree<char>*);				//печать дерева поиска
void add(Tree<char>*);							//добавить элемент
void eject_left(Tree<char>*);					//извлечь поддерево слева
void eject_right(Tree<char>*);					//извлечь поддерево справа
void delete_left(Tree<char>*);					//удалить поддерево слева
void delete_right(Tree<char>*);					//удалить поддерево справа
void number_of_elements(Tree<char>*);			//кол-во элементов дерева
void height(Tree<char>*);						//высота дерева
void number_by_symbol(Tree<char>*);				//найти количество элементов дерева, начинающихся с заданного символа

//------main-menu------

void Selection();

