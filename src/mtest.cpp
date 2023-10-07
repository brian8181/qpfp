// License:    GPL
// Author:     Brian K Preston
// File Name:  qpfp.cpp
// Build Date: Sat Aug  5 11:17:18 PM CDT 2023
// Version:    0.0.1

#include <iostream>
#include <string>
#include "utility.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
	if(argc < 2)
		cout << "argc=" << argc << endl;
	
	string s = argv[1];
	cout << "input=" << s << endl; 

	find_sub_expr(s);
	return 0;
}