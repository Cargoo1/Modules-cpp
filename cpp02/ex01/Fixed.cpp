/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 21:35:09 by acamargo          #+#    #+#             */
/*   Updated: 2026/03/02 16:13:15 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"
# include <cmath>
# include <iostream>


Fixed::Fixed(void) : _fixedValue(0)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(int const int_value): _fixedValue(int_value << Fixed::_numFractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
	return;
}

Fixed::Fixed(float const float_value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedValue = (int)roundf(float_value * (1 << Fixed::_numFractionalBits));
	return;
}

Fixed::Fixed(Fixed const & fixedValue)
{
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(fixedValue.getRawBits());
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

float	Fixed::toFloat(void) const
{
	return ((float)this->_fixedValue / (float)(1 << Fixed::_numFractionalBits));
}

int		Fixed::toInt(void) const
{
	return (this->_fixedValue >> Fixed::_numFractionalBits);
}

Fixed&	Fixed::operator=(Fixed const & new_value)
{
	std::cout << "Copy assigment operation called" << std::endl;
	this->~Fixed();
	new (this) Fixed(new_value);
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &value)
{
	o << value.toFloat();
	return (o);
}

int	const Fixed::_numFractionalBits = 8;
