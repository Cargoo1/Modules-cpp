/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:32:56 by acamargo          #+#    #+#             */
/*   Updated: 2026/03/02 16:54:53 by acamargo         ###   ########.fr       */
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
	Fixed	res;

	std::cout << "--- Operations Tests ---\n";
	b = 42.42f;
	a = 0.42f;
	res = a + b;
	std::cout << a << " + " << b  << " = " << res << '\n';
	b = 42.11111111111f;
	a = 0.1111111111111f;
	res = a - b;
	std::cout << a << " - " << b  << " = " << res << '\n';
	b = 0.5f;
	a = 0.5f;
	res = a * b;
	std::cout << a << " * " << b  << " = " << res << '\n';
	b = 0.5f;
	a = 10;
	res = a * b;
	std::cout << a << " / " << b  << " = " << res << '\n';

	std::cout << "--- Test comparasion operations ---\n";
	b = 0.5f;
	a = 10;
	res = a < b;
	std::cout << a << " < " << b  << " = " << res << '\n';

	b = 10.0f;
	a = 10.0f;
	res = a <= b;
	std::cout << a << " <= " << b  << " = " << res << '\n';

	b = 10.0f;
	a = 10.1f;
	res = a == b;
	std::cout << a << " == " << b  << " = " << res << '\n';

	b = 10.0f;
	a = 10.0f;
	res = a != b;
	std::cout << a << " != " << b  << " = " << res << '\n';

	std::cout << "--- Test incrementatiton operations ---\n";
	a = 10.0f;
	std::cout << a << " ++a = " << ++a << "\n";

	a = 0.0f;
	std::cout << a << " a++ = " << a++ << "\n";
	std::cout << a << '\n';

	a = 10.0f;
	std::cout << a << " --a = " << --a << "\n";

	a = 0.0f;
	std::cout << a << " a-- = " << a-- << "\n";
	std::cout << a << '\n';

	std::cout << "--- Test min max fns ---\n";
	a = 0.0f;
	b = -10.4f;
	std::cout << "max(" << a << ", " << b << ") = " << Fixed::max(a, b) << '\n';
	a = -10.5f;
	b = -20.0f;
	std::cout << "min(" << a << ", " << b << ") = " << Fixed::min(a, b) << '\n';
}
