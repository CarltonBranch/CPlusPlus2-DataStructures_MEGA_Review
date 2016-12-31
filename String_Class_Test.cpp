/**	@file: String_Class_test.cpp
@author Carlton Branch
@author clbranch.jr@gmail.com
@author https://github.com/CarltonBranch
@date 2016-09-28
@brief Unit test of sorted_vector container
*/

#define _CRT_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS
#define BOOST_TEST_MODULE String_Class_Test

#include <boost/test/unit_test.hpp>
#include <iostream>
#include "String_Class.hpp"
using namespace boost::unit_test;
using namespace std;


BOOST_AUTO_TEST_CASE(intro) {
	cout << "\n-- String Class --Unit test.\n";
	cout << "Last compiled: " << __TIMESTAMP__ << "\n\n";
}

BOOST_AUTO_TEST_CASE(default_constructor_test_int) {
	String_Class s("hello,world");
	BOOST_CHECK_EQUAL(s.toString(), "hello,world");
}

BOOST_AUTO_TEST_CASE(check_unique_test) {
	String_Class s("hello,world");
	BOOST_CHECK_EQUAL(s.CheckUniqueCharReturnBool(), false);
	String_Class s1("Carlton");
	BOOST_CHECK_EQUAL(s1.CheckUniqueCharReturnBool(), true);
	String_Class s2("");
	BOOST_CHECK_EQUAL(s2.CheckUniqueCharReturnBool(), false);

}

BOOST_AUTO_TEST_CASE(reverse_C_string_test) {
	String_Class s;
	BOOST_CHECK_EQUAL(s.ReverseCStringReturnResult(""), "");
	BOOST_CHECK_EQUAL(s.ReverseCStringReturnResult("hello"), "olleh");
}


BOOST_AUTO_TEST_CASE(delete_unique_test) {
	String_Class s("Hello");
	BOOST_CHECK_EQUAL(s.DeleteUniqueCharReturnBool(), "Helo");
	String_Class s1("HHH");
	BOOST_CHECK_EQUAL(s1.DeleteUniqueCharReturnBool(), "H");
}

BOOST_AUTO_TEST_CASE(replace_space_with_percent20_test) {
	String_Class s("H ll o");
	BOOST_CHECK_EQUAL(s.replaceSpaceswithPercent20ReturnCount(), 2);
	BOOST_CHECK_EQUAL(s.toString(), "H0ll0o");
}

BOOST_AUTO_TEST_CASE(check_Anagram_test) {
	String_Class s("Hello");
	BOOST_CHECK_EQUAL(s.CheckAnagramReturnBool("hel"), false );
	BOOST_CHECK_EQUAL(s.CheckAnagramReturnBool("helll"), false);
	BOOST_CHECK_EQUAL(s.CheckAnagramReturnBool("olleH"), true);
	}