/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 21:15:52 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/17 11:49:08 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

# include <iostream>

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	std::cout << "--- Tests ---\n\n";
	std::cout << "--- Inside the triangle ---\n";
	Point a(3.0f, 4.0f);
	Point b(4.0f, 1.0f);
	Point c(1.0f, 1.0f);
	Point point(1.1f,1.1f);
	std::cout << a.get_x() << ' ' << a.get_y() << '\n';
	std::cout << b.get_x() << ' ' << b.get_y() << '\n';
	std::cout << c.get_x() << ' ' << c.get_y() << '\n';
	std::cout << "Point: " << point.get_x() << ' ' << point.get_y() << '\n';
	if (bsp(a, b, c, point))
		std::cout << "The point is in the triangle\n";
	else
		std::cout << "The point is outside the triangle\n";

	std::cout << "--- Outside the triangle ---\n";
	Point point1(0.0f,0.0f);
	std::cout << a.get_x() << ' ' << a.get_y() << '\n';
	std::cout << b.get_x() << ' ' << b.get_y() << '\n';
	std::cout << c.get_x() << ' ' << c.get_y() << '\n';
	std::cout << "Point: " << point1.get_x() << ' ' << point1.get_y() << '\n';
	if (bsp(a, b, c, point1))
		std::cout << "The point is in the triangle\n";
	else
		std::cout << "The point is outside the triangle\n";
	std::cout << "--- In a vertex of the triangle ---\n";
	Point point2(3,4);
	std::cout << a.get_x() << ' ' << a.get_y() << '\n';
	std::cout << b.get_x() << ' ' << b.get_y() << '\n';
	std::cout << c.get_x() << ' ' << c.get_y() << '\n';
	std::cout << "Point: " << point2.get_x() << ' ' << point2.get_y() << '\n';
	if (bsp(a, b, c, point2))
		std::cout << "The point is in the triangle\n";
	else
		std::cout << "The point is outside the triangle\n";
	std::cout << "--- In an edge of the triangle ---\n";
	Point point3(2,1);
	std::cout << a.get_x() << ' ' << a.get_y() << '\n';
	std::cout << b.get_x() << ' ' << b.get_y() << '\n';
	std::cout << c.get_x() << ' ' << c.get_y() << '\n';
	std::cout << "Point: " << point3.get_x() << ' ' << point3.get_y() << '\n';
	if (bsp(a, b, c, point3))
		std::cout << "The point is in the triangle\n";
	else
		std::cout << "The point is outside the triangle\n";
	return (0);
}
