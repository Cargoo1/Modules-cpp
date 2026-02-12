/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:32:56 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/12 22:36:08 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"
# include <iostream>
#include <ostream>

int	main(void)
{
	Fixed	a;
	Fixed	b(10);
	Fixed	c(0.2f);
	Fixed	d(0.1f);

	Fixed	e = c + d;
	float	test = 0.0f + 1.0f / (1 << 8);
	std::cout << e << '\n';
	e = c - d;
	std::cout << e << '\n';
	e = c * d;
	std::cout << e << '\n';
	std::cout << test << '\n';
}
