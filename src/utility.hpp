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

void qmatch(const std::string& sexpress, const std::string& input, /* out */ std::vector<std::string>& matches);
void qmatch(const std::string& sexpress, const std::string& input, /* out */  std::vector<std::smatch>& matches);

#endif

