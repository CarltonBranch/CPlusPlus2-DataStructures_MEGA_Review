/**	@file: LinkedList_Class_test.cpp
@author Carlton Branch
@author clbranch.jr@gmail.com
@author https://github.com/CarltonBranch
@date 2016-12-24
@brief Unit test of sorted_vector container
*/

#define _CRT_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS
#define BOOST_TEST_MODULE String_Class_Test

#include <boost/test/unit_test.hpp>
#include <iostream>
#include "LinkedList.hpp"
using namespace boost::unit_test;
using namespace std;


BOOST_AUTO_TEST_CASE(intro) {
	cout << "\n-- LinkdList Class --Unit test.\n";
	cout << "Last compiled: " << __TIMESTAMP__ << "\n\n";
}

BOOST_AUTO_TEST_CASE(default_constructor_test_int) {
	LinkedList<int> * l = new LinkedList<int>();
	for (int i = 0; i < 10; ++i)
		l->pushToFront(i);
	BOOST_CHECK_EQUAL(l->peek(), 9);
	delete l;
}
