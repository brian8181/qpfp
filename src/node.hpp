#pragma once
#include <string>

using std::string;

class node
{
	public:
		node(char c);
		node(const string& s);  
        string get_val();
        void set_val(const string& s);

private:
		string val;

};