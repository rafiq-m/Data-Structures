#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node()
	{
		data = 0;
		next = nullptr;
	}
};

class Queue
{
private :
	Node* head = nullptr;
public:
	int last()
	{
		Node* temp;
		temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		return temp->data;
	}//returns the last element of queue
	int pop()
	{
		if (head == nullptr)
		{
			cout << "Queue is Empty " << endl;
			return NULL;
		}
		else
		{
			Node* thead = head;
			Node* temp = nullptr;
			head = head->next;
			return thead->data;
			delete thead;
			thead = nullptr;
		}
	}//returns the first element of the queue and deletes it
	void push(int data)
	{

		Node* temp = new Node();
		temp->data = data;
		temp->next = nullptr;
		if (head == nullptr)
		{
			head = temp;
		}
		else
		{
			Node* thead;
			thead = head;
			while (thead->next != nullptr)
			{
				thead = thead->next;
			}
			thead->next = temp;
		}
	}		// pushes the element on the last
	int size()
	{
		int counter = 1;
		Node* temp = head;
		while (temp->next != nullptr)
		{
			counter++;
			temp = temp->next;
		}
		return counter;
	}//tells the size
	void display()
	{

		Node* thead;
		thead = head;
		while (thead != nullptr)
		{
			cout << thead->data << endl;
			thead = thead->next;
		}
	}//Displays the content of linked list
};

int main()
{
	Queue* q = new Queue();
	q->push(1);
	q->push(2);
	q->display();
	cout << q->pop();
	cout << q->pop();
	cout << " POP: " << q->pop();
	q->display();
}