#include "node.hpp"

node::node(char c)
{
    val = string(1, c);
}

node::node(const string& s)
{
    val = s;
}

string node::get_val()
{
    return val;
}

void node::set_val(const string& s)
{
    val = s;
}