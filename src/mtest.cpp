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

void find_sub_expr(const std::string& input)
{
    int len = input.size();
    int i = 0;
    int cpos = 0;
    int opos = 0;

    while(i < len)  
    {
        //std::cout << "input[" << i << "]=" << input[i] << std::endl;
        if(input[i] == ')')
        {
            cpos = i;
            while(i > opos)
            {
                --i;
                //std::cout << "input[" << i << "]=" << input[i] << std::endl;
                if(input[i] == '(')
                {
                    opos = i;
                    string sub_exp = input.substr(opos+1, (cpos)-(opos+1));
                    std::cout << "sub exp = " << sub_exp  << std::endl;

                    string expr = R"(\s*(\d+)\s*([*/+-])\s*(\d+)\s*)";
                    vector<smatch> matches;
                    qmatch(expr, sub_exp, matches);

                    int len = matches.size();
                    for(int i = 0; i < len; ++i)
                    {
                        std::cout << "matches[" << i << "][0] = " << matches[i][0].str() <<  "   \\\\ sub" << std::endl; // sub
                        std::cout << "matches[" << i << "][1] = " << matches[i][1].str() <<  "   \\\\ rhs" << std::endl; // rhs
                        std::cout << "matches[" << i << "][2] = " << matches[i][2].str() <<  "   \\\\ opr" << std::endl; // opr
                        std::cout << "matches[" << i << "][3] = " << matches[i][3].str() <<  "   \\\\ lhs" << std::endl; // lhs
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
	if(argc < 2)
		cout << "argc=" << argc << endl;
	
	string s = argv[1];
	cout << "input = " << s << endl; 

	find_sub_expr(s);
	return 0;
}