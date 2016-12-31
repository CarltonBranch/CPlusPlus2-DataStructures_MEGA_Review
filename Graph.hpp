#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define max 3

class Graph {

		map<int, vector<int>*> list;
		vector<vector<bool> > matrix;
	
		void createMatrix(){
			//populate the spine vector
			for (int i = 0; i < max; ++i)
				matrix.push_back(vector<bool>());

			//populate the body with boolean values (false)
			for (int i = 0; i < max; ++i)
				matrix[i].push_back(false);
		}

public:

	Graph() {
		createMatrix();
	}

	//insert value into adjacency list
	 void insert(int key, int value) {
		if (list.find(key) == list.end() )
			list.insert_or_assign(key, new vector<int>());

			list.at(key)->push_back(value);
	}
	 
	 //insert value into adjacency matrix
	 void matrix_insert(int x, int y)
	 {
		 vector<bool>::iterator it;
		 it = matrix[x].begin() + y;
		 matrix[x].insert(it, true);
	 }

};
