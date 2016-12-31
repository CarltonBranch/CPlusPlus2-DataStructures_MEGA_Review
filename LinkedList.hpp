#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
class LinkedList {

	class Node
	{
	public:
		Node * next;
		T value;
		Node(T v) : value(v), next(nullptr) {}
	};

	Node * top;
	Node * root;
	size_t size;

public:

	LinkedList()
	{
		top = nullptr;
		root = nullptr;
		size = 0;
	}

	size_t getSize() { return size; }
	T peek() { return top->value; }

	~LinkedList()
	{
		Node * itM = top;
		while (itM != nullptr) {
			Node * delete_this = itM;
			itM = itM->next;
			delete delete_this;
		}
		size = 0;
	}


	void pushToFront(T v) {
		Node * temp = new Node(v);
		temp->next = top;
		top = temp;

		if (size == 0)
			root = temp;

		size++;
	}


	void appendToBack(T v) {
		Node * temp = new Node(v);
		temp->next = nullptr;
		root->next = temp;
		root = temp;

		if (size == 0)
			top = temp;

		size++;
	}


	bool deleteNode(T targetV) {
		Node * itM = top;
		Node * trail = nullptr;

		while (itM != nullptr)
		{
			if (itM->value == targetV)
			{
				Node * deletePtr = itM;

				if (size == 1)
				{
					delete deletePtr;
				}
				else if (trail != nullptr)
				{
					trail->next = itM->next;
					if (itM->next = nullptr)
						root = trail;
					delete deletePtr;
				}
				else
				{
					top = itM->next;
					delete deletePtr;
				}

				size--;
				return true;
			}
			trail = itM;
			itM = itM->next;
		}

		return false;
	}

	T getFront() { return top->value; }

	T getBack() { return root->value; }

	void prTList() {
		Node * itM = top;
		cout << endl << "List(" << getSize() << "): ";
		while (itM != nullptr)
		{
			cout << itM->value;
			if (itM->next != nullptr)
				cout << " - ";
			itM = itM->next;
		}
		cout << endl;
	}

	void delete_duplicates() {
		Node * itM = top;
		vector<T> v;
		while (itM->next != nullptr)
		{
			if (find(v.begin(), v.end(), itM->value) == v.end())
			{
				v.push_back(itM->value);
			}
			else
			{
				deleteNode(itM->value);
			}

			itM = itM->next;
		}
	}
};//End of class

