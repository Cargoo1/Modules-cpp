/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 21:35:09 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/11 17:41:28 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

# include <iostream>

Fixed::Fixed(void) : _fixedValue(0)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::~Fixed(void)
{
	std::cout << "Descructor called" << std::endl;
	return;
}

int		Fixed::getRawBits(void) const
{
	return (this->_fixedValue);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedValue = raw;
	return;
}

Fixed&	Fixed::operator=(Fixed const & new_value)
{
	std::cout << "Assing operation called" << std::endl;
	this->_fixedValue = new_value.getRawBits();
	return *this;
}

Fixed::Fixed(Fixed const & fixedValue)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixedValue;
	return;
}

Fixed::Fixed(int const int_value): _fixedValue(int_value)
{
	return;
}

Fixed::Fixed(float const int_value)
{

	return;
}

int	const Fixed::_numFractionalBits = 8;

