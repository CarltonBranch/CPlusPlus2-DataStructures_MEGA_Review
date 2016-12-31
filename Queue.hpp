#include <iostream>
using namespace std;

template <typename T>
class Queue {

	struct Node {
		Node * nextPtr;
		T value;
		};

	size_t count;

public:
	Node * topPtr;
	Node * rootPtr;

	Queue() { 
		count = 0; 
		topPtr = nullptr; 
		rootPtr = nullptr;
	}

	~Queue() 
	{
		while (rootPtr != nullptr)
		{
			Node * toDelete = rootPtr;
			rootPtr = rootPtr->nextPtr;
			delete toDelete;
		}

	}


	void push(T v) 
	{
		Node * temp = new Node();
		temp->value = v;
		temp->nextPtr = nullptr;
	
		if (count == 0)
		{
			topPtr = temp;
			rootPtr = temp;
		}
		else if (count == 1)
		{
			topPtr = rootPtr->nextPtr = temp;		
		}
		else { 
			topPtr->nextPtr = temp;
			topPtr = topPtr->nextPtr;
		}
		++count;
	}

	size_t getSize() { return count; }
	T peek() { return rootPtr->value; }

	void pop() {
		if (rootPtr != nullptr) {
			Node * toDelete = rootPtr;
			rootPtr = rootPtr->nextPtr;
			delete toDelete;
			count--;
		}
	}

	void print() 
	{
		Node * itQ = rootPtr;
		cout << "Queue("<<getSize()<<"): ";
		while (itQ != nullptr) 
		{
			cout << itQ->value << " ";
			itQ = itQ->nextPtr;
		}
		cout << endl;
	}

	bool isEmpty() 
	{ 
		if (count <=0) 
			return true; 
		else 
			return false; 
	}


	void sort()
	{
		if (count > 1) {
			for (unsigned i = 0; i < count - 1; ++i)
			{
				Node * itS = rootPtr;
				Node * runner = rootPtr->nextPtr;

				for (unsigned j = 0; j < count - 1; ++j)
				{
					T checkVal = itS->value;
					T runVal = runner->value;

					if (runVal < checkVal)
					{
						T temp = checkVal;
						itS->value = runner->value;
						runner->value = temp;
					}
					itS = itS->nextPtr;
					runner = runner->nextPtr;
				}
			}
		}
	}


};
