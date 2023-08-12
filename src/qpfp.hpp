// License:    GPL
// Author:     Brian K Preston
// File Name:  qpfp.hpp
// Build Date: Sat Aug  5 11:17:18 PM CDT 2023
// Version:    0.0.1

#ifndef _qpfp_HPP
#define _qpfp_HPP

#include <getopt.h>
#include <string>
#include <vector>
#include "bash_color.h"

// constants
const int NUMBER = 1;
const int MULT_DIV = 0;
const int ADD_SUB = 0;
const int OPERATOR = 3;
const int PAREN = 0;
const int OPEN_PAREN = 5;
const int CLOSE_PAREN = 5;

const std::string number_sexpress = "\\d+(\\.\\d*)?";
const std::string oper_sexpress = "[-+*/^)(]";
const std::string opers_sexpress = "(\\-)|(\\+)|(\\*)|(\\^)|(\\))|(\\()";
const std::string paren_sexpress = "[\\)\\(]";
const std::string parens_sexpress = "(\\))|(\\()";
const std::string binary_op_sexpress = number_sexpress + "\\s+" + "[-+*^]" + "\\s+" + number_sexpress;

const int opers_sexpress_grp_count = 7;
const int parens_sexpress_grp_count = 3;

// functions
void print_help();
int parse_options(int argc, char* argv[]);
void match(std::string input);
void match_groups(std::string input);
const std::vector<std::string>::const_iterator find_all_plus_operators(const std::vector<std::string>& input);
const std::vector<std::string>::const_iterator find_all_plus_operators(const std::vector<std::string>& input, const std::vector<std::string>::const_iterator& beg);

#endif
