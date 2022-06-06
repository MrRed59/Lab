#pragma once
#include<iostream>
#include"Search.h"
#include<vector>
#include"Tree.h"
#include<conio.h>

short Checking_For_Valid_Input();								//проверка ввода для типа данных short
char Checking_For_Valid_Input_Char();							//проверка ввода для типа данных char
//------functions-for-tree------
Tree<char>* create_tree();										//создать дерево
SearchTree<char>* create_ideal_tree();							//создать идеальное дерево
SearchTree<char>* create_array_search_tree();					//создать дерево поиска из массива
void show_tree(Tree<char>*);									//печать дерева
void show_tree(SearchTree<char>*);								//печать дерева поиска
void add(Tree<char>*);											//добавить элемент
void delete_left(SearchTree<char>*);							//удалить поддерево слева
void delete_right(SearchTree<char>*);							//удалить поддерево справа
void number_of_elements(SearchTree<char>*);						//кол-во элементов дерева
void height(SearchTree<char>*);									//высота дерева
void number_by_symbol(Tree<char>*);								//найти количество элементов дерева, начинающихся с заданного символа
SearchTree<char>* create_ideal_search(SearchTree<char>*);		// Преобразовать идеальное дерево в дерево поиска

//------main-menu------

void Selection();

