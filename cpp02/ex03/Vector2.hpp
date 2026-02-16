/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector2.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:41:35 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/16 21:00:42 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2_HPP

#define VECTOR2_HPP

# include "Point.hpp"

class	Vector2
{
public:
	Vector2(void);
	Vector2(Point v1, Point v2, Point v3);
	Vector2(Vector2 const & other);
	Vector2& operator=(Vector2 const &other);
	Point const &	get_v1(void) const;
	Point const &	get_v2(void) const;
	Point const &	get_v3(void) const;

private:
	Point const	_v1;
	Point const _v2;
};

#endif
