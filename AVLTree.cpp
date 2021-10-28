#pragma once

struct Node
{
	int key;
	int height;
	Node* left;
	Node* right;
	Node(int key)
	{
		height = 1;
		this->key = key;
		right = nullptr;
		left = nullptr;
	}
};
class Tree
{
public:
	Node* root = nullptr;
	Node* insert(Node* node, int key);
	Node* newNode(int key);
	void preOrder(Node* node);
	Node* leftRotation(Node* node);
	Node* rightRotation(Node* node);
	int getBalance(Node* node);
private:
	int height(Node* node);
	int max(int a, int b);
};



#include "Tree.h"
#include <iostream>
using namespace std;

Node* Tree::insert(Node* node, int key)
{
	if (node == nullptr)
	{
		return newNode(key);
	}
	else if (key < node->key)
	{
		node->left = insert(node->left, key);
	}
	else if (key > node->key)
	{
		node->right = insert(node->right, key);
	}
	else
	{
		return node;
	}

	node->height = 1 + max(height(node->left), height(node->right));

	int balance = getBalance(node);

	//LL
	if (balance > 1 && key < node->left->key)
	{
		return rightRotation(node);
	}
	//RR
	if (balance < -1 && key > node->right->key)
	{
		return leftRotation(node);
	}
	//LR
	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotation(node->left);
		return rightRotation(node);
	}
	//RL
	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotation(node->right);
		return leftRotation(node);
	}
	//Return the unchanged pointer
	return node;
}


Node* Tree::newNode(int key)
{
	Node* node = new Node(key);
	return node;
}

void Tree::preOrder(Node* root)
{
	if (root != NULL)
	{
		cout << root->key << " " ;
		preOrder(root->left);
		preOrder(root->right);
	}
}

int Tree::height(Node* node)
{
	if (node == NULL)
		return 0;
	return node->height;
}

int Tree::max(int a, int b)
{
	return (a > b) ? a : b;
}

Node* Tree::leftRotation(Node* node)
{
	Node* to_be = node->right;
	Node* other = to_be->left;

	to_be->left = node;
	node->right = other;

	node->height = 1 + max(height(node->left), height(node->right));

	to_be->height = 1 + max(height(to_be->left), height(to_be->right));

	return to_be;
}

Node* Tree::rightRotation(Node* node)
{
	Node* to_be = node->left;
	Node* other = to_be->right;

	to_be->right = node;
	node->left = other;

	node->height = 1 + max(height(node->left), height(node->right));

	to_be->height = 1 + max(height(to_be->left), height(to_be->right));

	return to_be;
}

int Tree::getBalance(Node* node)
{
	if (node == NULL)
		return 0;
	else
	{
		return height(node->left) - height(node->right);
	}
}

#include <iostream>
#include "Tree.h"
using namespace std;
int main()
{
	Tree* t = new Tree();
	t->root = t->insert(t->root, 10);
	t->root = t->insert(t->root, 20);
	t->root = t->insert(t->root, 30);
	t->root = t->insert(t->root, 40);
	t->root = t->insert(t->root, 50);
	t->root = t->insert(t->root, 25);
	t->preOrder(t->root);
}