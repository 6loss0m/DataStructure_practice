#include <iostream>

class Node
{
public:
	int data;
	Node* next;

	Node()
	{
		this->data = 0;
		this->next = NULL;
	}
};

class Stack
{
private:
	int size;
	Node* top;

public:

	Stack()
	{
		size = 0;
		top = NULL;
	}

	void Push(int value)
	{
		Node* newNode = new Node();

		newNode->data = value;
		this->size++;

		if (IsEmpty())
		{
			top = newNode;
		}
		else
		{
			newNode->next = top;
			top = newNode;
		}
	}

	int Pop()
	{
		if (IsEmpty())
		{
			std::cout << "No Data! Return ";
			return 0;
		}

		this->size--;
		int tempTopData = top->data;
		top = top->next;

		return tempTopData;
	}

	void Peek()
	{
		std::cout << top->data << std::endl;
	}

	bool IsEmpty()
	{
		if (this->size == 0) return true;
		return false;
	}

	int Size()
	{
		return this->size;
	}

	void Print()
	{
		if (IsEmpty()) return;

		Node* originTopPosition = top;

		for (int i = 0; i < this->size; i++)
		{
			std::cout << top->data << " ";

			top = top->next;
		}

		std::cout << std::endl;
		top = originTopPosition;
	}
};

int main()
{
	Stack testStack;

	testStack.Push(5);
	testStack.Push(2);
	testStack.Push(3);

	testStack.Print();
	testStack.Peek();

	std::cout << testStack.Size() << std::endl;
	std::cout << testStack.IsEmpty() << std::endl;

	std::cout << testStack.Pop() << std::endl;
	std::cout << testStack.Pop() << std::endl;
	std::cout << testStack.Pop() << std::endl;

	std::cout << testStack.Size() << std::endl;
	testStack.Print();
}