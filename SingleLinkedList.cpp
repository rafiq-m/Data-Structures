#pragma once
#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;
class Paranthesis
{
private:
	Stack* st;
public :
	void parenthesisCheck()
	{
		int z = 0;
		string s;
		cin >> s;
		Stack* st = new Stack();
		char c = s[0];
		st->push(c);
		for (int i = 1;i < s.length();i++)
		{
			try
			{
				char c = s[i];
				if (c == '[' || c == '{' || c == '(')
				{
					st->push(c);
					st->display();
				}
				else if (c == ']')
				{
					if (st->top() == '[')
					{
						st->pop();
					}
					else
					{
						throw 99;
					}
				}
				else if (c == '}')
				{
					if (st->top() == '{')
					{
						st->pop();
					}
					else
					{
						throw 99;
					}
				}
				else  if (c == ')')
				{
					if (st->top() == '(')
					{
						st->pop();
					}
					else
					{
						throw 99;
					}
				}
				z = 2;
			}
			catch (int i)
			{
				cout << " Equation Unbalanced" << endl;
				z = i;
				break;
			}
		}
		if (z == 2 && st->size() == 1)
		{
			cout << " Balanced" << endl;
		}
		else if (z == 2)
		{
			cout << "Equation unbalanced" << endl;
		}
	}
};

#include "SLL.h"
#include <iostream>
using namespace std;

SLL::SLL()
{
	head = nullptr;
	tail = nullptr;
}

void SLL::append(int data)
{
	if (head == nullptr)
	{
		head = new Node();
		tail = head;
		head->data = data;
	}
	else
	{
		tail->next = new Node();
		tail = tail->next;
		tail->data = data;
	}
}

void SLL::display()
{
	Node* temp;
	temp = head;
	while (temp!= nullptr)
	{
		std::cout << temp->data << endl;
		temp = temp->next;
	}
}

void SLL::deleteHead()
{
	Node* temp;
	temp = head;
	head = head->next;
	delete temp;
}

void SLL::deleteTail()
{
	Node* temp = nullptr;
	Node* toBeTail = nullptr;
	temp = head;
	while (temp != tail)
	{
		toBeTail = temp;
		temp = temp->next;
	}
	delete temp;
	tail = toBeTail;
	tail->next = nullptr;
	/*if (tail == nullptr)
		return;
	else 
	{
		Node* toBeTail;
		toBeTail = tail;
		if (head == tail) {
			head = nullptr;
			tail = nullptr;
		}
		else {
			Node* temp = head;
			while (temp->next != tail)
				temp = temp->next;
			tail = temp;
			tail->next = nullptr;
		}
		delete toBeTail;
	}*/
}
int main()
{
    std::cout << "Hello World!\n";
	SLL* sl = new SLL();
	sl->append(1);
	sl->append(2);
	sl->append(3);
	sl->append(4);
	sl->display();
	cout << "------Deleting Head--------" << endl;
	sl->deleteHead();
	sl->append(5);
	sl->display();
	cout << "------Deleting Tail--------" << endl;
	sl->deleteTail();
	sl->display();
	cout << "--------------" << endl;
}