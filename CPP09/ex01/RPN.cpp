#include "RPN.hpp"
#include <stack>
#include <sstream>
#include <cctype>
#include <exception>

RPN::RPN()
{}

RPN::RPN(const RPN& other)
{
	(void)other;
}

RPN& RPN::operator=(const RPN& other)
{
	(void)other;
	return (*this);
}

RPN::~RPN()
{}

int RPN::calculate(const std::string& expression)
{
	std::stack<int> Stack;
	std::stringstream ss(expression);
	std::string token;

	while (ss >> token)
	{
		if (token.size() == 1 && std::isdigit(static_cast<unsigned char>(token[0])))
			Stack.push(token[0] - '0');
		else if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (Stack.size() < 2)
				throw std::exception();
			int right = Stack.top();
			Stack.pop();
			int left = Stack.top();
			Stack.pop();

			int result = 0;
			if (token == "+")
				result = left + right;
			else if (token == "-")
				result = left - right;
			else if (token == "*")
				result = left * right;
			else
			{
				if (right == 0)
					throw std::exception();
				result = left / right;
			}
			Stack.push(result);
		}
		else
			throw std::exception();
	}
	if (Stack.size() != 1)
		throw std::exception();
	return (Stack.top());
}