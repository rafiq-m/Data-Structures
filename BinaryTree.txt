#pragma once

struct Node
{
	int data;
	int height;
	Node* right, * left;
	Node(int data)
	{
		this->data = data;
		height = 0;
		this->right = nullptr;
		this->left = nullptr;
	}
};
class Tree
{
public:
	Node* root = nullptr;
	void insert(Node* node, int data, int level);
	void inOrder(Node* node);
	void postOrder(Node* node);
	void preOrder(Node* node);
};

#include "Tree.h"
using namespace std;
#include <iostream>

void Tree::insert(Node* node,int data, int level)
{
	Node* temp = new Node(data);
	if (root == nullptr)
	{
		root = temp;
	}
	else
	{
		if (node->left == nullptr && node->data > data)
		{
			node->left = temp;
			node->left->height = level+1;
		}
		else if(node->right == nullptr && node->data < data)
		{
			node->right = temp;
			node->right->height = level+1;
		}
		else if (node->data < data)
		{
			int h = level + 1;
			insert(node->right, data, h);
		}
		else
		{
			int h = level + 1;
			insert(node->left, data, h);
		}
	}
}

void Tree::inOrder(Node* node)
{
	if (node->left != nullptr)
		inOrder(node->left);

	cout << node->data << " Height:" << node->height << " " << endl;

	if (node->right != nullptr)
		inOrder(node->right);
}

void Tree::postOrder(Node* node)
{
	if (node->left != nullptr)
		inOrder(node->left);

	if (node->right != nullptr)
		inOrder(node->right);

	cout << node->data << " ";
}

void Tree::preOrder(Node* node)
{
	cout << node->data << " ";

	if (node->left != nullptr)
		inOrder(node->left);

	if (node->right != nullptr)
		inOrder(node->right);
}

int main()
{
Tree* t = new Tree();
	t->insert(t->root,9,0);
	t->insert(t->root, 10,0);
	t->insert(t->root, 11,0);
	t->insert(t->root, 8,0);
	t->insert(t->root, 5,0);
	t->insert(t->root, 22,0);
	t->insert(t->root, 123,0);
	t->insert(t->root, 100,0);
	t->insert(t->root, 1,0);
	t->inOrder(t->root);
return 0;
}

