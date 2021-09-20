using namespace std;
#include <stdio.h>
#include <iostream>

struct ETNode
{
	char data;
	ETNode* left;
	ETNode* right;
	ETNode(char data)
	{
		this->data = data;
		left = nullptr;
		right = nullptr;
	}
};
struct Node
{
	ETNode* node;
	Node* next;
	Node(ETNode* node)
	{
		this->node = node;
		next = nullptr;
	}
};
class STackET
{
public:
	Node* top = nullptr;
	void push(ETNode* node)
	{
		Node* temp = new Node(node);
		if (top == nullptr)
		{
			top = temp;
		}
		else
		{
			temp->next = top;
			top = temp;
		}
	}

	ETNode* pop()
	{
		if (top == NULL)
		{
			cout << " Stack is null " << endl;
			return NULL;
		}
		else
		{
			Node* thead = top;
			top = top->next;
			ETNode* c = thead->node;
			thead->next = NULL;
			delete thead;
			return c;
		}
	}

	STackET()
	{
		top = nullptr;
	}

	void display()
	{
		Node* temp = top;
		while (temp != NULL)
		{
			cout << temp->node << endl;
			temp = temp->next;
		}
	}
	ETNode* toper()
	{
		if (top == NULL)
		{
			return NULL;
		}
		else
		{
			return top->node;
		}
	}

	int size()
	{
		int count = 0;
		Node* temp = top;
		while (temp != NULL)
		{
			count++;
			temp = temp->next;
		}
		return count;
	}

	bool empty()
	{
		if (top == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};


class ETree
{
public:
	STackET* st;
	ETNode* root = nullptr;
	ETree()
	{
		root = nullptr;
		st = new STackET();
	}
	void append(string s)
	{
		ETNode* temp = nullptr;
		for (int i = 0; i < s.size(); i++)
		{
			char c = s[i];
			temp = new ETNode(c);
			if (isOperator(c))
			{
				st->push(temp);
			}
			else
			{
				temp->right = st->pop();
				temp->left = st->pop();
				st->push(temp);
			}
		}
		root = st->toper();
		//cout << root->data << endl;
		//cout << root->left->data << endl;
		//cout << root->right->data << endl;
		//cout << root->right->left->data << endl;
	}

	bool isOperator(char c)
	{
		return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) ? true : false;
	}

	void postOrder(ETNode* node)
	{
		if (node != NULL)
		{
			postOrder(node->left);
			cout << node->data << endl;
			postOrder(node->right);

		}
	}
};

int main()
{
	ETree* t = new ETree();
	t->append("abc*+d-");
	t->postOrder(t->root);
}