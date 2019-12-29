#include <iostream>
#include <fstream>
#include "Balancer.h"
#include <string>

using namespace std;

int main()
{
	ifstream in("input.txt", ifstream::in);
	string str;
	in >> str;
	BraceChecker Angle_Brackets('[', ']');
	BraceChecker Figure_brackets('{', '}');
	BraceChecker Round_Brackets('(', ')');
	if (BraceChecker::isBalanced(str))
		cout << "Balanced";
	else
		cout << "Not balanced";
	return 0;
}