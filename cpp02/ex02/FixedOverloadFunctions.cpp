/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedOverloadFunctions.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandrocamargo <acamargo@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 04:39:55 by alejandrocama     #+#    #+#             */
/*   Updated: 2026/02/14 05:17:19 by alejandrocama    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed&	Fixed::min(Fixed& lhs, Fixed& rhs)
{
	if (rhs < lhs)
		return (rhs);
	return (lhs);
}

Fixed const &	Fixed::min(Fixed const &lhs, Fixed const &rhs)
{
	if (rhs < lhs)
		return (rhs);
	return (lhs);
}

Fixed&	Fixed::max(Fixed &lhs, Fixed &rhs)
{
	if (rhs > lhs)
		return (rhs);
	return (lhs);
}

Fixed const &	Fixed::max(Fixed const &lhs, Fixed const &rhs)
{
	if (rhs > lhs)
		return (rhs);
	return (lhs);
}
