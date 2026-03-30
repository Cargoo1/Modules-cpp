/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 17:46:16 by acamargo          #+#    #+#             */
/*   Updated: 2026/03/30 19:17:25 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"
#include <iostream>
#include <stdexcept>

ScalarConverter::ScalarConverter(void)
{
	return ;
}

ScalarConverter::ScalarConverter(const ScalarConverter & other)
{
	(void)other;
	return ;
}

ScalarConverter::~ScalarConverter(void)
{
	return ;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& other)
{
	if (this == &other)
		return *this;
	return *this;
}

bool		ft_isdigit(char c)
{
	if (c <= '9' && c >= '0')
		return true;
	return false;
}

bool	ft_isint(const std::string& str)
{
	for (int i = 0; i < (int)str.length(); i++)
	{
		if (str.at(i) == '.')
			return false;
	}
	return true;
}

ScalarConverter::Types	ScalarConverter::getType(char c)
{
	if (ft_isdigit(c) || (c == '-' || c == '+'))
		return INT;
	else
		return CHAR;
}

ScalarConverter::Types	findType(const std::string& str)
{
	ScalarConverter::Types	type = ScalarConverter::INVALID;
	bool	sign = 0;
	int		i = 0;

	if (!ft_isdigit(str.at(0)) && str.length() == 1)
		return ScalarConverter::CHAR;
	if (str.at(0) == '-' || str.at(0) == '+')
	{
		if (str.at(0) == '-')
			sign = 1;
		i++;
		if (str.compare(1,3,"inf") == 0)
			type = ScalarConverter::INFP;
		i += 3;
		if (i < static_cast<int>(str.length()) && str.at(i) == 'f')
			type = ScalarConverter::INFFP;
		return (ScalarConverter::Types)(type + sign);
	}
	else if (str.compare(0, 3, "nan") == 0)
	{
		type = ScalarConverter::NAN;
		i += 3;
		if (i < static_cast<int>(str.length()) && str.at(i) == 'f')
			type = ScalarConverter::NANF;
		return type;
	}
	while (i < static_cast<int>(str.length()))
	{
		if (!ft_isdigit(str.at(i)))
			return ScalarConverter::INVALID;
		i++;
	}
	return type;
}

void	ScalarConverter::convert(const std::string & str)
{
	Types	type = INVALID;
	if (!str.empty())
		type = findType(str);
	std::cout << type << '\n';
}
