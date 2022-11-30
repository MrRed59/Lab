#pragma once
#include"Search.h"


void initWindow(int, char**);
void display(void);
static void reshape(int, int);
static void drawLine(int, int, int, int);
static void drawFillCircle(int, int, int);
static void drawBlueCircle(int, int, int);
template<class T>
static void drawText(T , void*, int, int, int, int);
static void mouseMove(int, int);
SearchTree* get_help(SearchTree*, int, int, int);
int getPos(int, int, int, int);

struct pos
{
	int col;    // Столбец (х)
	int str;    // Строка  (у)
};

struct SGlutContextStruct
{
	/* window_width – ширина окна;
	 * window_height – высота окна;
	 * shift – отступ от краев (решено сделать его одинаковым с двух сторон);
	 * k - коэффициент ширины данных;
	 * R – радиус круга;
	 * x, y - координаты чего-либо;
	 * state - переменная состояния при работе с мышью
	*/
	void* tree;
	int window_width, window_height, shift, k, R, x, y, state;
};