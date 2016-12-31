#pragma once

template <typename T>
class BinTree {

	class Node {
	public:
		T value;
		Node * leftChild;
		Node * rightChild;
		Node(T val) : value(val), leftChild(nullptr), rightChild(nullptr) {}
	};

	size_t count;

	void preOrderTraversal(Node * node) {
		//current node - leftChild - rightChild
		if (node != nullptr)
		{
			cout << node->value << " ";
			preOrderTraversal(node->leftChild);
			preOrderTraversal(node->rightChild);
		}
	}

	void postOrderTraversal(Node * node) {
		//letChild - rightChild - current node
		if (node != nullptr)
		{
			postOrderTraversal(node->leftChild);
			postOrderTraversal(node->rightChild);
			cout << node->value << " ";
		}
	}

	void inOrderTraversal(Node * node)
	{
		//leftChild - current node - rightChild
		if (node != nullptr)
		{
			inOrderTraversal(node->leftChild);
			cout << node->value << " ";
			inOrderTraversal(node->rightChild);
		}
	}

	bool findTraversal(T searchVal, Node * node)
	{
		if (node != nullptr) {
			if (node->value == searchVal)
				return true;

			else if (searchVal <= node->value)
			{
				//go left
				findTraversal(searchVal, node->leftChild);
			}
			else
			{
				//go right
				findTraversal(searchVal, node->rightChild);
			}
		}
	}


	void DeleteTraversal(Node * node) {
		count = 0;
		if (node != nullptr)
		{
			if (node->leftChild != nullptr)
				DeleteTraversal(node->leftChild);

			if (node->rightChild != nullptr)
				DeleteTraversal(node->rightChild);

			delete node;
			count++;
		}
	}


public:
	Node * root;

	BinTree()
	{
		root = nullptr;
		count = 0;
	}


	~BinTree() {
		DeleteTraversal(root);
	}
	


	void push(T newVal) 
	{
		Node * insertNode = new Node(newVal);

		if (count == 0)
		{
			root = insertNode;
		}
		
		else {
			Node * itB = root;
			if (newVal <= root->value)
			{
				//go down left side
				while ( itB -> leftChild != nullptr )
				{
					itB = itB->leftChild;
				}
				itB->leftChild =insertNode;
				
			}
			else {
				//go down right side
				while (itB->rightChild != nullptr)
				{
					itB = itB->rightChild;
				}
				itB->rightChild = insertNode;
			}
		}
		count++;
	
	}
	
	//Modification----------------

	size_t getCount() {return count;}

	bool find(T searchVal) {
		if (findTraversal(searchVal, root))
		return true;

		return false;
	}

	

	bool deleteNodeReturnBool(T deleteVal)
	{
		Node * trailer = root;
		Node * runner = root;
		Node * leftHelper;
		while (runner != nullptr)
		{
			if (runner->value == deleteVal)
			{
				if (runner->leftChild == nullptr && runner->rightChild == nullptr) { count--; break; }

				else
				{
					if (runner->rightChild != nullptr)
					{
						if (runner->leftChild != nullptr)
						{
							leftHelper = runner->leftChild;
						}
						
						Node * toDelete = runner;
						trailer->rightChild = runner->rightChild;
						
						if ( runner == root )
						{
							root = trailer->rightChild;
						}
						
						runner = trailer -> rightChild;
						delete toDelete;						
					
						while ( runner -> leftChild != nullptr ) 
						{
							if ( runner == nullptr ) 
							{
								runner = leftHelper;
								break;
							}

							else if ( leftHelper -> value <= runner->value)
								runner = runner -> leftChild;

							else if (leftHelper -> value > runner->value)
								runner = runner -> rightChild;
						}
					}
				}
				--count;
				return true;
			}
			
			if (deleteVal <= runner -> value)
			{
				trailer = runner;
				runner = runner -> leftChild;
			}
			
			if (deleteVal > runner -> value)
			{
				trailer = runner;
				runner = runner -> rightChild;
			}
		}
		return false;
	}
		
	//Traversal-----------------
	
	//leftChild - current node - rightChild
	void traverseInOrder() {
		inOrderTraversal(root);
	}

	//current node - left child - right child
	void traversePreOrder() {
		preOrderTraversal(root);
	}

	//leftChild - rightChild - current node
	void traversePostOrder() {
		postOrderTraversal(root);
	}

};

