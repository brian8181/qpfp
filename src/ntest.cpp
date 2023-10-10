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
int main(int argc, char const *argv[])
{
	if(argc < 2)
		cout << "argc=" << argc << endl;
	
	string s = argv[1];
	cout << "argv[1] = " << s << endl; 

    vector<smatch> matches;
    string lhs = "\\s*(\\d+)\\s*";
    string op = "([*/+-])";
    string rhs = "(([*/+-])\\s*(\\d+)\\s*)+";
     
    //string exp = "(\\d)+";
    string exp = "(\\d+)";
    qmatch(exp, s, matches);

    int len = matches.size();
    for(int i = 0; i < len; ++i)
    {
        cout << "matches[" << i << "] = " << matches[i].str() <<  endl;
        // cout << "matches[" << i << "][1] = " << matches[i][1].str() <<  endl;
        // cout << "matches[" << i << "][2] = " << matches[i][2].str() <<  endl;
        // cout << "matches[" << i << "][3] = " << matches[i][3].str() <<  endl;
    }
}