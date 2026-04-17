/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 17:46:16 by acamargo          #+#    #+#             */
/*   Updated: 2026/04/17 17:08:11 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

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

ScalarConverter::Types	find_decimal_Type(std::string const & str)
{
	int		i = 0;
	ScalarConverter::Types	type = ScalarConverter::INT;
	bool	decimal_point = false;

	if (str.at(0) == '-' || str.at(0) == '+')
		i++;
	while (i < static_cast<int>(str.length()))
	{
		if (i == static_cast<int>(str.length()) - 1
			&& (str.at(i) == 'f'
			&& decimal_point))
			type = ScalarConverter::FLOAT;
		else if (!ft_isdigit(str.at(i)) && (str.at(i) != '.'))
			return ScalarConverter::INVALID;
		else if (str.at(i) == '.')
		{
			if (decimal_point
				|| (i + 1 >= static_cast<int>(str.length())
				|| !ft_isdigit(str.at(i + 1))))
				return ScalarConverter::INVALID;
			decimal_point = true;
			type = ScalarConverter::DOUBLE;
		}
		i++;
	}
	return type;
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
		if (i < static_cast<int>(str.length())
			&& (type == ScalarConverter::INFP
			&& str.at(i) == 'f'))
			type = ScalarConverter::INFFP;
	}
	else if (str.compare(0, 3, "nan") == 0)
	{
		type = ScalarConverter::NAND;
		i += 3;
		if (i < static_cast<int>(str.length()) && str.at(i) == 'f')
			type = ScalarConverter::NANF;
		return type;
	}
	if (type == ScalarConverter::INVALID)
		return find_decimal_Type(str);
	return (ScalarConverter::Types)(type + sign);
}

void	print_casts(int inum, float fnum, double dnum, char c, ScalarConverter::Types type, int overflows)
{
	(void)type;
	if (overflows & 1)
		std::cout << "char : impossible" << '\n';
	else if ((c >= 0 && c <= 32) || c == 127)
		std::cout << "char : Non displayable\n";
	else
		std::cout << "char : " << '\'' << c << '\'' << '\n';
	if (overflows >> 1 & 1)
		std::cout << "int : impossible\n";
	else
		std::cout << "int : " << inum << '\n';
	std::cout << "float : " << fnum << "f\n";
	std::cout << "double : " << dnum << '\n';
}

void	ScalarConverter::cast(long n, ScalarConverter::Types type)
{
	int		overflows = 0;
	int		inum = 0;
	float	fnum = 0;
	double	dnum = 0;
	char	c = 0;

	if (n > std::numeric_limits<int>::max() || n < std::numeric_limits<int>::min())
		overflows = overflows | 0b00000011;
	if (n > std::numeric_limits<char>::max() || n < std::numeric_limits<char>::min())
		overflows = overflows | 0b01;
	inum = static_cast<int>(n);
	c = static_cast<char>(n);
	fnum = static_cast<float>(n);
	dnum = static_cast<double>(n);
	print_casts(inum, fnum, dnum, c, type, overflows);
}

void	ScalarConverter::cast(char n, ScalarConverter::Types type)
{
	int		overflows = 0;
	int		inum = 0;
	float	fnum = 0;
	double	dnum = 0;

	inum = static_cast<int>(n);
	fnum = static_cast<float>(n);
	dnum = static_cast<double>(n);
	print_casts(inum, fnum, dnum, n, type, overflows);
}

void	ScalarConverter::cast(float n, ScalarConverter::Types type)
{
	int		overflows = 0;
	int		inum = 0;
	double	dnum = 0;
	float	decimal_part = std::fabs(n) - std::floor(std::fabs(n));
	int		sign = 1;
	if (n < 0.0f)
		sign = -1;
	float temp = sign * (fabs(n) - fabs(decimal_part));
	char	c = 0;

	inum = static_cast<int>(n);
	c = static_cast<char>(n);
	if (std::fabs(temp) - std::fabs(static_cast<float>(inum)) != 0.0f)
		overflows = overflows | 0b11;
	if ((std::fabs(temp) - std::fabs(static_cast<float>(c)) != 0.0f)
		|| c < 0)
		overflows = overflows | 0b01;
	dnum = static_cast<double>(n);
	print_casts(inum, n, dnum, c, type, overflows);
}

void	ScalarConverter::cast(double n, ScalarConverter::Types type)
{
	int		overflows = 0;
	int		inum = 0;
	float	fnum = 0;
	double	decimal_part = std::fabs(n) - std::floor(std::fabs(n));
	int		sign = 1;
	if (n < 0.0f)
		sign = -1;
	double	temp = sign * (fabs(n) - fabs(decimal_part));
	char	c = 0;

	inum = static_cast<int>(n);
	c = static_cast<char>(n);
	if (std::fabs(temp) - std::fabs(static_cast<double>(inum)) != 0.0)
		overflows = overflows | 0b11;
	if ((std::fabs(temp) - std::fabs(static_cast<double>(c)) != 0.0)
		|| c < 0)
		overflows = overflows | 0b01;
	fnum = static_cast<float>(n);
	print_casts(inum, n, fnum, c, type, overflows);
}

void	ScalarConverter::convert(const std::string & str)
{
	Types	type = INVALID;

	if (!str.empty())
		type = findType(str);
	if (type == ScalarConverter::INVALID)
	{
		std::cout << "Invalid input\n";
		return ;
	}
	switch (type) {
		case INT:
			cast(strtol(str.c_str(), NULL, 10), type);
			break;
		case CHAR:
			cast(str.at(0), type);
			break;
		case FLOAT:
			cast(strtof(str.c_str(), NULL), type);
			break;
		case DOUBLE:
			cast(strtod(str.c_str(), NULL), type);
			break;
		case INFP:
			print_casts(0, std::numeric_limits<float>::infinity(),
							std::numeric_limits<double>::infinity(),
							0, type, 0b11);
			break;
		case INFN:
			print_casts(0, -std::numeric_limits<float>::infinity(),
							-std::numeric_limits<double>::infinity(),
							0, type, 0b11);
			break;
		case INFFP:
			print_casts(0, std::numeric_limits<float>::infinity(),
							std::numeric_limits<double>::infinity(),
							0, type, 0b11);
			break;
		case INFFN:
			print_casts(0, -std::numeric_limits<float>::infinity(),
							-std::numeric_limits<double>::infinity(),
							0, type, 0b11);
			break;
		case NAND:
			print_casts(0, std::numeric_limits<float>::quiet_NaN(),
							std::numeric_limits<double>::quiet_NaN(),
							0, type, 0b11);
			break;
		case NANF:
			print_casts(0, std::numeric_limits<float>::quiet_NaN(),
							std::numeric_limits<double>::quiet_NaN(),
							0, type, 0b11);
			break;
		default:
			break;
	}
}
