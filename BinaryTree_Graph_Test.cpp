/**	@file: LinkedList_Class_test.cpp
@author Carlton Branch
@author clbranch.jr@gmail.com
@author https://github.com/CarltonBranch
@date 2016-12-24
@brief Unit test of sorted_vector container
*/

#define _CRT_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS
#define BOOST_TEST_MODULE Binary_Tree_Class_Test

#include <boost/test/unit_test.hpp>
#include <iostream>
#include "BinTree.hpp"
#include "Graph.hpp"
using namespace boost::unit_test;
using namespace std;
#define maximum 10


BOOST_AUTO_TEST_CASE(intro) {
	cout << "\n-- Binary Tree Class --Unit test.\n";
	cout << "Last compiled: " << __TIMESTAMP__ << "\n\n";
}

BOOST_AUTO_TEST_CASE(default_constructor_test_int) {
	BinTree<int> * b = new BinTree<int>();
	BOOST_CHECK_EQUAL(b->getCount(), 0);
	delete b;
}

BOOST_AUTO_TEST_CASE(default_push_test_int) {
	BinTree<int> * b = new BinTree<int>();
	for (unsigned i = 0; i < maximum; ++i)
	b->push(i);
	BOOST_CHECK_EQUAL(b->getCount(), maximum);
	delete b;
}


BOOST_AUTO_TEST_CASE(default_find_test_int) {
	BinTree<int> * b = new BinTree<int>();
	for (unsigned i = 0; i < maximum; ++i) 
	b->push(i);
	BOOST_CHECK_EQUAL(b->find(3), true);
	delete b;
}

BOOST_AUTO_TEST_CASE(default_deleteONE_test_int) {
	BinTree<int> * b = new BinTree<int>();
	b->push(10); 
	b->deleteNodeReturnBool(10);

	BOOST_CHECK_EQUAL(b->getCount(), 0);

	delete b;
}

//------------------------------------

BOOST_AUTO_TEST_CASE(intro3) {
	cout << "\n-- Graph Class --Unit test.\n";
	cout << "Last compiled: " << __TIMESTAMP__ << "\n\n";
}

BOOST_AUTO_TEST_CASE(default_graph_constructor_test_int) {
	Graph * g = new Graph();
	BOOST_CHECK(g != nullptr);
	delete g;
}
