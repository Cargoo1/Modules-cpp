/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:32:56 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/14 05:13:21 by alejandrocama    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"
# include <iostream>
#include <ostream>

int	main(void)
{
	Fixed	a;
	Fixed	b(10);
	Fixed	c(42.1293f);
	Fixed	d((1.0f/256));

	Fixed	e = c + d;
	float	test = 0.0f + 1.0f / (1 << 8);
	std::cout << e << '\n';
	e = c - d;
	std::cout << e << '\n';
	e = c * d;
	std::cout << e << '\n';
	std::cout << test << '\n';

	Fixed	div(10.0f);
	Fixed	div2(2.0f);

	std::cout << div2 << '\n';
	Fixed	res = div / div2;
	std::cout << res << '\n';

	std::cout << "--- Test comparasion operations ---\n";
	std::cout << "--- less equal---\n";
	Fixed	left(42.43f);
	Fixed	right(42.42f);

	std::cout << left.getRawBits() << '\n';
	std::cout << right.getRawBits() << '\n';
	std::cout << left << '\n';
	std::cout << right << '\n';
	if (left > right)
		std::cout << "Passed\n";
	std::cout << "--- less equal---\n";
	left = 2.0f;
	std::cout << "--- Test incrementatiton operations ---\n";
	std::cout << "--- pre incrementatiton---\n";
	Fixed	pre_increment;

	std::cout << pre_increment << '\n';
	std::cout << ++pre_increment << '\n';
	std::cout << "--- post incrementatiton---\n";
	Fixed	post_increment;
	std::cout << post_increment++ << '\n';
	std::cout << post_increment << '\n';

	std::cout << --post_increment << '\n';
	std::cout << --post_increment << '\n';
	post_increment = 0.0f;
	std::cout << post_increment-- << '\n';
	std::cout << post_increment << '\n';

	std::cout << "--- Test min max fns ---\n";
	Fixed  lhs(1.0f/256);
	Fixed  rhs(0.0f);
	std::cout << Fixed::max(++lhs, rhs) << '\n';
}
