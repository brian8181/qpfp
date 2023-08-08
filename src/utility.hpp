// License:    GPL
// Author:     Brian K Preston
// File Name:  qpfp.hpp
// Build Date: Sat Aug  5 11:17:18 PM CDT 2023
// Version:    0.0.1

#ifndef _utility_HPP
#define _utility_HPP

#include <string>
#include <vector>
#include <regex>

using std::string;
using std::vector;
using std::smatch;

void qmatch(const string& sexpress, const string& input, /* out */ vector<string>& matches);
void qmatch(const string& sexpress, const string& input, /* out */  vector<smatch>& matches);

#endif

