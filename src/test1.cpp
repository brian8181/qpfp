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

int main(int argc, char const *argv[])
{
    // check for input 
	if(argc < 2)
    {
		cout << "argc=" << argc << endl;
        return 0;
    }
	
	string s = argv[1];
	cout << "argv[1] = " << s << endl; 

    vector<smatch> matches;

    // string expr = "(\\d+)";
    // string expr = "\\d+";

    string lhs = "\\s*(\\d+)\\s*";
    // string op = "([*/+-])";
    string rhs = "(((([*/+-])\\s*(\\d+)\\s*)+)+)";
    //string rhs = "(([*/+-])\\s*(\\d+)\\s*)+(\\s*(\\d+)\\s*([*/+-])\\s*(\\d+)\\s*)*";
    string expr = lhs + rhs;

    qmatch(expr, s, matches);

    int len = matches.size();
    for(int i = 0; i < len; ++i)
    {
        cout << "matches[" << i << "] = " << matches[i].str() <<  endl;

        cout << "matches[" << i << "][0] = " << matches[i][0].str() <<  "   \\\\ sub" << endl; // sub
        cout << "matches[" << i << "][1] = " << matches[i][1].str() <<  "   \\\\ lhs" << endl; // lhs
        cout << "matches[" << i << "][2] = " << matches[i][2].str() <<  "   \\\\ rhs" << endl; // rhs
        cout << "matches[" << i << "][3] = " << matches[i][3].str() <<  "   \\\\ opr" << endl; // opr
        cout << "matches[" << i << "][4] = " << matches[i][4].str() <<  "   \\\\ rhs" << endl; // rhs
        cout << "matches[" << i << "][5] = " << matches[i][5].str() <<  "   \\\\ rhs" << endl; // rhs
        cout << "matches[" << i << "][6] = " << matches[i][6].str() <<  "   \\\\ rhs" << endl; // rhs
        cout << "matches[" << i << "][7] = " << matches[i][7].str() <<  "   \\\\ rhs" << endl; // rhs
    }
}