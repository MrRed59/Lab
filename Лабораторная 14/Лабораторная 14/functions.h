#pragma once
#include<iostream>
#include"Search.h"
#include<vector>
#include<conio.h>

short Checking_For_Valid_Input();					//проверка ввода для типа данных short
char Checking_For_Valid_Input_Char();				//проверка ввода для типа данных char
//------functions-for-tree------
SearchTree* create_ideal_tree();					//создать идеальное дерево
SearchTree* create_array_search_tree();				//создать дерево поиска из массива
void show_tree(SearchTree*);						//печать дерева поиска
void delete_left(SearchTree*);						//удалить поддерево слева
void delete_right(SearchTree*);						//удалить поддерево справа
void number_of_elements(SearchTree*);				//кол-во элементов дерева
void height(SearchTree*);							//высота дерева
SearchTree* create_ideal_search(SearchTree*);		// Преобразовать идеальное дерево в дерево поиска
void print_OpenGL(SearchTree*, int, char**);						// Печать дерева поиска в OpenGL

void number_by_symbol(SearchTree* tree);

//------main-menu------

void Selection(int argc, char** argv);

