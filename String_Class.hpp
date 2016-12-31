#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <cstdlib>
#include <algorithm>
using namespace std;

class String_Class {
	string str;
	char* str2;
	int count;
public:

	String_Class(){}
	String_Class(string input) : str(input) {}
	~String_Class() {  }

	string toString() {
		return str;
	}

	bool CheckUniqueCharReturnBool() {
		map<char, int> m;

		if (str.length() == 0)
			return false;
		
		for (unsigned i = 0; i < str.length(); i++)
		{
			if (m.find(str.at(i) ) == m.cend())
				m.insert_or_assign(str.at(i), 1);
			else
				return false;
		}
		
	 return true;
	}

	string DeleteUniqueCharReturnBool() {
		map<char, int> m;
		int last = 0;
		string result = "";

		if (str.length() == 0)
			return false;

		for (unsigned i = 0; i < str.length(); i++)
		{
			if (m.find(str.at(i)) == m.cend()) 
			{
				m.insert_or_assign(str.at(i), 1);
				result += str.at(i);
			}

			else
			{
				continue;
			}
		}
		return result;
	}

	int replaceSpaceswithPercent20ReturnCount() {
		int count = 0;
		string result = "";
		for (unsigned i = 0; i < str.length(); i++)
		{
			if (str.at(i) != ' ')
				result += str.at(i);
			else
			{
				result += '%20';
				count++;
			}
		}
		str = result;
		return count;
	}

	bool CheckAnagramReturnBool(string other)
	{
		map<char, int>m_self;
		map<char, int>m_other;

		//check for equal size and null size
		if (str.length() != other.length() || (str.length() == 0 || other.length() == 0)    )
			return false;

		//find mode for each character in self and other string 
		for (unsigned i = 0; i < str.length(); ++i) {
			if ( m_self.find( str.at(i) ) != m_self.end() ) {
				m_self.at(str.at(i))++;
			}
			else
			{
				m_self.insert_or_assign(str.at(i), 1);
			}
		
			if (m_other.find(other.at(i)) != m_other.end() ) {
				m_other.at(other.at(i))++;
			}
			else
			{
				m_other.insert_or_assign(other.at(i), 1);
			}
		}

		map<char, int> ::iterator itM;
		map<char, int> ::iterator itM2;
		itM2 = m_self.begin();

		for (itM = m_other.begin(); itM != m_other.end(); ++itM, ++itM2)
		{
			if (itM->second != itM2->second)
				return false;
		}

		return true;
	}


	string ReverseCStringReturnResult(char* str2) {
		string result = "";
		int count = 0;

		while (*str2 != '\0')
		{
			count++;
			str2++;
		}
		count--;
		str2--;
		while (count >= 0)
		{
			result += *str2;
			str2--;
			count--;
		}	
		
		return result;
	}

};