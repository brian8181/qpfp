#pragma once
#include "node.hpp"

class TerminalNode : public Node
{
	public:
		TerminalNode() = default;
		TerminalNode(char c);
		TerminalNode(string s);

		~TerminalNode() = default;
};