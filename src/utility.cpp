// License:    GPL
// Author:     Brian K Preston
// File Name:  qpfp.hpp
// Build Date: Sat Aug  5 11:17:18 PM CDT 2023
// Version:    0.0.1

#include "utility.hpp"

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

void qmatch(const string& sexpress, const string& input, /* out */ vector<std::smatch>& matches)
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


