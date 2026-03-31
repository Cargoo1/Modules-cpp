/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 17:46:16 by acamargo          #+#    #+#             */
/*   Updated: 2026/03/31 17:52:32 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"
#include <cinttypes>
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
		type = ScalarConverter::NAN;
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
	std::cout << "char : " << c << '\n';
	std::cout << "int : " << inum << '\n';
	std::cout << "float : " << fnum << '\n';
	std::cout << "double : " << dnum << '\n';
}

void	ScalarConverter::cast(long n, ScalarConverter::Types type)
{
	int		overflows = 0;
	int		inum = 0;
	float	fnum = 0;
	double	dnum = 0;
	char	c = 0;

	if (n > std::numeric_limits<int>::max())
		overflows = overflows | 3;
	else
	{
		inum = static_cast<int>(n);
		c = static_cast<char>(n);
	}
	print_casts(inum, fnum, dnum, c, type, overflows);

}

void	ScalarConverter::cast(float n, ScalarConverter::Types type)
{
	bool	int_overflow = false;
	bool	char_overflow = false;
	int		inum = 0;
	double	dnum;
	char	c;

	(void)int_overflow;
	(void)char_overflow;
	(void)c;
	if (n > CHAR_MAX)
		char_overflow = true;
	if (inum > 127)
		print_casts(&inum, &n, &dnum, NULL, type);
}
void	ScalarConverter::convert(const std::string & str)
{
	Types	type = INVALID;
	int		inum = 0;
	double	dnum = 0.0;
	float	fnum = 0.0;
	char	c = 0;

	if (!str.empty())
		type = findType(str);
	if (type == ScalarConverter::INVALID)
	{
		print_casts(NULL, NULL, NULL, NULL, type);
		return ;
	}
	switch (type) {
		case INT:
			break;
		case CHAR:
			c = str.at(0);
			inum = static_cast<int>(c);
			dnum = static_cast<double>(c);
			fnum = static_cast<float>(c);
			print_casts(&inum, &fnum, &dnum, &c, type);
			break;
		case FLOAT:
			fnum = std::strtof(str.c_str(), NULL);
			inum = static_cast<int>(fnum);
			c = static_cast<char>(fnum);
			dnum = static_cast<double>(fnum);
			if (static_cast<int>(fnum) > 127)
				print_casts(&inum, &fnum, &dnum, NULL, type);
			else
				print_casts(&inum, &fnum, &dnum, &c, type);
			break;
		case DOUBLE:
			dnum = std::strtod(str.c_str(), NULL);
			inum = static_cast<int>(dnum);
			c = static_cast<char>(dnum);
			fnum = static_cast<float>(dnum);
			if (static_cast<int>(dnum) > 127)
				print_casts(&inum, &fnum, &dnum, NULL, type);
			else
				print_casts(&inum, &fnum, &dnum, &c, type);
			break;
		default:
			break;
	}
}
