/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 19:55:49 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/16 22:04:23 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

# include "Point.hpp"


# define Vector2 Point

Fixed	cross_2d(Vector2 const & vec0, Vector2 const & vec1)
{
	return (vec0.get_x() * vec1.get_y() - vec1.get_x() * vec0.get_y());
}

bool	check_for_point(Point const & p0, Point const & p1, Point const & point)
{
	Vector2	vec(p1.get_x().toFloat() - p0.get_x().toFloat(),
				p1.get_y().toFloat() - p0.get_y().toFloat());
	Vector2	to_point(point.get_x().toFloat() - p0.get_x().toFloat(),
					point.get_y().toFloat() - p0.get_y().toFloat());

	if (cross_2d(to_point, vec) < 0.0f || cross_2d(to_point, vec) == 0.0f)
		return (false);
	return (true);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (!check_for_point(a, b, point))	
		return (false);
	if (!check_for_point(b, c, point))
		return (false);
	if (!check_for_point(c, a, point))
		return (false);
	return (true);
}
