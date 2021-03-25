#include <iostream>

/*
	2020_02_04 정원영
	큐 복습
*/

class Node
{
public:
	int data;
	Node* next;

	Node()
	{
		this->data = 0;
		next = NULL;
	}
};

class Queue
{
private:
	int size;
	Node* rear, *front;

public:
	Queue()
	{
		this->size = 0;
		rear = front = NULL;
	}

	void Enqueue(int value)
	{
		Node* newNode = new Node;
		newNode->data = value;
		newNode->next = NULL;

		if (IsEmpty())
		{
			rear = front = newNode;
		}
		else
		{
			rear->next = newNode;
			rear = newNode;
		}
		this->size++;
	}

	int Dequeue()
	{
		if (IsEmpty())
		{
			std::cout << "NoData Return ";
			return 0;
		}

		int tempFrontData = front->data;
		Node* tempFrontNode = front;
		front = front->next;
		this->size--;

		delete tempFrontNode;
		return tempFrontData;
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

	int Peek()
	{
		return front->data;
	}

	void Print()
	{
		if (IsEmpty()) return;

		Node* originFrontPosition = front;

		for (int i = 0; i < this->size; i++)
		{
			std::cout << front->data << " ";
			front = front->next;
		}

		front = originFrontPosition;
		std::cout << std::endl;
	}
};

int main()
{
	Queue testQueue;

	testQueue.Enqueue(5);
	testQueue.Enqueue(1);
	testQueue.Enqueue(3);

	testQueue.Print();
	std::cout << "Peek : " << testQueue.Peek() << std::endl;
	std::cout << "Size : " << testQueue.Size() << std::endl;

	std::cout << "Dequeue : " << testQueue.Dequeue() << std::endl;
	std::cout << "Dequeue : " << testQueue.Dequeue() << std::endl;
	std::cout << "Dequeue : " << testQueue.Dequeue() << std::endl;
	std::cout << "Dequeue : " << testQueue.Dequeue() << std::endl;

	testQueue.Print();
}