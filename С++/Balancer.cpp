#include "Balancer.h"
#include <stack>
#include <map>
#include <string>
#include <iostream>

using namespace std;

BraceChecker::BraceChecker(char opening, char closing)
{
	brackets_dictionary[opening] = closing;
}

bool BraceChecker::isBalanced(const string& str)
{
	map<char,char>::iterator dict_it;
	stack<char> opened_brackets;
	for (auto str_it = str.begin(); str_it != str.end(); ++str_it) {
		if (brackets_dictionary.find(*str_it) != brackets_dictionary.end())
			opened_brackets.push(*str_it);
		else {
			for (dict_it = brackets_dictionary.begin(); (dict_it != brackets_dictionary.end()) & (dict_it->second != *str_it); ++dict_it);
			if (dict_it != brackets_dictionary.end()) {
				if (!opened_brackets.empty() && (brackets_dictionary[opened_brackets.top()] == dict_it->second)) // && принципиально для случая пустого стека
					opened_brackets.pop();
				else
					return false;
			}
		}
	}
	if (opened_brackets.empty())
		return true;
	return false;
}