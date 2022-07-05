#pragma once
#include<iostream>
#include<queue>
#include<stack>

struct Node
{
	int value;

	Node* left;
	Node* right;
	
	Node(int value, Node* left, Node* right) : value{value},left{left},right{right}
	{
	}

};

class CompleteBinaryTree
{
private:
	Node* mRoot{};

public:
	CompleteBinaryTree()
	{
		mRoot = CreateNode(0);
	}

	Node* CreateNode(int value)
	{
		return new Node(value, nullptr, nullptr);
	}

	Node* GetNode()
	{
		return mRoot;
	}

	void Visit(Node* node) { std::cout << node->value << "->"; }
	Node* AddNode(Node* node, int value);
	bool CheckCBT(Node* node);
	void InOrder(Node* node);
	void BreadthFirst(Node* node);
	bool Search(Node* node, int value);
	bool Squence(Node* node);
	int height(Node* node);
};

