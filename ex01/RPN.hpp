/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:09:37 by tafocked          #+#    #+#             */
/*   Updated: 2025/05/19 18:42:10 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <iostream>

class RPN
{
public:
	RPN();
	RPN(const RPN &src);
	RPN &operator=(const RPN &src);
	~RPN();

	void evaluate(const std::string &expression);
private:
	std::stack<int> _stack;

	int applyOperation(int a, int b, char op);
};
