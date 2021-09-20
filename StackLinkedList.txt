struct Node
{
	char data;
	Node* next;
	Node(int data)
	{
		this->data = data;
		next = nullptr;
	}
};

class Stack
{
private:
	Node* head = nullptr;
public:
	Stack();
	void push(char data);
	char pop();
	char top();
	int size();
	bool empty();
	void display();
	void reverse();
	char elementAt(int count);
};

void Stack::push(char data)
{
	Node* temp = new Node(data);
	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		Node* thead = head;
		head = temp;
		head->next = thead;
	}

}

char Stack::pop()
{
	if (head == NULL)
	{
		cout << " Head is null " << endl;
		return NULL;
	}
	else
	{
		Node* thead = head;
		head = head->next;
		char c = thead->data;
		thead->next = NULL;
		delete thead;
		return c;
	}
}
Stack::Stack()
{
	head = nullptr;
}

void Stack::display()
{
	Node* temp = head;
	while (temp != NULL)
	{
		cout << temp->data << endl;
		temp = temp->next;
	}
}
char Stack::top()
{
	if (head == NULL)
	{
		return NULL;
	}
	else
	{
		return head->data;
	}
}

int Stack::size()
{
	int count = 0;
	Node* temp = head;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

bool Stack::empty()
{
	if (head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Stack::reverse()
{
	{
		// Initialize current, previous and 
		// next pointers 
		Node* current = head;
		Node* prev = NULL, * nexted = NULL;

		while (current != NULL) {
			// Store next 
			nexted = current->next;

			// Reverse current node's pointer 
			current->next = prev;

			// Move pointers one position ahead. 
			prev = current;
			current = nexted;
		}
		head = prev;
	}
}

char Stack::elementAt(int count)
{
	reverse();
	Node* temp = head;
	if (count < size())
	{
		for (int i = 1; i < count; i++)
		{
			temp = temp->next;
		}
		char c = temp->data;
		reverse();
		return c;
	}
	else
	{
		return NULL;
	}
}

int main(){
Stack* s = new Stack();
	s->push('a');
	s->push('b');
	s->pop();
	s->pop();
	s->display();
return 0;
}