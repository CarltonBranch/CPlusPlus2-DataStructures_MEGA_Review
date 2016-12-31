/**	@file: LinkedList_Class_test.cpp
@author Carlton Branch
@author clbranch.jr@gmail.com
@author https://github.com/CarltonBranch
@date 2016-12-24
@brief Unit test of sorted_vector container
*/

#define _CRT_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS
#define BOOST_TEST_MODULE Stack_Queue_Class_Test

#include <boost/test/unit_test.hpp>
#include <iostream>
#include "Stack.hpp"
#include "Queue.hpp"
using namespace boost::unit_test;
using namespace std;
#define maximum 10


BOOST_AUTO_TEST_CASE(intro) {
	cout << "\n-- Stack Class --Unit test.\n";
	cout << "Last compiled: " << __TIMESTAMP__ << "\n\n";
}

BOOST_AUTO_TEST_CASE(default_constructor_test_int) {
	Stack<int> * s = new Stack<int>();
	
	delete s;
}

BOOST_AUTO_TEST_CASE(push_test_int) {
	Stack<int> * s = new Stack<int>();
	for (int i = 0; i < 1000; ++i)
	{
		s->push(i);
		BOOST_CHECK_EQUAL(s->getSize(), i + 1);
		BOOST_CHECK_EQUAL(s->peek(), i);
	}
	delete s;
}

BOOST_AUTO_TEST_CASE(pop_test_int) {
	Stack<int> * s = new Stack<int>();
	for (int i = 0; i <= maximum; ++i) {
		s->push(i);
	}

	for (int i = 0; i < maximum; ++i) {
		s->pop();
		BOOST_CHECK_EQUAL(s->peek(), maximum - i - 1);
	}
	delete s;
}

BOOST_AUTO_TEST_CASE(min_value_test_int) {
	Stack<int> * s = new Stack<int>();
	for (int i = 5; i < 1000; ++i)
	{
		s->push(i);
	}
	BOOST_CHECK_EQUAL(s->min(), 5);
	
	delete s;
}
//----------------------------------------------------------------------

BOOST_AUTO_TEST_CASE(intro2) {
	cout << "\n-- Queue Class --Unit test.\n";
	cout << "Last compiled: " << __TIMESTAMP__ << "\n\n";
}

BOOST_AUTO_TEST_CASE(default_queue_constructor_test_int) {
	Queue<int> * q = new Queue<int>();
	delete q;
}

BOOST_AUTO_TEST_CASE(push_queue_test_int) {
	Queue<int> * q = new Queue<int>();
		q->push(11);
		q->push(10);
		q->push(9);
		q->push(8);
		BOOST_CHECK_EQUAL(q->peek(), 11);
		BOOST_CHECK_EQUAL(q->getSize(), 4);
		delete q;
}

BOOST_AUTO_TEST_CASE(pop_queue_test_int) {
	Queue<int> * q = new Queue<int>();
	for (int i = 0; i < maximum; ++i)
	{
		q->push(i);
	}
	for (int i = 0; i < maximum - 1; ++i) {
		q->pop();
		BOOST_CHECK_EQUAL(q->peek(), i + 1);
		BOOST_CHECK_EQUAL(q->getSize(), maximum - 1 - i);
	}
	delete q;
}
BOOST_AUTO_TEST_CASE(pop_queue_test_int2) {
	Queue<int> * q2 = new Queue<int>();
	q2->push(5);
	q2->pop();
	BOOST_CHECK_EQUAL(q2->getSize(), 0);
	delete q2;
}

BOOST_AUTO_TEST_CASE(pop_queue_test_int3) {
	Queue<int> * q2 = new Queue<int>();
	q2->pop();
	BOOST_CHECK_EQUAL(q2->getSize(), 0);
	delete q2;
}

BOOST_AUTO_TEST_CASE(pop_isEmpty_test_int3) {
	Queue<int> * q2 = new Queue<int>();
	BOOST_CHECK_EQUAL(q2->isEmpty(), true);
	q2->push(5);
	BOOST_CHECK_EQUAL(q2->isEmpty(), false);
	q2->pop();
	BOOST_CHECK_EQUAL(q2->isEmpty(), true);
	delete q2;
}