#include"functions.h"
#include<iostream>
#include<vector>
#include"Search.h"

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Ru");

	/*std::vector<char> arr = { 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107};
	SearchTree* tree = new SearchTree(arr.at(0));
	for (int i = 0; i < arr.size(); i++)
	{
		int left = 2 * i + 1;
		int right = left + 1;
		if (left < arr.size())
		{
			tree->findElement_insertLeft(tree, arr.at(i),
				arr.at(left));
		}
		if (right < arr.size())
		{
			tree->findElement_insertRight(tree, arr.at(i),
				arr.at(right));
		}
	}
	tree->drawTree(argc, argv, 800, 600, 1, 2);*/

	Selection(argc, argv);
}