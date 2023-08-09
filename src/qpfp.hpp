// License:    GPL
// Author:     Brian K Preston
// File Name:  qpfp.hpp
// Build Date: Sat Aug  5 11:17:18 PM CDT 2023
// Version:    0.0.1

#ifndef _qpfp_HPP
#define _qpfp_HPP

#include <getopt.h>
#include <string>
#include "bash_color.h"

using std::string;

// constants
const int NUMBER = 1;
const int MULT_DIV = 0;
const int ADD_SUB = 0;
const int OPERATOR = 3;
const int PAREN = 0;
const int OPEN_PAREN = 5;
const int CLOSE_PAREN = 5;

const string number_sexpress = "\\d+(\\.\\d*)?";
const string oper_sexpress = "[-+*/^)(]";
const string opers_sexpress = "(\\-)|(\\+)|(\\*)|(\\^)|(\\))|(\\()";
const string paren_sexpress = "[\\)\\(]";
const string parens_sexpress = "(\\))|(\\()";
const string binary_op_sexpress = number_sexpress + "\\s+" + "[-+*^]" + "\\s+" + number_sexpress;

// functions
void print_help();
int parse_options(int argc, char* argv[]);
void match(string input);
void inner_match(string input);

#endif

