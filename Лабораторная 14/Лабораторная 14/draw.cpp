#include "draw.h"
#include <math.h>
#include<string>
#include<vector>
#include<gl/glut.h>

SGlutContextStruct glutContext;

int getPos(int index, int width, int curLevel, int maxLevel)
{
	int x1 = 0;
	int x2 = pow(2, curLevel) - 1;
	int y1 = width / pow(2, curLevel + 1);
	int y2 = width - pow(2, maxLevel - curLevel);
	if (x1 == x2) 
		return y1;
	double k = (y2 - y1) / (x2 - x1);
	double m = -x1 * k + y1;
	int y = (int)(k * index + m);
	return y;
}

void SearchTree::setCoordsForNode(int window_width, int window_height, int shift, int tree_width, int tree_height, int x, int y, int R)
{
	// Это условие не выполняется, когда дерево состоит из одного элемента
	if (tree_width != tree_height)
	{
		
		int k_x = (window_width - 2 * (shift + R)) / (tree_width - 1); // Коэффициент пропорциональности по оси Ох		
		int k_y = (window_height - 2 * (shift + R)) / (tree_height - 1); // Коэффициент пропорциональности по оси Оy
		node_x = k_x * x + shift + R;					// x-координата узла
		node_y = window_height - k_y * y - shift - R;	// у-координата узла
	}
	else
	{
		node_x = window_width / 2; // x-координата узла
		node_y = window_height / 2; // у-координата узла
	}
}

void SearchTree::setCoordsForText(int k, int R)
{
	text_x = node_x - 3 * R / 4;		// х-координата первого символа текста
	text_y = node_y - 3 * R / (4 * k);	// у-координата первого символа текста
}

SearchTree* SearchTree::getNodeByCoords(int x, int y, int R)
{
	SearchTree* node = this;
	node = get_help(node, x, y, R);
	return node;
}

SearchTree* get_help(SearchTree* node, int x, int y, int R)
{
	if (pow(x - node->node_x, 2) + pow(y - node->node_y, 2) <= pow(R, 2))
			return node;

	SearchTree* temp = NULL;

	if (node->getLeft() != NULL)
		temp = get_help(node->getLeft(), x, y, R);

	if (temp != NULL) 
		return temp;

	if (node->getRight() != NULL)
		temp = get_help(node->getRight(), x, y, R);

	return temp;
}

//

void initWindow(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(glutContext.window_width, glutContext.window_height);
	glutCreateWindow("DrawTree");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutPassiveMotionFunc(mouseMove);
	glutMainLoop();
}

static void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, (GLsizei) w, 0, (GLsizei) h);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glutContext.window_width = w;
	glutContext.window_height = h;
	glutPostRedisplay();
}

static void drawLine(int x1, int y1, int x2, int y2)
{
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glEnd();
}

static void drawFillCircle(int x, int y, int R)
{
	glColor3f(1.0, 1.0, 1.0);
	float x1, y1;
	glBegin(GL_POINTS);
	for (int i = 0; i <= R; i++)
	{
		for (int t = 0; t <= 360; t++)
		{
			x1 = i * sin(t) + x;
			y1 = i * cos(t) + y;
			glVertex2f(x1, y1);
		}
	}
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	for (int i = R - 1; i <= R; i++)
	{
		for (int t = 0; t <= 360; t++)
		{
			x1 = R * sin(t) + x;
			y1 = R * cos(t) + y;
			glVertex2f(x1, y1);
		}
	}
	glEnd();
}

static void drawBlueCircle(int x, int y, int R)
{
	glColor3f(0.0, 0.0, 1.0);
	float x1, y1;
	glBegin(GL_POINTS);
	for (int i = R - 1; i <= R; i++)
	{
		for (int t = 0; t <= 360; t++)
		{
			x1 = R * sin(t) + x;
			y1 = R * cos(t) + y;
			glVertex2f(x1, y1);
		}
	}
	glEnd();
}

