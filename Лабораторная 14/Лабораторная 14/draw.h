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


//template<class T>
//void SearchTree<T>::drawTree(int argc, char** argv, int	window_width, int window_height, int shift, int k)
//{
//	SearchTree<T>* temp = this->copyTree();
//	temp = temp->replaceNULLforEmpty();
//	glutContext.tree = temp;
//	glutContext.window_width = window_width;
//	glutContext.window_height = window_height;
//	glutContext.shift = shift;
//	glutContext.k = k;
//	initWindow(argc, argv);
//}

//template <class S>
//void SearchTree<S>::printVTree(int k)
//{
//	int height = this->getHeight(); //Максимальное число листов на нижнем уровне(нумерация с нуля)
//	int maxLeafs = pow(2, height - 1); //Минимальная ширина дерева для печати	(не конечная, но необходимая)
//	int width = (2 * maxLeafs - 1);
//	int curLevel = 0; // Номер строки (на выводе)
//	int index = 0; // Номер элемента в строке (нумерация с нуля)
//	int factSpaces = getPos(index, width, curLevel, height - 1); //Позиция корня (число пробелов перед ним)
//	pos node;
//	std::vector<SearchTree<S>*> V;
//	std::vector<pos> Vi;
//	SearchTree<S>* t = this->copyTree();
//	t = t->replaceNULLforEmpty();
//	SearchTree<S>* p = t;
//	V.push_back(p);
//	node.col = factSpaces;
//	node.str = curLevel;
//	Vi.push_back(node);
//
//	for (int i = 0; i < t->getAmountOfNodes(); i++)
//	{
//		if (pow(2, curLevel) <= index + 1)
//		{
//			index = 0;
//			curLevel++;
//		}
//		if (V.at(i)->left != nullptr)
//		{
//			V.push_back(V.at(i)->left);
//			factSpaces = getPos(index, width, curLevel, height - 1);
//			node.col = factSpaces;
//			node.str = curLevel;
//			Vi.push_back(node);
//			index++;
//		}
//		if (V.at(i)->right != nullptr)
//		{
//			V.push_back(V.at(i)->right);
//			factSpaces = getPos(index, width, curLevel, height - 1);
//			node.col = factSpaces;
//			node.str = curLevel;
//			Vi.push_back(node);
//			index++;
//		}
//	}
//	/* Редактируем позиции в строчках (теперь они обозначают количество пробелов перед данным символом начиная с предыдущего символа):
// до этого эти значения представляли собой координаты (как х) */
//	for (int i = V.size() - 1; i >= 0; i--)
//	{
//		if (i != 0)
//		{
//			if (Vi.at(i - 1).str == Vi.at(i).str) Vi.at(i).col = Vi.at(i).col - Vi.at(i - 1).col - 1;
//		}
//	}
//	int flag = 0; // Следит за тем, что y меняется
//	for (int i = 0; i < V.size(); i++)
//	{
//		node = Vi.at(i);
//		curLevel = node.str; //Переход на новую строчку будет, когда y1	станет меньше y (слежка за изменением y)
//		if (flag < curLevel)
//		{
//			flag = curLevel;
//			std::cout << std::endl;
//		}
//		factSpaces = node.col;
//		int realSpaces = k * factSpaces;
//		for (int j = 0; j < realSpaces; j++)
//			std::cout << " ";
//		if (V.at(i)->getData() != NULL)
//			std::cout << V.at(i)->getData();
//		else for (int j = 0; j < k; j++)
//			std::cout << " ";
//	}
//	std::cout << std::endl;
//}