// License:    GPL
// Author:     Brian K Preston
// File Name:  qpfp.cpp
// Build Date: Sat Aug  5 11:17:18 PM CDT 2023
// Version:    0.0.1

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <regex>
#include "utility.hpp"
#include "qpfp.hpp"

using namespace std;

void print_help()
{
	string help = "qpfp [OPTION]... [INPUT]...";
	std::cout << help << std::endl;
}

int parse_options(int argc, char* argv[])
{
	string input = argv[1];
	parse(input);
	return 0;
}

void parse(string input)
{
	const string tokens_sexpress = "(" + number_sexpress + ")|(" + oper_sexpress + ")|(" + "[\\)\\(]" + ")";

	cout << "tokens ..." << endl;
	vector<string> tokens;
	qmatch(tokens_sexpress, input, tokens);
	int len = tokens.size();
	for(int i = 0; i < len; ++i)
	{
		cout << tokens[i] << ", ";
	}
	cout << endl;

	cout << "opers ..." << endl;
	vector<string> opers;
	qmatch(oper_sexpress, input, opers);
	len = opers.size();
	for(int i = 0; i < len; ++i)
	{
		cout << opers[i] << ", ";
	}
	cout << endl;

	cout << "numbers ..." << endl;
	vector<string> numbers;
	qmatch(number_sexpress, input, numbers);
	len = numbers.size();
	for(int i = 0; i < len; ++i)
	{
		cout << numbers[i] << ", ";
	}
	cout << endl;

	cout << "opers_alt ..." << endl;
	vector<string> opers_alt;
	qmatch(opers_sexpress, input, opers_alt);
	len = opers_alt.size();
	for(int i = 0; i < len; ++i)
	{
		cout << opers_alt[i] << ", ";
	}
	cout << endl;

	const int PLUS = 2;
	const int EXP = 4;
	const int MULT = 3;
	const int DIV = 5;
	const vector<int> op_map = {PLUS, EXP, MULT, DIV};

	cout << "opers sm ..." << endl;
	vector<smatch> opers_sm;
	qmatch(opers_sexpress, input, opers_sm);
	int ilen = opers_sm.size();
	cout << "ilen=" << ilen << endl;
	for(int i = 0; i < ilen; ++i)
	{
		int jlen = opers_sexpress.size();
		cout << "jlen=" << jlen << endl;
		for(int j = 1; j < jlen; ++j)
		{
			if(opers_sm[i][j].matched)
				cout << "j=" << j << " matched=" << opers_sm[i][0].str() << ", "; 
		}
	}
	cout << endl;
}