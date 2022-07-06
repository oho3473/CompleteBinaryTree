#include "CompleteBinaryTree.h"

void CompleteBinaryTree::BreadthFirst(Node* node)
{
	std::queue<Node*> queue;
	queue.push(node);

	while (!queue.empty())
	{
		auto node = queue.front();
		Visit(node);
		queue.pop();
		if (node->left != nullptr)
		{
			queue.push(node->left);
		}

		if (node->right != nullptr)
		{
			queue.push(node->right);
		}
	}
}

bool CompleteBinaryTree::Search(Node* node, int value)
{
	if (node == nullptr)
		return false;

	return (node->value == value) || Search(node->left, value) || Search(node->right, value);
}

//���� �� ��� �� ������ �� ����� ���� ��
bool CompleteBinaryTree::Squence(Node* node)
{
	if (node == nullptr)
		return 0;

	int lHeight = height(node->left) + 1;
	int rHeight = height(node->right) + 1;

	return (lHeight - rHeight);
	// 0 : ���� ����, 1 : ���� ��尡 ���� ŭ
}

int CompleteBinaryTree::height(Node* node)
{
	if (node == nullptr)
		return 0;
	else
	{
		int lHeight = height(node->left) + 1;
		int rHeight = height(node->right) + 1;

		return (lHeight > rHeight) ? lHeight : rHeight;
	}

}

void CompleteBinaryTree::InOrder(Node* node)
{
	if (node == nullptr)
		return;

	InOrder(node->left);
	Visit(node);
	InOrder(node->right);
}

Node* CompleteBinaryTree::AddNode(Node* node, int value)
{
	if (node == nullptr)
	{
		return CreateNode(value);
	}

	//�ڽľ���
	if (node->left == nullptr && node->right == nullptr)
	{
		return node->left = AddNode(node->left, value);
	}
	//�ڽ� ���� �ϳ�
	else if(node->left != nullptr && node->right == nullptr)
	{
		return node->right = AddNode(node->right, value);
	}
	//�ڽ� ��
	else
	{
		//���̰��� ������ ����ִ°�?
		if(Squence(node) == 0 && CheckCBT(node->right))
			return AddNode(node->right, value);

		//���̰� ������ �����߰�
		if (Squence(node) == 0)
			return AddNode(node->left, value);

		//���� ���̰� ũ�� ���� ����ִ°�
		if(Squence(node) == 1 && CheckCBT(node->left))
			return AddNode(node->left, value);

		//���� ���� Ŭ��
		if (Squence(node) == 1)
			return AddNode(node->right, value);
	}

	return node;
}

//�κ����� �ɰ��� �ڽ��� �ִ°�?
bool CompleteBinaryTree::CheckCBT(Node* node)
{
	if (node == nullptr)
		return false;


	bool x = CheckCBT(node->left);

	//���� �ڽ��� �ִ� ���
	if (Squence(node))
		return true;
	
	bool y = CheckCBT(node->right);

	return x || y;
	//true : ���� �ڽ� ���� false : �ڽľ���
}



