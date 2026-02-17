/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedOverloads.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 21:45:26 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/17 12:04:45 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

# include <iostream>

Fixed&	Fixed::operator=(Fixed const & new_value)
{
//	std::cout << "Copy assigment operation called" << std::endl;
	this->_fixedValue = new_value.getRawBits();
	return *this;
}

Fixed	Fixed::operator+(Fixed const &other) const
{
	Fixed	result;
	int		rawBits;

	rawBits = this->_fixedValue + other.getRawBits();
	result.setRawBits(rawBits);
	return (result);
}

Fixed	Fixed::operator-(Fixed const &other) const
{
	Fixed	result;
	int		rawBits;

	rawBits = this->getRawBits() - other.getRawBits();
	result.setRawBits(rawBits);
	return (result);
}

Fixed	Fixed::operator*(Fixed const &other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/(Fixed const &other) const
{
	if (other.toFloat() <= (1.0f / (1 << Fixed::_numFractionalBits)))
		return (Fixed(this->toFloat()));
	return (Fixed(this->toFloat() / other.toFloat()));
}

bool	Fixed::operator>(Fixed const &other) const
{
	if (this->getRawBits() > other.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<(Fixed const &other) const
{
	if (this->getRawBits() < other.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>=(Fixed const &other) const
{
	if (this->getRawBits() > other.getRawBits())
		return (true);
	else if (this->getRawBits() == other.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<=(Fixed const &other) const
{
	if (this->getRawBits() < other.getRawBits())
		return (true);
	else if (this->getRawBits() == other.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator==(Fixed const &other) const
{
	if (this->getRawBits() == other.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!=(Fixed const &other) const
{
	if (this->getRawBits() != other.getRawBits())
		return (true);
	return (false);
}

Fixed&	Fixed::operator++(void)
{
	*this = Fixed(this->toFloat() + EPSILON);
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);

	*this = Fixed(this->toFloat() + EPSILON);
	return (temp);
}

Fixed&	Fixed::operator--(void)
{
	*this = Fixed(this->toFloat() - EPSILON);
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);

	*this = Fixed(this->toFloat() - EPSILON);
	return (temp);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &value)
{
	o << value.toFloat();
	return (o);
}
