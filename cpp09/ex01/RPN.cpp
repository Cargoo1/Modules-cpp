/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 15:21:00 by acamargo          #+#    #+#             */
/*   Updated: 2026/10/06 18:55:57 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cctype>
#include <cstdlib>
#include <exception>
#include <limits>
#include <stack>
#include <stdexcept>
#include <string>

RPN::RPN(void)
{

}

RPN::RPN(const RPN& other)
{
	(void)other;

}

RPN::~RPN(void)
{

}

RPN&	RPN::operator=(const RPN& other)
{
	if (this == &other)
		return *this;
	this->~RPN();
	new (this) RPN(other);
	return *this;
}

int	RPN::calculate_expression(const std::string& str_expr)
{
	std::string			str_expr_cpy(str_expr);
	std::stack<int>		operands;
	std::stack<char>	expr;
	std::string::iterator	it;
	
	for (it = str_expr_cpy.begin(); it != str_expr_cpy.end();)
	{
		if (std::isspace(*it))
		{
			it = str_expr_cpy.erase(it);
			continue;
		}
		++it;
	}
	it = str_expr_cpy.begin();
	for (;it != str_expr_cpy.end(); ++it)
	{
		char	c = *it;
		if (std::isdigit(c))
		{
			operands.push(c - '0');
			continue;
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			if (operands.size() < 2)
				throw std::runtime_error("Bad token more operands needed");
			int	a, b;
			b = operands.top();
			operands.pop();
			a = operands.top();
			operands.pop();
			switch (c)
			{
				case '+':
					operands.push(RPN::add(a, b));
					break;
				case '-':
					operands.push(RPN::substraction(a, b));
					break;
				case '*':
					operands.push(RPN::multiplication(a, b));
					break;
				case '/':
					operands.push(RPN::division(a, b));
					break;
				default:
					throw std::runtime_error("Bad token");
					break;
			}
			continue;
		}
		throw std::runtime_error("Bad token");
	}
	if (operands.size() > 1 || operands.size() == 0)
		throw std::runtime_error("Missing tokens");
	return operands.top();
}

int		RPN::multiplication(int a, int b)
{
	if (a == 0 || b == 0)
		return a * b;
	else if ((a == -1 && b == std::numeric_limits<int>::min())
		|| (a == std::numeric_limits<int>::min() && b == -1))
		throw std::runtime_error("Overflow occured");
	else if (a == std::numeric_limits<int>::min() || b == std::numeric_limits<int>::min())
		throw std::runtime_error("Overflow or Underflow occured");
	else if ((a / b < 0) && a < std::numeric_limits<int>::min() / b)
		throw std::runtime_error("Underflow occured");
	else if ((a / b > 0) && a > std::numeric_limits<int>::max() / b)
		throw std::runtime_error("Overflow occured");
	return a * b;
}

int		RPN::division(int a, int b)
{
	if (b == 0)
		throw std::runtime_error("Division by 0");
	if ((a == -1 && b == std::numeric_limits<int>::min())
		|| (a == std::numeric_limits<int>::min() && b == -1))
		throw std::runtime_error("Overflow occured");
	return a / b;
}

int		RPN::add(int a, int b)
{
	if (a > 0 && b > 0 && a > std::numeric_limits<int>::max() - b)
		throw std::runtime_error("Overflow occured");
	else if (a < 0 && b < 0 && a < std::numeric_limits<int>::min() - b)
		throw std::runtime_error("Underflow occured");
	return a + b;
}

int		RPN::substraction(int a, int b)
{
	if (a < 0 && b > 0 && a < std::numeric_limits<int>::min() + b)
		throw std::runtime_error("Underflow occured");
	else if (a > 0 && b < 0 && a > std::numeric_limits<int>::max() + b)
		throw std::runtime_error("Overflow occured");
	return a - b;

}
