#include<iostream>
#include"CompleteBinaryTree.h"

int main()
{
	CompleteBinaryTree myTree;

	auto pRoot = myTree.CreateNode(1);
	myTree.AddNode(pRoot, 2);
	myTree.AddNode(pRoot, 3);
	myTree.AddNode(pRoot, 4);
	myTree.AddNode(pRoot, 5);
	myTree.AddNode(pRoot, 6);
	myTree.AddNode(pRoot, 7);
	myTree.AddNode(pRoot, 8);
	myTree.AddNode(pRoot, 9);
	myTree.AddNode(pRoot, 10);
	myTree.AddNode(pRoot, 11);
	myTree.AddNode(pRoot, 12);
	myTree.AddNode(pRoot, 13);
	myTree.AddNode(pRoot, 14);

	myTree.InOrder(pRoot);
	std::cout << std::endl;
	myTree.BreadthFirst(pRoot);
}