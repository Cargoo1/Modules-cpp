/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 17:39:22 by acamargo          #+#    #+#             */
/*   Updated: 2026/04/16 21:14:27 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP

# define SCALARCONVERTER_HPP

# include <string>

class	ScalarConverter
{
	public:
	enum	Types
	{
		INT,
		CHAR,
		FLOAT,
		DOUBLE,
		INFP,
		INFN,
		INFFP,
		INFFN,
		NANF,
		NAND,
		INVALID
	};
private:
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter & other);
	~ScalarConverter(void);

	ScalarConverter&	operator=(const ScalarConverter & other);
	Types	getType(char c);
	Types	find_decimal_Type(std::string const & str);



public:
	static void		convert(const std::string & str);
	static void		cast(long n, ScalarConverter::Types type);
	static void		cast(float n, ScalarConverter::Types type);
	static void		cast(double n, ScalarConverter::Types type);
	static void		cast(char c, ScalarConverter::Types type);
};

#endif
