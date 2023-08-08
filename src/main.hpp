// License:    GPL
// Author:     Brian K Preston
// File Name:  main.hpp
// Build Date: Sat Aug  5 11:17:18 PM CDT 2023
// Version:    0.0.1

#ifndef _STD_HPP
#define _STD_HPP

#include <string>
#include <getopt.h>
#include "bash_color.h"

// functions
void print_help();
void print_match_header(const string& pattern, const string& src, const bool single_flag, const bool pretty_flag);
int parse_options(int argc, char* argv[]);

#endif
