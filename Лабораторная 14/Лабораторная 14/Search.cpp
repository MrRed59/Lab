#include<iostream>
#include<vector>
#include<fstream>
#include<queue>
#include"draw.h"
#include<algorithm>
#include"Search.h"


void SearchTree::insertLeft(char dt) //вставка узла слева
{
	SearchTree* node = new SearchTree(dt);
	if (this->left != nullptr)
		this->left->parent = node;// Сделать так, чтобы его предком был новый узел
	node->left = this->left; //Теперь у нового узла левый потомок – это левый потомок вызывающего узла
	this->left = node; //А вызывающий узел теперь имеет	левого потомка – это новый узел
	node->parent = this; //Указываем, что у нового узла теперь предком является текущий узел
}

void SearchTree::insertRight(char dt) //вставка узла справа
{
	SearchTree* node = new SearchTree(dt);
	if (this->right != nullptr)
		this->right->parent = node;
	node->right = this->right;
	this->right = node;
	node->parent = this;
}

int SearchTree::getHeight()
{
	int h1 = 0, h2 = 0, hadd = 0;
	if (this == nullptr)
		return 0;
	if (this->left != nullptr)
		h1 = this->left->getHeight();
	if (this->right != nullptr)
		h2 = this->right->getHeight();
	if (h1 >= h2 && this->data)
		return h1 + 1;
	else if (this->data)
		return h2 + 1;
	else
		return 0;
}

int SearchTree::getAmountOfNodes()
{
	if (this == nullptr)
		return 0;
	if ((this->left == nullptr) && (this->right == nullptr))
		return 1;
	int l = 0;
	int r = 0;
	if (this->left != nullptr)
		l = this->left->getAmountOfNodes();
	if (this->right != nullptr)
		r = this->right->getAmountOfNodes();
	return (l + r + 1);
}

int SearchTree::getLevel(SearchTree* tree)
{
	return tree->getParent() == nullptr ? 0 : getLevel(tree->getParent()) + 1;
}

SearchTree* SearchTree::replaceNULLforEmpty()
{
	SearchTree* node = this->copyTree();
	int h = node->getHeight();
	node = replace_help(node, h);
	return node;
}

SearchTree* SearchTree::copyTree()
{
	SearchTree* tree = new SearchTree(this->data);
	if (this->parent != nullptr)
		tree->parent = this->parent;
	if (this->left != nullptr)
		tree->left = this->left->copyTree();
	if (this->right != nullptr)
		tree->right = this->right->copyTree();
	return tree;
}

SearchTree* SearchTree::replace_help(SearchTree* node, int h)
{
	int curLevel = getLevel(node);
	if ((node->getLeft() == nullptr) && (curLevel != (h - 1)))
		node->insertLeft(NULL);
	if ((node->getRight() == nullptr) && (curLevel != h - 1))
		node->insertRight(NULL);
	if (node->getLeft() != nullptr)
		node->addLeftTree(replace_help(node->getLeft(), h));
	if (node->getRight() != nullptr)
		node->addRightTree(replace_help(node->getRight(), h));
	return node;
}

SearchTree* SearchTree::findElement(char dt)
{
	if ((this == nullptr) || (dt == this->data))
		return this;
	if (dt < this->data)
		return this->left->findElement(dt);
	else
		return this->right->findElement(dt);
}

SearchTree* SearchTree::findMin()
{
	if (this->left == nullptr)
		return this;
	return this->left->findMin();
}

SearchTree* SearchTree::findMax()
{
	if (this->right == nullptr)
		return this;
	return this->right->findMax();
}

SearchTree* SearchTree::next()
{
	SearchTree* tree = this;
	if (tree->right != nullptr)
		return tree->right->findMin();
	SearchTree* t = tree->parent;
	while ((t != nullptr) && (tree == t->right))
	{
		tree = t;
		t = t->parent;
	}
	return t;
}

SearchTree* SearchTree::prev()
{
	SearchTree* tree = this;
	if (tree->left != nullptr)
		return tree->left->findMax();
	SearchTree* t = tree->parent;
	while ((t != nullptr) && (tree == t->left))
	{
		tree = t;
		t = t->parent;
	}
	return t;
}

void SearchTree::insertNode(char dt)
{
	SearchTree* tree = this;											//создаётся элемент равный текущему

	while (tree != NULL)												//проверяется существование элемента
	{
		if (dt >= tree->data)											//проверяется значение элемента
		{
			if (tree->right != NULL)									//проверяется существование элемента справа
			{
				tree = tree->right;										//переход к элементу справа
			}
			else
			{
				SearchTree* temp = new SearchTree(dt);			//создаётся новый элемент

				temp->parent = tree;									//задаётся новому элементу значение элемента предка
				tree->right = temp;										//задаётся элементу значение элемента справа
				break;
			}
		}
		else if (dt < tree->data)										//проверяется значение элемента
		{
			if (tree->left != NULL)										//проверяется существование элемента слева
			{
				tree = tree->left;										//переход к элементу слева
			}
			else
			{
				SearchTree* temp = new SearchTree(dt);			//создаётся новый элемент

				temp->parent = tree;									//задаётся новому элементу значение элемента предка
				tree->left = temp;										//задаётся элементу значение элемента слева
				break;
			}
		}
	}
}

