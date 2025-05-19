/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:13:10 by tafocked          #+#    #+#             */
/*   Updated: 2025/05/19 18:49:25 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{}

RPN::RPN(const RPN &src) : _stack(src._stack)
{}

RPN &RPN::operator=(const RPN &src)
{
	if (this != &src)
		_stack = src._stack;
	return *this;
}

RPN::~RPN()
{}

void RPN::evaluate(const std::string &expression)
{
	for (size_t i = 0; i < expression.length(); ++i)
	{
		char c = expression[i];
		if (isdigit(c))
		{
			_stack.push(c - '0');
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			if (_stack.size() < 2)
				throw std::runtime_error("Not enough operands.");
			int b = _stack.top();
			_stack.pop();
			int a = _stack.top();
			_stack.pop();
			int result = applyOperation(a, b, c);
			_stack.push(result);
		}
		else if (c != ' ')
			throw std::runtime_error("Invalid character in expression.");
	}
	if (_stack.size() != 1)
		throw std::runtime_error("Invalid expression.");
	std::cout << _stack.top() << std::endl;
}

int RPN::applyOperation(int a, int b, char op)
{
	if (op =='+')
		return (a + b);
	if (op == '-')
		return (a - b);
	if (op == '*')
		return (a * b);
	if (op =='/')
	{
		if (b == 0)
			throw std::runtime_error("Division by zero.");
		return a / b;
	}
	throw std::runtime_error("Invalid operator.");
}
