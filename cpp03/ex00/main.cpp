/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamargo <acamargo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:44:23 by acamargo          #+#    #+#             */
/*   Updated: 2026/02/17 14:17:49 by acamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <limits>

int	main(void)
{
	ClapTrap	test("test");
	std::cout << test.getHitPoints() << '\n';
	std::cout << std::numeric_limits<unsigned int>::max() << '\n';
}