template <class T>
static void drawText(T text, void* font, int text_x, int text_y, int R, int k)
{
	glColor3f(0.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef((text_x + text_x * 0.03), text_y, 0.0);
	std::string s;

	if (sizeof(text) == 1)
		s = text;
	else
		s = std::to_string(text).substr(0, 3);

	char* s1 = new char[s.size() + 1];

	for (int i = 0; i < s.size(); i++)
		s1[i] = s.at(i);

	s1[s.size()] = 0;
	char* c;
	int max_char_width = 0;
	int char_width = 0;

	for (c = s1; *c != '\0'; c++)
	{
		char_width = glutStrokeWidth(font, *c);
		if (max_char_width < char_width) 
			max_char_width = char_width;
	}

	float expand_x = (float)1.5 * R / (float)(k * max_char_width);
	float expand_y = (float)1.5 * R / (float)(k * 100);
	glScalef(expand_x, expand_y, 1.0);
	for (c = s1; *c != '\0'; c++)
		glutStrokeCharacter(font, *c);
	glPopMatrix();
}

void display(void)
{
	SearchTree* tree = (SearchTree*)glutContext.tree;
	int k = glutContext.k;
	int window_width = glutContext.window_width;
	int window_height = glutContext.window_height;
	int shift = glutContext.shift;
	int height = tree->getHeight();	
	int maxLeafs = pow(2, height - 1); // Максимальное число листов на	нижнем уровне (нумерация с нуля)	
	//int maxLeafs = 10;
	int width = 2 * maxLeafs - 1; // Минимальная ширина дерева для печати (не конечная, но необходимая)
	int curLevel = 0; // Номер строки (на выводе)
	int index = 0; //номер элемента в строке (нумерация с нуля)
	
	
	int factSpaces = getPos(index, width, curLevel, height - 1); // Позиция корня (число пробелов перед ним)
	pos node;
	std::vector<SearchTree*> V;
	std::vector<pos> Vi;
	int R; // Радиус круга
	R = (window_width - 2 * shift) / (2 * width);
	if (2 * R * height > (window_height - 2 * shift)) R = (window_height - 2 * shift) / (2 * height);
	glutContext.R = R;
	// Установили координаты корня при рисовании
	tree->setCoordsForNode(window_width, window_height,
		shift, width,
		height, factSpaces, curLevel, R);
	V.push_back(tree);
	node.col = factSpaces;
	node.str = curLevel;
	Vi.push_back(node);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(2);
	glEnable(GL_POINT_SMOOTH);

	for (int i = 0; i < tree->getAmountOfNodes(); i++)
	{
		if (pow(2, curLevel) <= index + 1)
		{
			index = 0;
			curLevel++;
		}
		if (V.at(i)->getLeft() != NULL)
		{
			V.push_back(V.at(i)->getLeft());
			factSpaces = getPos(index, width, curLevel, height - 1);
			node.col = factSpaces;
			node.str = curLevel;
			Vi.push_back(node);
			index++;
			V.at(i)->getLeft()->setCoordsForNode(window_width,
				window_height,
				shift, width, height, factSpaces, curLevel, R);
			if (V.at(i)->getLeft()->getData() != NULL)
			{
				int x1 = V.at(i)->node_x;
				int y1 = V.at(i)->node_y;
				int x2 = V.at(i)->getLeft()->node_x;
				int y2 = V.at(i)->getLeft()->node_y;
				drawLine(x1, y1, x2, y2);
			}
		}
		if (V.at(i)->getRight() != NULL)
		{
			V.push_back(V.at(i)->getRight());
			factSpaces = getPos(index, width, curLevel, height - 1);
			node.col = factSpaces;
			node.str = curLevel;
			Vi.push_back(node);
			index++;
			V.at(i)->getRight()->setCoordsForNode(window_width,
				window_height, shift, width, height, factSpaces,
				curLevel, R);
			if (V.at(i)->getRight()->getData() != NULL)
			{
				int x1 = V.at(i)->node_x;
				int y1 = V.at(i)->node_y;
				int x2 = V.at(i)->getRight()->node_x;
				int y2 = V.at(i)->getRight()->node_y;
				drawLine(x1, y1, x2, y2);
			}
		}
		if (V.at(i)->getData() != NULL)
		{
			if (glutContext.state == 0)
			{
				drawFillCircle(V.at(i)->node_x, V.at(i)->node_y, R);
			}
			else
			{
				drawFillCircle(V.at(i)->node_x, V.at(i)->node_y, R);
				if ((tree->getNodeByCoords(glutContext.x, glutContext.y, R)->node_x == V.at(i)->node_x) & (tree->getNodeByCoords(glutContext.x, glutContext.y, R)->node_y == V.at(i)->node_y))
					drawBlueCircle(V.at(i)->node_x, V.at(i)->node_y, R);
			}
			V.at(i)->setCoordsForText(k, R);
			drawText(V.at(i)->getData(), GLUT_STROKE_ROMAN, V.at(i)->text_x, V.at(i)->text_y, R, k);
		}
	}
	glutSwapBuffers();
	glDisable(GL_POINT_SMOOTH);
}

static void mouseMove(int x, int y)
{
	SearchTree* tree = (SearchTree*)glutContext.tree;
	int R = glutContext.R;
	SearchTree* node = tree->getNodeByCoords(x,
		glutContext.window_height - y, R);
	if (node != NULL)
	{
		glutContext.x = x;
		glutContext.y = glutContext.window_height - y;
		glutContext.state = 1;
		glutPostRedisplay();
	}
	else
	{
		glutContext.state = 0;
		glutPostRedisplay();
	}
}

void SearchTree::drawTree(int argc, char** argv, int window_width, int window_height, int shift, int k)
{
	SearchTree* temp = this->copyTree();
	temp = temp->replaceNULLforEmpty();
	glutContext.tree = temp;
	glutContext.window_width = window_width;
	glutContext.window_height = window_height;
	glutContext.shift = shift;
	glutContext.k = k;
	initWindow(argc, argv);
}
//