void SearchTree::deleteNode(char dt)
{
	SearchTree* e = this->findElement(dt);
	SearchTree* p = e->parent; //предок удаляемого элемента

	if ((e->left == nullptr) && (e->right == nullptr)) // Первый случай: удаляемый элемент не имеет потомков
	{
		if (p->left == e) p->left = nullptr;
		if (p->right == e) p->right = nullptr;
	}

	else if ((e->left == NULL) || (e->right == NULL)) // Второй случай: удаляемый элемент имеет одного потомка
	{
		if (e->left == NULL)
		{
			if (p->left == e) p->left = e->right;
			else p->right = e->right;
			e->right->parent = p;
		}
		else
		{
			if (p->left == e) p->left = e->left;
			else p->right = e->left;
			e->left->parent = p;
		}
	}

	// Третий случай: удаляемый элемент имеет двух потомков
	else
	{
		SearchTree* s = e->next();
		// Следующий элемент за удаляемым
		e->data = s->data;
		if (s->parent->left == s)
		{
			s->parent->left = s->right;
			if (s->right != NULL)
				s->right->parent = s->parent;
		}
		else
		{
			s->parent->right = s->right;
			if (s->right != NULL)
				s->right->parent = s->parent;
		}
	}
}

inline SearchTree::SearchTree(char dt)
{
	data = dt;															//задаётся значение элемента
	left = NULL;														//задаётся значение элемента слева
	right = NULL;														//задаётся значение элемента справа
	parent = NULL;														//задаётся значение элемента предка
}

SearchTree::~SearchTree()
{
	delete this->left;													//удаляется элемент слева
	delete this->right;													//удаляется элемент справа
}

inline SearchTree::SearchTree(const SearchTree& temp) :data(temp.data), left(temp.left), right(temp.right), parent(temp.parent)
{
}

void SearchTree::printSearchTree(int level)
{
	if (this != NULL)													//проверяется существование элемента
	{
		this->right->printSearchTree(level + 1);						//переход к элементу справа

		for (int i = 1; i < level; i++)									//выводятся пробелы
		{
			std::cout << "  ";
		}

		std::cout << this->data << std::endl;										//выводится значение элемента
		this->left->printSearchTree(level + 1);								//переход к элементу слева
	}
}

void SearchTree::preOrder(SearchTree* temp)
{
	if (temp != NULL)													//проверяется существование элемента
	{
		std::cout << temp->data << "   ";									//выводится значение элемента
		preOrder(temp->left);											//переход к элементу слева
		preOrder(temp->right);											//переход к элементу справа
	}
}

void SearchTree::inOrder(SearchTree* temp)
{
	if (temp != NULL)													//проверяется существование элемента
	{
		inOrder(temp->left);											//переход к элементу слева
		std::cout << temp->data << "   ";									//выводится значение элемента
		inOrder(temp->right);											//переход к элементу справа
	}
}

void SearchTree::postOrder(SearchTree* temp)
{
	if (temp != NULL)													//проверяется существование элемента
	{
		postOrder(temp->left);											//переход к элементу слева
		postOrder(temp->right);											//переход к элементу справа
		std::cout << temp->data << "   ";									//выводится значение элемента
	}
}

void SearchTree::printTree(int level)
{
	if (this != NULL)													//проверяется существование элемента
	{
		this->right->printTree(level + 1);								//переход к элементу справа

		for (int i = 1; i < level; i++)									//выводятся пробелы
		{
			std::cout << "  ";
		}

		std::cout << this->data << std::endl;										//выводится значение элемента
		this->left->printTree(level + 1);								//переход к элементу слева
	}
}

