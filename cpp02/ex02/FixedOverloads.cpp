/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedOverloads.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 21:45:26 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/12 23:05:48 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

# include <iostream>

Fixed&	Fixed::operator=(Fixed const & new_value)
{
	std::cout << "Copy assigment operation called" << std::endl;
	this->_fixedValue = new_value.getRawBits();
	return *this;
}

Fixed	Fixed::operator+(Fixed const &other)
{
	Fixed	result;
	int		rawBits;

	rawBits = this->_fixedValue + other.getRawBits();
	result.setRawBits(rawBits);
	return (result);
}

Fixed	Fixed::operator-(Fixed const &other)
{
	Fixed	result;
	int		rawBits;

	rawBits = this->getRawBits() - other.getRawBits();
	result.setRawBits(rawBits);
	return (result);
}

Fixed	Fixed::operator*(Fixed const &other)
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/(Fixed const &other)
{
	if (other)
	return (F)
}

std::ostream	&operator<<(std::ostream &o, Fixed const &value)
{
	o << value.toFloat();
	return (o);
}

