/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 21:15:52 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/16 22:06:31 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

# include <iostream>

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	Point const	a(3.0f, 4.0f);
	Point const b(4.0f, 1.0f);
	Point const c(1.0f, 1.0f);
	Point const point(2.0f,1.0f);

	if (bsp(a, b, c, point))
		std::cout << "in the triangle\n";
	else
		std::cout << "not inside the triangle\n";
	return (0);
}
