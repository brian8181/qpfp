#pragma once
#include <string>

using std::string;

class Node
{
	private:

		string value;

	public:
		Node(char c);
		Node(string s);

		Node() = default;

		~Node() = default;

		string Value();

};