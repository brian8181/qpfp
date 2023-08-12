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

const std::vector<std::string>::const_iterator find_first_of_add_sub_operator(const std::vector<std::string>& input);
const std::vector<std::string>::const_iterator find_first_of_mult_div_operator(const std::vector<std::string>& input);
const std::vector<std::string>::const_iterator find_match_cparen(const std::vector<std::string>& input);
const std::vector<std::string>::const_iterator find_match_cbrace(const std::vector<std::string>& input);
const std::vector<std::string>::const_iterator find_match_ccurly_brace(const std::vector<std::string>& input);
const std::vector<std::string>::const_iterator find_Last_oparen(const std::vector<std::string>& input);
const std::vector<std::string>::const_iterator find_Last_cparen(const std::vector<std::string>& input);
const std::vector<std::string>::const_iterator find__oparen_operator(const std::vector<std::string>& input);
const std::vector<std::string>::const_iterator find_exp_operator(const std::vector<std::string>& input);
const std::vector<std::string>::const_iterator find_mult_operator(const std::vector<std::string>& input);
const std::vector<std::string>::const_iterator find_plus_operator(const std::vector<std::string>& input);
const std::vector<std::string>::const_iterator find_plus_operator(const std::vector<std::string>& input, const std::vector<std::string>::const_iterator& beg);
//const std::vector<std::string>::const_iterator find_plus_operator(const std::vector<std::string>& input, vector<string>::size_type pos);
void qmatch(const std::string& sexpress, const std::string& input, /* out */ std::vector<std::string>& matches);
void qmatch(const std::string& sexpress, const std::string& input, /* out */  std::vector<std::smatch>& matches);

#endif

