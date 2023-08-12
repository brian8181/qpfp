// License:    GPL
// Author:     Brian K Preston
// File Name:  qpfp.cpp
// Build Date: Sat Aug  5 11:17:18 PM CDT 2023
// Version:    0.0.1

#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <algorithm>
#include "utility.hpp"
#include "qpfp.hpp"

using namespace std;

void print_help()
{
	string help = "qpfp [-h] [INPUT]";
	std::cout << help << std::endl;
}

int parse_options(int argc, char* argv[])
{
	if(argc != 2)
	{
		cout << "error: no input, or too many inputs ..." << endl;
		print_help();
		return -1;
	}
	
	string input = argv[1];
	if(input == "-h")
	{
		print_help();
		return 0;
	}

	match(input);
	match_groups(input);
	return 0;
}

void match(string input)
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

	// create binary operations from tokens
	auto op = find_plus_operator(tokens);
	auto lhs = op-1;
	auto rhs = op+1;
	cout << "binary + operation ..." << endl;
	cout << *lhs << *op << *rhs << endl;

	// overload
	op = find_plus_operator(tokens, op+1);
	lhs = op-1;
	rhs = op+1;
	cout << "overload, binary + operation ..." << endl;
	cout << *lhs << *op << *rhs << endl;

	op = find_mult_operator(tokens);
	lhs = op-1;
	rhs = op+1;
	cout << "binary * operation ..." << endl;
	cout << *lhs << *op << *rhs << endl;

	op = find_first_of_mult_div_operator(tokens);
	lhs = op-1;
	rhs = op+1;
	cout << "binary (* or /) operation ..." << endl;
	cout << *lhs << *op << *rhs << endl;

	op = find_first_of_add_sub_operator(tokens);
	lhs = op-1;
	rhs = op+1;
	cout << "binary (+ or -) operation ..." << endl;
	cout << *lhs << *op << *rhs << endl;


	op = find_Last_oparen(tokens);
	cout << "last ( ..." << endl;
	cout << "op=" << &op << " *op=" << *op << endl; 
	
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
}

void match_groups(string input)
{
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
		int jlen = opers_sexpress_grp_count;
		cout << "jlen=" << jlen << endl;
		for(int j = 1; j < jlen; ++j)
		{
			if(opers_sm[i][j].matched)
				cout << "j=" << j << " matched=" << opers_sm[i][0].str() << ", "; 
		}
	}
	cout << endl;
}

void match_mult_div_group(string input)
{
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
		int jlen = opers_sexpress_grp_count;
		cout << "jlen=" << jlen << endl;
		for(int j = 1; j < jlen; ++j)
		{
			if(opers_sm[i][j].matched)
				cout << "j=" << j << " matched=" << opers_sm[i][0].str() << ", "; 
		}
	}
	cout << endl;
}
