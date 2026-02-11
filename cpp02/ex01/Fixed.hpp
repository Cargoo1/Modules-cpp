/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 21:27:37 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/11 17:26:10 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP

# define FIXED_HPP

class	Fixed
{
public:
	Fixed(void);
	Fixed(Fixed const & fixedValue);
	Fixed(int const int_value);
	Fixed(float const float_value);
	~Fixed(void);
	Fixed&	operator=(Fixed const & fixedValue);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

private:
	int					_fixedValue;
	static int const	_numFractionalBits;

};

#endif