void SearchTree::printVTree(int k)
{
	int height = this->getHeight(); //Максимальное число листов на нижнем уровне(нумерация с нуля)
	int maxLeafs = pow(2, height - 1); //Минимальная ширина дерева для печати	(не конечная, но необходимая)
	int width = (2 * maxLeafs - 1);
	int curLevel = 0; // Номер строки (на выводе)
	int index = 0; // Номер элемента в строке (нумерация с нуля)
	int factSpaces = getPos(index, width, curLevel, height - 1); //Позиция корня (число пробелов перед ним)
	pos node;
	std::vector<SearchTree*> V;
	std::vector<pos> Vi;
	SearchTree* t = this->copyTree();
	t = t->replaceNULLforEmpty();
	SearchTree* p = t;
	V.push_back(p);
	node.col = factSpaces;
	node.str = curLevel;
	Vi.push_back(node);

	for (int i = 0; i < t->getAmountOfNodes(); i++)
	{
		if (pow(2, curLevel) <= index + 1)
		{
			index = 0;
			curLevel++;
		}
		if (V.at(i)->left != nullptr)
		{
			V.push_back(V.at(i)->left);
			factSpaces = getPos(index, width, curLevel, height - 1);
			node.col = factSpaces;
			node.str = curLevel;
			Vi.push_back(node);
			index++;
		}
		if (V.at(i)->right != nullptr)
		{
			V.push_back(V.at(i)->right);
			factSpaces = getPos(index, width, curLevel, height - 1);
			node.col = factSpaces;
			node.str = curLevel;
			Vi.push_back(node);
			index++;
		}
	}
	/* Редактируем позиции в строчках (теперь они обозначают количество пробелов перед данным символом начиная с предыдущего символа):
 до этого эти значения представляли собой координаты (как х) */
	for (int i = V.size() - 1; i >= 0; i--)
	{
		if (i != 0)
		{
			if (Vi.at(i - 1).str == Vi.at(i).str) Vi.at(i).col = Vi.at(i).col - Vi.at(i - 1).col - 1;
		}
	}
	int flag = 0; // Следит за тем, что y меняется
	for (int i = 0; i < V.size(); i++)
	{
		node = Vi.at(i);
		curLevel = node.str; //Переход на новую строчку будет, когда y1	станет меньше y (слежка за изменением y)
		if (flag < curLevel)
		{
			flag = curLevel;
			std::cout << std::endl;
		}
		factSpaces = node.col;
		int realSpaces = k * factSpaces;
		for (int j = 0; j < realSpaces; j++)
			std::cout << " ";
		if (V.at(i)->getData() != NULL)
			std::cout << V.at(i)->getData();
		else for (int j = 0; j < k; j++)
			std::cout << " ";
	}
	std::cout << std::endl;
}

size_t SearchTree::number_by_symbol(const char& value)
{
	size_t n_l{}, n_r{};

	if (this == nullptr)
	{
		return 0;
	}

	if (this->left != nullptr)
	{
		n_l = this->left->number_by_symbol(value);
	}
	if (this->right != nullptr)
	{
		n_r = this->right->number_by_symbol(value);
	}
	if (this->data == value)
	{
		return (n_l + n_r + 1);
	}
	return (n_l + n_r);
}

SearchTree* SearchTree::balancedTree(int n)
{
	if (!n)
		return nullptr;
	std::cout << "data=";
	char dt;
	std::cin >> dt;
	int nLeft = n / 2;
	int nRight = n - n / 2 - 1;
	SearchTree* tree = new SearchTree(dt);
	tree->addLeftTree(balancedTree(nLeft));
	tree->addRightTree(balancedTree(nRight));
	return tree;
}

void SearchTree::findElement_insertLeft(SearchTree* node, char dt1, char dt2)
{
	if (node != nullptr)
	{
		findElement_insertLeft(node->getLeft(), dt1, dt2);
		if (dt1 == node->getData()) node->insertLeft(dt2);
		findElement_insertLeft(node->getRight(), dt1, dt2);
	}
}

void SearchTree::findElement_insertRight(SearchTree* node, char dt1, char dt2)
{
	if (node != nullptr)
	{
		findElement_insertRight(node->getLeft(), dt1, dt2);
		if (dt1 == node->getData()) node->insertRight(dt2);
		findElement_insertRight(node->getRight(), dt1, dt2);
	}
}

void SearchTree::add(char dt)
{
	if (this == nullptr)
		return;

	if (this->data <= dt)
	{
		if (this->right == nullptr)
		{
			this->insertRight(dt);
		}
		else
		{
			this->right->add(dt);
		}
	}
	if (this->data > dt)
	{
		if (this->left == nullptr)
		{
			this->insertLeft(dt);
		}
		else
		{
			this->left->add(dt);
		}
	}
}

SearchTree* SearchTree::ejectLeft() // Извлечение
{
	if (this->left != nullptr)
	{
		SearchTree* temp = this->left;
		this->left = nullptr;
		return temp;
	}
	return nullptr;
}

void SearchTree::deleteLeft() // Удаление
{
	SearchTree* temp = this->ejectLeft();
	delete temp;
}

SearchTree* SearchTree::ejectRight()
{
	if (this->right != nullptr)
	{
		SearchTree* temp = this->right;
		this->right = nullptr;
		return temp;
	}
	return nullptr;
}

void SearchTree::deleteRight()
{
	SearchTree* temp = this->ejectRight();
	delete temp;
}

std::vector<char> SearchTree::copy_to_vector()
{
	static std::vector<char> v;
	if (this != nullptr)
	{
		v.push_back(this->data);
		this->left->copy_to_vector();
		this->right->copy_to_vector();
	}
	return v;
}

SearchTree* SearchTree::ideal_to_search(std::vector<char> v, int start, int end)
{
	if (!v.size() || start > end)
	{
		return nullptr;
	}

	int average = (start + end) / 2;

	SearchTree* tree = new SearchTree(v[average]);

	tree->right = ideal_to_search(v, average + 1, end);
	tree->left = ideal_to_search(v, start, average - 1);

	return tree;
}