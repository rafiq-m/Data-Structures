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

int main()
{
Paranthesis* p = new Paranthesis();
p->paranthesisCheck();
return 0;
}