#pragma once
#include <map>

class BraceChecker {
	static std::map<char,char> brackets_dictionary;
	public:
		static bool isBalanced(const std::string&);
		BraceChecker(char opening, char closing);
};
