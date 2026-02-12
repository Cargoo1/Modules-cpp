/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 21:27:37 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/12 22:47:47 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP

# define FIXED_HPP

#include <ostream>
class	Fixed
{
public:
	Fixed(void);
	Fixed(Fixed const &fixedValue);
	Fixed(int const int_value);
	Fixed(float const float_value);
	~Fixed(void);
	Fixed&	operator=(Fixed const & other);
	Fixed	operator+(Fixed const & other);
	Fixed	operator-(Fixed const & other);
	Fixed	operator*(Fixed const & other);
	Fixed	operator/(Fixed const & other);
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
