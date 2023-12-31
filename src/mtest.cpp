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

void create_nodes(const string& s)
{
	int len = s.size();
	for(int i = 0; i < len; ++i)
	{

		//nodes.pop_back( node(input[i]) );
	}
}

void find_sub_expr(const std::string& input)
{
    int len = input.size();
    int i = 0;
    int cpos = 0;
    int opos = 0;

    while(i < len)  
    {
        //std::cout << "input[" << i << "]=" << input[i] << endl;
        if(input[i] == ')')
        {
            cpos = i;
            while(i > opos)
            {
                --i;
                //std::cout << "input[" << i << "]=" << input[i] << endl;
                if(input[i] == '(')
                {
                    opos = i;
                    string sub_exp = input.substr(opos+1, (cpos)-(opos+1));
                    std::cout << "sub exp = " << sub_exp  << endl;

                    //string expr = R"(\s*(\d+)\s*(([*/+-])\s*(\d+)\s*)+)";
					string lhs = "\\s*(\\d+)\\s*";
					string rhs = "(([*/+-])\\s*(\\d+)\\s*)+";
					//string rhs = "(([*/+-])\\s*(\\d+)\\s*)+(\\s*(\\d+)\\s*([*/+-])\\s*(\\d+)\\s*)*";
					string expr = lhs + rhs;
					
                    vector<smatch> matches;
                    qmatch(expr, sub_exp, matches);

                    int len = matches.size();
                    for(int i = 0; i < len; ++i)
                    {
                        cout << "matches[" << i << "][0] = " << matches[i][0].str() <<  "   \\\\ sub" << endl; // sub
                        cout << "matches[" << i << "][1] = " << matches[i][1].str() <<  "   \\\\ lhs" << endl; // lhs
						cout << "matches[" << i << "][2] = " << matches[i][2].str() <<  "   \\\\ rhs" << endl; // rhs
                        cout << "matches[" << i << "][3] = " << matches[i][3].str() <<  "   \\\\ opr" << endl; // opr
                        cout << "matches[" << i << "][4] = " << matches[i][4].str() <<  "   \\\\ rhs" << endl; // rhs
						cout << "matches[" << i << "][5] = " << matches[i][5].str() <<  "   \\\\ rhs" << endl; // rhs
                    }
                    
                    i = (opos = cpos);
                    break;
               }
           }
        }
    ++i;
    }
}

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

	find_sub_expr(s);
	return 0;
}