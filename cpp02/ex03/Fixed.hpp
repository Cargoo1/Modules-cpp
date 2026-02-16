/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 21:27:37 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/16 21:33:48 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP

# define FIXED_HPP

#include <ostream>

# define EPSILON 1.0f / (1 << Fixed::_numFractionalBits)

class	Fixed
{
public:
	Fixed(void);
	Fixed(Fixed const &fixedValue);
	Fixed(int const int_value);
	Fixed(float const float_value);
	~Fixed(void);
	Fixed&	operator=(Fixed const & other);
	Fixed	operator+(Fixed const & other) const;
	Fixed	operator-(Fixed const & other) const;
	Fixed	operator*(Fixed const & other) const;
	Fixed	operator/(Fixed const & other) const;
	bool	operator>(Fixed const & other) const;
	bool	operator<(Fixed const & other) const;
	bool	operator>=(Fixed const & other) const;
	bool	operator<=(Fixed const & other) const;
	bool	operator==(Fixed const & other) const;
	bool	operator!=(Fixed const & other) const;
	Fixed&	operator++(void);
	Fixed	operator++(int);
	Fixed&	operator--(void);
	Fixed	operator--(int);
	static	Fixed& min(Fixed &lhs, Fixed &rhs);
	static	Fixed& max(Fixed &lhs, Fixed &rhs);
	static	Fixed const & min(Fixed const &lhs, Fixed const &rhs);
	static	Fixed const & max(Fixed const &lhs, Fixed const &rhs);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

private:
	int					_fixedValue;
	static int const	_numFractionalBits;

};

std::ostream	&operator<<(std::ostream &o, Fixed const &value);

#endif
