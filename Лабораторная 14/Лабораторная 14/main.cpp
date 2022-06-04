//#include<iostream>
//#include"Search.h"
//#include<vector>
//#include"Tree.h"
#include"functions.h"






int main()
{
	setlocale(LC_ALL, "Ru");

	Selection();

	//Tree<char>* tree = new Tree<char>('A');										//создаётся первый Элемент дерева

	//tree->insertLeft('B');														//добавляется Элемент слева
	//tree->getLeft()->insertLeft('D');											//переход к Элементу слева, добавляется Элемент слева
	//tree->getLeft()->getLeft()->insertLeft('G');								//переход к Элементу слева, переход к Элементу слева, добавляется Элемент слева
	//tree->getLeft()->insertRight('E');											//переход к Элементу слева,добавляется Элемент справа
	//tree->getLeft()->getLeft()->insertRight('H');								//переход к Элементу слева, переход к элементу слева, добавляется Элемент справа
	//tree->insertRight('C');														//добавляется Элемент справа
	//tree->getRight()->insertRight('F');											//переход к Элементу справа и добавляется Элемент справа
	//tree->getRight()->getRight()->insertLeft('I');								//переход к Элементу справа, переход к Элементу справа, добавляется Элемент слева
	//tree->getRight()->getRight()->insertRight('J');


	//SearchTree<int>* tree2 = new SearchTree<int>(2);
	//tree2->insertNode(1);
	//tree2->insertNode(3);
	//tree2->insertNode(6);
	//tree2->insertNode(4);
	//tree2->insertNode(7);
	//tree2->insertNode(1);
	//tree2->printSearchTree(1);

	//std::cout << "n=";
	//int n;
	//std::cin >> n;
	//Tree<int>* tree3 = Tree<int>::balancedTree(n);
	//tree3->printVTree(1);

	//std::vector<int> arr = { 19, 33, 13, 17, 3, 31, 35, 18, 15 };
	//Tree<int>* tree4 = new Tree<int>(arr.at(0));
	//for (int i = 0; i < arr.size(); i++)
	//{
	//	int left = 2 * i + 1;
	//	int right = left + 1;
	//	if (left < arr.size())
	//	{
	//		tree4->findElement_insertLeft(tree4, arr.at(i),
	//			arr.at(left));
	//	}
	//	if (right < arr.size())
	//	{
	//		tree4->findElement_insertRight(tree4, arr.at(i),
	//			arr.at(right));
	//	}
	//}
	//tree4->printVTree(2);

	//std::vector<int> arr2 = { 19, 33, 13, 17, 3, 31, 35, 18, 15 };
	//SearchTree<int>* tree5 = new SearchTree<int>(arr.at(0));
	//for (int i = 1; i < arr.size(); i++)
	//{
	//	tree5->insertNode(arr2.at(i));
	//}
	//tree5->inOrder(tree5);

	//Tree<int>* tree6 = new Tree<int>(11);
	//tree6->insertLeft(22);
	//tree6->getLeft()->insertLeft(33);
	//tree6->getLeft()->getLeft()->insertLeft(44);
	//tree6->getLeft()->insertRight(55);
	//tree6->getLeft()->getLeft()->insertRight(66);
	//tree6->insertRight(77);
	//tree6->getRight()->insertRight(88);
	//tree6->getRight()->getRight()->insertLeft(99);
	//tree6->getRight()->getRight()->insertRight(10);
	//std::cout << "Горизонтальная печать" << std::endl;
	//tree6->printTree(1);
	//std::cout << std::endl;
	//std::cout << "Вертикальная печать" << std::endl;
	//tree6->printVTree(2);

	//std::cout << "\nn=";
	//int n2;
	//std::cin >> n2;
	//Tree<int>* tree7 = Tree<int>::balancedTree(n2);
	//tree7->printVTree2();
}