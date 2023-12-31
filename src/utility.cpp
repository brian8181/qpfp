// License:    GPL
// Author:     Brian K Preston
// File Name:  qpfp.hpp
// Build Date: Sat Aug  5 11:17:18 PM CDT 2023
// Version:    0.0.1

#include <iostream> //debug
#include "utility.hpp"
#include <algorithm>

using std::string;
using std::vector;
using std::smatch;
using std::cout;
using std::endl;

const vector<string>::const_iterator find_first_of_add_sub_operator(const vector<string>& input)
{
    vector<string> ops = {"+", "-"};
    auto beg = input.begin();
    auto end = input.end();
    auto op = std::find_first_of(beg, end, ops.begin(), ops.end());
    return op;
}

const vector<string>::const_iterator find_first_of_mult_div_operator(const vector<string>& input)
{
    vector<string> ops = {"*", "/"};
    auto beg = input.begin();
    auto end = input.end();
    auto op = std::find_first_of(beg, end, ops.begin(), ops.end());
    return op;
}

const vector<string>::const_iterator find_exp_operator(const vector<string>& input)
{
    return find_exp_operator(input, input.begin());
}

const std::vector<std::string>::const_iterator find_exp_operator(const std::vector<std::string>& input, const std::vector<std::string>::const_iterator& beg)
{
    auto end = input.end();
    auto op = std::find(beg, end, "^");
    return op;
}

const vector<string>::const_iterator find_mult_operator(const vector<string>& input)
{
    return find_mult_operator(input, input.begin());
}

const std::vector<std::string>::const_iterator find_mult_operator(const std::vector<std::string>& input, const std::vector<std::string>::const_iterator& beg)
{
    auto end = input.end();
    auto op = std::find(beg, end, "*");
    return op;
}

const vector<string>::const_iterator find_plus_operator(const vector<string>& input)
{
   return find_plus_operator(input, input.begin());
}

const vector<string>::const_iterator find_plus_operator(const vector<string>& input, const vector<string>::const_iterator& beg)
{
    auto end = input.end();
    auto op = find(beg, end, "+");
    return op;
}

void qmatch(const string& sexpress, const string& input, /* out */ vector<string>& matches)
{
    std::regex::flag_type REGX_FLAGS = std::regex::ECMAScript;
    std::regex express = std::regex(sexpress, REGX_FLAGS);

    auto begin = std::sregex_iterator(input.begin(), input.end(), express);
    auto end = std::sregex_iterator();

    for(std::sregex_iterator iter = begin; iter != end; ++iter)
    {
        std::smatch match = *iter;
        matches.push_back(match.str());
    }
}

void qmatch(const string& sexpress, const string& input, /* out */ vector<smatch>& matches)
{
    std::regex::flag_type REGX_FLAGS = std::regex::ECMAScript;
    std::regex express = std::regex(sexpress, REGX_FLAGS);

    auto begin = std::sregex_iterator(input.begin(), input.end(), express);
    auto end = std::sregex_iterator();

    for(std::sregex_iterator iter = begin; iter != end; ++iter)
    {
        std::smatch match = *iter;
        matches.push_back(match);
    }
}
