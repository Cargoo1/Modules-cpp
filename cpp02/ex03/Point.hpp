/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:42:48 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/16 21:28:19 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP

#define POINT_HPP

# include "Fixed.hpp"

class	Point
{
public:
	Point(void);
	Point(float x, float y);
	Point(Point const & other);
	~Point(void);
	Fixed const &	get_x(void) const;
	Fixed const &	get_y(void) const;
	Point&	operator=(Point const & other);
private:
	Fixed const	_x;
	Fixed const	_y;
};

#endif
