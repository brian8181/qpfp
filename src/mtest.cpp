// License:    GPL
// Author:     Brian K Preston
// File Name:  qpfp.cpp
// Build Date: Sat Aug  5 11:17:18 PM CDT 2023
// Version:    0.0.1

#include <iostream>
#include <string>
#include <list>
#include "node.hpp"
#include "utility.hpp"

using namespace std;

list<node> nodes;

void create_nodes(const string& s)
{
	int len = s.size();
	for(int i = 0; i < len; ++i)
	{

		//nodes.pop_back( node(input[i]) );
	}
}

int main(int argc, char const *argv[])
{
	if(argc < 2)
		cout << "argc=" << argc << endl;
	
	string s = argv[1];
	cout << "input=" << s << endl; 

	find_sub_expr(s);
	return 0;
}