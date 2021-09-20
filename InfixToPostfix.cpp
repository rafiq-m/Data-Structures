#include <iostream>
#include <string>
#include "Stack.h"
#include <string>
using namespace std;

class InfixToPostfix
{
private:
	Stack* st = new Stack();
	string s;
public:
	InfixToPostfix();
	string inToPost()
	{
		string postfix;
		string sd;
		char c;
		cin >> sd;
		Stack* st = new Stack();
		for (int i = 0; i < sd.length();i++)
		{
			c = sd[i];
			if (c >= '0' && c <= '9')
			{
				postfix += c;
			}
			else if (c == '^')
			{
				while (st->top() == '^')
					postfix += st->pop();
				st->push(c);
			}
			else if (c == '*' || c == '/')
			{
				while (st->top() == '*' || st->top() == '/' || st->top() == '^')
				{
					postfix += st->pop();
				}
				st->push(c);
			}
			else if (c == '+' || c == '-')
			{
				while (!st->empty())
				{
					postfix += st->pop();
				}
				st->push(c);
			}
		}
		for (int i = 0; i <= st->size();i++)
		{
			postfix += st->pop();
		}
		cout << postfix << endl;
		return postfix;
	}

};

int main()
{
InfixToPostfix* p  = new InfixToPostfix();
p->inToPost();
return 0;
}
