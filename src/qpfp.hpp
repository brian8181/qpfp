// License:    GPL
// Author:     Brian K Preston
// File Name:  qpfp.hpp
// Build Date: Sat Aug  5 11:17:18 PM CDT 2023
// Version:    0.0.1

#ifndef _qpfp_HPP
#define _qpfp_HPP

// constants

// Options Flags
unsigned char DEFAULTS = 0;
unsigned char option_flags = 0; 

const int NUMBER = 1;
const int MULT_DIV = 0;
const int ADD_SUB = 0;
const int OPERATOR = 3;
const int PAREN = 0;
const int OPEN_PAREN = 5;
const int CLOSE_PAREN = 5;

const string number_sexpress = "\\d+(\\.\\d*)?";
const string oper_sexpress = "[-+*^]";
const string opers_sexpress = "(\\-)|(\\+)|(\\*)|(\\^)";
const string parens_sexpress = "(\\))|(\\()";
const string binary_op_sexpress = number_sexpress + "\\s+" + "[-+*^]" + "\\s+" + number_sexpress;


#endif

