#include <iostream>
#include <cassert>
using namespace std;

template <class T>
class Stack {

	class Node {
	public:
		Node * next;
		T value;
		Node(T v) : value(v), next(nullptr) {}
	};

	Node * top;
	size_t size;
	T min_value;

public:

	Stack()
	{
		top = nullptr;
		size = 0;
	}

	size_t getSize() { return size; }
	
	T peek() { assert(top != nullptr); return top->value; }

	~Stack(){
		Node * itM = top;
		while (itM != nullptr) {
			Node * delete_this = itM;
			itM = itM->next;
			delete delete_this;
		}
		size = 0;
	}

	void check_min(T v) {
		if ((size == 0) || (v < min_value))
			min_value = v;
	}

	void push(T v) {
		check_min(v);
		Node * temp = new Node(v);
		temp->next = top;
		top = temp;
		size++;
	}

	void pop() {
		assert(top != nullptr);
		Node * toDelete = top;
		top = top->next;
		delete toDelete;
		size--;
	}

	T min() { assert(top != nullptr);  return min_value; }

};
