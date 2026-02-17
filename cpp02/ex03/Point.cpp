/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:57:12 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/17 11:39:28 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Point.hpp"
# include "Fixed.hpp"

Point::Point(void): _x(0), _y(0)
{
	return ;
}

Point::Point(float x, float y) : _x(x), _y(y)
{
	return ;
}

Point::Point(Point const & other): _x(other._x), _y(other._y)
{
	return ;
}

Point::~Point(void)
{
	return ;
}

Point&	Point::operator=(Point const & other)
{
	(void)other;
	return *this;
}

Fixed const &	Point::get_x(void) const
{
	return (this->_x);
}

Fixed const & Point::get_y(void) const
{
	return (this->_y);
}

